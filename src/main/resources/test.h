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

Test if
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