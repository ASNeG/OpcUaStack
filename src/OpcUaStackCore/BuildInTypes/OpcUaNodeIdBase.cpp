/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#include <boost/lexical_cast.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeIdBase.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"
#include <sstream>

namespace OpcUaStackCore
{

	class OpcUaTypeVisitor : public boost::static_visitor<>
	{
	  public:
		void operator()(OpcUaNodeIdNullType) { opcUaBuildInType_ = OpcUaBuildInType_Unknown; }
		void operator()(OpcUaUInt32) { opcUaBuildInType_ = OpcUaBuildInType_OpcUaUInt32; }
		void operator()(OpcUaString::SPtr) { opcUaBuildInType_ = OpcUaBuildInType_OpcUaString; }
		void operator()(OpcUaGuid::SPtr) { opcUaBuildInType_ = OpcUaBuildInType_OpcUaGuid; }
		void operator()(OpcUaByteString::SPtr) { opcUaBuildInType_ = OpcUaBuildInType_OpcUaByteString; }

		OpcUaBuildInType opcUaBuildInType_;
	};


	OpcUaNodeIdBase::OpcUaNodeIdBase(void)
	: Object()
	, namespaceIndex_(0)
	, nodeIdValue_()
	{
	}

	OpcUaNodeIdBase::OpcUaNodeIdBase(const OpcUaNodeIdBase& nodeId)
	: Object()
	, namespaceIndex_(nodeId.namespaceIndex_)
	, nodeIdValue_(nodeId.nodeIdValue_)
	{
	}

	OpcUaNodeIdBase::OpcUaNodeIdBase(OpcUaUInt32 nodeId, OpcUaUInt16 namespaceIndex)
	: Object()
	, namespaceIndex_(0)
	, nodeIdValue_()
	{
		set(nodeId, namespaceIndex);
	}

	OpcUaNodeIdBase::OpcUaNodeIdBase(const std::string& nodeId, OpcUaUInt16 namespaceIndex)
	: Object()
	, namespaceIndex_(0)
	, nodeIdValue_()
	{
		set(nodeId, namespaceIndex);
	}

	OpcUaNodeIdBase::~OpcUaNodeIdBase(void)
	{
	}

	void
	OpcUaNodeIdBase::reset(void)
	{
		namespaceIndex_ = 0;
		nodeIdValue_ = OpcUaNodeIdValue();
	}

	OpcUaNodeIdValue&
	OpcUaNodeIdBase::nodeIdValue(void)
	{
		return nodeIdValue_;
	}
	
	void 
	OpcUaNodeIdBase::nodeIdValue(OpcUaNodeIdValue& nodeIdValue)
	{
		nodeIdValue_ = nodeIdValue;
	}

	void 
	OpcUaNodeIdBase::namespaceIndex(OpcUaUInt16 namespaceIndex)
	{
		namespaceIndex_ = namespaceIndex;
	}

	OpcUaInt16 
	OpcUaNodeIdBase::namespaceIndex(void) const
	{
		return namespaceIndex_;
	}

	OpcUaBuildInType 
	OpcUaNodeIdBase::nodeIdType(void) const
	{
		OpcUaTypeVisitor opcUaTypeVisitor;
		boost::apply_visitor(opcUaTypeVisitor, nodeIdValue_);
		return opcUaTypeVisitor.opcUaBuildInType_;
	}

	void 
	OpcUaNodeIdBase::set(OpcUaUInt32 nodeId, OpcUaUInt16 namespaceIndex)
	{
		namespaceIndex_ = namespaceIndex;
		nodeIdValue_ = nodeId;
	}

	void 
	OpcUaNodeIdBase::set(const std::string& nodeId, OpcUaUInt16 namespaceIndex)
	{
		if (nodeId.length() == 36 && nodeId.substr(8,1) == "-" && nodeId.substr(13,1) == "-" && nodeId.substr(18,1) == "-" && nodeId.substr(23,1) == "-") {
			OpcUaGuid::SPtr opcUaGuidSPtr = boost::make_shared<OpcUaGuid>();
			*opcUaGuidSPtr = nodeId;
			nodeIdValue_ = opcUaGuidSPtr;
		}
		else {
			OpcUaString::SPtr opcUaStringSPtr = boost::make_shared<OpcUaString>();
			*opcUaStringSPtr = nodeId;
			nodeIdValue_ = opcUaStringSPtr;
		}
		namespaceIndex_ = namespaceIndex;
	}

