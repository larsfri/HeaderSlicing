package org.example;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;

import static org.junit.jupiter.api.Assertions.*;

class MainTest {

    private final PrintStream standardOut = System.out;
    private final ByteArrayOutputStream outputStreamCaptor = new ByteArrayOutputStream();

    @BeforeEach
    public void setUp() {
        System.setOut(new PrintStream(outputStreamCaptor));
    }
    @Test
    void mainArgs1() {
        Main.main(null);
        assertEquals("Error Syntax incorrect\n" +
                "Syntax: .exc [-d dir | -f file] -o output", outputStreamCaptor.toString()
                .trim());
    }

    @Test
    void mainArgs2() {
        String[] arguments = {
                "-e", "path", "-o", "path"
        };
        Main.main(arguments);
        assertEquals("Error Syntax incorrect\n" +
                "Syntax: .exc [-d dir | -f file] -o output", outputStreamCaptor.toString()
                .trim());
    }
    @Test
    void mainArgs3() {
        String[] arguments = {
                "-d", "path", "-i", "path"
        };
        Main.main(arguments);
        assertEquals("Error Syntax incorrect\n" +
                "Syntax: .exc [-d dir | -f file] -o output", outputStreamCaptor.toString()
                .trim());
    }
    @Test
    void mainInPath() {
        String[] arguments = {
                "-d", "/noDirectory", "-o", "/noDirectory"
        };
        Main.main(arguments);
        assertEquals("Could not read input path\n" +
                "Syntax: .exc [-d dir | -f file] -o output", outputStreamCaptor.toString()
                .trim());
    }

    @Test
    void mainOutPath() {
        String path = Paths.get("")
                .toAbsolutePath()
                .toString();
        String[] arguments = {
                "-d", path, "-o", "/noDirectory"
        };
        Main.main(arguments);
        assertEquals("Could not read output path\n" +
                "Syntax: .exc [-d dir | -f file] -o output", outputStreamCaptor.toString()
                .trim());
    }

    @Test
    public void runDefineOBJ(){
        String input = "src/test/java/TestData/defineOBJ.c";
        String output = "src/test/java/TestData/Output/";

        String pathInput = Paths.get(input)
                .toAbsolutePath()
                .toString();

        String pathOutput = Paths.get(output)
                .toAbsolutePath()
                .toString();
        String[] arguments = {
                "-f", pathInput, "-o", pathOutput
        };

        Main.main(arguments);

        output = "src/test/java/TestData/Output/defineOBJ.c";
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

    @AfterEach
    public void tearDown() {
        System.setOut(standardOut);
    }
}