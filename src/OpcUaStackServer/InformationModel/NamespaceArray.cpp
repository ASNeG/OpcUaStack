/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackServer/InformationModel/NamespaceArray.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	NamespaceArray::NamespaceArray(void)
	: informationModel_()
	{
	}
	
	NamespaceArray::~NamespaceArray(void)
	{
	}

	void 
	NamespaceArray::informationModel(InformationModel::SPtr informationModel)
	{
		informationModel_ = informationModel;
	}

	void 
	NamespaceArray::namespaceArray(std::vector<std::string>& namespaceArray)
	{
		namespaceArray.clear();

		OpcUaDataValue dataValue;
		if (!informationModel_->getValue(OpcUaId_Server_NamespaceArray, AttributeId_Value, dataValue)) {
			return;
		}
		
		for (int32_t idx=0; idx<dataValue.variant()->arrayLength(); idx++) {
			OpcUaString::SPtr stringValue = dataValue.variant()->variantSPtr<OpcUaString>((uint32_t)idx);
			namespaceArray.push_back(stringValue->value());
		}
	}

	bool 
	NamespaceArray::addNamespaceName(const std::string& namespaceName)
	{
		OpcUaDataValue dataValue;
		if (!informationModel_->getValue(OpcUaId_Server_NamespaceArray, AttributeId_Value, dataValue)) {
			return false;
		}

		OpcUaString::SPtr stringValue = boost::make_shared<OpcUaString>();
		*stringValue = namespaceName;
		dataValue.variant()->pushBack(stringValue);
		dataValue.statusCode(Success);
		dataValue.sourceTimestamp().dateTime(boost::posix_time::microsec_clock::local_time());
		dataValue.serverTimestamp().dateTime(boost::posix_time::microsec_clock::local_time());
		
		return informationModel_->setValue(OpcUaId_Server_NamespaceArray, AttributeId_Value, dataValue);
	}

	bool 
	NamespaceArray::replaceNamespaceNames(std::vector<std::string>& namespaceNameVec)
	{
		OpcUaDataValue dataValue;
		std::vector<std::string>::iterator it;
		for (it = namespaceNameVec.begin(); it != namespaceNameVec.end(); it++) {
			OpcUaString::SPtr stringValue = boost::make_shared<OpcUaString>();
			*stringValue = *it;
			dataValue.variant()->pushBack(stringValue);
		}
		dataValue.statusCode(Success);
		dataValue.sourceTimestamp().dateTime(boost::posix_time::microsec_clock::local_time());
		dataValue.serverTimestamp().dateTime(boost::posix_time::microsec_clock::local_time());
		
		return informationModel_->setValue(OpcUaId_Server_NamespaceArray, AttributeId_Value, dataValue);
	}

	bool 
	NamespaceArray::addNamespaceNames(std::vector<std::string>& namespaceNameVec)
	{
		OpcUaDataValue dataValue;
		if (!informationModel_->getValue(OpcUaId_Server_NamespaceArray, AttributeId_Value, dataValue)) {
			return false;
		}

		std::vector<std::string>::iterator it;
		for (it = namespaceNameVec.begin(); it != namespaceNameVec.end(); it++) {
			OpcUaString::SPtr stringValue = boost::make_shared<OpcUaString>();
			*stringValue = *it;
			dataValue.variant()->pushBack(stringValue);
		}
		dataValue.statusCode(Success);
		dataValue.sourceTimestamp().dateTime(boost::posix_time::microsec_clock::local_time());
		dataValue.serverTimestamp().dateTime(boost::posix_time::microsec_clock::local_time());
		
		return informationModel_->setValue(OpcUaId_Server_NamespaceArray, AttributeId_Value, dataValue);
	}

	int32_t 
	NamespaceArray::getNamespaceIndex(const std::string& namespaceName)
	{
		std::vector<std::string>::iterator it;
		std::vector<std::string> namespaceArray;
		this->namespaceArray(namespaceArray);

		uint32_t namespaceIndex = 0;
		for (it = namespaceArray.begin(); it != namespaceArray.end(); it++) {
			if (*it == namespaceName) return namespaceIndex;
			namespaceIndex++;
		}

		return -1;
	}

	std::string 
	NamespaceArray::getNamespaceName(uint32_t namespaceIndex)
	{
		std::vector<std::string> namespaceArray;
		this->namespaceArray(namespaceArray);

		if (namespaceIndex >= namespaceArray.size()) return "";
		return namespaceArray[namespaceIndex];
	}

	bool 
	NamespaceArray::expandedNodeIdToNodeId(OpcUaExpandedNodeId& expandedNodeId, OpcUaNodeId& nodeId)
	{
		// set namespace index
		int32_t namespaceIndex = getNamespaceIndex(expandedNodeId.namespaceUri().value());
		if (namespaceIndex < 0) return false;
		nodeId.namespaceIndex((uint16_t)namespaceIndex);
	
		// set node identifier
		nodeId.nodeIdValue(expandedNodeId.nodeIdValue());

		return true;
	}

	bool 
	NamespaceArray::existNamespaceIndex(uint32_t namespaceIndex)
	{
		std::vector<std::string>::iterator it;
		std::vector<std::string> namespaceArray;
		this->namespaceArray(namespaceArray);


		if (namespaceIndex >= namespaceArray.size()) return false;
		return true;
	}
		
	bool 
	NamespaceArray::existNamespaceName(const std::string& namespaceName)
	{
		return (getNamespaceIndex(namespaceName) != -1);
	}
}
