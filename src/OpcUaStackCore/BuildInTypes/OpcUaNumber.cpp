#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/ByteOrder.h"

namespace OpcUaStackCore
{

	static uint32_t number = 1;

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaBoolean
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaBoolean& value)
	{
		os.write((char*)&value, 1);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaBoolean& value)
	{	
		is.read((char*)&value, 1);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaBooleanArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaBooleanArray& value)
	{
		value.opcUaBinaryEncode(os);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaBooleanArray& value)
	{	
		value.opcUaBinaryDecode(is);
	}

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaBooleanArray::SPtr& value)
	{
		value->opcUaBinaryEncode(os);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaBooleanArray::SPtr& value)
	{	
		value->opcUaBinaryDecode(is);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaSByte
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaSByte& value)
	{	
		os.write((char*)&value, 1);
	}
	
	void 
	opcUaBinaryDecode(std::istream& is, OpcUaSByte& value)
	{	
		is.read((char*)&value, 1);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaSByteArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaSByteArray& value)
	{	
		value.opcUaBinaryEncode(os);
	}
	
	void 
	opcUaBinaryDecode(std::istream& is, OpcUaSByteArray& value)
	{	
		value.opcUaBinaryDecode(is);
	}

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaSByteArray::SPtr& value)
	{	
		value->opcUaBinaryEncode(os);
	}
	
	void 
	opcUaBinaryDecode(std::istream& is, OpcUaSByteArray::SPtr& value)
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
	opcUaBinaryEncode(std::ostream& os, const OpcUaByte& value)
	{	
		os.write((char*)&value, 1);
	}

	void
	opcUaBinaryDecode(std::istream& is, OpcUaByte& value)
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
	opcUaBinaryEncode(std::ostream& os, const OpcUaByteArray& value)
	{	
		value.opcUaBinaryEncode(os);
	}

	void
	opcUaBinaryDecode(std::istream& is, OpcUaByteArray& value)
	{	
		value.opcUaBinaryDecode(is);
	}

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaByteArray::SPtr& value)
	{	
		value->opcUaBinaryEncode(os);
	}

	void
	opcUaBinaryDecode(std::istream& is, OpcUaByteArray::SPtr& value)
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
	opcUaBinaryEncode(std::ostream& os, const OpcUaInt16& value)
	{	
		opcUaBinaryEncodeNumber(os, value);
	}
	
	void 
	opcUaBinaryDecode(std::istream& is, OpcUaInt16& value)
	{	
		opcUaBinaryDecodeNumber(is, value);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaInt16Array
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaInt16Array& value)
	{	
		value.opcUaBinaryEncode(os);
	}
	
	void 
	opcUaBinaryDecode(std::istream& is, OpcUaInt16Array& value)
	{	
		value.opcUaBinaryDecode(is);
	}

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaInt16Array::SPtr& value)
	{	
		value->opcUaBinaryEncode(os);
	}
	
	void 
	opcUaBinaryDecode(std::istream& is, OpcUaInt16Array::SPtr& value)
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
	opcUaBinaryEncode(std::ostream& os, const OpcUaUInt16& value)
	{	
		opcUaBinaryEncodeNumber(os, value);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaUInt16& value)
	{	
		opcUaBinaryDecodeNumber(is, value);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaUInt16Array
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaUInt16Array& value)
	{	
		value.opcUaBinaryEncode(os);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaUInt16Array& value)
	{	
		value.opcUaBinaryDecode(is);
	}

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaUInt16Array::SPtr& value)
	{	
		value->opcUaBinaryEncode(os);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaUInt16Array::SPtr& value)
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
	opcUaBinaryEncode(std::ostream& os, const OpcUaInt32& value)
	{	
		opcUaBinaryEncodeNumber(os, value);
	}
	
	void 
	opcUaBinaryDecode(std::istream& is, OpcUaInt32& value)
	{
		opcUaBinaryDecodeNumber(is, value);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaInt32Array
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaInt32Array& value)
	{	
		value.opcUaBinaryEncode(os);
	}
	
	void 
	opcUaBinaryDecode(std::istream& is, OpcUaInt32Array& value)
	{
		value.opcUaBinaryDecode(is);
	}

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaInt32Array::SPtr& value)
	{	
		value->opcUaBinaryEncode(os);
	}
	
	void 
	opcUaBinaryDecode(std::istream& is, OpcUaInt32Array::SPtr& value)
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
	opcUaBinaryEncode(std::ostream& os, const OpcUaUInt32& value)
	{	
		opcUaBinaryEncodeNumber(os, value);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaUInt32& value)
	{	
		opcUaBinaryDecodeNumber(is, value);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaUInt32Array
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaUInt32Array& value)
	{	
		value.opcUaBinaryEncode(os);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaUInt32Array& value)
	{	
		value.opcUaBinaryDecode(is);
	}

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaUInt32Array::SPtr& value)
	{	
		value->opcUaBinaryEncode(os);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaUInt32Array::SPtr& value)
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
	opcUaBinaryEncode(std::ostream& os, const OpcUaInt64& value)
	{	
		opcUaBinaryEncodeNumber(os, value);
	}
	
	void 
	opcUaBinaryDecode(std::istream& is, OpcUaInt64& value)
	{	
		opcUaBinaryDecodeNumber(is, value);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaInt64Array
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaInt64Array& value)
	{	
		value.opcUaBinaryEncode(os);
	}
	
	void 
	opcUaBinaryDecode(std::istream& is, OpcUaInt64Array& value)
	{	
		value.opcUaBinaryDecode(is);
	}

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaInt64Array::SPtr& value)
	{	
		value->opcUaBinaryEncode(os);
	}
	
	void 
	opcUaBinaryDecode(std::istream& is, OpcUaInt64Array::SPtr& value)
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
	opcUaBinaryEncode(std::ostream& os, const OpcUaUInt64& value)
	{	
		opcUaBinaryEncodeNumber(os, value);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaUInt64& value)
	{	
		opcUaBinaryDecodeNumber(is, value);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaUInt64Array
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaUInt64Array& value)
	{	
		value.opcUaBinaryEncode(os);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaUInt64Array& value)
	{	
		value.opcUaBinaryDecode(is);
	}

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaUInt64Array::SPtr& value)
	{	
		value->opcUaBinaryEncode(os);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaUInt64Array::SPtr& value)
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
	opcUaBinaryEncode(std::ostream& os, const OpcUaFloat& value)
	{	
		opcUaBinaryEncodeNumber(os, value);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaFloat& value)
	{	
		opcUaBinaryDecodeNumber(is, value);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaFloatArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaFloatArray& value)
	{	
		value.opcUaBinaryEncode(os);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaFloatArray& value)
	{	
		value.opcUaBinaryDecode(is);
	}

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaFloatArray::SPtr& value)
	{	
		value->opcUaBinaryEncode(os);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaFloatArray::SPtr& value)
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
	opcUaBinaryEncode(std::ostream& os, const OpcUaDouble& value)
	{	
		opcUaBinaryEncodeNumber(os, value);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaDouble& value)
	{	
		opcUaBinaryDecodeNumber(is, value);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaDoubleArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaDoubleArray& value)
	{	
		value.opcUaBinaryEncode(os);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaDoubleArray& value)
	{	
		value.opcUaBinaryDecode(is);
	}

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaDoubleArray::SPtr& value)
	{	
		value->opcUaBinaryEncode(os);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaDoubleArray::SPtr& value)
	{	
		value->opcUaBinaryDecode(is);
	}

}
