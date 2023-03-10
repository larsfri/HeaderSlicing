package org.example;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LogicExpressionTest {

    @Test
    void getValueFalse() {
        LogicExpression expr = new LogicExpression("1 * 0");
        assertFalse(expr.getValue());
    }
    @Test
    void getValueTrue() {
        LogicExpression expr = new LogicExpression("1 || 0");
        assertTrue(expr.getValue());
    }
}