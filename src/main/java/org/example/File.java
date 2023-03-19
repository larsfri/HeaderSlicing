package org.example;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * This class handles an Array List with all Lines of the document.
 */
public class File {
    /** Path to the file that is handled by this instance. */
    private String path;
    /** Array List with all lines read from the file. */
    private ArrayList<String> dataLines = new ArrayList<String>();
    /** Index of line that is currently being processed. */
    private int lineIndex = 0;

    /**
     * Read a file into memory using a BufferedReader instance.
     * This function reads a file into memory by putting each line into a string.
     * As a first post-processing, long lines split by backslash are merged again.
     * The result is an ArrayList that is used by further operations of the class.
     * @param path Path to file to read into memory.
     */
    public File(String path) {
        this.path = path;
        try {
            BufferedReader bufferedReader = new BufferedReader(new FileReader(this.path));
            List<String> list = bufferedReader.lines().toList();
            dataLines.addAll(list);
            dataLines.add(0, "");
            mergeContinuedLines();
            bufferedReader.close();
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    /**
     * Default constructor that initialised an empty instance without a path.
     */
    public File() {
        path = "";
    }

    /**
     * Merge lines that are split by backslash into a single (long) line.
     */
    private void mergeContinuedLines() {
        if (dataLines != null) {
            for (int i = 0; i < dataLines.size() - 1; i++) {
                String line = dataLines.get(i);
                if (line.length() > 0) {
                    char lastChar = line.charAt(line.length() - 1);
                    if (lastChar == '\\') {
                        String merge = line.substring(0, line.length() - 1) + dataLines.get(i + 1);
                        dataLines.set(i, merge);
                        dataLines.remove(i + 1);
                        i--;
                    }
                }
            }
        }
    }

    /**
     * Return line index.
     * @return Index of line currently processed.
     */
    public int getLineIndex() {
        return lineIndex;
    }

    /**
     * Append a line to the end of the internal Array.
     * @param line Line to add to the Array.
     */
    public void addLine(String line) {
        dataLines.add(line);
    }

    /**
     * Clear the internal Array of lines.
     */
    public void clear() {
        dataLines.clear();
    }

    /**
     * Returns the current line, i.e. the line corresponding to the Line Index.
     * @return Line of current line index.
     */
    public String getCurrentLine() {
        return dataLines.get(lineIndex);
    }

    /**
     * Returns the line following the current line, or null for none (end of file).
     * This function increments the Line Index by one.
     * @return The line following the current line, or null for none.
     */
    public String getNextLine() {
        if (lineIndex < (dataLines.size() - 1)) {
            lineIndex++;
            return dataLines.get(lineIndex);
        } else {
            return null;
        }
    }

    /**
     * Change the content of the current line to the given string.
     * @param line New content of current line.
     */
    public void changeCurrentLine(String line) {
        dataLines.set(lineIndex, line);
    }

    /**
     * Delete the current line from the Array.
     */
    public void deleteCurrentLine() {
        dataLines.remove(lineIndex);
    }

    /**
     * Store the Array to a new file.
     * This operation stores the Array to a (new) file using a BufferedWriter.
     * The outputPath has to be a valid path and file name, including permission to write to it.
     * @param outputPath Full file path and name for the file to create.
     */
    public void saveDataToFile(String outputPath) {
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter(outputPath));

            for (String line : dataLines) {
                writer.write(line);
                writer.newLine();
            }

            writer.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    /**
     * Move back by one line.
     * This function goes back by one line (if possible).
     */
    public void reduceIndex() {
        if (lineIndex != 0) {
            lineIndex--;
        }
    }
}
