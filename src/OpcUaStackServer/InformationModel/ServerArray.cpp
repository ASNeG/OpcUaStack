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
#include "OpcUaStackServer/InformationModel/ServerArray.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	ServerArray::ServerArray(void)
	: informationModel_()
	{
	}
	
	ServerArray::~ServerArray(void)
	{
	}

	void 
	ServerArray::informationModel(InformationModel::SPtr informationModel)
	{
		informationModel_ = informationModel;
	}

	void 
	ServerArray::serverArray(std::vector<std::string>& serverArray)
	{
		OpcUaVariant variant;
		informationModel_->getValue(OpcUaId_Server_ServerArray, AttributeId_Value, variant);
		for (int32_t idx=0; idx<variant.arrayLength(); idx++) {
			OpcUaString::SPtr stringValue = variant.variantSPtr<OpcUaString>((uint32_t)idx);
			serverArray.push_back(stringValue->value());
		}
	}

	bool 
	ServerArray::addServerName(const std::string& serverName)
	{
		OpcUaDataValue dataValue;
		if (!informationModel_->getValue(OpcUaId_Server_ServerArray, AttributeId_Value, dataValue)) {
			return false;
		}

		OpcUaString::SPtr stringValue = boost::make_shared<OpcUaString>();
		*stringValue = serverName;
		dataValue.variant()->pushBack(stringValue);
		dataValue.statusCode(Success);
		dataValue.sourceTimestamp().dateTime(boost::posix_time::microsec_clock::local_time());
		dataValue.serverTimestamp().dateTime(boost::posix_time::microsec_clock::local_time());

		return informationModel_->setValue(OpcUaId_Server_ServerArray, AttributeId_Value, dataValue);

	}

	int32_t 
	ServerArray::getServerIndex(const std::string& serverName)
	{
		std::vector<std::string>::iterator it;
		std::vector<std::string> serverArray;
		this->serverArray(serverArray);

		uint32_t serverIndex = 0;
		for (it = serverArray.begin(); it != serverArray.end(); it++) {
			if (*it == serverName) return serverIndex;
			serverIndex++;
		}

		return -1;
	}

	std::string 
	ServerArray::getServerName(uint32_t serverIndex)
	{
		std::vector<std::string> serverArray;
		this->serverArray(serverArray);

		if (serverIndex >= serverArray.size()) return "";
		return serverArray[serverIndex];
	}

	bool 
	ServerArray::existServerIndex(uint32_t serverIndex)
	{
		std::vector<std::string>::iterator it;
		std::vector<std::string> serverArray;
		this->serverArray(serverArray);

		if (serverArray.size() >= serverIndex) return false;
		return true;
	}
		
	bool 
	ServerArray::existServerName(const std::string& serverName)
	{
		return (getServerIndex(serverName) != -1);
	}
}
