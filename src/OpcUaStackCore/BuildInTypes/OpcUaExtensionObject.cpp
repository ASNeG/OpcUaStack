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
	OpcUaExtensionObject::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaStackCore::opcUaBinaryEncode(os, typeId_);
		if (!body_.exist()) {
			OpcUaStackCore::opcUaBinaryEncode(os, (OpcUaByte)0x00);
			OpcUaStackCore::opcUaBinaryEncode(os, (OpcUaInt32)0x00);
		}
		else {
			OpcUaStackCore::opcUaBinaryEncode(os, (OpcUaByte)0x01);
			OpcUaStackCore::opcUaBinaryEncode(os, body_);
		}
	}
		
	void 
	OpcUaExtensionObject::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByte encodingByte;
		OpcUaStackCore::opcUaBinaryDecode(is, typeId_);
		OpcUaStackCore::opcUaBinaryDecode(is, encodingByte);
		if (encodingByte == 0x00) {
			OpcUaInt32 length;
			OpcUaStackCore::opcUaBinaryDecode(is, length);
		}
		else if (encodingByte == 0x01) {
			OpcUaStackCore::opcUaBinaryDecode(is, body_);
		}
		else {
			// FIXME: todo
		}
	}

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaExtensionObject& value)
	{
		value.opcUaBinaryEncode(os);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaExtensionObject& value)
	{
		value.opcUaBinaryDecode(is);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	// 
	// OpcUaExtensionObjectArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void opcUaBinaryEncode(std::ostream& os, const OpcUaExtensionObjectArray& value)
	{
		value.opcUaBinaryEncode(os);
	}

	void opcUaBinaryEncode(std::ostream& os, const OpcUaExtensionObjectArray::SPtr& value)
	{
		value->opcUaBinaryEncode(os);
	}

	void opcUaBinaryDecode(std::istream& is, OpcUaExtensionObjectArray& value)
	{
		value.opcUaBinaryDecode(is);
	}

	void opcUaBinaryDecode(std::istream& is, OpcUaExtensionObjectArray::SPtr& value)
	{
		value->opcUaBinaryDecode(is);
	}

};