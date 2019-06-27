/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaSByteArray& value)
	{
		return value.encode(pt);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaSByteArray& value)
	{
		return value.decode(pt);
	}

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaSByteArray::SPtr& value)
	{
		return value->encode(pt);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaSByteArray::SPtr& value)
	{
		return value->decode(pt);
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

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaByte& value)
	{
		return Json::encode(pt, value);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaByte& value)
	{
		return Json::decode(pt, value);
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

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaByteArray& value)
	{
		return value.encode(pt);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaByteArray& value)
	{
		return value.decode(pt);
	}

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaByteArray::SPtr& value)
	{
		return value->encode(pt);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaByteArray::SPtr& value)
	{
		return value->decode(pt);
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

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaInt16& value)
	{
		return Json::encode(pt, value);
	}
	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaInt16& value)
	{
		return Json::decode(pt, value);
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

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaInt16Array& value)
	{
		return value.encode(pt);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaInt16Array& value)
	{
		return value.decode(pt);
	}

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaInt16Array::SPtr& value)
	{
		return value->encode(pt);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaInt16Array::SPtr& value)
	{
		return value->decode(pt);
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

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaUInt16& value)
	{
		return Json::encode(pt, value);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaUInt16& value)
	{
		return Json::decode(pt, value);
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

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaUInt16Array& value)
	{
		return value.encode(pt);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaUInt16Array& value)
	{
		return value.decode(pt);
	}

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaUInt16Array::SPtr& value)
	{
		return value->encode(pt);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaUInt16Array::SPtr& value)
	{
		return value->decode(pt);
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

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaInt32& value)
	{
		return Json::encode(pt, value);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaInt32& value)
	{
		return Json::decode(pt, value);
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

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaInt32Array& value)
	{
		return value.encode(pt);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaInt32Array& value)
	{
		return value.decode(pt);
	}

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaInt32Array::SPtr& value)
	{
		return value->encode(pt);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaInt32Array::SPtr& value)
	{
		return value->decode(pt);
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

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaUInt32& value)
	{
		return Json::encode(pt, value);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaUInt32& value)
	{
		return Json::decode(pt, value);
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

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaUInt32Array& value)
	{
		return value.encode(pt);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaUInt32Array& value)
	{
		return value.decode(pt);
	}

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaUInt32Array::SPtr& value)
	{
		return value->encode(pt);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaUInt32Array::SPtr& value)
	{
		return value->decode(pt);
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

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaInt64& value)
	{
		return Json::encode(pt, value);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaInt64& value)
	{
		return Json::decode(pt, value);
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

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaInt64Array& value)
	{
		return value.encode(pt);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaInt64Array& value)
	{
		return value.decode(pt);
	}

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaInt64Array::SPtr& value)
	{
		return value->encode(pt);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaInt64Array::SPtr& value)
	{
		return value->decode(pt);
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

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaUInt64& value)
	{
		return Json::encode(pt, value);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaUInt64& value)
	{
		return Json::decode(pt, value);
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

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaUInt64Array& value)
	{
		return value.encode(pt);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaUInt64Array& value)
	{
		return value.decode(pt);
	}

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaUInt64Array::SPtr& value)
	{
		return value->encode(pt);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaUInt64Array::SPtr& value)
	{
		return value->decode(pt);
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

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaFloat& value)
	{
		return Json::encode(pt, value);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaFloat& value)
	{
		return Json::decode(pt, value);
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

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaFloatArray& value)
	{
		return value.encode(pt);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaFloatArray& value)
	{
		return value.decode(pt);
	}

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaFloatArray::SPtr& value)
	{
		return value->encode(pt);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaFloatArray::SPtr& value)
	{
		return value->decode(pt);
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

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaDouble& value)
	{
		return Json::encode(pt, value);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaDouble& value)
	{
		return Json::decode(pt, value);
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

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaDoubleArray& value)
	{
		return value.encode(pt);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaDoubleArray& value)
	{
		return value.decode(pt);
	}

	bool
	OpcUaNumber::encode(boost::property_tree::ptree& pt, const OpcUaDoubleArray::SPtr& value)
	{
		return value->encode(pt);
	}

	bool
	OpcUaNumber::decode(boost::property_tree::ptree& pt, OpcUaDoubleArray::SPtr& value)
	{
		return value->decode(pt);
	}

}
