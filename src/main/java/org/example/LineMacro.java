package org.example;

public class LineMacro extends Macro{

    public LineMacro(String name){
        super(name);
    }

    @Override
    public String getBody(String line) {
        return line;
    }

    @Override
    public int countArguments() {
        return 0;
    }

    @Override
    public boolean checkHashtag() {
        return false;
    }
}
