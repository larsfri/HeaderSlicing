package org.example;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class StringOperationsTest {
    String lineWithComment = "01234\"Comment\"bla";
    String lineEscapeComment = "0123456\\\"9\"";
    String emptyLine = "";
    String notDefined = null;
    String doubleEscape = "0123\\\\67";
    String tripleEscape = "012\\\\\\67";
    String parenthesis = "()";
    String doubleParenthesis = "(())";
    String unclosedParenthesis = "((())";

    @Test
    void checkSimpleString() {
        int index = StringOperations.checkString(lineWithComment);
        assertEquals(5, index);
    }

    @Test
    void checkEmptyString() {
        int index = StringOperations.checkString(emptyLine);
        assertEquals(-1, index);
    }

    @Test
    void checkStringWithEscape() {
        int index = StringOperations.checkString(lineEscapeComment);
        assertEquals(10, index);
    }

    @Test
    void singleEscape() {
        boolean esc = StringOperations.escapeChar(7, lineEscapeComment);
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
        //ToDo
    }

    @Test
    void trimSpaces() {
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
}