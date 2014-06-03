#ifndef LOGGER_H
#define LOGGER_H

#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using std::vector;
using std::string;

enum Severity { Info, Warning, Error, Severe };

#define LOG( severity, message) Logger::Log( severity, message, __FILE__, __LINE__ )
#define END_LOG Logger::shutDown();

//#pragma warning ( disable : 4100)

class Logger
{
public:
#if LOG_ON
	Logger(void);
	~Logger(void);
	static void initialize(const char* filename);
	static void StringReplace(string& str, const string& from, const string& to);
	static string Sanitize(string str);
	static void Log( Severity severity, const char* message, const char * logFile, int logLine);
	static void shutdown();
#else
	Logger(void){}
	~Logger(void){}
	static void initialize(const char* filename){filename;}
	static void StringReplace(string& str, const string& from, const string& to){str; from; to;}
	static string Sanitize(string str){str;}
	static void Log( Severity severity, const char* message, const char * logFile, int logLine){severity; message; logFile; logLine;}
	static void shutdown(){}
#endif

private:
#if LOG_ON
	const char* fileName;
	static vector <string> logList;
	static vector <Severity> severityList;
	static void WriteFile();
#endif
};

//#pragma warning ( default : 4100)

#endif