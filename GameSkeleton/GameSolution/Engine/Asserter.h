#ifndef ASSERTER_H
#define ASSERTER_H

#include "Logger.h"

//#pragma warning ( disable: 4127)

#if ASSERTER_ON

#define ASSERT(expr, ...) do { const char* msg = #expr##" "##__VA_ARGS__; if (!(expr)) {LOG(Severe, msg); END_LOG DebugBreak(); exit(1);}}while(0);

#else
#define ASSERT(expr, ...)

#endif

#endif

