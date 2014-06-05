#ifndef LOGGER_H
#define LOGGER_H

#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using std::vector;
using std::string;

#include "ExportHeader.h"

namespace Engine
{
	namespace Logging
	{
		enum Severity { Info, Warning, Error, Severe };

		#define LOG( severity, message) Logger::Log( severity, message, __FILE__, __LINE__ )
		#define END_LOG Logger::shutDown();

		//#pragma warning ( disable : 4100)

		class Logger
		{
		private:
		#if LOG_ON
			static const char* fileName;
			static vector <string> logList;
			static vector <Severity> severityList;
			static void WriteFile();
		#endif

		public:
		#if LOG_ON
			Logger(void);
			~Logger(void);
			ENGINE_SHARED static void initialize(const char* filename);
			static void StringReplace(string& str, const string& from, const string& to);
			static string Sanitize(string str);
			ENGINE_SHARED static void Log( Severity severity, const char* message, const char * logFile, int logLine);
			ENGINE_SHARED static void shutdown();
		#else
			Logger(void){}
			~Logger(void){}
			ENGINE_SHARED static void initialize(const char* filename){filename;}
			static void StringReplace(string& str, const string& from, const string& to){str; from; to;}
			static string Sanitize(string str){str;}
			ENGINE_SHARED static void Log( Severity severity, const char* message, const char * logFile, int logLine){severity; message; logFile; logLine;}
			ENGINE_SHARED static void shutdown(){}
		#endif
		};
	}
}

//#pragma warning ( default : 4100)

#endif