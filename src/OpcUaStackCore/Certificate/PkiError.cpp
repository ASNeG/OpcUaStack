/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#include <openssl/err.h>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Certificate/PkiError.h"

namespace OpcUaStackCore
{

	PkiError::PkiError(void)
	: errorList_()
	{
	}

	PkiError::~PkiError(void)
	{
	}

	void
	PkiError::clear(void)
	{
		errorList_.clear();
	}

	void
	PkiError::openSSLError(void)
	{
	    ERR_load_crypto_strings();

	    unsigned long error = ERR_get_error();
	    while (error != 0)
	    {
	    	errorList_.push_back(ERR_error_string(error, NULL));
	        error = ERR_get_error();

	        if (errorList_.size() > 20) {
	        	errorList_.pop_front();
	        }
	    }
	}

	void
	PkiError::openSSLError(const std::string& message)
	{
		errorList_.push_back(message);
	}

	void
	PkiError::getError(std::list<std::string>& errorList)
	{
		errorList = errorList_;
		errorList_.clear();
	}

	void
	PkiError::logError(LogLevel logLevel, const std::string& logMessage)
	{
		Log log(logLevel, logMessage);

		std::list<std::string>::iterator it;
		for (it = errorList_.begin(); it != errorList_.end(); it++) {
			log.parameter("SSLErrorMessage", *it);
		}

		errorList_.clear();
	}

}

