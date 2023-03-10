package org.example;

import org.junit.jupiter.api.Test;

import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;

import static org.junit.jupiter.api.Assertions.*;

class CodeAnalyzerTest {

    /*
    All tests run with config.txt set to:
    #exclude EXC
    #ignore IGN
    #define DEF
     */

    @Test
    public void runDefineOBJ(){
        CodeAnalyzer analyzer = new CodeAnalyzer("src/test/java/TestData/defineOBJ.c",null);
        String output = "src/test/java/TestData/Output/defineOBJ.c";
        analyzer.saveDataToFile(output);
        String out = "failed";
        String expected = "";
        try {
            out = new String(Files.readAllBytes(Paths.get(output)), StandardCharsets.UTF_8);
            expected = new String(Files.readAllBytes(Paths.get("src/test/java/TestData/Expected/defineOBJ.c")), StandardCharsets.UTF_8);

        }catch(Exception e){
           e.printStackTrace();
        }
        assertEquals(expected, out);
    }
    @Test
    public void runDefineFunc(){
        CodeAnalyzer analyzer = new CodeAnalyzer("src/test/java/TestData/defineFunc.c",null);
        String output = "src/test/java/TestData/Output/defineFunc.c";
        analyzer.saveDataToFile(output);
        String out = "failed";
        String expected = "";
        try {
            out = new String(Files.readAllBytes(Paths.get(output)), StandardCharsets.UTF_8);
            expected = new String(Files.readAllBytes(Paths.get("src/test/java/TestData/Expected/defineFunc.c")), StandardCharsets.UTF_8);

        }catch(Exception e){
            e.printStackTrace();
        }
        assertEquals(expected, out);
    }

    @Test
    public void runConditionals(){
        CodeAnalyzer analyzer = new CodeAnalyzer("src/test/java/TestData/conditionals.c",null);
        String output = "src/test/java/TestData/Output/conditionals.c";
        analyzer.saveDataToFile(output);
        String out = "failed";
        String expected = "";
        try {
            out = new String(Files.readAllBytes(Paths.get(output)), StandardCharsets.UTF_8);
            expected = new String(Files.readAllBytes(Paths.get("src/test/java/TestData/Expected/conditionals.c")), StandardCharsets.UTF_8);

        }catch(Exception e){
            e.printStackTrace();
        }
        assertEquals(expected, out);
    }
    @Test
    public void runInclude(){
        CodeAnalyzer analyzer = new CodeAnalyzer("src/test/java/TestData/include.c",null);
        String output = "src/test/java/TestData/Output/include.c";
        analyzer.saveDataToFile(output);
        String out = "failed";
        String expected = "";
        try {
            out = new String(Files.readAllBytes(Paths.get(output)), StandardCharsets.UTF_8);
            expected = new String(Files.readAllBytes(Paths.get("src/test/java/TestData/Expected/include.c")), StandardCharsets.UTF_8);

        }catch(Exception e){
            e.printStackTrace();
        }
        assertEquals(expected, out);
    }
}