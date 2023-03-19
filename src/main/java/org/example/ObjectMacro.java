package org.example;

/**
 * This class extends the abstract Macro base class for an Object Macro.
  */
public class ObjectMacro extends Macro {
    /** Body of the Macro. */
    private String body;

    /**
     * Constructor taking name and definition.
     * @param name Name of Macro.
     * @param definition Definition of the Macro, i.e. the body of the Macro.
     */
    public ObjectMacro(String name, String definition) {
        super(name);
        this.body = definition;
    }

    /**
     * Returns the body of the Macro from the given parameter.
     * @param s Parameter to consider, which is ignored for an Object Macro.
     * @return Body of the Macro, as defined in the contructor.
     */
    @Override
    public String getBody(String s) {
        return body;
    }

    /**
     * Return the number of arguments of the Function Macro.
     * @return Number of arguments of the Function Macro, which is defined as -1 for an Object Macro.
     */
    @Override
    public int countArguments() {
        return -1;
    }

}
