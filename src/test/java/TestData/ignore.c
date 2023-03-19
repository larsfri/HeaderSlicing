#ifdef IGN
#define A
#include "test_include.h"
#endif
#ifdef A
FALSE
#else
TRUE
#endif
#ifndef BUFSIZ
TRUE
#endif
#if IGN
//Should not be evaluated
#endif