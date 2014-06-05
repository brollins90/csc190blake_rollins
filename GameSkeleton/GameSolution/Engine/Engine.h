#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "ExportHeader.h"
#include <iostream>
#include "Vector2D.h"
#include "Vector3D.h"
#include "Matrix2D.h"
#include "Matrix3D.h"
#include "Clock.h"
#include "Logger.h"
#include "Profiler.h"
#include "Asserter.h"

namespace Engine
{
	// your stuff goes here...
	// use ENGINE_SHARED to indicate a function or class that you want to export
	ENGINE_SHARED void Init();

	ENGINE_SHARED bool sampleFunctionThatReturnsTrue();
	
	struct ENGINE_SHARED Vector2D;
	struct ENGINE_SHARED Vector3D;
	struct ENGINE_SHARED Matrix2D;
	struct ENGINE_SHARED Matrix3D;
	class ENGINE_SHARED Timing::Clock;
	class ENGINE_SHARED Logging::Logger;
	class ENGINE_SHARED Profiling::Profiler;
}

#endif // _ENGINE_H_