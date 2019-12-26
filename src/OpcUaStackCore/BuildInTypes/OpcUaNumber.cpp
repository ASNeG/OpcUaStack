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
	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaBoolean& value)
	{
		os.write((char*)&value, 1);
		return os.good();
	}

	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaBoolean& value)
	{	
		is.read((char*)&value, 1);
		return is.good();
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaBooleanArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaBooleanArray& value)
	{
		return value.opcUaBinaryEncode(os);
	}

	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaBooleanArray& value)
	{	
		return value.opcUaBinaryDecode(is);
	}

	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaBooleanArray::SPtr& value)
	{
		return value->opcUaBinaryEncode(os);
	}

	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaBooleanArray::SPtr& value)
	{	
		return value->opcUaBinaryDecode(is);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaSByte
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaSByte& value)
	{	
		os.write((char*)&value, 1);
		return os.good();
	}
	
	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaSByte& value)
	{	
		is.read((char*)&value, 1);
		return is.good();
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaSByteArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaSByteArray& value)
	{	
		return value.opcUaBinaryEncode(os);
	}
	
	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaSByteArray& value)
	{	
		return value.opcUaBinaryDecode(is);
	}

	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaSByteArray::SPtr& value)
	{	
		return value->opcUaBinaryEncode(os);
	}
	
	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaSByteArray::SPtr& value)
	{	
		return value->opcUaBinaryDecode(is);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaByte
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaByte& value)
	{	
		os.write((char*)&value, 1);
		return os.good();
	}

	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaByte& value)
	{	
		is.read((char*)&value, 1);
		return is.good();
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaByteArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaByteArray& value)
	{	
		return value.opcUaBinaryEncode(os);
	}

	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaByteArray& value)
	{	
		return value.opcUaBinaryDecode(is);
	}

	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaByteArray::SPtr& value)
	{	
		return value->opcUaBinaryEncode(os);
	}

    bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaByteArray::SPtr& value)
	{	
		return value->opcUaBinaryDecode(is);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaInt16
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaInt16& value, bool littleEndian)
	{	
		if (littleEndian) {
			return ByteOrder<OpcUaInt16>::opcUaBinaryEncodeNumberLE(os, value);
		}
		else {
			return ByteOrder<OpcUaInt16>::opcUaBinaryEncodeNumberBE(os, value);
		}
	}
	
	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaInt16& value, bool littleEndian)
	{	
		if (littleEndian) {
			return ByteOrder<OpcUaInt16>::opcUaBinaryDecodeNumberLE(is, value);
		}
		else {
			return ByteOrder<OpcUaInt16>::opcUaBinaryDecodeNumberBE(is, value);
		}
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaInt16Array
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaInt16Array& value)
	{	
		return value.opcUaBinaryEncode(os);
	}
	
	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaInt16Array& value)
	{	
		return value.opcUaBinaryDecode(is);
	}

	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaInt16Array::SPtr& value)
	{	
		return value->opcUaBinaryEncode(os);
	}
	
	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaInt16Array::SPtr& value)
	{	
		return value->opcUaBinaryDecode(is);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaUInt16
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaUInt16& value, bool littleEndian)
	{	
		if (littleEndian) {
			return ByteOrder<OpcUaUInt16>::opcUaBinaryEncodeNumberLE(os, value);
		}
		else {
			return ByteOrder<OpcUaUInt16>::opcUaBinaryEncodeNumberBE(os, value);
		}
	}

	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaUInt16& value, bool littleEndian)
	{	
		if (littleEndian) {
			return ByteOrder<OpcUaUInt16>::opcUaBinaryDecodeNumberLE(is, value);
		}
		else {
			return ByteOrder<OpcUaUInt16>::opcUaBinaryDecodeNumberBE(is, value);
		}
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaUInt16Array
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaUInt16Array& value)
	{	
		return value.opcUaBinaryEncode(os);
	}

	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaUInt16Array& value)
	{	
		return value.opcUaBinaryDecode(is);
	}

	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaUInt16Array::SPtr& value)
	{	
		return value->opcUaBinaryEncode(os);
	}

	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaUInt16Array::SPtr& value)
	{	
		return value->opcUaBinaryDecode(is);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaInt32
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaInt32& value, bool littleEndian)
	{	
		if (littleEndian) {
			return ByteOrder<OpcUaInt32>::opcUaBinaryEncodeNumberLE(os, value);
		}
		else {
			return ByteOrder<OpcUaInt32>::opcUaBinaryEncodeNumberBE(os, value);
		}
	}
	
	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaInt32& value, bool littleEndian)
	{
		if (littleEndian) {
			return ByteOrder<OpcUaInt32>::opcUaBinaryDecodeNumberLE(is, value);
		}
		else {
			return ByteOrder<OpcUaInt32>::opcUaBinaryDecodeNumberBE(is, value);
		}
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaInt32Array
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaInt32Array& value)
	{	
		return value.opcUaBinaryEncode(os);
	}
	
	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaInt32Array& value)
	{
		return value.opcUaBinaryDecode(is);
	}

	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaInt32Array::SPtr& value)
	{	
		return value->opcUaBinaryEncode(os);
	}
	
	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaInt32Array::SPtr& value)
	{
		return value->opcUaBinaryDecode(is);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaUInt32
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaUInt32& value, bool littleEndian)
	{	
		if (littleEndian) {
			return ByteOrder<OpcUaUInt32>::opcUaBinaryEncodeNumberLE(os, value);
		}
		else {
			return ByteOrder<OpcUaUInt32>::opcUaBinaryEncodeNumberBE(os, value);
		}
	}

	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaUInt32& value, bool littleEndian)
	{	
		if (littleEndian) {
			return ByteOrder<OpcUaUInt32>::opcUaBinaryDecodeNumberLE(is, value);
		}
		else {
			return ByteOrder<OpcUaUInt32>::opcUaBinaryDecodeNumberBE(is, value);
		}
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaUInt32Array
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaUInt32Array& value)
	{	
		return value.opcUaBinaryEncode(os);
	}

	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaUInt32Array& value)
	{	
		return value.opcUaBinaryDecode(is);
	}

	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaUInt32Array::SPtr& value)
	{	
		return value->opcUaBinaryEncode(os);
	}

	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaUInt32Array::SPtr& value)
	{	
		return value->opcUaBinaryDecode(is);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaInt64
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaInt64& value, bool littleEndian)
	{	
		if (littleEndian) {
			return ByteOrder<OpcUaInt64>::opcUaBinaryEncodeNumberLE(os, value);
		}
		else {
			return ByteOrder<OpcUaInt64>::opcUaBinaryEncodeNumberBE(os, value);
		}
	}
	
	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaInt64& value, bool littleEndian)
	{	
		if (littleEndian) {
			return ByteOrder<OpcUaInt64>::opcUaBinaryDecodeNumberLE(is, value);
		}
		else {
			return ByteOrder<OpcUaInt64>::opcUaBinaryDecodeNumberBE(is, value);
		}
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaInt64Array
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaInt64Array& value)
	{	
		return value.opcUaBinaryEncode(os);
	}
	
	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaInt64Array& value)
	{	
		return value.opcUaBinaryDecode(is);
	}

	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaInt64Array::SPtr& value)
	{	
		return value->opcUaBinaryEncode(os);
	}
	
	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaInt64Array::SPtr& value)
	{	
		return value->opcUaBinaryDecode(is);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaUInt64
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaUInt64& value, bool littleEndian)
	{	
		if (littleEndian) {
			return ByteOrder<OpcUaUInt64>::opcUaBinaryEncodeNumberLE(os, value);
		}
		else {
			return ByteOrder<OpcUaUInt64>::opcUaBinaryEncodeNumberBE(os, value);
		}
	}

	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaUInt64& value, bool littleEndian)
	{	
		if (littleEndian) {
			return ByteOrder<OpcUaUInt64>::opcUaBinaryDecodeNumberLE(is, value);
		}
		else {
			return ByteOrder<OpcUaUInt64>::opcUaBinaryDecodeNumberBE(is, value);
		}
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaUInt64Array
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaUInt64Array& value)
	{	
		return value.opcUaBinaryEncode(os);
	}

	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaUInt64Array& value)
	{	
		return value.opcUaBinaryDecode(is);
	}

	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaUInt64Array::SPtr& value)
	{	
		return value->opcUaBinaryEncode(os);
	}

	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaUInt64Array::SPtr& value)
	{	
		return value->opcUaBinaryDecode(is);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaFloat
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaFloat& value, bool littleEndian)
	{	
		if (littleEndian) {
			return ByteOrder<OpcUaFloat>::opcUaBinaryEncodeNumberLE(os, value);
		}
		else {
			return ByteOrder<OpcUaFloat>::opcUaBinaryEncodeNumberBE(os, value);
		}
	}

	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaFloat& value, bool littleEndian)
	{	
		if (littleEndian) {
			return ByteOrder<OpcUaFloat>::opcUaBinaryDecodeNumberLE(is, value);
		}
		else {
			return ByteOrder<OpcUaFloat>::opcUaBinaryDecodeNumberBE(is, value);
		}
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaFloatArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaFloatArray& value)
	{	
		return value.opcUaBinaryEncode(os);
	}

	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaFloatArray& value)
	{	
		return value.opcUaBinaryDecode(is);
	}

	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaFloatArray::SPtr& value)
	{	
		return value->opcUaBinaryEncode(os);
	}

	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaFloatArray::SPtr& value)
	{	
		return value->opcUaBinaryDecode(is);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaDouble
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaDouble& value, bool littleEndian)
	{	
		if (littleEndian) {
			return ByteOrder<OpcUaDouble>::opcUaBinaryEncodeNumberLE(os, value);
		}
		else {
			return ByteOrder<OpcUaDouble>::opcUaBinaryEncodeNumberBE(os, value);
		}
	}

	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaDouble& value, bool littleEndian)
	{	
		if (littleEndian) {
			return ByteOrder<OpcUaDouble>::opcUaBinaryDecodeNumberLE(is, value);
		}
		else {
			return ByteOrder<OpcUaDouble>::opcUaBinaryDecodeNumberBE(is, value);
		}
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaDoubleArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaDoubleArray& value)
	{	
		return value.opcUaBinaryEncode(os);
	}

	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaDoubleArray& value)
	{	
		return value.opcUaBinaryDecode(is);
	}

	bool
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaDoubleArray::SPtr& value)
	{	
		return value->opcUaBinaryEncode(os);
	}

	bool
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaDoubleArray::SPtr& value)
	{	
		return value->opcUaBinaryDecode(is);
	}


}
