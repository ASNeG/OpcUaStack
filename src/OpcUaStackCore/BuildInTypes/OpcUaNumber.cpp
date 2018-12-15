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
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaInt16& value, bool littleEndian)
	{	
		if (littleEndian) {
			ByteOrder<OpcUaInt16>::opcUaBinaryEncodeNumberLE(os, value);
		}
		else {
			ByteOrder<OpcUaInt16>::opcUaBinaryEncodeNumberBE(os, value);
		}
	}
	
	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaInt16& value, bool littleEndian)
	{	
		if (littleEndian) {
			ByteOrder<OpcUaInt16>::opcUaBinaryDecodeNumberLE(is, value);
		}
		else {
			ByteOrder<OpcUaInt16>::opcUaBinaryDecodeNumberBE(is, value);
		}
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
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaUInt16& value, bool littleEndian)
	{	
		if (littleEndian) {
			ByteOrder<OpcUaUInt16>::opcUaBinaryEncodeNumberLE(os, value);
		}
		else {
			ByteOrder<OpcUaUInt16>::opcUaBinaryEncodeNumberBE(os, value);
		}
	}

	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaUInt16& value, bool littleEndian)
	{	
		if (littleEndian) {
			ByteOrder<OpcUaUInt16>::opcUaBinaryDecodeNumberLE(is, value);
		}
		else {
			ByteOrder<OpcUaUInt16>::opcUaBinaryDecodeNumberBE(is, value);
		}
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
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaInt32& value, bool littleEndian)
	{	
		if (littleEndian) {
			ByteOrder<OpcUaInt32>::opcUaBinaryEncodeNumberLE(os, value);
		}
		else {
			ByteOrder<OpcUaInt32>::opcUaBinaryEncodeNumberBE(os, value);
		}
	}
	
	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaInt32& value, bool littleEndian)
	{
		if (littleEndian) {
			ByteOrder<OpcUaInt32>::opcUaBinaryDecodeNumberLE(is, value);
		}
		else {
			ByteOrder<OpcUaInt32>::opcUaBinaryDecodeNumberBE(is, value);
		}
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
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaUInt32& value, bool littleEndian)
	{	
		if (littleEndian) {
			ByteOrder<OpcUaUInt32>::opcUaBinaryEncodeNumberLE(os, value);
		}
		else {
			ByteOrder<OpcUaUInt32>::opcUaBinaryEncodeNumberBE(os, value);
		}
	}

	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaUInt32& value, bool littleEndian)
	{	
		if (littleEndian) {
			ByteOrder<OpcUaUInt32>::opcUaBinaryDecodeNumberLE(is, value);
		}
		else {
			ByteOrder<OpcUaUInt32>::opcUaBinaryDecodeNumberBE(is, value);
		}
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
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaInt64& value, bool littleEndian)
	{	
		if (littleEndian) {
			ByteOrder<OpcUaInt64>::opcUaBinaryEncodeNumberLE(os, value);
		}
		else {
			ByteOrder<OpcUaInt64>::opcUaBinaryEncodeNumberBE(os, value);
		}
	}
	
	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaInt64& value, bool littleEndian)
	{	
		if (littleEndian) {
			ByteOrder<OpcUaInt64>::opcUaBinaryDecodeNumberLE(is, value);
		}
		else {
			ByteOrder<OpcUaInt64>::opcUaBinaryDecodeNumberBE(is, value);
		}
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
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaUInt64& value, bool littleEndian)
	{	
		if (littleEndian) {
			ByteOrder<OpcUaUInt64>::opcUaBinaryEncodeNumberLE(os, value);
		}
		else {
			ByteOrder<OpcUaUInt64>::opcUaBinaryEncodeNumberBE(os, value);
		}
	}

	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaUInt64& value, bool littleEndian)
	{	
		if (littleEndian) {
			ByteOrder<OpcUaUInt64>::opcUaBinaryDecodeNumberLE(is, value);
		}
		else {
			ByteOrder<OpcUaUInt64>::opcUaBinaryDecodeNumberBE(is, value);
		}
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
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaFloat& value, bool littleEndian)
	{	
		if (littleEndian) {
			ByteOrder<OpcUaFloat>::opcUaBinaryEncodeNumberLE(os, value);
		}
		else {
			ByteOrder<OpcUaFloat>::opcUaBinaryEncodeNumberBE(os, value);
		}
	}

	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaFloat& value, bool littleEndian)
	{	
		if (littleEndian) {
			ByteOrder<OpcUaFloat>::opcUaBinaryDecodeNumberLE(is, value);
		}
		else {
			ByteOrder<OpcUaFloat>::opcUaBinaryDecodeNumberBE(is, value);
		}
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
	OpcUaNumber::opcUaBinaryEncode(std::ostream& os, const OpcUaDouble& value, bool littleEndian)
	{	
		if (littleEndian) {
			ByteOrder<OpcUaDouble>::opcUaBinaryEncodeNumberLE(os, value);
		}
		else {
			ByteOrder<OpcUaDouble>::opcUaBinaryEncodeNumberBE(os, value);
		}
	}

	void 
	OpcUaNumber::opcUaBinaryDecode(std::istream& is, OpcUaDouble& value, bool littleEndian)
	{	
		if (littleEndian) {
			ByteOrder<OpcUaDouble>::opcUaBinaryDecodeNumberLE(is, value);
		}
		else {
			ByteOrder<OpcUaDouble>::opcUaBinaryDecodeNumberBE(is, value);
		}
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
