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

#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaExtensionObject
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaExtensionObject::OpcUaExtensionObject(void)
	: ObjectPool<OpcUaExtensionObject>()
	, typeId_()
	, body_()
	{
	}
		
	OpcUaExtensionObject::~OpcUaExtensionObject(void)
	{
	}

	void 
	OpcUaExtensionObject::typeId(const OpcUaNodeId& typeId)
	{
		typeId_ = typeId;
	}

	OpcUaNodeId& 
	OpcUaExtensionObject::typeId(void)
	{
		return typeId_;
	}

	void 
	OpcUaExtensionObject::body(const OpcUaByteString& body)
	{
		body_ = body;
	}

	OpcUaByteString& 
	OpcUaExtensionObject::body(void)
	{
		return body_;
	}

	void 
	OpcUaExtensionObject::copyTo(OpcUaExtensionObject& extensionObject)
	{
		typeId_.copyTo(extensionObject.typeId());
		body_.copyTo(extensionObject.body());
	}

	void 
	OpcUaExtensionObject::out(std::ostream& os) const
	{
		// FIXME: todo...
	}

	bool 
	OpcUaExtensionObject::operator!=(const OpcUaExtensionObject& extensionObject) const
	{
		// FIXME: todo
		return true;
	}

	bool 
	OpcUaExtensionObject::operator==(const OpcUaExtensionObject& extensionObject) const
	{
		// FIXME: todo
		return true;
	}

	void 
	OpcUaExtensionObject::opcUaBinaryEncode(std::ostream& os) const
	{
		typeId_.opcUaBinaryEncode(os);
		if (!body_.exist()) {
			OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x00);
			OpcUaNumber::opcUaBinaryEncode(os, (OpcUaInt32)0x00);
		}
		else {
			OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x01);
			body_.opcUaBinaryEncode(os);
		}
	}
		
	void 
	OpcUaExtensionObject::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByte encodingByte;
		typeId_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, encodingByte);
		if (encodingByte == 0x00) {
			OpcUaInt32 length;
			OpcUaNumber::opcUaBinaryDecode(is, length);
		}
		else if (encodingByte == 0x01) {
			body_.opcUaBinaryDecode(is);
		}
	}
	
	bool
	OpcUaExtensionObject::encode(boost::property_tree::ptree& pt) const
	{
		boost::property_tree::ptree typeId;
		if (!typeId_.encode(typeId)) return false;
		pt.put_child("TypeId", typeId);

		if (!body_.exist()) return false;
		if (!body_.encode(pt)) return false;
		return true;
	}

	bool
	OpcUaExtensionObject::decode(boost::property_tree::ptree& pt)
	{
		boost::optional<boost::property_tree::ptree&> typeId;
		typeId = pt.get_child_optional("TypeId");
		if (!typeId) return false;
		if (!typeId_.decode(*typeId)) return false;

		if (!body_.decode(pt)) return false;
		return true;
	}

};
