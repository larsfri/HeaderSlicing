//This is a test file

#define OBJ Object Macro body
#define FUNC(X,Y,Z) Function macro Body with X,Y,Z as Params

#ifdef OBJ //should be run
OBJ
#else //shouldnt be run
fehler
#endif

#ifdef FUNC //should be run
FUNC(Macro1,Macro2,Macro3)
#else //shouldnt be run
fehler
#endif

#ifdef ABC //shouldnt be run
 Fehler
#else //shoul be run
Nicht definiert!
Test korrekt
#endif

#include "test_include.h"

#ifndef ABC
Fehler
#else
Import erfolgreich
#endif