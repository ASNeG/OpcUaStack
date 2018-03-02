/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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
		std::list<std::string>::const_iterator it;
		for (it = errorList.begin(); it != errorList.end(); it++) {
			errorList_.push_back(*it);
		}
	}

	std::list<std::string>
	OpenSSLError::errorList(void)
	{
		std::list<std::string> errorList = errorList_;
		errorList_.clear();
		return errorList;
	}

	void
	OpenSSLError::log(LogLevel logLevel, const std::string& message)
	{
		std::list<std::string>::iterator it;

		Log log(logLevel, message);
		for (it = errorList_.begin(); it != errorList_.end(); ++it) {
			std::cout << *it << std::endl;
			log.parameter("SSLError", *it);
		}
		errorList_.clear();
	}

}
