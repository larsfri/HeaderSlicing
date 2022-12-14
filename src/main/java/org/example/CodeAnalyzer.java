package org.example;

import java.util.ArrayList;

public class CodeAnalyzer {

    private File file;
    private String filename;
    private String line;
    private int type;
    private boolean comment;
    private MacroTable macroTable;


    public CodeAnalyzer(String filename, MacroTable macroTable){
        if(macroTable == null){
            this.macroTable = new MacroTable();
        }else{
            this.macroTable = macroTable;
        }
        this.filename = filename;
        file = new File(filename);
        line = file.getCurrentLine();
        type = checkType();

    }
    //gets next line returns true if line not null
    public boolean nextLine(){
        line = file.getNextLine();
        type = checkType();
        if(type == -1) return false;
        return true;
    }
    public int getLineIndex(){
        return file.getLineIndex();
    }

    public int processLine(){
        switch(type){
            case -1: return -1;
            case 0: return 0;
            case 1:
                //analyze Preprocessing code
                preprocessing();
                return 1;
            case 2:
                //check comment
                //find macros & replace them
                processCodeLine(this.line);
                return 2;
            default:
                System.out.println("Unexpected Type for Line");
                return -1;
        }
    }

    private void preprocessing() {
        int space = line.indexOf(" ");
        String operator = line.substring(0, space);
        switch (operator){
            case "#define": defineMacro(line.substring(space));
        }
    }

    private void defineMacro(String name) {
        name = StringOperations.trimSpaces(name);
        int space = name.indexOf(" ");
        String body = "";
        String macro = name;
        if(space == -1) {
            macroTable.addObjectMacro(macro, body);
        }else{
            macro = name.substring(0, space);
            body = name.substring(space);
            body = StringOperations.trimSpaces(body);
            if(macro.indexOf("(") == -1){
                macroTable.addObjectMacro(macro, body);
            }else{
                defineFunctionMacro(name);
            }
        }

    }

    private void defineFunctionMacro(String name) {
        int open = StringOperations.openParenthesis((name));
        int close = open + 1 + StringOperations.closeParenthesis(name.substring(open+1), 0);
        if(close == -1 || close +2 > name.length()){
            System.out.println("Unexpected macro declaration, ERROR");
        }else {
            String parameter = name.substring(open +1, close);
            String body = name.substring(close + 1);
            String[] param = parameter.split(",");
            name = name.substring(0, open);
            macroTable.addFunctionMacro(name, body, param);
        }
    }


    /*
       -1 null
       0 empty line
       1 pre-processor code
       2 normal code
        */
    public int checkType() {

        if(line == null) return -1;
        if(line.equals("")) return 0;
        if(line.charAt(0) == '#') return 1;
        if(StringOperations.trimSpaces(line).equals("")) return 0;

        return 2;
    }

    public String processCodeLine(String code){
        if (code.length() == 0) return code;
        String result = code;
        if(comment){
            int commentEnd = StringOperations.checkBlockCommentEnd(code);
            if(commentEnd >= 0){
                comment = false;
                return result.substring(0, commentEnd+2) + processCodeLine(code.substring(commentEnd+2));
            }
        }
        int lineComment = StringOperations.checkLineComment(code);
        if(lineComment >=0){
            code = code.substring(0, lineComment);
            return processCodeLine(code) + result.substring(lineComment);
        }
        int blockComment = StringOperations.checkBlockComment(code);
        if(blockComment >= 0){
            comment = true;
            return processCodeLine(code);
        }
        return checkForStrings(code);

    }

    private String checkForStrings(String code) {
        int index = StringOperations.checkString(code);
        if(index == -1) return checkForReplacements(code);
        int end = index+1 + StringOperations.checkString(code.substring(index+1));

        return checkForReplacements(code.substring(0, index)) + code.substring(index, end+1) + checkForStrings(code.substring(end+1));
        
    }

    private String checkForReplacements(String code){
        for(Macro m: macroTable.getMacros()){
            if(code.contains(m.getName())){
                if(m.countArguments() == -1){
                    code = replaceObjectMacro(code, m);
                }else{
                    code = replaceFunctionMacro(code, m);
                }

                code = checkForMacros(code);
                break;
            }
        }
        return code;
    }

    private String replaceObjectMacro(String code, Macro m) {
        String name = m.getName();
        int index = code.indexOf(name);
        char prev = StringOperations.previousChar(code, index);
        char next = StringOperations.nextChar(code, index + name.length() -1);
        if(prev == ' ' || prev == '(' || prev == ','){
            if(next == ' ' || next == ')' || next == ','){
                code = StringOperations.replaceString(code,name, m.getBody(""));
            }
        }
        return code;
    }

    private String checkForMacros(String code) {
        if(code == "") return "";
        String[] parts = code.split(" ");
        String result = "";
        for(String s: parts){
            String res = s;
            if(res.charAt(0) == '#') stringifyMacro(res);
            if(StringOperations.openParenthesis(s) != -1){
                res = checkFunctionMacro(s);
            }else {
                Macro m = macroTable.checkForMacro(s);
                res = m.getBody("");
            }
            result = result +" " + res;
        }

        return result;
    }

    private String stringifyMacro(String res) {
        String text = checkForMacros(res.substring(1));
        if(text.equals(res.substring(1))) return res;
        return "\"" + text + "\"";

    }

    private String checkFunctionMacro(String macro){
        int open = StringOperations.openParenthesis(macro);
        int close = open + 1 +StringOperations.closeParenthesis(line.substring(open+1), 0);
        String parenthesis = macro.substring(open +1 , close);
        String[] parts = parenthesis.split(",");
        parenthesis = checkForMacros(parenthesis);


    }
}
