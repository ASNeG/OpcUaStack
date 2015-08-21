#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/ByteOrder.h"
#include "OpcUaStackCore/BuildInTypes/Json.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaBoolean
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaBoolean& value)
	{
		os.write((char*)&value, 1);
	}

	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaBoolean& value)
	{	
		is.read((char*)&value, 1);
	}

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaBoolean& value)
	{
		return Json::encode(pt, value);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaBoolean& value)
	{
		return Json::decode(pt, value);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaBooleanArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaBooleanArray& value)
	{
		value.opcUaBinaryEncode(os);
	}

	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaBooleanArray& value)
	{	
		value.opcUaBinaryDecode(is);
	}

	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaBooleanArray::SPtr& value)
	{
		value->opcUaBinaryEncode(os);
	}

	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaBooleanArray::SPtr& value)
	{	
		value->opcUaBinaryDecode(is);
	}

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaBooleanArray& value)
	{
		return value.encode(pt);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaBooleanArray& value)
	{
		return value.decode(pt);
	}

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaBooleanArray::SPtr& value)
	{
		return value->encode(pt);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaBooleanArray::SPtr& value)
	{
		return value->decode(pt);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaSByte
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaSByte& value)
	{	
		os.write((char*)&value, 1);
	}
	
	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaSByte& value)
	{	
		is.read((char*)&value, 1);
	}

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaSByte& value)
	{
		return Json::encode(pt, value);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaSByte& value)
	{
		return Json::decode(pt, value);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaSByteArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaSByteArray& value)
	{	
		value.opcUaBinaryEncode(os);
	}
	
	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaSByteArray& value)
	{	
		value.opcUaBinaryDecode(is);
	}

	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaSByteArray::SPtr& value)
	{	
		value->opcUaBinaryEncode(os);
	}
	
	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaSByteArray::SPtr& value)
	{	
		value->opcUaBinaryDecode(is);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaByte
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaByte& value)
	{	
		os.write((char*)&value, 1);
	}

	void
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaByte& value)
	{	
		is.read((char*)&value, 1);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaByteArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaByteArray& value)
	{	
		value.opcUaBinaryEncode(os);
	}

	void
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaByteArray& value)
	{	
		value.opcUaBinaryDecode(is);
	}

	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaByteArray::SPtr& value)
	{	
		value->opcUaBinaryEncode(os);
	}

	void
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaByteArray::SPtr& value)
	{	
		value->opcUaBinaryDecode(is);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaInt16
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaInt16& value)
	{	
		ByteOrder<OpcUaInt16>::opcUaBinaryEncodeNumber(os, value);
	}
	
	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaInt16& value)
	{	
		ByteOrder<OpcUaInt16>::opcUaBinaryDecodeNumber(is, value);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaInt16Array
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaInt16Array& value)
	{	
		value.opcUaBinaryEncode(os);
	}
	
	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaInt16Array& value)
	{	
		value.opcUaBinaryDecode(is);
	}

	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaInt16Array::SPtr& value)
	{	
		value->opcUaBinaryEncode(os);
	}
	
	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaInt16Array::SPtr& value)
	{	
		value->opcUaBinaryDecode(is);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaUInt16
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaUInt16& value)
	{	
		ByteOrder<OpcUaUInt16>::opcUaBinaryEncodeNumber(os, value);
	}

	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaUInt16& value)
	{	
		ByteOrder<OpcUaUInt16>::opcUaBinaryDecodeNumber(is, value);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaUInt16Array
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaUInt16Array& value)
	{	
		value.opcUaBinaryEncode(os);
	}

	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaUInt16Array& value)
	{	
		value.opcUaBinaryDecode(is);
	}

	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaUInt16Array::SPtr& value)
	{	
		value->opcUaBinaryEncode(os);
	}

	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaUInt16Array::SPtr& value)
	{	
		value->opcUaBinaryDecode(is);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaInt32
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaInt32& value)
	{	
		ByteOrder<OpcUaInt32>::opcUaBinaryEncodeNumber(os, value);
	}
	
	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaInt32& value)
	{
		ByteOrder<OpcUaInt32>::opcUaBinaryDecodeNumber(is, value);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaInt32Array
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaInt32Array& value)
	{	
		value.opcUaBinaryEncode(os);
	}
	
	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaInt32Array& value)
	{
		value.opcUaBinaryDecode(is);
	}

	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaInt32Array::SPtr& value)
	{	
		value->opcUaBinaryEncode(os);
	}
	
	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaInt32Array::SPtr& value)
	{
		value->opcUaBinaryDecode(is);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaUInt32
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaUInt32& value)
	{	
		ByteOrder<OpcUaUInt32>::opcUaBinaryEncodeNumber(os, value);
	}

	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaUInt32& value)
	{	
		ByteOrder<OpcUaUInt32>::opcUaBinaryDecodeNumber(is, value);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaUInt32Array
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaUInt32Array& value)
	{	
		value.opcUaBinaryEncode(os);
	}

	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaUInt32Array& value)
	{	
		value.opcUaBinaryDecode(is);
	}

	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaUInt32Array::SPtr& value)
	{	
		value->opcUaBinaryEncode(os);
	}

	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaUInt32Array::SPtr& value)
	{	
		value->opcUaBinaryDecode(is);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaInt64
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaInt64& value)
	{	
		ByteOrder<OpcUaInt64>::opcUaBinaryEncodeNumber(os, value);
	}
	
	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaInt64& value)
	{	
		ByteOrder<OpcUaInt64>::opcUaBinaryDecodeNumber(is, value);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaInt64Array
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaInt64Array& value)
	{	
		value.opcUaBinaryEncode(os);
	}
	
	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaInt64Array& value)
	{	
		value.opcUaBinaryDecode(is);
	}

	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaInt64Array::SPtr& value)
	{	
		value->opcUaBinaryEncode(os);
	}
	
	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaInt64Array::SPtr& value)
	{	
		value->opcUaBinaryDecode(is);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaUInt64
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaUInt64& value)
	{	
		ByteOrder<OpcUaUInt64>::opcUaBinaryEncodeNumber(os, value);
	}

	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaUInt64& value)
	{	
		ByteOrder<OpcUaUInt64>::opcUaBinaryDecodeNumber(is, value);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaUInt64Array
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaUInt64Array& value)
	{	
		value.opcUaBinaryEncode(os);
	}

	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaUInt64Array& value)
	{	
		value.opcUaBinaryDecode(is);
	}

	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaUInt64Array::SPtr& value)
	{	
		value->opcUaBinaryEncode(os);
	}

	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaUInt64Array::SPtr& value)
	{	
		value->opcUaBinaryDecode(is);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaFloat
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaFloat& value)
	{	
		ByteOrder<OpcUaFloat>::opcUaBinaryEncodeNumber(os, value);
	}

	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaFloat& value)
	{	
		ByteOrder<OpcUaFloat>::opcUaBinaryDecodeNumber(is, value);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaFloatArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaFloatArray& value)
	{	
		value.opcUaBinaryEncode(os);
	}

	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaFloatArray& value)
	{	
		value.opcUaBinaryDecode(is);
	}

	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaFloatArray::SPtr& value)
	{	
		value->opcUaBinaryEncode(os);
	}

	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaFloatArray::SPtr& value)
	{	
		value->opcUaBinaryDecode(is);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaDouble
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaDouble& value)
	{	
		ByteOrder<OpcUaDouble>::opcUaBinaryEncodeNumber(os, value);
	}

	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaDouble& value)
	{	
		ByteOrder<OpcUaDouble>::opcUaBinaryDecodeNumber(is, value);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaDoubleArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaDoubleArray& value)
	{	
		value.opcUaBinaryEncode(os);
	}

	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaDoubleArray& value)
	{	
		value.opcUaBinaryDecode(is);
	}

	void 
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaDoubleArray::SPtr& value)
	{	
		value->opcUaBinaryEncode(os);
	}

	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaDoubleArray::SPtr& value)
	{	
		value->opcUaBinaryDecode(is);
	}

}
