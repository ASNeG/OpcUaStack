/*
   Copyright 2018-2020 Kai Huebl (kai@huebl-sgh.de)

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

#include <iostream>
#include <openssl/err.h>

#include "OpcUaStackCore/Certificate/OpenSSLError.h"

namespace OpcUaStackCore
{

	OpenSSLError::OpenSSLError(void)
	{
	}

	OpenSSLError::OpenSSLError(const std::list<std::string>& errorList)
	{
		addError(errorList);
	}

	OpenSSLError::~OpenSSLError(void)
	{
		errorList_.clear();
	}

	bool
	OpenSSLError::isError(void)
	{
		return errorList_.size() > 0;
	}

	void
	OpenSSLError::addOpenSSLError(void)
	{
		uint32_t count = 0;

	    unsigned long err = ERR_get_error();
	    while (err != 0 && count < 10)
	    {
	        errorList_.push_back(ERR_error_string(err, NULL));
	        err = ERR_get_error();

	        count++;
	    }
	    ERR_remove_state(0);
	}

	void
	OpenSSLError::addError(const std::string& message)
	{
		errorList_.push_back(message);
	}

	void
	OpenSSLError::addError(const std::list<std::string>& errorList)
	{
		for (auto message : errorList) {
			errorList_.push_back(message);
		}
	}

	std::list<std::string>
	OpenSSLError::errorList(void)
	{
		auto errorList = errorList_;
		errorList_.clear();
		return errorList;
	}

	void
	OpenSSLError::log(LogLevel logLevel, const std::string& message)
	{
		Log log(logLevel, message);
		for (auto message : errorList_) {
			log.parameter("SSLError", message);
		}
		errorList_.clear();
	}

}
