package org.example;

public class ObjectMacro extends Macro{
    private String body;

    public ObjectMacro(String name, String definition){
        super(name);
        this.body = definition;
    }

    public String getBody(String s){
        return body;
    }

    public int countArguments(){return -1;}




}
