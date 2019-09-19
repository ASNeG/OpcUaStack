/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#include <sstream>
#include "OpcUaClient/ClientService/ClientServiceExecute.h"


namespace OpcUaClient
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ClientServiceExecute - static
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ClientServiceExecute::ClientServiceFactory ClientServiceExecute::clientServiceFactory_;

	bool
	ClientServiceExecute::addClientService(uint32_t command, ClientServiceBase::SPtr clientServiceBase)
	{
		ClientServiceFactory::iterator it;
		it = clientServiceFactory_.find(command);
		if (it != clientServiceFactory_.end()) return false;
		clientServiceFactory_.insert(std::make_pair(command, clientServiceBase));
		return true;
	}

	ClientServiceBase::SPtr
	ClientServiceExecute::getClientService(uint32_t command)
	{
		ClientServiceFactory::iterator it;
		it = clientServiceFactory_.find(command);
		if (it != clientServiceFactory_.end()) return it->second;
		ClientServiceBase::SPtr clientServiceBase;
		return clientServiceBase;
	}


// ------------------------------------------------------------------------
// ------------------------------------------------------------------------
//
// CommandParser
//
// ------------------------------------------------------------------------
// ------------------------------------------------------------------------
	ClientServiceExecute::ClientServiceExecute(void)
	: errorString_("")
	, clientServiceManager_()
	{
	}

	ClientServiceExecute::~ClientServiceExecute(void)
	{
	}

	bool
	ClientServiceExecute::run(CommandBase::Vec& commandBaseVec)
	{
		for (auto commandBase : commandBaseVec) {
			// find factory element
			auto clientServiceBase = getClientService(commandBase->cmd());
			if (!clientServiceBase) {
				std::stringstream ss;
				ss << "the client service for the command " << commandBase->command() << " is unknown";
				errorString(ss.str());
				return false;
			}

			// run client service
			if (!clientServiceBase->run(clientServiceManager_, commandBase)) {
				std::stringstream ss;
				ss << "client service for command " << commandBase->command() << " error: "
				   << clientServiceBase->errorMessage();
				errorString(ss.str());
				return false;
			}
		}

		return true;
	}

	void
	ClientServiceExecute::errorString(const std::string& errorString)
	{
		errorString_ = errorString;
	}

	std::string&
	ClientServiceExecute::errorString(void)
	{
		return errorString_;
	}

}

