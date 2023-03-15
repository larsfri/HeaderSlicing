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
    private int expandedMacros;

    private int counterMacroExp;
    private int counterNotEmptyLines;
    private int counterRemovedLines;
    private int counterConditionals;


    public CodeAnalyzer(String filename, MacroTable macroTable) {
        if (macroTable == null) {
            this.macroTable = new MacroTable();
        } else {
            this.macroTable = macroTable;
        }
        macroTable = this.macroTable;
        includePaths = macroTable.getPaths();
        this.filename = filename;
        macroTable.setFilename(filename);
        file = new File(filename);
        line = file.getCurrentLine();
        type = checkType();
        openIfs = new ArrayList<Integer>();

        do {
            macroTable.setLine(file.getLineIndex());
            expandedMacros = 0;
            this.processLine();
        } while (this.nextLine());

    }

    public void printStats() {
        System.out.println("Lines not empty before processing:  " + counterNotEmptyLines);
        System.out.println("Lines removed during processing:  " + counterRemovedLines);
        System.out.println("Macros resolved:  " + counterMacroExp);
        System.out.println("Conditionals evaluated:  " + counterConditionals);
    }

    //gets next line returns true if line not null
    public boolean nextLine() {
        line = file.getNextLine();
        type = checkType();
        if (type == -1) return false;
        return true;
    }


    public void saveDataToFile(String path) {
        try {
            file.saveDataToFile(path);
            System.out.println("Saved to " + path);
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("Error while saving");
        }
    }

    public int processLine() {
        if (falseIf > -1) {
            checkEndIf();
            counterRemovedLines++;
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
                counterNotEmptyLines++;
                preprocessing();
                return 1;
            case 2:
                //check comment
                //find macros & replace them
                counterNotEmptyLines++;
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
            } else {
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
                    if (falseIf == openIfs.size()) {
                        checkElseIf(code);
                    }
                    break;
                case "else":
                    if (falseIf == openIfs.size()) {
                        falseIf = -1;
                    }
            }

        }


    }

    private void checkElseIf(String code) {
        code = removeComments(code);
        code = StringOperations.trimSpaces(code);

        int lastIf = openIfs.size() - 1;
        if (openIfs.get(lastIf) == 1) {
            falseIf = openIfs.size();
            return;
        }
        if (checkExclude(code)) {
            openIfs.remove(lastIf);
            openIfs.add(2);
        }
        if (checkIgnore(code)) {
            openIfs.remove(lastIf);
            openIfs.add(0);
        }
        if (checkTrue(code)) {
            openIfs.remove(lastIf);
            openIfs.add(1);
            falseIf = -1;
        } else {
            openIfs.remove(lastIf);
            openIfs.add(-1);
            falseIf = openIfs.size();
        }
    }

    private boolean checkExclude(String code) {
        code = removeComments(code);
        code = StringOperations.trimSpaces(code);
        return macroTable.checkExclude(code);
    }

    private boolean checkIgnore(String code) {
        code = removeComments(code);
        code = StringOperations.trimSpaces(code);
        return macroTable.checkIgnore(code);
    }

    private void endFalseIf() {
        if (openIfs.size() == 0) return;
        if (openIfs.size() == falseIf) {
            falseIf = -1;
        }
        openIfs.remove(openIfs.size() - 1);
    }

    private void preprocessing() {
        while (line.contains("\t")) {
            line = line.replace("\t", "  ");
        }
        String operator = line.substring(1);
        operator = StringOperations.trimSpaces(operator);
        int space = operator.indexOf(" ");
        String subLine = "";
        if (space != -1) {
            subLine = operator.substring(space);
            subLine = StringOperations.trimSpaces(subLine);
            operator = operator.substring(0, space);
        }
        int currentIf = 1;
        if (openIfs.size() > 0) {
            if (openIfs.contains(0)) {
                currentIf = 0;
            }
            if (openIfs.contains(2)) {
                currentIf = 2;
            }
        }
        switch (operator) {
            case "define":
                if (currentIf == 1) {
                    defineMacro(subLine);
                    counterRemovedLines++;
                    file.deleteCurrentLine();
                    file.reduceIndex();
                }
                if (currentIf == 2) {
                    addExclude(subLine, true);
                }
                break;
            case "undef":
                if (currentIf == 1) {
                    undefMacro(subLine);
                    counterRemovedLines++;
                    file.deleteCurrentLine();
                    file.reduceIndex();
                }
                if (currentIf == 2) {
                    addExclude(subLine, true);
                }
                break;
            case "include":
                if (currentIf == 1) {
                    include(subLine);
                }
                if (currentIf == 2) {
                    excludedInclude(subLine);
                }
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
                checkIf(subLine);
                break;
            case "endif":
                endIf();
                break;
            case "exclude":
                addExclude(subLine, true);
                break;
            case "ignore":
                addExclude(subLine, false);
                break;

            default:
                String processedLine = processCodeLine(line);
                file.changeCurrentLine(processedLine);
        }
    }


    private void addExclude(String name, boolean fullExclude) {
        name = removeComments(name);
        name = StringOperations.trimSpaces(name);
        int space = name.indexOf(" ");
        if (space > -1) {
            name = name.substring(0, space);
        }
        if (fullExclude) {
            macroTable.addExclude(name);
        } else {
            macroTable.addIgnore(name);
        }
    }

    private void endIf() {
        boolean check = false;
        if (openIfs.size() > 0) {
            int openIf = openIfs.get(openIfs.size() - 1);
            if (openIf == 0 || openIf == 2) check = true;
            openIfs.remove(openIfs.size() - 1);
        }
        if (!check) {
            counterRemovedLines++;
            file.deleteCurrentLine();
            file.reduceIndex();
        }
    }

    private void checkIf(String expression) {
        expression = removeComments(expression);
        expression = StringOperations.trimSpaces(expression);
        if (macroTable.checkLineExclude(expression)) {
            openIfs.add(2);
            return;
        }
        if (macroTable.checkLineIgnore(expression)) {
            openIfs.add(0);
            return;
        }
        boolean ifTrue = checkTrue(expression);
        if (ifTrue) {
            openIfs.add(1);
        } else {
            openIfs.add(-1);
            falseIf = openIfs.size();
        }
        counterConditionals++;
        counterRemovedLines++;
        file.deleteCurrentLine();
        file.reduceIndex();
    }

    private boolean checkTrue(String expression) {
        expression = replaceDefinedOperator(expression);
        expression = processCodeLine(expression);
        LogicExpression expr = new LogicExpression(expression);
        return expr.getValue();

    }

    private String replaceDefinedOperator(String expression) {
        boolean check = false;
        int length = 7;
        int index = expression.indexOf("defined");
        if (index >= 0) {
            index = index + 7;
            if (expression.length() > index) {

                String macro = expression.substring(index);
                length = length + macro.length();
                macro = StringOperations.trimSpaces(macro);
                length = length - macro.length();
                int space = macro.indexOf(" ");
                if (space >= 0) {
                    macro = macro.substring(0, space);
                }
                length = length + macro.length();
                if (macro.charAt(0) == '(') {
                    macro = macro.substring(1);
                    if (macro.charAt(macro.length() - 1) == ')') {
                        macro = macro.substring(0, macro.length() - 1);
                    }
                }
                Macro m = macroTable.checkForMacro(macro);
                if (m != null) check = true;
            }
            String begin = expression.substring(0, index - 7);
            String result = "0";
            if (check) result = "1";
            String end = "";
            if (expression.length() > (length + index - 7)) end = expression.substring(length + index - 7);
            expression = begin + result + end;
            expression = replaceDefinedOperator(expression);
        }

        return expression;
    }

    private void doElse() {

        int lastIf = 1;
        if (openIfs.size() > 0) {
            lastIf = openIfs.get(openIfs.size() - 1);
        }
        if (lastIf == 0 || lastIf == 2) {
            //Igonre else
        }
        if (lastIf == 1) {
            falseIf = openIfs.size();
            counterRemovedLines++;
            file.deleteCurrentLine();
            file.reduceIndex();
        }
    }

    private void ifNotDef(String name) {
        name = removeComments(name);
        name = StringOperations.trimSpaces(name);
        boolean ignore = macroTable.checkIgnore(name);
        boolean exclude = macroTable.checkExclude(name);
        if (exclude) {
            openIfs.add(2);
        } else if (ignore) {
            openIfs.add(0);
        } else {
            if (!checkDef(name)) {
                openIfs.add(1);
            } else {
                openIfs.add(-1);
                falseIf = openIfs.size();
            }
            counterConditionals++;
            counterRemovedLines++;
            file.deleteCurrentLine();
            file.reduceIndex();
        }
    }

    private void ifDef(String name) {
        name = removeComments(name);
        name = StringOperations.trimSpaces(name);
        boolean ignore = macroTable.checkIgnore(name);
        boolean exclude = macroTable.checkExclude(name);
        if (exclude) {
            openIfs.add(2);
        } else if (ignore) {
            openIfs.add(0);
        } else {
            if (checkDef(name)) {
                openIfs.add(1);
            } else {
                openIfs.add(-1);
                falseIf = openIfs.size();
            }
            counterConditionals++;
            counterRemovedLines++;
            file.deleteCurrentLine();
            file.reduceIndex();
        }
    }

    private boolean checkDef(String name) {
        Macro m = macroTable.checkForMacro(name);
        if (m == null) return false;
        return true;
    }

    private void excludedInclude(String subLine) {
        MacroTable table = new MacroTable();
        include(subLine, table);
        ArrayList<String> names = table.getAllMacroNames();
        for (String name :
                names) {
            this.macroTable.addExclude(name);
        }
    }

    private void include(String name) {
        include(name, this.macroTable);
    }

    private void include(String name, MacroTable table) {
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
                CodeAnalyzer incl = new CodeAnalyzer(newfile, table);
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
                    CodeAnalyzer incl = new CodeAnalyzer(newfile, table);
                    succes = true;
                } catch (Exception e) {
                    succes = false;
                }
            }
        }
        if (!succes) System.out.println("Include failed: " + name);
        macroTable.setFilename(filename);
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
        if (close == -1 || close + 1 > name.length()) {
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
            int blockEnd = StringOperations.checkBlockCommentEnd(code);
            if (blockEnd > blockComment) {
                comment = false;
                String check = code.substring(0, blockComment) + code.substring(blockEnd + 2);
                return checkForReplacements(check) + code.substring(blockComment, blockEnd + 2);
            }
            return checkForReplacements(code.substring(0, blockComment)) + processCodeLine(code.substring(blockComment));
        }
        return checkForReplacements(code);

    }


    private String checkForReplacements(String code) {
        if (expandedMacros > 25) return code;
        for (Macro m : macroTable.getMacros()) {

            if (!macroTable.checkExclude(m.getName()) &&
                    !macroTable.checkIgnore(m.getName()) &&
                    code.contains(m.getName())) {
                boolean inString = false;
                int index = code.indexOf(m.getName());
                int strBegin = StringOperations.checkString(code);
                while (strBegin != -1) {
                    int strEnd = strBegin + 1 + StringOperations.checkString(code.substring(strBegin + 1));
                    if (index > strBegin && index < strEnd) {
                        inString = true;
                        if (code.length() >= strEnd) {
                            code = code.substring(0, strEnd + 1) + checkForReplacements(code.substring(strEnd + 1));
                        }
                    }
                    int nextStr = StringOperations.checkString(code.substring(strEnd + 1));
                    if (nextStr != -1) {
                        strBegin = nextStr + 1 + strEnd;
                    } else {
                        strBegin = nextStr;
                    }

                }

                if (!inString) {
                    String oldCode = code;
                    if (m.countArguments() == -1) {
                        code = replaceObjectMacro(code, m);
                    } else {
                        code = replaceFunctionMacro(code, m);
                    }
                    if (!code.equals(oldCode)) {
                        counterMacroExp++;
                        code = checkForReplacements(code);
                    }
                }
            }

        }
        return code;
    }


    private String replaceFunctionMacro(String code, Macro m) {
        String name = m.getName();
        int index = code.indexOf(name);
        char prev = StringOperations.previousChar(code, index);
        char next = StringOperations.nextChar(code, index + name.length() - 1);
        if (prev == ' ' || prev == '(' || prev == ',' || prev == '{' || prev == '}' || prev == '=' || prev == '#') {
            boolean stringized = false;
            if (prev == '#') stringized = true;
            if (next != '(') {
                //System.out.println("Function Macro without parenthesis" + name);
                return code;
            }
            int parBeg = index + name.length();
            int end = StringOperations.closeParenthesis(code.substring(parBeg + 1), 0);
            if (end == -1) {
                return code;
            }
            int parEnd = parBeg + 1 + end;
            String parameter = code.substring(parBeg + 1, parEnd);
            String oldMacro = code.substring(index, parEnd + 1);
            if (stringized) oldMacro = code.substring(index - 1, parEnd + 1);

            String expandedParameter = checkForReplacements(parameter);
            if (stringized) expandedParameter = parameter;

            String[] param = expandedParameter.split(",");
            param = StringOperations.joinStrings(param);
            if (param.length != m.countArguments()) {
                System.out.println("Parameter missmatch for " + name);
                return code;
            }
            String body = m.getBody(expandedParameter);
            if (stringized) {
                body = "\"" + body + "\"";

            }
            code = StringOperations.replaceString(code, oldMacro, body);
        }
        return code;
    }

    private String replaceObjectMacro(String code, Macro m) {
        String name = m.getName();
        int index = code.indexOf(name);
        char prev = StringOperations.previousChar(code, index);
        char next = StringOperations.nextChar(code, index + name.length() - 1);
        if (prev == ' ' || prev == '(' || prev == ',' || prev == '{' || prev == '}' || prev == '=') {
            if (next == ' ' || next == ')' || next == ',' || next == ';' || next == '{' || next == '}' || next == '=') {
                code = StringOperations.replaceString(code, name, m.getBody(""));
            }
        }
        if (prev == '#') {
            if (next == ' ' || next == ')' || next == ',' || next == ';' || next == '{' || next == '}' || next == '=') {
                String stringizedBody = "\"" + m.getBody("") + "\"";
                String replace = code.substring(index - 1, index + name.length());
                code = StringOperations.replaceString(code, replace, stringizedBody);
            }
        }
        return code;
    }

    public File getFile() {
        return this.file;
    }

    public int getCounterMacroExp() {
        return counterMacroExp;
    }

    public int getCounterConditionals() {
        return counterConditionals;
    }

    public int getNotEmptyLines() {
        return counterNotEmptyLines;
    }

    public int getRemovedLines() {
        return counterRemovedLines;
    }
}
