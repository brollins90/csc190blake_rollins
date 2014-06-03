#ifndef PROFILER_H
#define PROFILER_H

//#pragma warning ( disable : 4100)

class Profiler
{
private:
#if PROFILER_ON
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
#endif

public:
#if PROFILER_ON
	static void initialize(const char* filename);
	static void shutdown();
	static void addEntry(const char* category, float time);
	static void newFrame();
#else
	static void initialize(const char* filename) {filename;}
	static void shutdown() {}
	static void addEntry(const char* category, float time) {category; time;}
	static void newFrame() {}
#endif
};

//#pragma warning ( default : 4100)

#endif