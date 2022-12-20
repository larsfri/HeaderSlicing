package org.example;

public abstract class Macro {
    private String name;

    public Macro(String name){
        this.name = name;
    }

    public String getName(){
        return name;
    }
    public abstract String getBody(String parameter);
    public abstract int countArguments();
}
