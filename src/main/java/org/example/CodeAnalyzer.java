package org.example;

import java.util.ArrayList;

public class CodeAnalyzer {

    private File file;
    private String filename;
    private String line;
    private int type;
    private boolean comment;
    private MacroTable macroTable;

    private ArrayList<String> includePaths;
    private ArrayList<Integer> openIfs;
    private int falseIf = -1;


    public CodeAnalyzer(String filename, MacroTable macroTable) {
        if (macroTable == null) {
            this.macroTable = new MacroTable();
        } else {
            this.macroTable = macroTable;
        }
        SetUp setup = new SetUp();
        includePaths = setup.getPaths();
        this.filename = filename;
        file = new File(filename);
        line = file.getCurrentLine();
        type = checkType();
        openIfs = new ArrayList<Integer>();

        do {
            this.processLine();
        } while (this.nextLine());

    }

    //gets next line returns true if line not null
    public boolean nextLine() {
        line = file.getNextLine();
        type = checkType();
        if (type == -1) return false;
        return true;
    }

    public int getLineIndex() {
        return file.getLineIndex();
    }

    public boolean saveDataToFile(String path) {
        try {
            file.saveDataToFile(path);
            System.out.println("Saved to " + path);
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("Error while saving");
            return false;
        }
    }

    public int processLine() {
        if (falseIf > -1) {
            checkEndIf();
            file.deleteCurrentLine();
            file.reduceIndex();
            return 0;
        }
        switch (type) {
            case -1:
                return -1;
            case 0:
                return 0;
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

    private void checkEndIf() {
        String code = StringOperations.trimSpaces(line);
        if (code.equals("")) return;
        if (code.charAt(0) == '#') {
            code = code.substring(1);
            code = StringOperations.trimSpaces(code);
            int space = code.indexOf(" ");
            String operator = code;
            if (space >= 0) {
                operator = code.substring(0, space);
                code = code.substring(space);
            }else {
                code = "";
            }
                switch (operator) {
                    case "endif":
                        endFalseIf();
                        break;
                    case "if":
                    case "ifdef":
                    case "ifndef":
                        openIfs.add(-1);
                        break;
                    case "elif":
                        checkElseIf(code);
                        break;
                    case "else":
                        falseIf = -1;
                }

        }


    }

    private void checkElseIf(String code) {
        int lastIf = openIfs.size() - 1;
        if (openIfs.get(lastIf) == 1) {
            falseIf = openIfs.size();
            return;
        }
        if (checkIgnore(code)) {
            openIfs.remove(lastIf);
            openIfs.add(0);
        }
        if (checkTrue(code)) {
            openIfs.remove(lastIf);
            openIfs.add(1);
        } else {
            openIfs.remove(lastIf);
            openIfs.add(-1);
            falseIf = openIfs.size();
        }
    }

    private boolean checkTrue(String code) {
        return false;
        //ToDo
    }

    private boolean checkIgnore(String code) {
        return false;
        //Todo
    }

    private void endFalseIf() {
        if (openIfs.size() == falseIf) {
            falseIf = -1;
        }
        openIfs.remove(openIfs.size() - 1);
    }

    private void preprocessing() {
        String operator = line.substring(1);
        operator = StringOperations.trimSpaces(operator);
        int space = operator.indexOf(" ");
        String subLine;
        if (space != -1) {
            subLine = operator.substring(space);
            subLine = StringOperations.trimSpaces(subLine);
            operator = operator.substring(0, space);
        } else {
            subLine = "";
        }

        switch (operator) {
            case "define":
                defineMacro(subLine);
                file.deleteCurrentLine();
                file.reduceIndex();
                break;
            case "undef":
                undefMacro(subLine);
                file.deleteCurrentLine();
                file.reduceIndex();
                break;
            case "include":
                include(subLine);
                break;
            case "ifdef":
                ifDef(subLine);
                break;
            case "ifndef":
                ifNotDef(subLine);
                break;
            case "elif":
                checkElseIf(subLine);
                break;
            case "else":
                doElse();
                break;
            case "if":
                openIfs.add(1);
                //ToDo
                break;
            case "endif":
                if(openIfs.size()>0) {
                    openIfs.remove(openIfs.size() - 1);
                }
                file.deleteCurrentLine();
                file.reduceIndex();
                break;

        }
    }

    private void doElse() {
        int lastIf = openIfs.get(openIfs.size() - 1);
        if (lastIf == 0) {
            //Igonre else
        }
        if (lastIf == 1) {
            falseIf = -1;
            file.deleteCurrentLine();
            file.reduceIndex();
        }
    }

    private void ifNotDef(String name) {
        name = removeComments(name);
        name = StringOperations.trimSpaces(name);
        boolean ignore = macroTable.checkIgnore(name);
        if (ignore) {
            openIfs.add(0);
        } else {
            if (!checkDef(name)) {
                openIfs.add(1);
            } else {
                openIfs.add(-1);
                falseIf = openIfs.size();
            }
            file.deleteCurrentLine();
            file.reduceIndex();
        }
    }

    private void ifDef(String name) {
        name = removeComments(name);
        name = StringOperations.trimSpaces(name);
        boolean ignore = macroTable.checkIgnore(name);
        if (ignore) {
            openIfs.add(0);
        } else {
            if (checkDef(name)) {
                openIfs.add(1);
            } else {
                openIfs.add(-1);
                falseIf = openIfs.size();
            }
            file.deleteCurrentLine();
            file.reduceIndex();
        }
    }

    private boolean checkDef(String name) {
        Macro m = macroTable.checkForMacro(name);
        if (m == null) {
            return false;
        }
        return true;
    }

    private void include(String name) {
        if(name.contains("features.h")){
            System.out.println("here");
        }
        int begin = name.indexOf("\"");
        boolean quote = false;
        int beg = name.indexOf("<");
        if (begin == -1 && beg == -1) {
            return;
        }
        if (begin >= 0) {
            quote = true;
            name = name.substring(begin + 1);
            int end = name.indexOf("\"");
            if (end >= 0) name = name.substring(0, end);
        } else {
            name = name.substring(beg + 1);
            int end = name.indexOf(">");
            if (end >= 0) name = name.substring(0, end);
        }
        boolean succes = false;
        if (quote) {
            int i = filename.lastIndexOf("/");
            String newfile = filename.substring(0, i + 1) + name;
            try {
                CodeAnalyzer incl = new CodeAnalyzer(newfile, this.macroTable);
                succes = true;
            } catch (Exception e) {
                succes = false;
            }
        }
        for (String searchPath : includePaths) {
            if (!succes) {
                searchPath = StringOperations.trimSpaces(searchPath);
                String newfile = searchPath + "/" + name;
                try {
                    CodeAnalyzer incl = new CodeAnalyzer(newfile, this.macroTable);
                    succes = true;
                } catch (Exception e) {
                    succes = false;
                }
            }
        }
        if (!succes) System.out.println("Include failed: " + name);
    }

    private void undefMacro(String name) {
        name = removeComments(name);
        name = StringOperations.trimSpaces(name);
        Macro m = macroTable.checkForMacro(name);
        if (m != null) {
            macroTable.removeMacro(m);
        }
    }

    public String removeComments(String code) {
        if (code.length() == 0) return code;
        String result = code;
        if (comment) {
            int commentEnd = StringOperations.checkBlockCommentEnd(code);
            if (commentEnd >= 0) {
                comment = false;
                return code.substring(commentEnd + 2);
            }
            return "";
        }
        int lineComment = StringOperations.checkLineComment(code);
        int blockComment = StringOperations.checkBlockComment(code);

        if (lineComment >= 0) {
            if (blockComment >= 0 && blockComment < lineComment) {
                comment = true;
                return code.substring(0, blockComment) + removeComments(code.substring(blockComment));
            }
            code = code.substring(0, lineComment);
            return code;
        }
        if (blockComment >= 0) {
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
        if (space == -1) {
            macroTable.addObjectMacro(macro, body);
        } else {
            macro = name.substring(0, space);
            body = name.substring(space);
            body = StringOperations.trimSpaces(body);
            if (macro.indexOf("(") == -1) {
                macroTable.addObjectMacro(macro, body);
            } else {
                defineFunctionMacro(name);
            }
        }

    }

    private void defineFunctionMacro(String name) {
        int open = StringOperations.openParenthesis((name));
        int close = open + 1 + StringOperations.closeParenthesis(name.substring(open + 1), 0);
        if (close == -1 || close + 2 > name.length()) {
            System.out.println("Unexpected macro declaration, ERROR");
        } else {
            String parameter = name.substring(open + 1, close);
            String body = name.substring(close + 1);
            body = StringOperations.trimSpaces(body);
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

        if (line == null) return -1;
        if (line.equals("")) return 0;
        if (line.charAt(0) == '#') return 1;
        if (StringOperations.trimSpaces(line).equals("")) return 0;

        return 2;
    }

    public String processCodeLine(String code) {
        if (code.length() == 0) return code;
        String result = code;
        if (comment) {
            int commentEnd = StringOperations.checkBlockCommentEnd(code);
            if (commentEnd >= 0) {
                comment = false;
                return result.substring(0, commentEnd + 2) + processCodeLine(code.substring(commentEnd + 2));
            }
            return code;
        }
        int lineComment = StringOperations.checkLineComment(code);
        if (lineComment >= 0) {
            code = code.substring(0, lineComment);
            return processCodeLine(code) + result.substring(lineComment);
        }
        int blockComment = StringOperations.checkBlockComment(code);
        if (blockComment >= 0) {
            comment = true;
            return checkForStrings(code.substring(0, blockComment)) + processCodeLine(code.substring(blockComment));
        }
        return checkForStrings(code);

    }

    private String checkForStrings(String code) {
        int index = StringOperations.checkString(code);
        if (index == -1) return checkForReplacements(code);
        int end = index + 1 + StringOperations.checkString(code.substring(index + 1));

        return checkForReplacements(code.substring(0, index)) + code.substring(index, end + 1) + checkForStrings(code.substring(end + 1));

    }

    private String checkForReplacements(String code) {
        for (Macro m : macroTable.getMacros()) {
            if (code.contains(m.getName())) {
                String oldCode = code;
                if (m.countArguments() == -1) {
                    code = replaceObjectMacro(code, m);
                } else {
                    code = replaceFunctionMacro(code, m);
                }
                if (!code.equals(oldCode)) code = checkForReplacements(code);

                break;
            }
        }
        return code;
    }


    private String replaceFunctionMacro(String code, Macro m) {
        String name = m.getName();
        int index = code.indexOf(name);
        char prev = StringOperations.previousChar(code, index);
        char next = StringOperations.nextChar(code, index + name.length() - 1);
        if (prev == ' ' || prev == '(' || prev == ',' || prev == '{' || prev == '}') {
            if (next != '(') {
                System.out.println("Fuction Macro without parenthesis");
                return code;
            }
            int parBeg = index + name.length();
            int parEnd = parBeg + 1 + StringOperations.closeParenthesis(code.substring(parBeg +1), 0);
            String parameter = code.substring(parBeg +1, parEnd);
            String oldMacro = code.substring(index, parEnd+1);

            String expandedParameter = checkForReplacements(parameter);

            String[] param = expandedParameter.split(",");
            if (param.length != m.countArguments()) {
                System.out.println("Parameter missmatch for " + name);
                return code;
            }
            String body = m.getBody(expandedParameter);
            code = StringOperations.replaceString(code, oldMacro, body);
        }
        return code;
    }

    private String replaceObjectMacro(String code, Macro m) {
        String name = m.getName();
        int index = code.indexOf(name);
        char prev = StringOperations.previousChar(code, index);
        char next = StringOperations.nextChar(code, index + name.length() - 1);
        if (prev == ' ' || prev == '(' || prev == ',' || prev == '{' || prev == '}') {
            if (next == ' ' || next == ')' || next == ',' || next == ';' || next == '{' || next == '}') {
                code = StringOperations.replaceString(code, name, m.getBody(""));
            }
        }
        return code;
    }

    public File getFile() {
        return this.file;
    }
}
