package org.example;

import java.util.ArrayList;

/**
 * This class extends the abstract Macro base class for a Function Macro.
 * A Function Macro has a body with arguments.
 */
public class FunctionMacro extends Macro {
    /** Body of the Macro. */
    private String body;
    /** Array of arguments of the Macro. */
    private String[] arguments;

    /**
     * Constructor taking name, definition and parameters.
     * @param name Name of Macro.
     * @param definition Definition of the Macro, i.e. the body of the Macro.
     * @param param Array of arguments of the Function Macro.
     */
    public FunctionMacro(String name, String definition, String[] param) {
        super(name);
        this.body = definition;
        if (param == null) {
            arguments = new String[0];
        } else {
            arguments = param;
        }
    }

    /**
     * Returns the body of the Macro from the given parameter
     * @param parameter Body of the Macro with comma-separated list of parameter values.
     * @return Body of Macro with arguments replaced by the given parameter values.
     * In case of a parameter mismatch or empty parameter, the original body is returned.
     */
    @Override
    public String getBody(String parameter) {
        if (parameter == null) {
            return body;
        }
        String[] param = parameter.split(",");
        param = StringOperations.joinStrings(param);
        if (param.length != arguments.length) {
            System.out.println("Parameter count missmatch");
            return body;
        }
        String newBody = body;
        for (int i = 0; i < param.length; i++) {
            newBody = replaceParam(newBody, param[i], i);
        }
        return newBody;
    }

    /**
     * Replace parameter at given index by the replacement string.
     * @param newBody Body to modify.
     * @param replacement Replacement string for parameter at given index.
     * @param index Index of parameter to replace.
     * @return Body with parameter at given index replaced by given replacement.
     */
    private String replaceParam(String newBody, String replacement, int index) {
        String result = newBody;
        result = StringOperations.replaceString(newBody, arguments[index], replacement);
        if (!result.equals(newBody)) {
            int start = newBody.indexOf(arguments[index]);
            start = start + replacement.length();
            result = result.substring(0, start) + replaceParam(result.substring(start), replacement, index);
        }
        return result;
    }

    /**
     * Return the number of arguments of the Function Macro.
     * @return Number of arguments of the Function Macro.
     */
    @Override
    public int countArguments() {
        if (arguments == null) return 0;
        return arguments.length;
    }
}
