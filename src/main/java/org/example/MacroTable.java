package org.example;

import java.io.*;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.function.Consumer;

/**
 * This class contains lists of all Macros found in all code files.
 * A macro is either to be processed (the default), to be ignored,
 * or to be excluded.
 */
public class MacroTable {
    /** List of all macros that shall be ignored in conditionals. */
    private ArrayList<String> ignoreList;
    /** List of all macros that shall be excluded. */
    private ArrayList<String> excludeList;
    /** List of all macros that shall be processed. */
    private ArrayList<Macro> macros;

    /** Name of file that is currently being processed. */
    private String filename;
    /** Line number within the current file. */
    private int line;

    /** List of Paths as retrieved from the Setup class. */
    private ArrayList<String> paths;

    /** File path of the configuration file. */
    private String configPath = "src/main/resources/config.txt";
    /** File path of the file with the predefined macros of GCC. */
    private String predefPath = "src/main/resources/gcc-predef.txt";

    /**
     * Constructor for a new instance of a Macro Table.
     * This constructor initialises all three Macro lists.
     * It then creates a Setup instance and retrieves all Paths from it.
     * Further, it adds Preset Macros for DATE and TIME.
     */
    public MacroTable() {
        macros = new ArrayList<Macro>();
        ignoreList = new ArrayList<String>();
        excludeList = new ArrayList<String>();
        SetUp setup = new SetUp();
        paths = setup.getPaths();
        filename = "";
        line = 0;
        addPresetMacros();
    }

    /**
     * Adds __DATE__ and __TIME__ to the list of macros to be handled.
     */
    private void addPresetMacros() {
        updatePredefs();
        CodeAnalyzer analyzer = new CodeAnalyzer(predefPath, this);
        CodeAnalyzer config = new CodeAnalyzer(configPath, this);

        printStatus();

        macros.add(new ObjectMacro("__DATE__", getDate()));
        macros.add((new ObjectMacro("__TIME__", getTime())));
    }

    /**
     * Print the status of the Macro Table to the console.
     * The status contains the number of Macros that are handled, and as well
     * the full list of macros to be excluded or ignored in conditionals.
     */
    private void printStatus() {
        System.out.println("There are " + macros.size() + " Macros predefined");
        for (String exc :
                excludeList) {
            System.out.println(exc + " is completely excluded from processing");
        }
        for (String ign :
                ignoreList) {
            System.out.println("Conditionals containing " + ign + " are skipped, but Macros defined within are not");
        }
    }

