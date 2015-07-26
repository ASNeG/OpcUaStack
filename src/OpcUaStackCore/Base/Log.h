#ifndef __OpcUaStackCore_Log_h__
#define __OpcUaStackCore_Log_h__

#include <boost/shared_ptr.hpp>
#include <string>
#include <vector>
#include <sstream>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	typedef enum {
		Error,
		Warning,
		Info,
		Debug,
		Trace
	} LogLevel;


	class DLLEXPORT LogHandle
	{
	  public:
	    LogHandle(void);
	    LogHandle(const std::string& logHandleName);
	    ~LogHandle(void);

	    void logHandleName(const std::string& logHandleName);
	    std::string logHandleName(void);

	  private:
	    std::string logHandleName_;
	};


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
		~Log(void);

		template<typename T>
		  Log& parameter(const std::string& parameterName, const T& parameterValue) {
			  std::stringstream ss;
			  ss << parameterValue;
			  format(parameterName, ss.str());
			  return *this;
		  }

		template<typename T1, typename T2>
		  Log& parameter(const std::string& parameterName, const T1& parameterValue1, const T2& parameterValue2) {
			  std::stringstream ss;
			  ss << parameterValue1 << parameterValue2;
			  format(parameterName, ss.str());
			  return *this;
		  }

		template<typename T1, typename T2, typename T3>
		  Log& parameter(
		    const std::string& parameterName,
		    const T1& parameterValue1,
		    const T2& parameterValue2,
		    const T3& parameterValue3
		  ) {
			  std::stringstream ss;
			  ss << parameterValue1 << parameterValue2 << parameterValue3;
			  format(parameterName, ss.str());
			  return *this;
		  }

		template<typename T>
		  Log& parameter(const std::string& parameterName, boost::shared_ptr<T> parameterValueSPtr) {
			  std::stringstream ss;
			  if (parameterValueSPtr.get() != nullptr) ss << *parameterValueSPtr;
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
		LogHandle* logHandle_;
	};

}

#endif
