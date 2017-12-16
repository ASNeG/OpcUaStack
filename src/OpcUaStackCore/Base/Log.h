/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

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
		LogIf(void) {}
		virtual ~LogIf(void) {}

		virtual bool logout(LogLevel logLevel, const std::string& message) = 0;
		virtual LogLevel getLogLevel(void) = 0;
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
			  if (!activate_) return *this;
			  std::stringstream ss;
			  ss << parameterValue;
			  format(parameterName, ss.str());
			  return *this;
		  }

		template<typename T1, typename T2>
		  Log& parameter(const std::string& parameterName, const T1& parameterValue1, const T2& parameterValue2) {
			  if (!activate_) return *this;
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
			  if (!activate_) return *this;
			  std::stringstream ss;
			  ss << parameterValue1 << parameterValue2 << parameterValue3;
			  format(parameterName, ss.str());
			  return *this;
		  }

		template<typename T>
		  Log& parameter(const std::string& parameterName, boost::shared_ptr<T> parameterValueSPtr) {
			  if (!activate_) return *this;
			  std::stringstream ss;
			  if (parameterValueSPtr.get() != nullptr) ss << *parameterValueSPtr;
			  format(parameterName, ss.str());
			  return *this;
		  }

		template<typename T>
		  Log& parameter(const std::string& parameterName, std::vector<T>& parameterValue) {
			  if (!activate_) return *this;
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
			  if (!activate_) return *this;
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

		bool activate_;
		LogLevel logLevel_;
		std::string message_;
		std::string parameter_;
		LogHandle* logHandle_;
	};

}

#endif
