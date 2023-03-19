package org.example;

/**
 * This is an abstract base class for the handling of macros.
 * Derived classes exist for the handling of Function Macro and Object Macro.
 */
public abstract class Macro {
    /** Name of Macro that is processed by this instance. */
    private String name = "";

    /**
     * Constructor taking the Macro name as argument.
     * @param name Name of macro instance.
     */
    public Macro(String name) {
        this.name = name;
    }

    /**
     * Returns the name of the Macro.
     * @return Name of macro
     */
    public String getName() {
        return name;
    }

    /**
     * Returns the body of the Macro from the given parameter.
     * @param parameter Body of the Macro for the given parameter.
     */
    public abstract String getBody(String parameter);

    /**
     * Returns the number of arguments of the Macro.
     * @return Number of arguments of the Macro.
     */
    public abstract int countArguments();
}
