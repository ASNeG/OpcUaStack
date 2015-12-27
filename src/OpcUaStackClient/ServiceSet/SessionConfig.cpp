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


#include "OpcUaStackClient/ServiceSet/SessionConfig.h"


namespace OpcUaStackClient
{

	SessionConfig::SessionConfig(void)
	: applicationDescription_(construct<ApplicationDescription>())
	, sessionName_("urn:127.0.0.1:ASNeG.de:ASNeG-Client")
	, sessionTimeout_(3600000)
	, maxResponseMessageSize_(16777216)
	{
		applicationDescription_->applicationType(ApplicationType_Client);
	}

	SessionConfig::~SessionConfig(void)
	{
	}

}
