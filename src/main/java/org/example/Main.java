package org.example;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {

    public static void main(String[] args) {


        System.out.println("Hello world!");
        //String filename = "src/main/resources/SQLite/sqlite-src-3400100/src/alter.c";
        //String filename = "src/main/resources/test.h";
        //String newFile = "src/main/resources/test_processed.h";
        String filename = "src/main/resources/Parson/parson.c";
        String newFile = "src/main/resources/Parson/edit_parson.c";

        try{
            Scanner scanner = new Scanner(System.in);
            System.out.println("Process Directory(1) or File(2):");
            System.out.println("Enter 1/2 ");

            int type = scanner.nextInt();
            while(type != 1 && type != 2){
                type = scanner.nextInt();
            }
            scanner.nextLine();
            System.out.println("Enter the input path:");
            String inputPath = scanner.nextLine();
            System.out.println("Enter the Folder for the output");
            String outputPath = scanner.nextLine();
            if(type == 1){
                processDir(inputPath, outputPath);
            }
            if(type == 2){
                processFile(inputPath, outputPath);
            }

        }catch(Exception e){
            e.printStackTrace();
        }


        //CodeAnalyzer analyzer = new CodeAnalyzer(filename, null);
        //analyzer.saveDataToFile(newFile);

        //analyzer.saveDataToFile("src/main/resources/SQLite/sqlite-src-3400100/src/alter_edit.c");


/*
        SetUp systemPaths = new SetUp();
        ArrayList<String> paths = systemPaths.getPaths();
        for(String p:paths) {
            System.out.println(p);
          }

 */



    }

    private static void processFile(String inputPath, String outputPath) {
        outputPath = processOutputPath(inputPath, outputPath);
        CodeAnalyzer analyzer = new CodeAnalyzer(inputPath, null);
        analyzer.saveDataToFile(outputPath);
    }

    private static String processOutputPath(String inputPath, String outputPath) {
        int index = inputPath.lastIndexOf("/");
        String filename = inputPath.substring(index +1);
        outputPath = StringOperations.trimSpaces(outputPath);
        return outputPath + "/" + filename;
    }

    private static void processDir(String inputPath, String outputPath) {
        try {
            System.out.println("These files are processed: ");

            List<Path> paths = Files.walk(Paths.get(inputPath))
                    .filter(Files::isRegularFile)
                    .collect(Collectors.toList());

            for (Path path:
                 paths) {
                String s = path.toString();
                System.out.println(s);
                processFile(s, outputPath);
            }




        }catch (Exception e){
            e.printStackTrace();
        }

    }

}