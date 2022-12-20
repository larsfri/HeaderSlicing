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
    void checkCommentBegin(){

    }
}