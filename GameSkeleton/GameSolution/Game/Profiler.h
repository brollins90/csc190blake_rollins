#ifndef PROFILER_H
#define PROFILER_H

class Profiler
{
	const char* fileName;
	static const unsigned int MAX_FRAME_SAMPLES = 15000;
	static const unsigned int MAX_PROFILE_CATEGORIES = 20;
	unsigned int frameIndex;
	unsigned int categoryIndex;
	unsigned int numUsedCategories;
	struct ProfileCategory
	{
		const char* name;
		float samples[MAX_FRAME_SAMPLES];
	} categories[MAX_PROFILE_CATEGORIES];

	char getDelimiter(unsigned int index) const;

public:
	void initialize(const char* filename);
	void shutdown();
	void addEntry(const char* category, float time);
	void newFrame();
};

#endif