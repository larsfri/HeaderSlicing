package org.example;

import java.nio.file.Files;
import  java.io.File;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {
    private static int counterMacroExp;
    private static int counterNotEmptyLines;
    private static int counterRemovedLines;
    private static int counterConditionals;

    public static int counterIncludes;

    public static int counterDefinedMacros;

    private static String inputDir;

    public static void main(String[] args) {
        counterIncludes = 0;
        if(args.length != 4){
            System.out.println("Error Systanx incorrect");
            System.out.println("Systax: .exc [-d dir| -f file] -o output");
        }


        /*
        try {
            Scanner scanner = new Scanner(System.in);
            System.out.println("Process Directory(1) or File(2):");
            System.out.println("Enter 1/2 ");

            int type = scanner.nextInt();
            while (type != 1 && type != 2) {
                type = scanner.nextInt();
            }
            scanner.nextLine();
            System.out.println("Enter the input path:");
            String inputPath = scanner.nextLine();
            System.out.println("Enter the Folder for the output");
            String outputPath = scanner.nextLine();
            if (type == 1) {
                processDir(inputPath, outputPath);
            }
            if (type == 2) {
                processFile(inputPath, outputPath);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
         */
        inputDir = args[1];
        makeOutputDir(args[1], args[3]);
        if(args[0].equals("-d")){
            processDir(args[1], args[3]);
        }
        if (args[0].equals("-f")){
            processFile(args[1], args[3]);
        }

        System.out.println("Total stats for processing: ");
        System.out.println("Lines not empty before processing:  " + counterNotEmptyLines);
        System.out.println("Lines removed during processing:  " + counterRemovedLines);
        System.out.println("Macros resolved:  " + counterMacroExp);
        System.out.println("Conditionals evaluated:  " + counterConditionals);
        System.out.println("Included files:" + counterIncludes);
        System.out.println("Defined Macros: "+counterDefinedMacros);

    }



    private static void processFile(String inputPath, String outputPath) {
        outputPath = processOutputPath(inputPath, outputPath);
        long start = System.currentTimeMillis();
        CodeAnalyzer analyzer = new CodeAnalyzer(inputPath, null);
        analyzer.saveDataToFile(outputPath);
        long end = System.currentTimeMillis();
        analyzer.printStats();
        counterMacroExp += analyzer.getCounterMacroExp();
        counterConditionals += analyzer.getCounterConditionals();
        counterNotEmptyLines += analyzer.getNotEmptyLines();
        counterRemovedLines += analyzer.getRemovedLines();
        counterDefinedMacros += analyzer.getDefinedMacros();
        long duration = end - start;
        System.out.println("File took: " + duration + " ms to process.");
    }

    private static String processOutputPath(String inputPath, String outputPath) {

        String filename = inputPath.replace(inputDir, "");
        outputPath = StringOperations.trimSpaces(outputPath);
        return outputPath + filename;
    }

    private static void processDir(String inputPath, String outputPath) {
        try {
            System.out.println("These files are processed: ");

            List<Path> paths = Files.walk(Paths.get(inputPath))
                    .filter(Files::isRegularFile)
                    .collect(Collectors.toList());

            long start = System.currentTimeMillis();
            for (Path path :
                    paths) {
                String s = path.toString();
                if (s.endsWith(".h") || s.endsWith(".c") || s.endsWith(".cpp") || s.endsWith(".hpp")) {
                    System.out.println(s);
                    processFile(s, outputPath);
                }
            }
            long duration = System.currentTimeMillis() - start;
            System.out.println("Total time: " + duration + " ms");


        } catch (Exception e) {
            e.printStackTrace();
        }

    }
    private static void makeOutputDir(String inputPath, String outputPath) {

        try {
            File[] directories = new File(inputPath).listFiles(File::isDirectory);
            for (File f:
                 directories) {
                String path = f.getAbsolutePath();
                makeOutputDir(path, outputPath);
                path = path.replace(inputDir, "");
                path = outputPath +path;
                Files.createDirectories(Paths.get(path));
            }
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }
}