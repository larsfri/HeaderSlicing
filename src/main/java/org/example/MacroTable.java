package org.example;

import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;

public class MacroTable {
    private ArrayList<String> ignoreList;
    private ArrayList<Macro> macros;

    public MacroTable(){
        macros = new ArrayList<Macro>();
        addPresetMacros();
    }

    private void addPresetMacros() {
        //ToDO
        CodeAnalyzer analyzer = new CodeAnalyzer("src/main/resources/gcc-predef.txt", this);
        do{
            analyzer.processLine();
        }while(analyzer.nextLine());

        macros.add(new ObjectMacro("__DATE__", getDate()));
        macros.add((new ObjectMacro("__TIME__", getTime())));
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
            System.out.println("Macro "+name +" is redefined without #undef");
            macros.remove(m);
        }
        ObjectMacro macro = new ObjectMacro(name, body);
        macros.add(macro);
    }
    public void addFunctionMacro(String name,String body, String[] parameter){
        Macro m = checkForMacro(name);
        if(m != null){
            System.out.println("Macro "+name +" is redefined without #undef");
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
    public ArrayList<Macro> getMacros(){
        return macros;
    }
}
