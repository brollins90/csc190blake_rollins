#ifndef ASSERTER_H
#define ASSERTER_H

#include <cstdlib>
#include "Profiler.h"
#include "Logger.h"

#pragma warning ( disable: 4127)

#if ASSERTER_ON

#define ASSERT(expr, ...) do { const char* msg = #expr##" "##__VA_ARGS__; if (!(expr)) {LOG(Engine::Logging::Severity::Severe, msg); END_LOG END_PROF DebugBreak(); exit(1);}}while(0);

#else
#define ASSERT(expr, ...)

#endif

//#pragma warning ( default : 4127)

#endif