	void
	OpcUaNodeIdBase::set(const OpcUaString& nodeId, OpcUaUInt16 namespaceIndex)
	{
		set(nodeId.value(), namespaceIndex);
	}

	void
	OpcUaNodeIdBase::set(const OpcUaGuid& nodeId, OpcUaUInt16 namespaceIndex)
	{
		OpcUaGuid::SPtr opcUaGuidSPtr = boost::make_shared<OpcUaGuid>();
		*opcUaGuidSPtr = nodeId;
		nodeIdValue_ = opcUaGuidSPtr;
		namespaceIndex_ = namespaceIndex;
	}

	void
	OpcUaNodeIdBase::set(const OpcUaByteString& nodeId, OpcUaUInt16 namespaceIndex)
	{
		OpcUaByteString::SPtr opcUaByteStringSPtr = boost::make_shared<OpcUaByteString>();
		*opcUaByteStringSPtr = nodeId;
		nodeIdValue_ = opcUaByteStringSPtr;
		namespaceIndex_ = namespaceIndex;
	}

	void
	OpcUaNodeIdBase::set(const OpcUaNodeIdNullType& nodeId)
	{
		setNull();
	}

	void 
	OpcUaNodeIdBase::set(OpcUaByte* buf, OpcUaInt32 bufLen, OpcUaUInt16 namespaceIndex)
	{
		OpcUaByteString::SPtr opcUaByteStringSPtr = boost::make_shared<OpcUaByteString>();
		opcUaByteStringSPtr->value(buf, bufLen);
		namespaceIndex_ = namespaceIndex;
		nodeIdValue_ = opcUaByteStringSPtr;
	}

	bool 
	OpcUaNodeIdBase::get(OpcUaUInt32& nodeId, OpcUaUInt16& namespaceIndex)
	{
		if (nodeIdType() != OpcUaBuildInType_OpcUaUInt32) {
			return false;
		}

		namespaceIndex = namespaceIndex_;
		nodeId = boost::get<OpcUaUInt32>(nodeIdValue_);
		return true;
	}

	bool 
	OpcUaNodeIdBase::get(std::string& nodeId, OpcUaUInt16& namespaceIndex)
	{
		namespaceIndex = namespaceIndex_;
		if (nodeIdType() == OpcUaBuildInType_OpcUaString) {
			OpcUaString::SPtr opcUaStringSPtr;
			opcUaStringSPtr = boost::get<OpcUaString::SPtr>(nodeIdValue_);
			nodeId = opcUaStringSPtr->value();
		}
		else if (nodeIdType() == OpcUaBuildInType_OpcUaGuid) {
			OpcUaGuid::SPtr opcUaGuidSPtr;
			opcUaGuidSPtr = boost::get<OpcUaGuid::SPtr>(nodeIdValue_); 
			nodeId = opcUaGuidSPtr->value();
		}
		else {
			return false;
		}
		return true;
	}

	bool
	OpcUaNodeIdBase::get(OpcUaByteString& nodeId, OpcUaUInt16& namespaceIndex)
	{
		if (nodeIdType() != OpcUaBuildInType_OpcUaByteString) {
			return false;
		}

		namespaceIndex = namespaceIndex_;
		OpcUaByteString::SPtr opcUaByteStringSPtr;
		opcUaByteStringSPtr = boost::get<OpcUaByteString::SPtr>(nodeIdValue_);
		opcUaByteStringSPtr->copyTo(nodeId);
		return true;
	}

