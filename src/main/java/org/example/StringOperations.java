package org.example;

/**
 * This class provides operations for handling of strings.
 * This helper class provides various functions for working with strings.
 * This includes functions to search for a specific character, but as well operations
 * to modify a string, e.g. to trim white spaces or search and replace text.
 */
public class StringOperations {

    /**
     * Checks for \" and returns index
     * @param line The line to parse for \".
     * @return Index of first \" in string, or -1 for none.
     */
    public static int checkString(String line) {
        if (line == null) return -1;
        int index = line.indexOf("\"");
        if (index > 0) {
            if (escapeChar(index - 1, line)) {
                // If \" is escaped, continue search recursively
                int substring = checkString(line.substring(index + 1));
                if (substring >= 0) {
                    index = index + substring + 1;
                } else {
                    index = -1;
                }
            }
        }
        return index;
    }

    /**
     * Checks for valid escape character in line at given index.
     * @param index Position in line to check for escape character.
     * @param line Line to use for check.
     * @return True if valid escape character as position index, false otherwise.
     */
    public static boolean escapeChar(int index, String line) {
        if (index < 0) return false;
        if (line.charAt(index) == '\\') {
            // confirm that backslash is not escaped itself
            if (escapeChar(index - 1, line)) {
                return false;
            }
            return true;
        }
        return false;
    }

    /**
     * Checks if line contains a given sequence (outside of a string).
     * @param line Line to use for check.
     * @param sequence Sequence to check for.
     * @return Index of sequence within string, or -1 for none.
     */
    public static int checkForSequence(String line, String sequence) {
        int indexLine = line.indexOf(sequence);
        if (indexLine == -1) return -1;

        // sequence found; now confirm that it is not within a string
        int stringBegin = checkString(line);
        if (stringBegin >= 0) {
            int stringEnd = checkString(line.substring(stringBegin + 1));
            if (stringBegin < indexLine && stringEnd > indexLine) {
                indexLine = checkForSequence(line.substring(stringEnd + 1), sequence);
                if (indexLine >= 0) {
                    return indexLine + stringEnd + 1;
                }
            }
        }
        return indexLine;
    }

    /**
     * Remove spaces at beginning of a line.
     * @param line Line to trim for leading space.
     * @return Line without leading spaces.
     */
    public static String trimSpaces(String line) {
        if (line == null) return null;
        if (line.length() == 0) return line;
        while (line.charAt(0) == ' ') {
            line = line.substring(1);
            if (line.equals("")) return line;
        }
        while (line.charAt(line.length() - 1) == ' ') {
            line = line.substring(0, line.length() - 1);
            if (line.equals("")) return line;
        }
        return line;
    }

    /**
     * Returns index of first opening parenthesis, if any.
     * @param line Line to search for opening parenthesis.
     * @return Index of first opening parenthesis, or -1 for none.
     */
    public static int openParenthesis(String line) {
        if (line == null) return -1;
        return checkForSequence(line, "(");
    }

    /**
     * Returns index of first closing parenthesis without opening parenthesis.
     * Is called recursively with a smaller substring.
     * @param line Line to search for closing parenthesis.
     * @param counter Counter for pairs of opening and closing parenthesis.
     * @return Index of first unmatched closing parenthesis, or -1 for none.
     */
    public static int closeParenthesis(String line, int counter) {
        if (line == null) return -1;
        int index = checkForSequence(line, ")");
        int check = openParenthesis(line);
        if (check < index && check != -1) {
            counter++;
            int nextIndex = closeParenthesis(line.substring(check + 1), counter);
            if (nextIndex == -1) return -1;
            return check + 1 + nextIndex;
        }
        if (counter > 0) {
            counter--;
            int nextIndex = closeParenthesis(line.substring(index + 1), counter);
            if (nextIndex == -1) return -1;
            return index + 1 + nextIndex;
        }
        return index;
    }

    /**
     * Checks a line for first index of line comment (starting with \"//\").
     * @param line Line to check for comment.
     * @return Index of first comment, or -1 for none.
     */
    public static int checkLineComment(String line) {
        if (line == null) return -1;
        return checkForSequence(line, "//");
    }

    /**
     * Checks a line for first index of block comment (starting with \"/*\").
     * @param line Line to check for comment.
     * @return Index of first comment, or -1 for none.
     */
    public static int checkBlockComment(String line) {
        if (line == null) return -1;
        return checkForSequence(line, "/*");
    }

    /**
     * Checks a line for first index of end of block comment (ending with \"* /\").
     * @param line Line to check for comment.
     * @return Index of first end of comment, or -1 for none.
     */
    public static int checkBlockCommentEnd(String line) {
        if (line == null) return -1;
        return checkForSequence(line, "*/");
    }

    /**
     * Brief Replace a search string by a replacement string (if found).
     * @param line Line to use for search and replace.
     * @param toReplace Test to replace.
     * @param replacement Replacement text.
     * @return Modified line with search string replaced.
     */
    public static String replaceString(String line, String toReplace, String replacement) {
        if (line == null || toReplace == null || replacement == null) return line;
        if (line.equals("") || toReplace.equals("")) return line;
        int index = checkForSequence(line, toReplace);
        if (index < 0) return line;
        return line.substring(0, index) + replacement + line.substring(index + toReplace.length());
    }

    /**
     * Returns character before index, or ' ' of there is no previous character.
     * @param line Line to use to retrieve character from.
     * @param index Index to look for (i.e. return the character before this index).
     * @return The character before the given index, or ' '.
     */
    public static char previousChar(String line, int index) {
        index--;
        if (index >= 0 && index < line.length()) {
            return line.charAt(index);
        }
        return ' ';
    }

    /**
     * Returns character following given index, or ' ' of there is no following character.
     * @param line Line to use to retrieve character from.
     * @param index Index to look for (i.e. return the character after this index).
     * @return The character after the given index, or ' '.
     */
    public static char nextChar(String line, int index) {
        index++;
        if (index >= 0 && index < line.length()) {
            return line.charAt(index);
        }
        return ' ';
    }

    /**
     * Do someting.
     * @param param Array of strings.
     * @return
     */
    public static String[] joinStrings(String[] param) {
        String[] result;
        for (int i = 0; i < param.length - 1; i++) {
            int index = StringOperations.checkString(param[i]);
            if (index >= 0) {
                if (StringOperations.checkString(param[i].substring(index + 1)) == -1) {
                    result = new String[param.length - 1];
                    result[i] = param[i] + "," + param[i + 1];
                    for (int j = 0; j < result.length; j++) {
                        if (j < i) {
                            result[j] = param[j];
                        }
                        if (j > i) {
                            result[j] = param[j + 1];
                        }
                    }
                    return joinStrings(result);
                }
            }
        }
        return param;
    }
}
