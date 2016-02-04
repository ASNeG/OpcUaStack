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

#include <boost/asio/streambuf.hpp>
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"
#include "OpcUaStackCore/Base/Utility.h"

namespace OpcUaStackCore
{
	
	bool ExtensibleParameter::init_ = false;
	ExtensibleParameterMap ExtensibleParameter::extensibleParameterMap_;

	bool 
	ExtensibleParameter::deregisterFactoryElement(OpcUaUInt32 nodeId, OpcUaUInt16 namespaceIndex) {
		OpcUaNodeId opcUaNodeId;
		opcUaNodeId.set(nodeId, namespaceIndex);
		return deregisterFactoryElement(opcUaNodeId);
	}

	bool 
	ExtensibleParameter::deregisterFactoryElement(const std::string& nodeId, OpcUaUInt16 namespaceIndex) {
		OpcUaNodeId opcUaNodeId;
		opcUaNodeId.set(nodeId, namespaceIndex);
		return deregisterFactoryElement(opcUaNodeId);
	}

	bool 
	ExtensibleParameter::deregisterFactoryElement(OpcUaByte* buf, OpcUaInt32 bufLen, OpcUaUInt16 namespaceIndex) {
		OpcUaNodeId opcUaNodeId;
		opcUaNodeId.set(buf, bufLen, namespaceIndex);
		return deregisterFactoryElement(opcUaNodeId);
	}

	bool 
	ExtensibleParameter::deregisterFactoryElement(OpcUaNodeId& opcUaNodeId) {
		return ExtensibleParameter::deleteElement(opcUaNodeId);
	}

	bool 
	ExtensibleParameter::insertElement(OpcUaNodeId& opcUaNodeId, ExtensibleParameterBase::BSPtr epSPtr)
	{
		ExtensibleParameterMap::iterator it;
		it = extensibleParameterMap_.find(opcUaNodeId);
		if (it != extensibleParameterMap_.end()) {
			return false;
		}
		extensibleParameterMap_.insert(std::make_pair(opcUaNodeId, epSPtr));
		return true;
	}

	bool 
	ExtensibleParameter::deleteElement(OpcUaNodeId& opcUaNodeId)
	{
		ExtensibleParameterMap::iterator it;
		it = extensibleParameterMap_.find(opcUaNodeId);
		if (it == extensibleParameterMap_.end()) {
			return false;
		}
		extensibleParameterMap_.erase(it);
		return true;
	}

	ExtensibleParameterBase::BSPtr 
	ExtensibleParameter::findElement(OpcUaNodeId& opcUaNodeId)
	{
		ExtensibleParameterBase::BSPtr epSPtr;
		ExtensibleParameterMap::iterator it;
		it = extensibleParameterMap_.find(opcUaNodeId);
		if (it != extensibleParameterMap_.end()) {
			epSPtr = it->second;
		}
		return epSPtr;
	}

	ExtensibleParameter::ExtensibleParameter(void)
	: parameterTypeId_()
	, epSPtr_()
	{
	}

	ExtensibleParameter::~ExtensibleParameter(void)
	{
	}

	void
	ExtensibleParameter::clear(void)
	{
		parameterTypeId_.clear();
		epSPtr_.reset();
	}

	OpcUaNodeId& 
	ExtensibleParameter::parameterTypeId(void)
	{
		return parameterTypeId_;
	}

	bool 
	ExtensibleParameter::exist(void)
	{
		if (epSPtr_.get() == NULL) {
			return false;
		}
		return true;
	}

	void 
	ExtensibleParameter::opcUaBinaryEncode(std::ostream& os) const
	{
		if(epSPtr_.get() == NULL)
		{
			OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
			OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
			OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
		} else {
			parameterTypeId_.opcUaBinaryEncode(os);
			OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x01);

			boost::asio::streambuf sb;
			std::ostream osb(&sb);
			epSPtr_->opcUaBinaryEncode(osb);

			OpcUaUInt32 bufferLength = OpcUaStackCore::count(sb);
			OpcUaNumber::opcUaBinaryEncode(os, bufferLength);
			os << osb.rdbuf();
		}
	}

	void 
	ExtensibleParameter::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByte encodingMask;
		parameterTypeId_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, encodingMask);

		ExtensibleParameterMap::iterator it;
		it = extensibleParameterMap_.find(parameterTypeId_);
		if (it == extensibleParameterMap_.end()) {
			return;
		}

		OpcUaUInt32 bufferLength;
		OpcUaNumber::opcUaBinaryDecode(is, bufferLength);
		epSPtr_ = it->second->factory();
		epSPtr_->opcUaBinaryDecode(is);
	}
}