	bool 
	OpcUaNodeIdBase::get(OpcUaByte** buf, OpcUaInt32* bufLen, OpcUaUInt16& namespaceIndex)
	{
		if (nodeIdType() != OpcUaBuildInType_OpcUaByteString) {
			return false;
		}

		namespaceIndex = namespaceIndex_;
		OpcUaByteString::SPtr opcUaByteStringSPtr;
		opcUaByteStringSPtr = boost::get<OpcUaByteString::SPtr>(nodeIdValue_);
		opcUaByteStringSPtr->value(buf, bufLen);
		return true;
	}

	void
	OpcUaNodeIdBase::copyFrom(const OpcUaNodeIdBase& opcUaNodeIdBase)
	{
		const_cast<OpcUaNodeIdBase*>(&opcUaNodeIdBase)->copyTo(*this);
	}

	void 
	OpcUaNodeIdBase::copyTo(OpcUaNodeIdBase& opcUaNodeIdBase) 
	{
		opcUaNodeIdBase.namespaceIndex(namespaceIndex_);

		OpcUaBuildInType type =  nodeIdType();
		switch(type)
		{
			case OpcUaBuildInType_OpcUaUInt32:
			{
				OpcUaUInt32 value = boost::get<OpcUaUInt32>(nodeIdValue_);
				opcUaNodeIdBase.nodeId(value);
				break;
			}
			case OpcUaBuildInType_OpcUaString:
			{
				OpcUaString::SPtr value = boost::get<OpcUaString::SPtr>(nodeIdValue_);
				OpcUaString::SPtr newValue = boost::make_shared<OpcUaString>();
				value->copyTo(*newValue);
				opcUaNodeIdBase.nodeId(newValue);
				break;
			}
			case OpcUaBuildInType_OpcUaGuid:
			{
				OpcUaGuid::SPtr value = boost::get<OpcUaGuid::SPtr>(nodeIdValue_);
				OpcUaGuid::SPtr newValue = boost::make_shared<OpcUaGuid>();
				value->copyTo(*newValue);
				opcUaNodeIdBase.nodeId(newValue);
				break;
			}
			case OpcUaBuildInType_OpcUaByteString:
			{
				OpcUaByteString::SPtr value = boost::get<OpcUaByteString::SPtr>(nodeIdValue_);
				OpcUaByteString::SPtr newValue = boost::make_shared<OpcUaByteString>();
				value->copyTo(*newValue);
				opcUaNodeIdBase.nodeId(newValue);
				break;
			}
			default:
				Log(Error, "Unknown type").parameter("TypeId", type);
		}
	}

	bool 
	OpcUaNodeIdBase::operator!=(const OpcUaNodeIdBase& opcUaNodeId) const
	{
		return !operator==(opcUaNodeId);
	}

	bool 
	OpcUaNodeIdBase::operator==(const OpcUaNodeIdBase& opcUaNodeIdBase) const
	{
		return ((opcUaNodeIdBase < *this) == false) &&  ((*this < opcUaNodeIdBase) == false);
	}

