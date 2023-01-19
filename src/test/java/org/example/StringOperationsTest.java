package org.example;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class StringOperationsTest {
    String lineWithString = "01234\"String\"bla";
    String lineEscapeString = "0123456\\\"9\"";
    String emptyLine = "";
    String notDefined = null;
    String doubleEscape = "0123\\\\67";
    String tripleEscape = "012\\\\\\67";
    String parenthesis = "()";
    String doubleParenthesis = "(())";
    String unclosedParenthesis = "((())";
    String comment = "//Comment";
    String blockComment = "/*Comment*/ code";

    @Test
    void checkSimpleString() {
        int index = StringOperations.checkString(lineWithString);
        assertEquals(5, index);
    }

    @Test
    void checkEmptyString() {
        int index = StringOperations.checkString(emptyLine);
        assertEquals(-1, index);
    }

    @Test
    void checkStringWithEscape() {
        int index = StringOperations.checkString(lineEscapeString);
        assertEquals(10, index);
    }

    @Test
    void singleEscape() {
        boolean esc = StringOperations.escapeChar(7, lineEscapeString);
        assertTrue(esc);
    }
    @Test
    void doubleEscape() {
        boolean esc = StringOperations.escapeChar(5, doubleEscape);
        assertFalse(esc);
    }
    @Test
    void tripleEscape() {
        boolean esc = StringOperations.escapeChar(5, tripleEscape);
        assertTrue(esc);
    }

    @Test
    void checkForSequence() {
        int result = StringOperations.checkForSequence(lineWithString, "Comment");
        assertEquals(6,6);
    }

    @Test
    void trimSpaces() {
        String line = "   bla";
        String result = StringOperations.trimSpaces(line);
        assertEquals("bla", result);
    }
    @Test
    void checkParenthesis(){
        int start = StringOperations.openParenthesis(parenthesis);
        int end = StringOperations.closeParenthesis(parenthesis.substring(start+1), 0);
        assertEquals(0, start);
        assertEquals(0, end);
    }

    @Test
    void checkDoubleParenthesis(){
        int start = StringOperations.openParenthesis(doubleParenthesis);
        int end = StringOperations.closeParenthesis(doubleParenthesis.substring(start+1), 0);
        assertEquals(0, start);
        assertEquals(2, end);
    }

    @Test
    void testCheckForSequence() {
        String s = "0123456";
        int index = StringOperations.checkForSequence(s, "456");
        assertEquals(4, index);
    }

    @Test
    void testTrimSpaces() {
        String s = "  0123";
        s = StringOperations.trimSpaces(s);
        assertEquals("0123", s);
        String b = "  ";
        b = StringOperations.trimSpaces(b);
        assertEquals("", b);
    }

    @Test
    void checkLineComment() {
        int index = StringOperations.checkLineComment(comment);
        assertEquals(0, index);
    }

    @Test
    void checkBlockComment() {
        int index = StringOperations.checkBlockComment(blockComment);
        assertEquals(0, index);
    }

    @Test
    void checkBlockCommentEnd() {
        int index = StringOperations.checkBlockCommentEnd(blockComment);
        assertEquals(9, index);
    }

    @Test
    void replaceString() {
        String s = "Test X * 3";
        s = StringOperations.replaceString(s, "X", "10");
        assertEquals("Test 10 * 3", s);
    }

    @Test
    void previousChar() {
        String s = "Test Test()";
        char a = StringOperations.previousChar(s, 0);
        char b = StringOperations.previousChar(s, 5);
        assertEquals(a,b);
    }

    @Test
    void nextChar() {
        String s = "Test Test()";
        char a = StringOperations.nextChar(s, 3);
        char b = StringOperations.nextChar(s, 8);
        assertEquals(' ', a);
        assertEquals('(',b);
    }
}