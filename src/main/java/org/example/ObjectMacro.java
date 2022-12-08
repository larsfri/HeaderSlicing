package org.example;

public class ObjectMacro {
    private String name;
    private String body;

    public ObjectMacro(String name, String definition){
        this.name = name;
        this.body = definition;
    }

    public String getBody(){
        return body;
    }

    public String getName(){
        return name;
    }




}
