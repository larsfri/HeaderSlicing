#ifdef __LINE__
TRUE
#endif
#ifndef __FILE__
FALSE
#else
TRUE
#endif
#if 0
FALSE
#if 1
FALSE
#endif
if 1
FALSE
#endif
#endif
#if defined(__LINE__)
TRUE
#else
FALSE
#endif
#if 0
FALSE
#elif 1
TRUE
#endif