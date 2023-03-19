package org.example;

import java.nio.file.Files;
import  java.io.File;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 * This is the Main function of the Java program.
 * The program collects some statistics about the processed code.
 */
public class Main {
    /** Number of Macro expressions replaced. */
    private static int counterMacroExp;
    /** Number of processed lines that were not empty. */
    private static int counterNotEmptyLines;
    /** Number of lines removed. */
    private static int counterRemovedLines;
    /** Number of conditional expressions evaluated. */
    private static int counterConditionals;
    /** Number of include statements processed. */
    public static int counterIncludes;
    /** Number of macros defined. */
    public static int counterDefinedMacros;
    /** Top-level input directory in case a complete directory is processed. */
    private static String inputDir;

    /** 
     * Main function of Java program.
     * @param args Command-line arguments provided to the program.
     */
    public static void main(String[] args) {
        counterIncludes = 0;
        if (args.length != 4) {
            System.out.println("Error Systanx incorrect");
            System.out.println("Systax: .exc [-d dir| -f file] -o output");
        }

        inputDir = args[1];
        makeOutputDir(args[1], args[3]);
        if (args[0].equals("-d")) {
            processDir(args[1], args[3]);
        }
        if (args[0].equals("-f")) {
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

    /**
     * Process a single file.
     * @param inputPath File to process.
     * @param outputPath Folder into which to write the output file.
     */
    private static void processFile(String inputPath, String outputPath) {
        outputPath = processOutputPath(inputPath, outputPath);
        long start = System.currentTimeMillis();
        CodeAnalyzer analyzer = new CodeAnalyzer(inputPath, null);
        analyzer.saveDataToFile(outputPath);
        long end = System.currentTimeMillis();

        // Print statistics for a single file.
        analyzer.printStats();

        // Add statistics of this file to the totals.
        counterMacroExp += analyzer.getCounterMacroExp();
        counterConditionals += analyzer.getCounterConditionals();
        counterNotEmptyLines += analyzer.getNotEmptyLines();
        counterRemovedLines += analyzer.getRemovedLines();
        counterDefinedMacros += analyzer.getDefinedMacros();

        // Report the processing time on the console.
        long duration = end - start;
        System.out.println("File took: " + duration + " ms to process.");
    }

    /**
     * Derive the output file name from the input file name and output path.
     * @param inputPath File to process.
     * @param outputPath Folder into which to write the output file.
     * @return File name of output file, which includes output path and file name from input path.
     */
    private static String processOutputPath(String inputPath, String outputPath) {

        String filename = inputPath.replace(inputDir, "");
        outputPath = StringOperations.trimSpaces(outputPath);
        return outputPath + filename;
    }

    /**
     * Process all files and folders in a directory recursively.
     * The operation only considers files with extensions *.h and *.c.
     * @param inputPath Folder to be processed searching for input files.
     * @param outputPath Folder into which to write the output files.
     * @return
     */
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

    /**
     * Create output directory structure using input Path and output Path.
     * @param inputPath Input directory to process recursively.
     * @param outputPath Outpput directory to use for generated files.
     */
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
