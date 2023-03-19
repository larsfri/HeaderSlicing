package org.example;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

/**
 * This class reads the list of paths from GCC.
 */
public class SetUp {
    /** List of all paths. */
    private ArrayList<String> paths;

    /**
     * Constructor of SetUp class.
     * This constructor reads the list of paths from gcc. It calls gcc via a dedicated process,
     * and then processes the Error Stream (std::err) for the list of paths.
     */
    public SetUp() {
        paths = new ArrayList<String>();
        Process process;
        ArrayList<String> readStream = new ArrayList<String>();
        try {
            process = Runtime.getRuntime().exec("cpp -v /dev/null -o /dev/null");
            //wsl cpp -v /dev/null -o /dev/null
            //bash "cpp -v /dev/null -o /dev/null"
            //wsl gcc -xc -E -v -
            //process = Runtime.getRuntime().exec("wsl echo | wsl gcc -Wp,-v -x c++ - -fsyntax-only");

            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getErrorStream()));
            String s;
            while ((s = reader.readLine()) != null) {
                readStream.add(s);
            }
            process.destroy();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

        // Search for the line that marks the start of the include paths
        boolean path = false;
        for (String line : readStream) {
            if (line.equals("End of search list.")) path = false;
            if (path) {
                paths.add(line);
            }
            if (line.equals("#include <...> search starts here:")) path = true;
        }
    }

    /**
     * Return the list of search paths.
     * @return List of search paths.
     */
    public ArrayList<String> getPaths() {
        return paths;
    }
}
