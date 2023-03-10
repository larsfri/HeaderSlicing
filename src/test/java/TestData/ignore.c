#ifdef IGN
#define A
#include <stdio.h>
#endif
#ifdef A
FALSE
#else
TRUE
#endif
#ifndef BUFSIZ
TRUE
#endif