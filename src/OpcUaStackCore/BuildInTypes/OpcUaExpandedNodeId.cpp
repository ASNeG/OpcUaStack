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

#include "OpcUaStackCore/BuildInTypes/OpcUaExpandedNodeId.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaExpandedNodeId
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaExpandedNodeId::OpcUaExpandedNodeId(void)
	: Object()
	, OpcUaNodeIdBase()
	, namespaceUri_()
	, serverIndex_()
	{
	}
	
	OpcUaExpandedNodeId::~OpcUaExpandedNodeId(void)
	{
	}

	void 
	OpcUaExpandedNodeId::namespaceUri(OpcUaString& namespaceUri)
	{
		namespaceUri_ = namespaceUri;
	}

	void
	OpcUaExpandedNodeId::namespaceUri(const std::string& namespaceUri)
	{
		namespaceUri_ = namespaceUri;
	}

	OpcUaString& 
	OpcUaExpandedNodeId::namespaceUri(void)
	{
		return namespaceUri_;
	}
		
	void 
	OpcUaExpandedNodeId::serverIndex(OpcUaUInt32 serverIndex)
	{
		serverIndex_ = serverIndex;
	}
		
	OpcUaUInt32 
	OpcUaExpandedNodeId::serverIndex(void)
	{
		return serverIndex_;
	}

	OpcUaByte 
	OpcUaExpandedNodeId::encodingFlag(void) const
	{
		OpcUaByte expandedEncodingFlag = 0x00;
		if (namespaceUri_.exist()) {
			const_cast<OpcUaExpandedNodeId*>(this)->namespaceIndex(0);
			expandedEncodingFlag |= 0x80;
		}
		if (serverIndex_ != 0) expandedEncodingFlag |= 0x40;
		return expandedEncodingFlag;
	}
	
	void 
	OpcUaExpandedNodeId::encodingFlag(OpcUaByte expandedEncodingFlag)
	{
		expandedEncodingFlag_ = expandedEncodingFlag;
	}

	void 
	OpcUaExpandedNodeId::out(std::ostream& os) const
	{
		os << *(OpcUaNodeIdBase*)this;
		if (namespaceUri_.size() > 0) os << ",nu=" << namespaceUri_;
		if (serverIndex_ != 0) os << ",si" << serverIndex_;
	}

	void 
	OpcUaExpandedNodeId::copyTo(OpcUaExpandedNodeId& opcUaExpandedNodeId)
	{
		OpcUaNodeIdBase::copyTo(opcUaExpandedNodeId);
		if (namespaceUri_.size() > 0) opcUaExpandedNodeId.namespaceUri(namespaceUri_);
		if (serverIndex_ != 0) opcUaExpandedNodeId.serverIndex(serverIndex_);
	}
	bool 
	OpcUaExpandedNodeId::operator!=(const OpcUaExpandedNodeId& opcUaExpandedNodeId) const
	{
		return !operator==(opcUaExpandedNodeId);
	}

	bool 
	OpcUaExpandedNodeId::operator==(const OpcUaExpandedNodeId& opcUaExpandedNodeId) const
	{
		return
			namespaceUri_ == const_cast<OpcUaExpandedNodeId*>(&opcUaExpandedNodeId)->namespaceUri() &&
			serverIndex_ == const_cast<OpcUaExpandedNodeId*>(&opcUaExpandedNodeId)->serverIndex() &&
			OpcUaNodeIdBase::operator==(opcUaExpandedNodeId);
	}

	void 
	OpcUaExpandedNodeId::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNodeIdBase::opcUaBinaryEncode(os);
		if (namespaceUri_.size() > 0) namespaceUri_.opcUaBinaryEncode(os);
		if (serverIndex_ != 0) OpcUaNumber::opcUaBinaryEncode(os, serverIndex_);
	}

	void 
	OpcUaExpandedNodeId::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNodeIdBase::opcUaBinaryDecode(is);
		if ((expandedEncodingFlag_ & 0x80) == 0x80) {
			namespaceIndex(0);
			namespaceUri_.opcUaBinaryDecode(is);
		}
		if ((expandedEncodingFlag_ & 0x40) == 0x40) OpcUaNumber::opcUaBinaryDecode(is, serverIndex_);
	}

	bool
	OpcUaExpandedNodeId::encode(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree nodeId;
		if (!OpcUaNodeIdBase::encode(nodeId)) return false;
		pt.put_child("NodeId", nodeId);

		if (namespaceUri_.size() > 0) {
			boost::property_tree::ptree namespaceUri;
			if (!namespaceUri_.encode(namespaceUri)) return false;
			pt.put_child("NamespaceUri", namespaceUri);
		}

		if (serverIndex_ != 0) {
			boost::property_tree::ptree serverIndex;
			if (!Json::encode(serverIndex, serverIndex_)) return false;
			pt.put_child("ServerIndex", serverIndex);
		}

		return true;
	}

	bool
	OpcUaExpandedNodeId::decode(boost::property_tree::ptree& pt)
	{
		// read nodeid
		boost::property_tree::ptree nodeId;
		nodeId = pt.get_child("NodeId");
		if (!OpcUaNodeIdBase::decode(nodeId)) return false;

		// namespace uri
		boost::optional<boost::property_tree::ptree&> namespaceUri;
		namespaceUri = pt.get_child_optional("NamespaceUri");
		if (!namespaceUri) {
			// nothing todo
		}
		else {
			namespaceIndex(0);
			if (!namespaceUri_.decode(*namespaceUri)) return false;
		}

		// server index
		boost::optional<boost::property_tree::ptree&> serverIndex;
		serverIndex = pt.get_child_optional("ServerIndex");
		if (!serverIndex) {
			serverIndex_ = 0;
		}
		else {
			if (!Json::decode(*serverIndex, serverIndex_)) return false;
		}

		return true;
	}

}
