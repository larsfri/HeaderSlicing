package org.example;

public class StringOperations {

    //Checks for " and returns index
    public static int checkString(String line){
        if(line == null) return -1;
        int index = line.indexOf("\"");
        if(index > 0){
            if(escapeChar(index -1, line)){
                int substring = checkString(line.substring(index+1));
                if(substring >= 0){
                    index = index + substring + 1;
                }else{
                    index = -1;
                }
            }
        }
        return index;
    }

    //Checks for valid escape in line at index
    public static boolean escapeChar(int index, String line){
        if(index < 0) return false;
        if(line.charAt(index) == '\\'){
            if(escapeChar(index -1, line)){
                return false;
            }
            return true;
        }
        return false;
    }

    //Checks if line contains sequence outside of strings, returns int of starting char
    public static int checkForSequence(String line, String sequence){
        int indexLine = line.indexOf(sequence);
        if(indexLine == -1) return -1;
        int stringBegin = checkString(line);
        if(stringBegin >= 0){
            int stringEnd = checkString(line.substring(stringBegin +1));
            if(stringBegin < indexLine && stringEnd > indexLine){
                indexLine = checkForSequence(line.substring(stringEnd +1), sequence);
                if(indexLine >= 0){
                    return indexLine +stringEnd + 1;
                }
            }
        }
        return indexLine;
    }


    //Removes spaces at beginning
    public static String trimSpaces(String line) {
        if(line == null)return null;
        if(line.length() == 0) return line;
        while(line.charAt(0) == ' '){
            line = line.substring(1);
            if(line.equals(""))return line;
        }
        return line;
    }
    //returns index of first opening parenthesis if occurs
    public static int openParenthesis(String line){
        if(line == null)return -1;
        return checkForSequence(line, "(");
    }

    //returns first closing parenthesis without opening, called with substring from opening
    public static int closeParenthesis(String line, int counter){
        if(line == null) return -1;
        int index = checkForSequence(line, ")");
        int check = openParenthesis(line);
        if(check < index && check != -1){
            counter++;
            int nextIndex = closeParenthesis(line.substring(check+1), counter);
            if(nextIndex == -1) return -1;
            return check + 1 + nextIndex;
        }
        if(counter > 0){
            counter --;
            int nextIndex = closeParenthesis(line.substring(index+1), counter);
            if(nextIndex == -1) return -1;
            return index + 1 + nextIndex;
        }
        return index;
    }

    public static int checkLineComment(String line){
        if(line == null) return -1;
        return checkForSequence(line, "//");
    }

    public static int checkBlockComment(String line) {
        if(line == null) return -1;
        return checkForSequence(line, "/*");
    }
    public static int checkBlockCommentEnd(String line) {
        if(line == null) return -1;
        return checkForSequence(line, "*/");
    }
    //replace
    public static String replaceString(String line, String toReplace, String replacement){
        if(line == null || toReplace == null || replacement == null) return line;
        if(line.equals("") || toReplace.equals("")) return line;
        int index = checkForSequence(line, toReplace);
        if(index < 0) return line;
        return line.substring(0, index) + replacement + replaceString(line.substring(index + toReplace.length()), toReplace, replacement);
    }

    //retruns previous char, or ' ' if theres no previous char
    public static char previousChar(String line, int index){
        index --;
        if(index >= 0 && index < line.length()){
            return line.charAt(index);
        }
        return ' ';
    }

    //retruns next char, or ' ' if theres no further char
    public static char nextChar(String line, int index){
        index ++;
        if(index >= 0 && index < line.length()){
            return line.charAt(index);
        }
        return ' ';
    }

}
