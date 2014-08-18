#ifndef __OpcUaStackCore_Log_h__
#define __OpcUaStackCore_Log_h__

#include <boost/shared_ptr.hpp>
#include <string>
#include <vector>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	typedef enum {
		Error,
		Warning,
		Info,
		Debug
	} LogLevel;

	class LogIf
	{
	  public:
		virtual bool logout(LogLevel logLevel, const std::string& message) = 0;
	};

	class DLLEXPORT Log
	{
	  public:
		static LogIf* logIf_;
		static void logIf(LogIf* logIf);
		static LogIf* logIf(void);
		static bool logout(LogLevel logLevel, const std::string& message);

		Log(LogLevel logLevel, const std::string& message);
		Log(const std::string& message);
		~Log(void);

		template<typename T>
		  Log& parameter(const std::string& parameterName, const T& parameterValue) {
			  std::stringstream ss;
			  ss << parameterValue;
			  format(parameterName, ss.str());
			  return *this;
		  }

		template<typename T>
		  Log& parameter(const std::string& parameterName, boost::shared_ptr<T> parameterValueSPtr) {
			  std::stringstream ss;
			  if (parameterValueSPtr.get() != nullptr) ss << parameterValue;
			  format(parameterName, ss.str());
			  return *this;
		  }

		template<typename T>
		  Log& parameter(const std::string& parameterName, std::vector<T>& parameterValue) {
			  std::stringstream ss;
			  bool first = true;
			  typename std::vector<T>::iterator it;
			  ss << "[";
			  for (it=parameterValue.begin(); it!=parameterValue.end(); it++) {
				  if (!first) ss << ",";
				  ss << *it;
			  }
			  ss << "]";
			  format(parameterName, ss.str());
			  return *this;
		  }

		template<typename T>
		  Log& parameter(const std::string& parameterName, std::vector<boost::shared_ptr<T> >& parameterValue) {
			  std::stringstream ss;
			  bool first = true;
			  typename std::vector<T>::iterator it;
			  ss << "[";
			  for (it=parameterValue.begin(); it!=parameterValue.end(); it++) {
				  if (!first) ss << ",";
				  ss << **it;
			  }
			  ss << "]";
			  format(parameterName, ss.str());
			  return *this;
		  }

		std::string logLevel(void);

	  private:
		void format(const std::string& parameterName, const std::string& parameterValue);

		LogLevel logLevel_;
		std::string message_;
		std::string parameter_;
	};

}

#endif