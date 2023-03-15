package org.example;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

//Handles an Array List with all Lines of the document
public class File {
    private String path;
    private ArrayList<String> dataLines = new ArrayList<String>();
    private int lineIndex = 0;

    //new org.example.File is read from Filename
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

    public File() {
        path = "";
    }

    //Merges lines separated by backslashs, last line isn't checked
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

    public int getLineIndex() {
        return lineIndex;
    }

    public void setLineIndex(int index) {
        this.lineIndex = index;
    }

    public String getPath() {
        return path;
    }

    public void setPath(String path) {
        this.path = path;
    }

    public void addLine(String line) {
        dataLines.add(line);
    }

    public void clear() {
        dataLines.clear();
    }

    public void insertLineAfterIndex(String line) {
        dataLines.add(lineIndex + 1, line);
    }

    //returns current line
    public String getCurrentLine() {
        return dataLines.get(lineIndex);
    }

    //returns next line or null
    public String getNextLine() {
        if (lineIndex < (dataLines.size() - 1)) {
            lineIndex++;
            return dataLines.get(lineIndex);
        } else {
            return null;
        }
    }

    //current line is set to given string
    public void changeCurrentLine(String line) {
        dataLines.set(lineIndex, line);
    }

    //current line is removed
    public void deleteCurrentLine() {
        dataLines.remove(lineIndex);
    }

    //returns true if line is in bounds and was deleted
    public boolean deleteLine(int index) {
        if (index < dataLines.size()) {
            dataLines.remove(index);
            return true;
        }
        return false;
    }

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

    public void reduceIndex() {
        if (lineIndex != 0) {
            lineIndex--;
        }
    }
}
