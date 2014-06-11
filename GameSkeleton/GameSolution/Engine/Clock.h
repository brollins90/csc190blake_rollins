#ifndef CLOCK_H
#define CLOCK_H

#include "ExportHeader.h"
#include <Windows.h>

namespace Engine
{
	namespace Timing
	{
		class Clock
		{
			LARGE_INTEGER startTime;
			LARGE_INTEGER timeFrequency;
			LARGE_INTEGER timeLastFrame;
			LARGE_INTEGER deltaLastFrame;
			float deltaTime;
		public: 
			ENGINE_SHARED bool initialize();
			ENGINE_SHARED bool shutdown();
			ENGINE_SHARED void newFrame();
			ENGINE_SHARED void setStartTime();
			ENGINE_SHARED float timeElapsedLastFrame() const;
		};
	}
}
#endif