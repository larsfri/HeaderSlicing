package org.example;

import java.io.*;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;

public class MacroTable {
    private ArrayList<String> ignoreList;
    private ArrayList<Macro> macros;

    private String configPath = "src/main/resources/config.txt";
    private String predefPath = "src/main/resources/gcc-predef.txt";

    public MacroTable(){
        macros = new ArrayList<Macro>();
        ignoreList = new ArrayList<String>();
        addPresetMacros();
    }

    private void addPresetMacros() {
        CodeAnalyzer config = new CodeAnalyzer(configPath, this);
        addIgnoreList(config);
        ArrayList<String> predefs = getPredefs();
        updatePredef(predefs);

        CodeAnalyzer analyzer = new CodeAnalyzer(predefPath, this);

        macros.add(new ObjectMacro("__DATE__", getDate()));
        macros.add((new ObjectMacro("__TIME__", getTime())));
    }

    private void updatePredef(ArrayList<String> predefs) {
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter(predefPath));

            for (String line: predefs) {
                writer.write(line);
                writer.newLine();
            }

            writer.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    private ArrayList<String> getPredefs() {
        Process process;
        ArrayList<String> readStream = new ArrayList<String>();
        try{
            process = Runtime.getRuntime().exec("echo | gcc -dM -E -");

            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            String s;
            while ((s = reader.readLine()) != null) {
                readStream.add(s);
            }
            process.destroy();
        }catch(Exception e){
            throw new RuntimeException(e);
        }
        return readStream;
    }

    private void addIgnoreList(CodeAnalyzer config) {
        File configFile = config.getFile();
        configFile.setLineIndex(0);
        String name = configFile.getCurrentLine();
        while (name != null){
            ignoreList.add(name);
            name = configFile.getNextLine();
        }

    }

    private String getTime() {
        LocalTime time = java.time.LocalTime.now();
        return time.getHour() + ":"+ time.getMinute() + ":"+ time.getSecond();
    }

    private String getDate() {
        LocalDate date = java.time.LocalDate.now();
        String dateString = getMonth(date.getMonthValue());
        return dateString + " "+ date.getDayOfMonth() + " "+ date.getYear();
    }

    private String getMonth(int monthValue) {
        switch (monthValue){
            case 1: return "Jan";
            case 2: return "Feb";
            case 3: return "Mar";
            case 4: return "Apr";
            case 5: return "Mai";
            case 6: return "Jun";
            case 7: return "Jul";
            case 8: return "Aug";
            case 9: return "Sep";
            case 10: return "Okt";
            case 11: return "Nov";
            case 12: return "Dec";
        }
        return "";
    }


    public void addObjectMacro(String name, String body) {
        Macro m = checkForMacro(name);
        if(m != null){
            //System.out.println("Macro "+name +" is redefined without #undef");
            macros.remove(m);
        }
        ObjectMacro macro = new ObjectMacro(name, body);
        macros.add(macro);
    }
    public void addFunctionMacro(String name,String body, String[] parameter){
        Macro m = checkForMacro(name);
        if(m != null){
            //System.out.println("Macro "+name +" is redefined without #undef");
            macros.remove(m);
        }
        FunctionMacro macro = new FunctionMacro(name, body, parameter);
        macros.add(macro);
    }

    public Macro checkForMacro(String name){
        for(Macro m:macros){
            if(m.getName().equals(name)){
                return m;
            }
        }
        return null;
    }
    public void removeMacro(Macro m){
        macros.remove(m);
    }
    public ArrayList<Macro> getMacros(){
        return macros;
    }

    public boolean checkIgnore(String name) {
        if(ignoreList.contains(name)) return true;
        return false;
    }
}
