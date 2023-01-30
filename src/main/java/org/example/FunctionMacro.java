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
        if(parameter == null){
            return body;
        }
        String[] param = parameter.split(",");
        if(param.length != arguments.length){
            System.out.println("Parameter count missmatch");
            return body;
        }
        String newBody = body;
        for (int i = 0; i < param.length; i++) {
            newBody = replaceParam(newBody, param[i], i);
        }
        return newBody;
    }

    private String replaceParam(String newBody, String replacement, int index) {
        String result = newBody;
        result = StringOperations.replaceString(newBody, arguments[index], replacement);
        if(!result.equals(newBody)){
            int start = newBody.indexOf(arguments[index]);
            start = start + replacement.length();
            result = result.substring(0, start) + replaceParam(result.substring(start), replacement, index);
        }
        return result;
    }

    @Override
    public int countArguments(){
        if(arguments == null) return 0;
        return arguments.length;
    }

    @Override
    public boolean checkHashtag() {
        if(body.contains("#")) return true;
        return false;
    }
}
