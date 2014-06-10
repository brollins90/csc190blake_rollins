#if PROFILER_ON
#include "Engine.h"

namespace Engine
{
	namespace Profiling
	{
		const char* Profiling::Profiler::fileName;
		unsigned int Profiling::Profiler::frameIndex;
		unsigned int Profiling::Profiler::categoryIndex;
		unsigned int Profiling::Profiler::numUsedCategories;
		Profiling::Profiler::ProfileCategory Profiling::Profiler::categories[MAX_PROFILE_CATEGORIES];

		void Profiler::initialize(const char* filename)
		{
			fileName = filename;
			frameIndex = 0;
			frameIndex--;
			categoryIndex = 0;
			numUsedCategories = 0;
		}

		void Profiler::shutdown()
		{
			std::ofstream outStream(fileName, std::ios::trunc);

			// Write cat headers
			for (unsigned int i = 0; i < numUsedCategories; i++)
			{
				outStream << categories[i].name;
				outStream << getDelimiter(i);	
			}

			unsigned int temp = 0;
			temp--;
			frameIndex = (frameIndex == temp) ? frameIndex + 1 : frameIndex;
			// Write data
			for (unsigned int frame = 0; frame < frameIndex; frame++)
			{
				for (unsigned int cat = 0; cat < numUsedCategories; cat++)
				{
					outStream << categories[cat].samples[frame];
					outStream << getDelimiter(cat);
				}
			}

		}

		void Profiler::addEntry(const char* cat, float time)
		{
			if (frameIndex >= MAX_FRAME_SAMPLES) {
				frameIndex = 0;
			}
			//assert(frameIndex < MAX_FRAME_SAMPLES);
			ASSERT((categoryIndex < MAX_PROFILE_CATEGORIES), "category index is greater than max number of categories")
			ProfileCategory& pc = categories[categoryIndex];

			if (frameIndex == 0) {
				pc.name = cat;
				numUsedCategories++;
			} else {
				ASSERT(pc.name == cat /*&& cat != null*/, "");
				ASSERT(categoryIndex < numUsedCategories, "");
			}

			categoryIndex++;
			pc.samples[frameIndex] = time;
	

		}

		void Profiler::newFrame()
		{
			if (frameIndex > 0) {
				ASSERT(categoryIndex == numUsedCategories, "");
			}
			frameIndex++;
			categoryIndex = 0;

		}

		char Profiler::getDelimiter(unsigned int index) //const
		{
			return ((index + 1) < numUsedCategories) ? ',' : '\n';
		}
	}
}
#endif
