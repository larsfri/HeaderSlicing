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

        do{
            this.processLine();
        }while(this.nextLine());

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

    public boolean saveDataToFile(String path){
        try{
            file.saveDataToFile(path);
            System.out.println("Saved to "+path);
            return true;
        }catch(Exception e){
            e.printStackTrace();
            System.out.println("Error while saving");
            return false;
        }
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
                String newLine = processCodeLine(this.line);
                file.changeCurrentLine(newLine);
                return 2;
            default:
                System.out.println("Unexpected Type for Line");
                return -1;
        }
    }

    private void preprocessing() {
        int space = line.indexOf(" ");
        if(space != -1) {
            String operator = line.substring(0, space);
            switch (operator) {
                case "#define":
                    defineMacro(line.substring(space));
                    file.deleteCurrentLine();
                    file.reduceIndex();
                    break;
                case "#undef":
                    undefMacro(line.substring(space));
                    file.deleteCurrentLine();
                    file.reduceIndex();
                    break;
                case "#include":
                    include(line.substring(space));
                    break;
                case "#ifdef":
                    ifDef(line.substring(space));
                    break;

            }
        }
    }

    private void ifDef(String name) {
        name = removeComments(name);
        name = StringOperations.trimSpaces(name);
        boolean ignore = macroTable.checkIgnore(name);
    }

    private void include(String name) {
        int begin = name.indexOf("\"");
        boolean quote = false;
        int beg = name.indexOf("<");
        if(begin >= 0){
                quote = true;
                name = name.substring(begin+1);
                int end = name.indexOf("\"");
                if(end >= 0) name = name.substring(0, end);
            }else{
                name = name.substring(beg+1);
                int end = name.indexOf(">");
                if(end >= 0)name = name.substring(0, end);
            }
        boolean succes = false;
        if(quote){
            int i = filename.lastIndexOf("/");
            String newfile = filename.substring(0,i+1) + name;
            try{
                CodeAnalyzer incl = new CodeAnalyzer(newfile, this.macroTable);
                succes = true;
            }catch(Exception e){
                succes = false;
            }
        }
    }

    private void undefMacro(String name) {
        name = removeComments(name);
        name = StringOperations.trimSpaces(name);
        Macro m = macroTable.checkForMacro(name);
        if(m != null) {
            macroTable.removeMacro(m);
        }
    }

    public String removeComments(String code){
        if (code.length() == 0) return code;
        String result = code;
        if(comment){
            int commentEnd = StringOperations.checkBlockCommentEnd(code);
            if(commentEnd >= 0){
                comment = false;
                return code.substring(commentEnd+2);
            }
            return "";
        }
        int lineComment = StringOperations.checkLineComment(code);
        int blockComment = StringOperations.checkBlockComment(code);

        if(lineComment >=0){
            if(blockComment >= 0 && blockComment < lineComment){
                comment = true;
                return code.substring(0, blockComment) + removeComments(code.substring(blockComment));
            }
            code = code.substring(0, lineComment);
            return code;
        }
        if(blockComment >= 0){
            comment = true;
            return code.substring(0, blockComment) + removeComments(code.substring(blockComment));
        }
        return code;
    }


    private void defineMacro(String name) {
        name = removeComments(name);
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
            return code;
        }
        int lineComment = StringOperations.checkLineComment(code);
        if(lineComment >=0){
            code = code.substring(0, lineComment);
            return processCodeLine(code) + result.substring(lineComment);
        }
        int blockComment = StringOperations.checkBlockComment(code);
        if(blockComment >= 0){
            comment = true;
            return checkForStrings(code.substring(0, blockComment)) + processCodeLine(code.substring(blockComment));
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
                code = checkForReplacements(code);
                break;
            }
        }
        return code;
    }


    private String replaceFunctionMacro(String code, Macro m) {
        String name = m.getName();
        int index = code.indexOf(name);
        char prev = StringOperations.previousChar(code, index);
        char next = StringOperations.nextChar(code, index + name.length() -1);
        if(prev == ' ' || prev == '(' || prev == ','){
            if(next != '('){
                System.out.println("Fuction Macro without parenthesis");
                return code;
            }
            int parBeg = index + name.length();
            int parEnd = parBeg + StringOperations.closeParenthesis(code.substring(parBeg), 0);
            String parameter = code.substring(parBeg,parEnd);

            String expandedParameter = checkForReplacements(parameter);

            String[] param = expandedParameter.split(",");
            if(param.length != m.countArguments()){
               System.out.println("Parameter missmatch for "+name);
                return code;
            }
            String body = m.getBody(expandedParameter);
            code = StringOperations.replaceString(code,name,body);
        }
        return code;
    }

    private String replaceObjectMacro(String code, Macro m) {
        String name = m.getName();
        int index = code.indexOf(name);
        char prev = StringOperations.previousChar(code, index);
        char next = StringOperations.nextChar(code, index + name.length() -1);
        if(prev == ' ' || prev == '(' || prev == ','){
            if(next == ' ' || next == ')' || next == ','|| next == ';'){
                code = StringOperations.replaceString(code,name, m.getBody(""));
            }
        }
        return code;
    }

    public File getFile() {
        return this.file;
    }
}
