#ifndef DEBUG_INFO

#include<cstdio>

template<typename arg, typename ...args>
inline void IGNORE(arg x, args... y){ return; }

#ifdef DEBUG_LOCAL
// output the debug info
#define DEBUG_INFO printf
#else
// debug -> off
#define DEBUG_INFO IGNORE
#endif

#endif
