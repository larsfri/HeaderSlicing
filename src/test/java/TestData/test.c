//This is a test file
__FILE__ __LINE__
#define OBJ Object Macro body
#define FUNC3(X,Y,Z) Function macro Body with X Y and Z as Params
//Test Macro expansion
test #OBJ "OBJ"
OBJ FUNC3(1,2,3) FUNC3(OBJ, FUNC3(1,2,3), OBJ) //OBJ
//Expected Object Macro body Function mb with 1,2,3 as params func mb with object mb func mb 1,2,3 as param obj m b as param
#ifdef OBJ //should be run
OBJ //OBJ ifdef correct
#else //shouldn't be run
//Error else block OBJ ifdef
#endif

#ifdef FUNC3 //should be run
FUNC3(1,2,3 )// FUNC3 ifdef correct
#else //shouldnt be run
//Error FUNC3 ifdef
#endif

#ifdef ABC //shouldn't be run
//Error ABC ifdef
#else //shoul be run
//else block of ABC run correctly
#endif

#include "test_include.h"

#ifdef ABC
//ABC imported Succesfully
#include "test_include.h"
#else
//Import ABC nicht erfolgreich
#endif

#if 1
Success easy test
#else
Auswertung falsch
#endif

#if defined(ABC)
Success second test
#else
Auswertung falsch
#endif

#define ABC

"ABC" ABC
OBJ "OBJ"
OBJ OBJ OBJ
"OBJ"1

#if defined(ABC) && ABC
Auswertung falsch
#if 1
Inner Test korrekt
#else
Fehler
#endif
#else
Success third test
#endif


#if defined(ABC) && ABC
Auswertung falsch
#elif defined(ABC)
Success elif test
#else
Auswertung falsch(else)
#endif