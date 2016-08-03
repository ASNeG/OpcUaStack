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

#define REAL_SERVER_URI "opt.tcp://127.0.0.1:8889"
#define REAL_SESSION_NAME "urn:127.0.0.1:ASNeG.de:ASNeG-Client"

#include "OpcUaStackClient/ValueBasedInterface/VBIClient.h"

int main(int argc, char**argv)
{
	OpcUaStatusCode statusCode;
	VBIClient client;
	ConnectContext connectContext;

	// connect to opc ua server
	connectContext.endpointUrl_ = REAL_SERVER_URI;
	connectContext.sessionName_ = REAL_SESSION_NAME;
	statusCode = client.syncConnect(connectContext);
	if (statusCode != Success) {
		std::cout << "connect to opc ua server error" << std::endl;
		return -1;
	}

	std::cout << "connect to opc ua server success" << std::endl;
}
