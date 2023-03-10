#ifdef EXC
#define A
#include <stdio.h>
#endif
#ifdef A
//Should not be evaluated
#endif
#ifdef BUFSIZ
//Should not be evaluated
#endif