package org.example;

import java.util.ArrayList;

public class FunctionMacro extends Macro{
    private String body;
    private String[] arguments;

    public FunctionMacro(String name, String definition, ArrayList<String> param){
        super(name);
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

    @Override
    public String getBody(String parameter) {
        //ToDo
        return null;
    }

    public int countArguments(){
        if(arguments == null) return 0;
        return arguments.length;
    }



}
