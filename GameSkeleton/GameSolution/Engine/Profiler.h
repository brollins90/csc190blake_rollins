#ifndef PROFILER_H
#define PROFILER_H

#include "ExportHeader.h"

//#pragma warning ( disable : 4100)
namespace Engine
{
	namespace Profiling
	{
		class Profiler
		{
		private:
		#if PROFILER_ON
			static const char* fileName;
			static const unsigned int MAX_FRAME_SAMPLES = 15000;
			static const unsigned int MAX_PROFILE_CATEGORIES = 20;
			static unsigned int frameIndex;
			static unsigned int categoryIndex;
			static unsigned int numUsedCategories;
			static struct ProfileCategory
			{
				const char* name;
				float samples[MAX_FRAME_SAMPLES];
			} categories[MAX_PROFILE_CATEGORIES];

			static char getDelimiter(unsigned int index);
		#endif

		public:
		#if PROFILER_ON
			ENGINE_SHARED static void initialize(const char* filename);
			ENGINE_SHARED static void shutdown();
			ENGINE_SHARED static void addEntry(const char* category, float time);
			ENGINE_SHARED static void newFrame();
		#else
			ENGINE_SHARED static void initialize(const char* filename) {filename;}
			ENGINE_SHARED static void shutdown() {}
			ENGINE_SHARED static void addEntry(const char* category, float time) {category; time;}
			ENGINE_SHARED static void newFrame() {}
		#endif
		};
	}
}

//#pragma warning ( default : 4100)

#endif