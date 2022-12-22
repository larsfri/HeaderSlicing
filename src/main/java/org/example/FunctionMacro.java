package org.example;

import java.util.ArrayList;

public class FunctionMacro extends Macro{
    private String body;
    private String[] arguments;

    public FunctionMacro(String name, String definition, String[] param){
        super(name);
        this.body = definition;
        if(param == null){
            arguments = new String[0];
        }else {
            arguments = param;
        }
    }

    @Override
    public String getBody(String parameter) {
        String[] param = parameter.split(",");
        String result = body;
        for (int i = 0; i < param.length; i++) {
            body = StringOperations.replaceString(body, arguments[i], param[i]);
        }
        return body;
    }

    public int countArguments(){
        if(arguments == null) return 0;
        return arguments.length;
    }



}
