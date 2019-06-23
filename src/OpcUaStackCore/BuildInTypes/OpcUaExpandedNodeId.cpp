/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/lexical_cast.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaExpandedNodeId.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"

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
	: OpcUaNodeIdBase()
	, namespaceUri_()
	, serverIndex_()
	, expandedEncodingFlag_(0)
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
		if (serverIndex_ != 0) {
			expandedEncodingFlag |= 0x40;
		}
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
		if (namespaceUri_.exist()) os << ",nsu=" << namespaceUri_;
		if (serverIndex_ != 0) os << ",svr" << serverIndex_;
	}

	void 
	OpcUaExpandedNodeId::copyTo(OpcUaExpandedNodeId& opcUaExpandedNodeId)
	{
		OpcUaNodeIdBase::copyTo(opcUaExpandedNodeId);
		if (namespaceUri_.exist()) {
			opcUaExpandedNodeId.namespaceUri(namespaceUri_);
		}
		if (serverIndex_ != 0) {
			opcUaExpandedNodeId.serverIndex(serverIndex_);
		}
	}
	bool 
	OpcUaExpandedNodeId::operator!=(const OpcUaExpandedNodeId& opcUaExpandedNodeId) const
	{
		return !operator==(opcUaExpandedNodeId);
	}

	bool 
	OpcUaExpandedNodeId::operator==(const OpcUaExpandedNodeId& opcUaExpandedNodeId) const
	{
		if (namespaceUri_.toStdString() != "") {
			if (namespaceUri_ != const_cast<OpcUaExpandedNodeId*>(&opcUaExpandedNodeId)->namespaceUri()) return false;
		}
		else {
			if (namespaceIndex_ != const_cast<OpcUaExpandedNodeId*>(&opcUaExpandedNodeId)->namespaceIndex()) return false;
		}
		if (serverIndex_ != const_cast<OpcUaExpandedNodeId*>(&opcUaExpandedNodeId)->serverIndex()) return false;
		return OpcUaNodeIdBase::operator ==(opcUaExpandedNodeId);
	}

	void 
	OpcUaExpandedNodeId::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNodeIdBase::opcUaBinaryEncode(os);
		if (namespaceUri_.exist()) {
			namespaceUri_.opcUaBinaryEncode(os);
		}
		if (serverIndex_ != 0) {
			OpcUaNumber::opcUaBinaryEncode(os, serverIndex_);
		}
	}

	void 
	OpcUaExpandedNodeId::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNodeIdBase::opcUaBinaryDecode(is);
		if ((expandedEncodingFlag_ & 0x80) == 0x80) {
			namespaceIndex(0);
			namespaceUri_.opcUaBinaryDecode(is);
		}
		if ((expandedEncodingFlag_ & 0x40) == 0x40) {
			OpcUaNumber::opcUaBinaryDecode(is, serverIndex_);
		}
	}

	bool
	OpcUaExpandedNodeId::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(elementTree, xmlns)) {
			Log(Error, "OpcUaExpandedNodeId xml encoder error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(xmlns.addPrefix(element), elementTree));
		return true;
	}

	bool
	OpcUaExpandedNodeId::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		pt.put(xmlns.addPrefix("Identifier"), toString());
		return true;
	}

	bool
	OpcUaExpandedNodeId::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::optional<std::string> sourceValue = pt.get_optional<std::string>(xmlns.addPrefix("Identifier"));
		if (!sourceValue) {
			Log(Error, "OpcUaExpandedNodeId xml decoder error - element not exist in xml document")
				.parameter("Element", "Identifier");
			return false;
		}

		if (!fromString(*sourceValue)) {
			Log(Error, "OpcUaExpandedNodeId xml decoder error - value format error")
				.parameter("Element", "Identifier")
				.parameter("Value", *sourceValue);
			return false;
		}

		return true;
	}

	bool
	OpcUaExpandedNodeId::jsonEncodeImpl(boost::property_tree::ptree& pt) const
	{
		switch (nodeIdType())
		{
			case OpcUaBuildInType_OpcUaString:
			{
				OpcUaUInt32 idType = 1;
				if (!JsonNumber::jsonEncode(pt, idType, "IdType")) {
					Log(Error, "OpcUaNodeId json encode error")
					    .parameter("Element", "IdType");
					return false;
				}
				OpcUaString::SPtr string = boost::get<OpcUaString::SPtr>(nodeIdValue_);
				if (!string->jsonEncode(pt, "Id")) {
					Log(Error, "OpcUaNodeId json encode error")
					    .parameter("Element", "Id");
					return false;
				}
				break;
			}
			case OpcUaBuildInType_OpcUaGuid:
			{
				OpcUaUInt32 idType = 2;
				if (!JsonNumber::jsonEncode(pt, idType, "IdType")) {
					Log(Error, "OpcUaNodeId json encode error")
					    .parameter("Element", "IdType");
					return false;
				}
				OpcUaGuid::SPtr guid = boost::get<OpcUaGuid::SPtr>(nodeIdValue_);
				if (!guid->jsonEncode(pt, "Id")) {
					Log(Error, "OpcUaNodeId json encode error")
					    .parameter("Element", "Id");
					return false;
				}
				break;
			}
			case OpcUaBuildInType_OpcUaByteString:
			{
				OpcUaUInt32 idType = 3;
				if (!JsonNumber::jsonEncode(pt, idType, "IdType")) {
					Log(Error, "OpcUaNodeId json encode error")
					    .parameter("Element", "IdType");
					return false;
				}
				OpcUaByteString::SPtr byteString = boost::get<OpcUaByteString::SPtr>(nodeIdValue_);
				if (!byteString->jsonEncode(pt, "Id")) {
					Log(Error, "OpcUaNodeId json encode error")
						.parameter("Element", "Id");
					return false;
				}
				break;
			}
			default:
			{
				OpcUaUInt32 number = boost::get<OpcUaUInt32>(nodeIdValue_);
				if (!JsonNumber::jsonEncode(pt, number, "Id")) {
					Log(Error, "OpcUaNodeId json encode error")
						.parameter("Element", "Id");
					return false;
				}
				break;
			}
		}

		// add namespace
		if (namespaceUri_.toStdString() != "") {
			namespaceUri_.jsonEncode(pt, "Namespace");
		}
		else if (namespaceIndex_ != 0) {
			JsonNumber::jsonEncode(pt, namespaceIndex_, "Namespace");
		}

		// add serveruri
		if (serverIndex_ != 0) {
			if (!JsonNumber::jsonEncode(pt, serverIndex_, "ServerUri")) {
				Log(Error, "OpcUaNodeId json encode error")
					.parameter("Element", "ServerUri");
				return false;
			}
		}

		return true;
	}

	bool
	OpcUaExpandedNodeId::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		OpcUaUInt32 idType = 0;
		if (!JsonNumber::jsonDecode(pt, idType, "IdType")) {
			idType = 0;
		}

		namespaceUri_ = "";
		OpcUaUInt16 namespaceIndex = 0;
		if (namespaceUri_.jsonDecode(pt, "Namespace")) {

			// check if namespaceUri or namespace index available
			try {
				namespaceIndex = boost::lexical_cast<uint16_t>(namespaceUri_.toStdString());
			} catch (boost::bad_lexical_cast&)
			{
				namespaceIndex = 0;
			}
			if (namespaceIndex != 0) {
				namespaceUri_ = "";
			}
		}

		serverIndex_ = 0;
		if (!JsonNumber::jsonDecode(pt, serverIndex_, "ServerUri")) {
			serverIndex_ = 0;
		}

		switch (idType)
		{
			case 0: // uint32
			{
				OpcUaUInt32 id;
				if (!JsonNumber::jsonDecode(pt, id, "Id")) {
					Log(Error, "OpcUaNodeId json decode error")
					    .parameter("Element", "Id");
					return false;
				}
				set(id, namespaceIndex);
				break;
			}
			case 1: // string
			{
				OpcUaString id;
				if (!id.jsonDecode(pt, "Id")) {
					Log(Error, "OpcUaNodeId json decode error")
					    .parameter("Element", "Id");
					return false;
				}
				set(id, namespaceIndex);
				break;
			}
			case 2: // guid
			{
				OpcUaGuid id;
				if (!id.jsonDecode(pt, "Id")) {
					Log(Error, "OpcUaNodeId json decode error")
					    .parameter("Element", "Id");
					return false;
				}
				set(id, namespaceIndex);
				break;
			}
			case 3: // byte string
			{
				OpcUaByteString id;
				if (!id.jsonDecode(pt, "Id")) {
					Log(Error, "OpcUaNodeId json decode error")
					    .parameter("Element", "Id");
					return false;
				}
				set(id, namespaceIndex);
				break;
			}
			default:
			{
				Log(Error, "OpcUaNodeId json decode error - IdType invalid")
				    .parameter("Element", "Id")
					.parameter("IdType", idType);
				return false;
			}
		}

		return true;
	}

	bool
	OpcUaExpandedNodeId::fromString(const std::string& nodeIdString)
	{
		size_t pos;
		size_t posBegin;
		size_t posEnd;

		//
		// find token "srv=" (optional)
		//
		serverIndex_ = 0;
		pos = nodeIdString.find("svr=");
		if (pos == std::string::npos) {
			posBegin = 0;
			posEnd = 0;
		}
		else {
			posBegin = 4;
			posEnd = nodeIdString.find_first_of(';', posBegin);
			if (posEnd == std::string::npos) {
				return false;
			}

			try {
				serverIndex_ = boost::lexical_cast<uint16_t>(nodeIdString.substr(posBegin, posEnd-posBegin));
			} catch (boost::bad_lexical_cast&)
			{
				return false;
			}
			posBegin = posEnd+1;
		}

		//
		// find token "nsu=" (optional)
		//
		namespaceUri_ = "";
		namespaceIndex_ = 0;
		pos = nodeIdString.find("nsu=", posBegin);
		if (pos != std::string::npos) {
			posBegin = pos+4;
			posEnd = nodeIdString.find_first_of(';', posBegin);

			namespaceUri_ = nodeIdString.substr(posBegin, posEnd-posBegin);

			posBegin = posEnd+1;
		}
		else {
			//
			// find token "ns=" (optional)
			//
			namespaceUri_.reset();

			pos = nodeIdString.find("ns=", posBegin);
			if (pos != std::string::npos) {
				posBegin = pos+3;
				posEnd = nodeIdString.find_first_of(';', posBegin);

				try {
					namespaceIndex_ = boost::lexical_cast<uint16_t>(nodeIdString.substr(posBegin, posEnd-posBegin));
				} catch (boost::bad_lexical_cast&)
				{
					return false;
				}

				posBegin = posEnd+1;
			}
			else {
				return false;
			}
		}

		//
		// find token "i=" (optional)
		//
		pos = nodeIdString.find("i=", posBegin);
		if (pos != std::string::npos) {
			posBegin = pos+2;
			posEnd = nodeIdString.length();

			try {
				uint32_t value = boost::lexical_cast<uint32_t>(nodeIdString.substr(posBegin, posEnd-posBegin));
				nodeId(value);
			} catch (boost::bad_lexical_cast&)
			{
				return false;
			}

			return true;
		}

		//
		// find token "s=" (optional)
		//
		pos = nodeIdString.find("s=", posBegin);
		if (pos != std::string::npos) {
			posBegin = pos+2;
			posEnd = nodeIdString.length();

			try {
				OpcUaString::SPtr value = constructSPtr<OpcUaString>();
				*value = nodeIdString.substr(posBegin, posEnd-posBegin);
				nodeId(value);
			} catch (boost::bad_lexical_cast&)
			{
				return false;
			}

			return true;
		}

		//
		// find token "g=" (optional)
		//
		pos = nodeIdString.find("g=", posBegin);
		if (pos != std::string::npos) {
			posBegin = pos+2;
			posEnd = nodeIdString.length();

			try {
				OpcUaGuid::SPtr value = constructSPtr<OpcUaGuid>();
				*value = nodeIdString.substr(posBegin, posEnd-posBegin);
				nodeId(value);
			} catch (boost::bad_lexical_cast&)
			{
				return false;
			}

			return true;
		}

		return false;
	}

	std::string
	OpcUaExpandedNodeId::toString(void) const
	{
		std::stringstream nodeIdStream;
		if (serverIndex_ != 0) {
			nodeIdStream << "svr=" << serverIndex_ << ";";
		}

		if (namespaceUri_.size() > 0) {
			nodeIdStream << "nsu=" << namespaceUri_ << ";";
		}
		else {
			if (namespaceIndex_ != 0) {
				nodeIdStream << "ns=" << namespaceIndex_ << ";";
			}
		}

		switch(nodeIdType())
		{
			case OpcUaBuildInType_OpcUaUInt32:
			{
				OpcUaUInt32 value;
				OpcUaUInt16 namespaceIndex;

				const_cast<OpcUaExpandedNodeId*>(this)->get(value, namespaceIndex);
				nodeIdStream << "i=" << value;
				break;
			}
			case OpcUaBuildInType_OpcUaString:
			{
				std::string value;
				OpcUaUInt16 namespaceIndex;

				const_cast<OpcUaExpandedNodeId*>(this)->get(value, namespaceIndex);
				nodeIdStream << "s=" << value;
				break;
			}
			case OpcUaBuildInType_OpcUaGuid:
			{
				std::string value;
				OpcUaUInt16 namespaceIndex;

				const_cast<OpcUaExpandedNodeId*>(this)->get(value, namespaceIndex);
				nodeIdStream << "g=" << value;
				break;
			}
			case OpcUaBuildInType_OpcUaByteString:
			{
				OpcUaByteString value;
				OpcUaUInt16 namespaceIndex;

				const_cast<OpcUaExpandedNodeId*>(this)->get(value, namespaceIndex);
				nodeIdStream << "h=" << value;
				break;
			}
            default:
                Log(Error, "Wrong type")
               		.parameter("NodeId", *this)
               		.parameter("NodeType", nodeIdType());
		}
		return nodeIdStream.str();
	}

}
