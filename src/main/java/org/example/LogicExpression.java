package org.example;

import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * This class evaluates a Logic Expression using GCC.
 * Conditionals of the preprocessor can be very complex.
 * To ensure that they are evaluated exactly the way they will be treated by GCC,
 * all macros are placed by values, and then GCC is used to evaluate the expression 
 */
public class LogicExpression {
    /** Boolean value whether the expression evaluates to true or false. */
    private boolean value;
    /** File to generate with expression to be compiled by GCC. */
    private String path = "src/main/resources/logicEXPR.c";

    /**
     * Constructor for a given expression.
     * @param expression Expression to evaluate.
     */
    public LogicExpression(String expression) {
        File file = new File();
        String line1 = "#if " + expression;
        file.addLine(line1);
        file.addLine("1");
        file.addLine("#else");
        file.addLine("0");
        file.addLine("#endif");
        file.saveDataToFile(path);
        value = evaluateFile();
        clearFile(file);

    }

    /**
     * Clear the existing file, and save the new expression to file.
     * @param file File to clear and use for new expression.
     */
    private void clearFile(File file) {
        file.clear();
        file.saveDataToFile(path);
    }

    /**
     * Evaluate the content of the file.
     * @return True if expression in file evaluates to 1, false otherwise.
     */
    private boolean evaluateFile() {
        String result = processFile();
        if (result.contains("1")) {
            return true;
        }
        return false;
    }

    /**
     * Process the file with the expression using GCC.
     * @return Output of GCC for the expression in the file.
     */
    private String processFile() {
        try {
            Process process = Runtime.getRuntime().exec("gcc -E " + path);
            String result = "0";
            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            String s;
            while ((s = reader.readLine()) != null) {
                result = s;
            }
            process.destroy();
            return result;

        } catch (Exception e) {
            e.printStackTrace();
        }
        return "0";
    }

    /**
     * Return the value of the expression.
     * @return True or false, depending on the evaluation of the expression by GCC.
     */
    public boolean getValue() {
        return value;
    }
}