	bool 
	OpcUaNodeIdBase::operator<(const OpcUaNodeIdBase& opcUaNodeIdBase) const
	{
		if (namespaceIndex() < opcUaNodeIdBase.namespaceIndex()) {
			return true;
		}

		if (opcUaNodeIdBase.namespaceIndex() < namespaceIndex()) {
			return false;
		}

		if (nodeIdType() < opcUaNodeIdBase.nodeIdType()) {
			return true;
		}

		if (opcUaNodeIdBase.nodeIdType() < nodeIdType()) {
			return false;
		}

		switch(nodeIdType())
		{
			case OpcUaBuildInType_OpcUaUInt32:
			{
				OpcUaUInt32 value1 = boost::get<OpcUaUInt32>(nodeIdValue_);
				OpcUaUInt32 value2 = opcUaNodeIdBase.nodeId<OpcUaUInt32>();
				return value1 < value2;
				break;
			}
			case OpcUaBuildInType_OpcUaString:
			{
				OpcUaString::SPtr value1 = boost::get<OpcUaString::SPtr>(nodeIdValue_);
				OpcUaString::SPtr value2 = opcUaNodeIdBase.nodeId<OpcUaString::SPtr>();

				if (value1.get() == NULL && value2.get() == NULL) return false;
				if (value1.get() != NULL && value2.get() == NULL) return false;
				if (value1.get() == NULL && value2.get() != NULL) return true;
				return *value1 < *value2;
				break;
			}
			case OpcUaBuildInType_OpcUaGuid:
			{
				OpcUaGuid::SPtr value1 = boost::get<OpcUaGuid::SPtr>(nodeIdValue_);
				OpcUaGuid::SPtr value2 = opcUaNodeIdBase.nodeId<OpcUaGuid::SPtr>();

				if (value1.get() == NULL && value2.get() == NULL) return false;
				if (value1.get() != NULL && value2.get() == NULL) return false;
				if (value1.get() == NULL && value2.get() != NULL) return true;
				return *value1 < *value2;
				break;
			}
			case OpcUaBuildInType_OpcUaByteString:
			{
				OpcUaByteString::SPtr value1 = boost::get<OpcUaByteString::SPtr>(nodeIdValue_);
				OpcUaByteString::SPtr value2 = opcUaNodeIdBase.nodeId<OpcUaByteString::SPtr>();

				if (value1.get() == NULL && value2.get() == NULL) return false;
				if (value1.get() != NULL && value2.get() == NULL) return false;
				if (value1.get() == NULL && value2.get() != NULL) return true;
				return *value1 < *value2;
				break;
			}

			default: Log(Error, "Unknown type").parameter("TypeId", nodeIdType());
		}

		return false;
	}

	bool
	OpcUaNodeIdBase::isNull(void) const
	{
		if (nodeIdType() == OpcUaBuildInType_Unknown) {
			return true;
		}
		return false;
	}

    void
	OpcUaNodeIdBase::setNull(void)
    {
		namespaceIndex_ = 0;
		nodeIdValue_ = OpcUaNodeIdNullType();
    }

	OpcUaByte 
	OpcUaNodeIdBase::encodingFlag(void) const
	{
		return 0x00;
	}
		
	void 
	OpcUaNodeIdBase::encodingFlag(OpcUaByte expandedEncodingFlag)
	{
	}

	void
	OpcUaNodeIdBase::out(std::ostream& os)
	{
		os << *this;
	}

	bool
	OpcUaNodeIdBase::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		OpcUaBuildInType type =  nodeIdType();
		OpcUaByte ef = encodingFlag();

		if (type == OpcUaBuildInType_Unknown) {
			//
			// The type of the node identifier is unknown. We generate a
			// default variable.
			//

			OpcUaUInt32 nodeId = 0;
			OpcUaUInt16 namespaceIndex = 0;
			const_cast<OpcUaNodeIdBase*>(this)->set(nodeId, namespaceIndex);
			type =  nodeIdType();
		}

		if (namespaceIndex_ == 0 && type == OpcUaBuildInType_OpcUaUInt32) {
			OpcUaUInt32 identifier = boost::get<OpcUaUInt32>(nodeIdValue_);

			if (identifier <= 0xFF) {

				//
				// The numeric value fits into the two byte representation
				//

				OpcUaByte encodingMask = 0x00+ef;
				rc &= OpcUaNumber::opcUaBinaryEncode(os, encodingMask);
				rc &= OpcUaNumber::opcUaBinaryEncode(os, (OpcUaStackCore::OpcUaByte)identifier);
				return rc;
			}
		}

		if (namespaceIndex_ <= 0xFF && type == OpcUaBuildInType_OpcUaUInt32) {
			OpcUaUInt32 identifier = boost::get<OpcUaUInt32>(nodeIdValue_);
			if (identifier <= 0xFFFF) {

				//
				// The numeric value fits into the four byte representation
				//

				OpcUaByte encodingMask = 0x01+ef;
				rc &= OpcUaNumber::opcUaBinaryEncode(os, encodingMask);
				rc &= OpcUaNumber::opcUaBinaryEncode(os, (OpcUaStackCore::OpcUaByte)namespaceIndex_);
				rc &= OpcUaNumber::opcUaBinaryEncode(os, (OpcUaStackCore::OpcUaUInt16)identifier);
				return rc;
			}
		}

