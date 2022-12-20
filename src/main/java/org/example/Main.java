package org.example;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {

        System.out.println("Hello world!");
        String filename = "src/main/resources/analyzer.h";
        CodeAnalyzer analyzer = new CodeAnalyzer(filename, null);
        analyzer.getLineIndex();




    }
}