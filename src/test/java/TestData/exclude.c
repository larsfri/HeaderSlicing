#ifdef EXC
#define A
#include "test_include.h"
#endif
#ifdef A
//Should not be evaluated
#endif
#ifdef BUFSIZ
//Should not be evaluated
#endif
#if A
//Should not be evaluated
#endif