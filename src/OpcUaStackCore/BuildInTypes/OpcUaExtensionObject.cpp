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

	
};