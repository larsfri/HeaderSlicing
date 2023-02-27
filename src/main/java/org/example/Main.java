package org.example;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {


        System.out.println("Hello world!");
        //String filename = "src/main/resources/SQLite/sqlite-src-3400100/src/alter.c";
        //String filename = "src/main/resources/test.h";
        //String newFile = "src/main/resources/test_processed.h";
        String filename = "src/main/resources/Parson/parson.c";
        String newFile = "src/main/resources/Parson/edit_parson.c";


        CodeAnalyzer analyzer = new CodeAnalyzer(filename, null);
        analyzer.saveDataToFile(newFile);

        //analyzer.saveDataToFile("src/main/resources/SQLite/sqlite-src-3400100/src/alter_edit.c");


/*
        SetUp systemPaths = new SetUp();
        ArrayList<String> paths = systemPaths.getPaths();
        for(String p:paths) {
            System.out.println(p);
          }

 */



    }
}