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

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/Server/ServerStatusDataType.h"

namespace OpcUaStackServer
{

	ServerStatusDataType::ServerStatusDataType(void)
	{
	}

	ServerStatusDataType::~ServerStatusDataType(void)
	{
	}

	bool
	ServerStatusDataType::init(InformationModel::SPtr& informationModel)
	{
		// set server status
		{
			OpcUaDataValue dataValue;
			dataValue.variant()->variant((OpcUaInt32)0);
			dataValue.statusCode(Success);
			dataValue.sourceTimestamp().dateTime(boost::posix_time::microsec_clock::local_time());
			dataValue.serverTimestamp().dateTime(boost::posix_time::microsec_clock::local_time());
			bool rc = informationModel->setValue(OpcUaId_Server_ServerStatus_State, AttributeId_Value, dataValue);
		}

		return true;
	}

}
