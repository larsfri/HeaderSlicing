package org.example;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class LogicExpression {
    private boolean value;
    private String path = "src/main/resources/logicEXPR.c";

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

    private void clearFile(File file) {
        file.clear();
        file.saveDataToFile(path);
    }

    private boolean evaluateFile() {
        String result = processFile();
        if (result.contains("1")) {
            return true;
        }
        return false;
    }

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


    public boolean getValue() {
        return value;
    }
}
