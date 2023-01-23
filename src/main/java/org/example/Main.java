package org.example;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {


        System.out.println("Hello world!");
        //String filename = "src/main/resources/analyzer.h";
        String filename = "src/main/resources/SQLite/sqlite-src-3400100/src/alter.c";
        String newFile = "src/main/resources/SQLite/sqlite-src-3400100/src/alter_edit.c";


        CodeAnalyzer analyzer = new CodeAnalyzer(filename, null);
        analyzer.saveDataToFile(newFile);

        //analyzer.saveDataToFile("src/main/resources/analyzer_edit.h");



        SetUp systemPaths = new SetUp();
        ArrayList<String> paths = systemPaths.getPaths();
        for(String p:paths) {
            System.out.println(p);
          }



    }
}