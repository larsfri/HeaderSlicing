package org.example;

public class CodeAnalyzer {

    private File file;
    private String filename;
    private String line;
    private int type;
    private boolean comment;

    public CodeAnalyzer(String filename){
        this.filename = filename;
        file = new File(filename);
        line = file.getCurrentLine();
        type = checkType();

    }
    //gets next line returns true if line not null
    public boolean nextLine(){
        line = file.getNextLine();
        type = checkType();
        if(type == -1) return false;
        return true;
    }

    public int processLine(){
        switch(type){
            case -1: return -1;
            case 0: return 0;
            case 1:
                //analyze Preprocessing code
                return 1;
            case 2:
                //check comment
                //find macros & replace them
                return 2;
            default:
                System.out.println("Unexpected Type for Line");
                return -1;
        }
    }



    /*
       -1 null
       0 empty line
       1 pre-processor code
       2 normal code
        */
    private int checkType() {

        if(line == null) return -1;
        if(line.equals("")) return 0;
        if(line.charAt(0) == '#') return 1;
        if(StringOperations.trimSpaces(line).equals("")) return 0;

        return 2;
    }
}
