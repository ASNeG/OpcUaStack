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

#include "OpcUaClient/ClientService/CommandExecute.h"


namespace OpcUaClient
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ClientServiceExecute - static
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	CommandExecute::ClientServiceFactory CommandExecute::clientServiceFactory_;

	bool
	CommandExecute::addClientService(uint32_t command, ClientServiceBase::SPtr clientServiceBase)
	{
		ClientServiceFactory::iterator it;
		it = clientServiceFactory_.find(command);
		if (it != clientServiceFactory_.end()) return false;
		clientServiceFactory_.insert(std::make_pair(command, clientServiceBase));
		return true;
	}

	ClientServiceBase::SPtr
	CommandExecute::getClientService(uint32_t command)
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
	CommandExecute::CommandExecute(void)
	: errorString_("")
	, clientServiceManager_()
	{
	}

	CommandExecute::~CommandExecute(void)
	{
	}

	bool
	CommandExecute::run(CommandBase::Vec& commandBase)
	{
		return true;
	}

	void
	CommandExecute::errorString(const std::string& errorString)
	{
		errorString_ = errorString;
	}

	std::string&
	CommandExecute::errorString(void)
	{
		return errorString_;
	}

}

