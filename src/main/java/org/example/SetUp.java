package org.example;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class SetUp {
    private ArrayList<String> paths;

    public SetUp(){
        Process process;
        paths = new ArrayList<String>();
        try{
            process = Runtime.getRuntime().exec("ipconfig");
            //wsl cpp -v /dev/null -o /dev/null
            //wsl gcc -xc -E -v -
            //process = Runtime.getRuntime().exec("wsl echo | wsl gcc -Wp,-v -x c++ - -fsyntax-only");

            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            String s;
            while ((s = reader.readLine()) != null) {
                System.out.println("line: " + s);
            }
            List<String> list = reader.lines().toList();
            paths.addAll(list);
            process.destroy();
        }catch(Exception e){
            throw new RuntimeException(e);
        }

        boolean path = false;
        for (String line:paths) {
            if(line.equals("End of search list.")) path = false;
            if(!path){
                paths.remove(line);
            }
            if(line.equals("#include <...> search starts here:"))path = true;
        }
    }

    public ArrayList<String> getPaths(){
        return paths;
    }
}
