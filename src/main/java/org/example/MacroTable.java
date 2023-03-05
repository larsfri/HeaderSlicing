package org.example;

import java.io.*;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.function.Consumer;

public class MacroTable {
    private ArrayList<String> ignoreList;
    private ArrayList<String> excludeList;
    private ArrayList<Macro> macros;

    private String configPath = "src/main/resources/config.txt";
    private String predefPath = "src/main/resources/gcc-predef.txt";

    public MacroTable(){
        macros = new ArrayList<Macro>();
        ignoreList = new ArrayList<String>();
        excludeList = new ArrayList<String>();
        addPresetMacros();
    }
    public MacroTable(boolean empty){
        macros = new ArrayList<Macro>();
        ignoreList = new ArrayList<String>();
        excludeList = new ArrayList<String>();
    }

    private void addPresetMacros() {

        updatePredefs();
        CodeAnalyzer analyzer = new CodeAnalyzer(predefPath, this);
        CodeAnalyzer config = new CodeAnalyzer(configPath, this);

        printStatus();

        macros.add(new ObjectMacro("__DATE__", getDate()));
        macros.add((new ObjectMacro("__TIME__", getTime())));

    }

    private void printStatus() {
        System.out.println("There are "+ macros.size() +" Macros defined");
        for (String exc:
             excludeList) {
            System.out.println(exc +" is completely excluded from processing");
        }
        for (String ign:
                ignoreList) {
            System.out.println("Conditionals containing" + ign + " are skipped, but Macros defined within are not");
        }
    }

    private void updatePredefs() {
        Process process;
        ArrayList<String> readStr = new ArrayList<String>();
        try{
            //process = Runtime.getRuntime().exec("cpp -dM -E - < /dev/null");
            //process = Runtime.getRuntime().exec("gcc -dM -E - < /dev/null");
            //process = Runtime.getRuntime().exec("echo | gcc -dM -E -");
            //process = Runtime.getRuntime().exec("touch foo.h; cpp -dM foo.h");

            process = Runtime.getRuntime().exec("src/main/resources/updatePredef.bat");
            //process = Runtime.getRuntime().exec("pwd");
            process.waitFor();
            process.destroy();
            System.out.println("Predefined Macros updated");
        }catch(Exception e){
            throw new RuntimeException(e);
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
        if(checkLineIgnore(name)) return null;
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
    public boolean checkExclude(String name) {
        if(excludeList.contains(name)) return true;
        return false;
    }
    public boolean checkLineIgnore(String line){
        for(String name: ignoreList){
            if(line.contains(name)){
                return true;
            }
        }
        return false;
    }
    public boolean checkLineExclude(String line){
        for(String name: excludeList){
            if(line.contains(name)){
                return true;
            }
        }
        return false;
    }
    public ArrayList<String> getAllMacroNames(){
        ArrayList<String> names = new ArrayList<String>();
        for (Macro m:
             macros) {
            names.add(m.getName());
        }
        names.addAll(excludeList);
        return names;
    }
    public void addExclude(String s){
        excludeList.add(s);
    }
    public void addIgnore(String s){
        ignoreList.add(s);
    }
}
