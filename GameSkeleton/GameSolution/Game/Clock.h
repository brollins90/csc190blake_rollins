#ifndef CLOCK_H
#define CLOCK_H

#include <Windows.h>

namespace Timing
{
	class Clock
	{
		LARGE_INTEGER timeFrequency;
		LARGE_INTEGER timeLastFrame;
		LARGE_INTEGER deltaLastFrame;
		float deltaTime;
	public: 
		bool initialize();
		bool shutdown();
		void newFrame();
		float timeElapsedLastFrame() const;
	};
}

#endif