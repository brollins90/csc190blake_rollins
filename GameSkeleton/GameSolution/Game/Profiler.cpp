#include "Profiler.h"
#include "assert.h"
#include <fstream>

void Profiler::initialize(const char* filename)
{
	this->fileName = filename;
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
	assert(categoryIndex < MAX_PROFILE_CATEGORIES);
	ProfileCategory& pc = categories[categoryIndex];

	if (frameIndex == 0) {
		pc.name = cat;
		numUsedCategories++;
	} else {
		assert(pc.name == cat /*&& cat != null*/);
		assert(categoryIndex < numUsedCategories);
	}

	categoryIndex++;
	pc.samples[frameIndex] = time;
	

}

void Profiler::newFrame()
{
	if (frameIndex > 0) {
		assert(categoryIndex == numUsedCategories);
	}
	frameIndex++;
	categoryIndex = 0;

}

char Profiler::getDelimiter(unsigned int index) const
{
	return ((index + 1) < numUsedCategories) ? ',' : '\n';
}