		switch(type)
		{
			case OpcUaBuildInType_OpcUaUInt32:
			{
				OpcUaByte encodingMask = 0x02+ef;
				rc &= OpcUaNumber::opcUaBinaryEncode(os, encodingMask);
				rc &= OpcUaNumber::opcUaBinaryEncode(os, namespaceIndex_);
				rc &= OpcUaNumber::opcUaBinaryEncode(os, boost::get<OpcUaUInt32>(nodeIdValue_));
				break;
			}
			case OpcUaBuildInType_OpcUaString:
			{
				OpcUaByte encodingMask = 0x03+ef;
				rc &= OpcUaNumber::opcUaBinaryEncode(os, encodingMask);
				rc &=  OpcUaNumber::opcUaBinaryEncode(os, namespaceIndex_);
				rc &= boost::get<OpcUaString::SPtr>(nodeIdValue_)->opcUaBinaryEncode(os);
				break;
			}
			case OpcUaBuildInType_OpcUaGuid:
			{
				OpcUaByte encodingMask = 0x04+ef;
				rc &= OpcUaNumber::opcUaBinaryEncode(os, encodingMask);
				rc &= OpcUaNumber::opcUaBinaryEncode(os, namespaceIndex_);
				rc &= boost::get<OpcUaGuid::SPtr>(nodeIdValue_)->opcUaBinaryEncode(os);
				break;
			}
			case OpcUaBuildInType_OpcUaByteString:
			{
				OpcUaByte encodingMask = 0x05+ef;
				rc &= OpcUaNumber::opcUaBinaryEncode(os, encodingMask);
				rc &= OpcUaNumber::opcUaBinaryEncode(os, namespaceIndex_);
				rc &= boost::get<OpcUaByteString::SPtr>(nodeIdValue_)->opcUaBinaryEncode(os);
				break;
			}
			default:
			{
				rc = false;
				Log(Error, "Unknown type").parameter("TypeId", nodeIdType());
			}
		}
		return rc;
	}

	bool
	OpcUaNodeIdBase::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		OpcUaByte encodingByte;
		rc &= OpcUaNumber::opcUaBinaryDecode(is, encodingByte);

		OpcUaByte ef = encodingByte & 0xF0;
		encodingFlag(ef);
		encodingByte &= 0x0F;

		switch (encodingByte)
		{
			case 0x00:
			{
				OpcUaByte identifier;
				namespaceIndex_ = 0;
				rc &= OpcUaNumber::opcUaBinaryDecode(is, identifier);
				nodeIdValue_ = (OpcUaInt32)identifier;
				break;
			}
			case 0x01:
			{
				OpcUaByte namespaceIndex;
				OpcUaUInt16 identifier;
				rc &= OpcUaNumber::opcUaBinaryDecode(is, namespaceIndex);
				rc &= OpcUaNumber::opcUaBinaryDecode(is, identifier);
				namespaceIndex_ = namespaceIndex;
				nodeIdValue_ = (OpcUaInt32)identifier;
				break;
			}
			case 0x02:
			{
				OpcUaInt32 value;
				rc &= OpcUaNumber::opcUaBinaryDecode(is, namespaceIndex_);
				rc &= OpcUaNumber::opcUaBinaryDecode(is, value);
				nodeIdValue_ = value;
				break;
			}
			case 0x03:
			{
				OpcUaString::SPtr value = boost::make_shared<OpcUaString>();
				rc &= OpcUaNumber::opcUaBinaryDecode(is, namespaceIndex_);
				rc &= value->opcUaBinaryDecode(is);
				nodeIdValue_ = value;
				break;
			}
			case 0x04:
			{
				OpcUaGuid::SPtr value = boost::make_shared<OpcUaGuid>();
				rc &= OpcUaNumber::opcUaBinaryDecode(is, namespaceIndex_);
				rc &= value->opcUaBinaryDecode(is);
				nodeIdValue_ = value;
				break;
			}
			case 0x05:
			{
				OpcUaByteString::SPtr value = boost::make_shared<OpcUaByteString>();
				rc &= OpcUaNumber::opcUaBinaryDecode(is, namespaceIndex_);
				rc &= value->opcUaBinaryDecode(is);
				nodeIdValue_ = value;
				break;
			}
		}

		return rc;
	}

	bool
	OpcUaNodeIdBase::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(elementTree, xmlns)) {
			Log(Error, "OpcUaNodeId xml encoder error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(xmlns.addPrefix(element), elementTree));
		return true;
	}

	bool
	OpcUaNodeIdBase::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		pt.put(xmlns.addPrefix("Identifier"), toString());
		return true;
	}

	bool
	OpcUaNodeIdBase::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::optional<std::string> sourceValue = pt.get_optional<std::string>(xmlns.addPrefix("Identifier"));
		if (!sourceValue) {
			Log(Error, "OpcUaNodeId xml decoder error - element not exist in xml document")
				.parameter("Element", "Identifier");
			return false;
		}
		return fromString(*sourceValue);
	}

	bool
	OpcUaNodeIdBase::jsonEncodeImpl(boost::property_tree::ptree &pt) const
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
		if (namespaceIndex_ != 0) {
			JsonNumber::jsonEncode(pt, namespaceIndex_, "Namespace");
		}
		return true;
	}

	bool
	OpcUaNodeIdBase::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		OpcUaUInt32 idType = 0;
		if (!JsonNumber::jsonDecode(pt, idType, "IdType")) {
			idType = 0;
		}

		OpcUaUInt16 namespaceIndex = 0;
		if (!JsonNumber::jsonDecode(pt, namespaceIndex, "Namespace")) {
			namespaceIndex = 0;
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
	OpcUaNodeIdBase::fromString(const std::string& nodeIdString)
	{
		size_t pos;
		size_t posBegin;
		size_t posEnd;

		//
		// find token "ns=" (optional)
		//
		namespaceIndex_ = 0;
		pos = nodeIdString.find("ns=");
		if (pos == std::string::npos) {
			posBegin = 0;
			posEnd = 0;
		}
		else {
			posBegin = 3;
			posEnd = nodeIdString.find_first_of(';', posBegin);
			if (posEnd == std::string::npos) {
				return false;
			}

			try {
				namespaceIndex_ = boost::lexical_cast<uint16_t>(nodeIdString.substr(posBegin, posEnd-posBegin));
			} catch (boost::bad_lexical_cast&)
			{
				return false;
			}
			posBegin = posEnd+1;
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
				OpcUaString::SPtr value = boost::make_shared<OpcUaString>();
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
				OpcUaGuid::SPtr value = boost::make_shared<OpcUaGuid>();
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
	OpcUaNodeIdBase::toString(void) const
	{
		std::stringstream nodeIdStream;
		if (namespaceIndex_ != 0) {
			nodeIdStream << "ns=" << namespaceIndex_ << ";";
		}

		switch(nodeIdType())
		{
			case OpcUaBuildInType_OpcUaUInt32:
			{
				OpcUaUInt32 value = boost::get<OpcUaUInt32>(nodeIdValue_);
				nodeIdStream << "i=" << value;
				break;
			}
			case OpcUaBuildInType_OpcUaString:
			{
				OpcUaString::SPtr value = boost::get<OpcUaString::SPtr>(nodeIdValue_);
				if (value.get() != nullptr) {
					std::string str = *value;
					nodeIdStream << "s=" << str;
				}
				break;
			}
			case OpcUaBuildInType_OpcUaGuid:
			{
				OpcUaGuid::SPtr value = boost::get<OpcUaGuid::SPtr>(nodeIdValue_);
				if (value.get() != nullptr) {
					std::string str = *value;
					nodeIdStream << "g=" << str;
				}
				break;
			}
			case OpcUaBuildInType_OpcUaByteString:
			{
				OpcUaByteString::SPtr value = boost::get<OpcUaByteString::SPtr>(nodeIdValue_);
				if (value.get() != nullptr) {
					std::string str = value->toHexString();
					nodeIdStream << "h=" << str;
				}
				break;
			}
			default: Log(Error, "Unknown type").parameter("TypeId", nodeIdType());
		}

		return nodeIdStream.str();
	}

}