    /**
     * Brief.
     */
    private void updatePredefs() {
        Process process;
        ArrayList<String> readStr = new ArrayList<String>();
        try {
            //process = Runtime.getRuntime().exec("cpp -dM -E - < /dev/null");
            //process = Runtime.getRuntime().exec("gcc -dM -E - < /dev/null");
            //process = Runtime.getRuntime().exec("echo | gcc -dM -E -");
            //process = Runtime.getRuntime().exec("touch foo.h; cpp -dM foo.h");

            process = Runtime.getRuntime().exec("src/main/resources/updatePredef.bat");
            //process = Runtime.getRuntime().exec("pwd");
            process.waitFor();
            process.destroy();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    /**
     * Get local time of machine and return in human-readable format.
     * The human readable format used is \"hh::mm::ss\".
     * @return Human-readable time formatted according to the format used.
     */
    private String getTime() {
        LocalTime time = java.time.LocalTime.now();
        return time.getHour() + ":" + time.getMinute() + ":" + time.getSecond();
    }

    /**
     * Get local date of machine and return in human-readable format.
     * The human readable format used is \"mmm dd yyyy\".
     * The function uses getMonth() to get a 3-letter name for a month.
     * @return Human-readable date formatted according to the format used.
     */
    private String getDate() {
        LocalDate date = java.time.LocalDate.now();
        String dateString = getMonth(date.getMonthValue());
        return dateString + " " + date.getDayOfMonth() + " " + date.getYear();
    }

    /**
     * Convert a month between 1 and 12 to a 3-letter string.
     * @param monthValue 1-based index of the month (between 1 and 12).
     * @return 3-letter string for the given month value.
     */
    private String getMonth(int monthValue) {
        switch (monthValue) {
            case 1:
                return "Jan";
            case 2:
                return "Feb";
            case 3:
                return "Mar";
            case 4:
                return "Apr";
            case 5:
                return "Mai";
            case 6:
                return "Jun";
            case 7:
                return "Jul";
            case 8:
                return "Aug";
            case 9:
                return "Sep";
            case 10:
                return "Okt";
            case 11:
                return "Nov";
            case 12:
                return "Dec";
        }
        return "";
    }

    /**
     * Adds a new object macro to the list of macros to be handled.
     * The function checks that the macro is not already included in the list.
     * Should that be the case, then the old definition is first deleted.
     * @param name Name of the macro to add.
     * @param body Body of the macro to add.
     */
    public void addObjectMacro(String name, String body) {
        Macro m = checkForMacro(name);
        if (m != null) {
            //System.out.println("Macro "+name +" is redefined without #undef");
            macros.remove(m);
        }
        ObjectMacro macro = new ObjectMacro(name, body);
        macros.add(macro);
    }

    /**
     * Adds a new function macro to the list of macros to be handled.
     * The function checks that the macro is not already included in the list.
     * Should that be the case, then the old definition is first deleted.
     * @param name Name of the macro to add.
     * @param body Body of the macro to add.
     * @param parameter List of parameters of the macro to add.
     */
    public void addFunctionMacro(String name, String body, String[] parameter) {
        Macro m = checkForMacro(name);
        if (m != null) {
            //System.out.println("Macro "+name +" is redefined without #undef");
            macros.remove(m);
        }
        FunctionMacro macro = new FunctionMacro(name, body, parameter);
        macros.add(macro);
    }

    /**
     * Return the Macro instance with the given name, or null for none.
     * In case that the macro shall be excluded, null is returned as well.
     * Special handling has been added for __FILE__ and __LINE__, which return
     * the name of the file currently processed, or the current line number.
     * @param name Name of the macro to search for.
     * @return Macro with given name, or null if macro either does not exist,
     * or shall be ignored in the current line.
     */
    public Macro checkForMacro(String name) {
        if (checkLineIgnore(name)) return null;
        for (Macro m : macros) {
            if (m.getName().equals(name)) {
                return m;
            }
        }
        if (name.equals("__FILE__")) return getFilename();
        if (name.equals("__LINE__")) return getLine();
        return null;
    }

    /**
     * Create and return an Object Macro for the current line number.
     * @return Object Macro for the current line number.
     */
    private Macro getLine() {
        Macro m = new ObjectMacro("__LINE__", "" + line);
        return m;
    }

    /**
     * Change the current line number to a new value.
     * @param line New line number to set.
     */
    public void setLine(int line) {
        this.line = line;
    }

    /**
     * Create and return an Object Macro for the current file name.
     * @return Object Macro for the current file name.
     */
    private Macro getFilename() {
        Macro m = new ObjectMacro("__FILE__", filename);
        return m;
    }

    /**
     * Change the file name to a new path.
     * @param filename New file name to set.
     */
    public void setFilename(String filename) {
        this.filename = filename;
    }

    /**
     * Remove a macro from the list of macros to be processed.
     * @param m Macro to remove from list.
     */
    public void removeMacro(Macro m) {
        macros.remove(m);
    }

    /**
     * Return an Array List with all defined macros.
     * This function adds macros for __FILE__ and __LINE__.
     * @return List of all macros to be processed.
     */
    public ArrayList<Macro> getMacros() {
        ArrayList<Macro> m = (ArrayList<Macro>) macros.clone();
        m.add(getFilename());
        m.add(getLine());
        return m;
    }

    /**
     * Check whether the macro with the given name shall be ignored.
     * @param name Name of macro to be checked for.
     * @return True of macro shall be ignored, false otherwise.
     */
    public boolean checkIgnore(String name) {
        if (ignoreList.contains(name)) return true;
        return false;
    }

    /**
     * Check whether the macro with the given name shall be excluded.
     * @param name Name of macro to be checked for.
     * @return True of macro shall be excluded, false otherwise.
     */
    public boolean checkExclude(String name) {
        if (excludeList.contains(name)) return true;
        return false;
    }

    /**
     * Checks if a given line includes a Macro that shall be ignored.
     * @param line Line to check for a Macro to be ignored in conditionals.
     * @return True if line contains a Macro to be ignored, false otherwise.
     */
    public boolean checkLineIgnore(String line) {
        for (String name : ignoreList) {
            if (line.contains(name)) {
                return true;
            }
        }
        return false;
    }

    /**
     * Checks if a given line includes a Macro that shall be excluded.
     * @param line Line to check for a Macro to be excluded.
     * @return True if line contains a Macro to be excluded, false otherwise.
     */
    public boolean checkLineExclude(String line) {
        for (String name : excludeList) {
            if (line.contains(name)) {
                return true;
            }
        }
        return false;
    }

    /**
     * Return an Array List of all Macros to be processed.
     * @return Array List of all Macros to be processed.
     */
    public ArrayList<String> getAllMacroNames() {
        boolean afterPreset = false;
        ArrayList<String> names = new ArrayList<String>();
        for (Macro m :
                macros) {

            if (afterPreset) names.add(m.getName());

            if (m.getName().equals("__TIME__")) afterPreset = true;

        }
        names.addAll(excludeList);
        return names;
    }

    /**
     * Add a macro with the given name to the list of Macros to be excluded.
     * @param s Name of Macro to be excluded.
     */
    public void addExclude(String s) {
        excludeList.add(s);
    }

    /**
     * Add a macro with the given name to the list of Macros to be ignored.
     * @param s Name of Macro to be ignored.
     */
    public void addIgnore(String s) {
        ignoreList.add(s);
    }

    /**
     * Return an Array List of all paths.
     * @return Array List of all paths.
     */
    public ArrayList<String> getPaths() {
        return paths;
    }
}
