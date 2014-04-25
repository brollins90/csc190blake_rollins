#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "ExportHeader.h"
#include <iostream>

namespace Engine
{
	// your stuff goes here...
	// use ENGINE_SHARED to indicate a function or class that you want to export
	ENGINE_SHARED void Init();

	ENGINE_SHARED bool sampleFunctionThatReturnsTrue();

	struct ENGINE_SHARED Vector2;
}

#endif // _ENGINE_H_