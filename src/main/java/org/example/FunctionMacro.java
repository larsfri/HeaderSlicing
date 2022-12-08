package org.example;

import java.util.ArrayList;

public class FunctionMacro {
    private String name;
    private String body;
    private String[] arguments;

    public FunctionMacro(String name, String definition, ArrayList<String> param){
        this.name = name;
        this.body = definition;
        if(param == null){
            arguments = new String[0];
        }else {
            arguments = new String[param.size()];
            for (int i = 0; i < param.size(); i++) {
                arguments[i] = param.get(i);
            }
        }
    }

    public FunctionMacro(String name, String definition) {
        this.name = name;
        this.body = definition;
        this.arguments = new String[0];
    }
    public int countArguments(){
        if(arguments == null) return 0;
        return arguments.length;
    }

    public String getName(){
        return name;
    }


}
