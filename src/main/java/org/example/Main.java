package org.example;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        /*

        System.out.println("Hello world!");
        String filename = "src/main/resources/analyzer.h";
        CodeAnalyzer analyzer = new CodeAnalyzer(filename, null);

        analyzer.saveDataToFile("src/main/resources/analyzer_edit.h");
         */

        SetUp systemPaths = new SetUp();
        ArrayList<String> paths = systemPaths.getPaths();
        for(String p:paths) {
            System.out.println(p);
        }


    }
}