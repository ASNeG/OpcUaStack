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

#include "OpcUaStackCore/BuildInTypes/OpcUaDataValue.h"
#include "OpcUaStackCore/Base/Utility.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaDataValue
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaDataValue::OpcUaDataValue(void)
	:  ObjectPool<OpcUaDataValue>()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_()
	, sourceTimestamp_()		
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
	}
		
	OpcUaDataValue::~OpcUaDataValue(void)
	{
	}

	OpcUaVariant::SPtr 
	OpcUaDataValue::variant(void)
	{
		if (opcUaVariantSPtr_.get() == nullptr) {
			opcUaVariantSPtr_ = OpcUaVariant::construct();
		}
		return opcUaVariantSPtr_;
	}

	void 
	OpcUaDataValue::statusCode(const OpcUaStatusCode& opcUaStatusCode)
	{
		opcUaStatusCode_ = opcUaStatusCode;
	}

	OpcUaStatusCode  
	OpcUaDataValue::statusCode(void)
	{
		return opcUaStatusCode_;
	}

	void  
	OpcUaDataValue::sourceTimestamp(const OpcUaDateTime& sourceTimestamp)
	{
		sourceTimestamp_ = sourceTimestamp;
	}

	OpcUaDateTime&  
	OpcUaDataValue::sourceTimestamp(void)
	{
		return sourceTimestamp_;
	}

	void  
	OpcUaDataValue::sourcePicoseconds(const OpcUaUInt16& sourcePicoseconds)
	{
		sourcePicoseconds_ = sourcePicoseconds;
	}

	OpcUaInt16  
	OpcUaDataValue::sourcePicoseconds(void)
	{
		return sourcePicoseconds_;
	}

	void  
	OpcUaDataValue::serverTimestamp(const OpcUaDateTime& serverTimestamp)
	{
		serverTimestamp_ = serverTimestamp;
	}

	OpcUaDateTime&  
	OpcUaDataValue::serverTimestamp(void)
	{
		return serverTimestamp_;
	}

	void  
	OpcUaDataValue::serverPicoseconds(const OpcUaUInt16& serverPicoseconds)
	{
		serverPicoseconds_ = serverPicoseconds;
	}

	OpcUaInt16  
	OpcUaDataValue::serverPicoseconds(void)
	{
		return serverPicoseconds_;
	}

	bool 
	OpcUaDataValue::trigger(OpcUaDataValue::SPtr dataValue, DataChangeTrigger dataChangeTrigger)
	{
		return trigger(*dataValue, dataChangeTrigger);
	}

	bool 
	OpcUaDataValue::trigger(OpcUaDataValue& dataValue, DataChangeTrigger dataChangeTrigger)
	{
		switch (dataChangeTrigger) 
		{
			case DataChangeTrigger_Status_Value_Timestamp:
			{
				if (dataValue.sourceTimestamp() != sourceTimestamp()) return true;
			}
			case DataChangeTrigger_Status_Value:
			{
				if (*dataValue.variant() != *variant()) return true;
			}
			case DataChangeTrigger_Status:
			{
				if (dataValue.statusCode() != statusCode()) return true;
			}
		}
		return false;
	}

	void 
	OpcUaDataValue::reset(void)
	{
		opcUaVariantSPtr_.reset();
		opcUaStatusCode_ = Success;
		sourceTimestamp_ = 0;
		serverTimestamp_ = 0;
		sourcePicoseconds_ = 0;
		serverPicoseconds_ = 0;
	}

	void 
	OpcUaDataValue::out(std::ostream& os) const
	{
		bool outputExist = false;
		if (opcUaVariantSPtr_.get() != NULL) {
			os << "Value=";
		    os << *opcUaVariantSPtr_;
			outputExist = true;
		}
		if (opcUaStatusCode_ != 0) {
			if (outputExist) os << ",";
			os << "Status=" << OpcUaStatusCodeMap::shortString(opcUaStatusCode_);
			outputExist = true;
		}
		if (sourceTimestamp_.exist()) {
			if (outputExist) os << ",";
			os << "SourceTime=" << sourceTimestamp_;
			outputExist = true;
		}
		if (serverTimestamp_.exist()) {
			if (outputExist) os << ",";
			os << "ServerTime=" << serverTimestamp_;
			outputExist = true;
		}
		if (sourcePicoseconds_ != 0) {
			if (outputExist) os << ",";
			os << "SourcePicoSec=" << sourcePicoseconds_;
			outputExist = true;
		}
		if (serverPicoseconds_ != 0) {
			if (outputExist) os << ",";
			os << "ServerPicoSec=" << serverPicoseconds_;
			outputExist = true;
		}
	}

	void 
	OpcUaDataValue::copyFrom(OpcUaDataValue& dataValue)
	{
		dataValue.copyTo(*this);
	}

	void
	OpcUaDataValue::copyTo(OpcUaDataValue& dataValue)
	{
		if (opcUaVariantSPtr_.get() != NULL) {
		    opcUaVariantSPtr_->copyTo(*dataValue.variant());
		}
		if (opcUaStatusCode_ != dataValue.statusCode()) {
		    dataValue.statusCode(opcUaStatusCode_);
		}
		if (sourceTimestamp_.exist()) {
			dataValue.sourceTimestamp(sourceTimestamp_);
		}
		if (serverTimestamp_.exist()) {
			dataValue.serverTimestamp(serverTimestamp_);
		}
		if (sourcePicoseconds_ != 0) {
			dataValue.sourcePicoseconds(sourcePicoseconds_);
		}
		if (serverPicoseconds_ != 0) {
			dataValue.serverPicoseconds(serverPicoseconds_);
		}
	}

	void 
	OpcUaDataValue::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaByte encodingMask = 0x00;

		if (opcUaVariantSPtr_.get() != NULL) {
			encodingMask += 0x01;
		}
		if (opcUaStatusCode_ != 0) {
			encodingMask += 0x02;
		}
		if (sourceTimestamp_.exist()) {
			encodingMask += 0x04;
		}
		if (serverTimestamp_.exist()) {
			encodingMask += 0x08;
		}
		if (sourcePicoseconds_ != 0) {
			encodingMask += 0x10;
		}
		if (serverPicoseconds_ != 0) {
			encodingMask += 0x20;
		}

		OpcUaNumber::opcUaBinaryEncode(os,encodingMask);
		if (opcUaVariantSPtr_.get() != NULL) {
			opcUaVariantSPtr_->opcUaBinaryEncode(os);
		}
		if (opcUaStatusCode_ != 0) {
			OpcUaNumber::opcUaBinaryEncode(os,opcUaStatusCode_);
		}
		if (sourceTimestamp_.exist()) {
			sourceTimestamp_.opcUaBinaryEncode(os);
		}
		if (sourcePicoseconds_ != 0) {
			OpcUaNumber::opcUaBinaryEncode(os,sourcePicoseconds_);
		}
		if (serverTimestamp_.exist()) {
			serverTimestamp_.opcUaBinaryEncode(os);
		}
		if (serverPicoseconds_ != 0) {
			OpcUaNumber::opcUaBinaryEncode(os,serverPicoseconds_);
		}
	}
		

	void 
	OpcUaDataValue::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByte encodingMask;
		OpcUaNumber::opcUaBinaryDecode(is,encodingMask);

		if ((encodingMask & 0x01) == 0x01) {
			opcUaVariantSPtr_ = OpcUaVariant::construct();
			opcUaVariantSPtr_->opcUaBinaryDecode(is);
		}
		if ((encodingMask & 0x02) == 0x02) {
			OpcUaInt32 tmp;
			OpcUaNumber::opcUaBinaryDecode(is,tmp); opcUaStatusCode_ = (OpcUaStatusCode)tmp;
		}
		if ((encodingMask & 0x04) == 0x04) {
			sourceTimestamp_.opcUaBinaryDecode(is);
		}
		if ((encodingMask & 0x08) == 0x08) {
			serverTimestamp_.opcUaBinaryDecode(is);
		}
		if ((encodingMask & 0x10) == 0x10) {
			OpcUaNumber::opcUaBinaryDecode(is,sourcePicoseconds_);
		}	
		if ((encodingMask & 0x20) == 0x20) {
			OpcUaNumber::opcUaBinaryDecode(is,serverPicoseconds_);
		}
	}


	bool
	OpcUaDataValue::encode(boost::property_tree::ptree& pt) const
	{
		if (opcUaVariantSPtr_.get() != NULL) {
			boost::property_tree::ptree ptVariant;
			if (!opcUaVariantSPtr_->encode(ptVariant)) return false;
			pt.add_child("Value", ptVariant);
		}
		if (opcUaStatusCode_ != 0) {
			boost::property_tree::ptree ptStatusCode;
			if (!OpcUaNumber::encode(ptStatusCode, (OpcUaUInt32)opcUaStatusCode_)) return false;
			pt.add_child("StatusCode", ptStatusCode);
		}
		if (sourceTimestamp_.exist()) {
			boost::property_tree::ptree ptSourceTimestamp;
			if (!sourceTimestamp_.encode(ptSourceTimestamp)) return false;
			pt.add_child("SourceTimestamp", ptSourceTimestamp);
		}
		if (sourcePicoseconds_ != 0) {
			boost::property_tree::ptree ptSourcePicoseconds;
			if (!OpcUaNumber::encode(ptSourcePicoseconds, (OpcUaInt16)sourcePicoseconds_)) return false;
			pt.add_child("SourcePicoseconds", ptSourcePicoseconds);
		}
		if (serverTimestamp_.exist()) {
			boost::property_tree::ptree ptServerTimestamp;
			if (!serverTimestamp_.encode(ptServerTimestamp)) return false;
			pt.add_child("ServerTimestamp", ptServerTimestamp);
		}
		if (serverPicoseconds_ != 0) {
			boost::property_tree::ptree ptServerPicoseconds;
			if (!OpcUaNumber::encode(ptServerPicoseconds, (OpcUaInt16)serverPicoseconds_)) return false;;
			pt.add_child("ServerPicoseconds", ptServerPicoseconds);
		}

		return true;
	}

	bool
	OpcUaDataValue::decode(boost::property_tree::ptree& pt, OpcUaBuildInType type, bool isArray)
	{
		// Value
		boost::optional<boost::property_tree::ptree&> value;
		value = pt.get_child_optional("Value");
		if (value) {
			opcUaVariantSPtr_ = OpcUaVariant::construct();
			if (!opcUaVariantSPtr_->decode(*value, type, isArray)) return false;
		}

		// StatusCode
		boost::optional<boost::property_tree::ptree&> statusCode;
		statusCode = pt.get_child_optional("StatusCode");
		if (statusCode) {
			OpcUaUInt32 sc;
			if (!Json::decode(*statusCode, sc)) return false;
			opcUaStatusCode_ = (OpcUaStatusCode)sc;
		}

		// SourceTimestamp
		boost::optional<boost::property_tree::ptree&> sourceTimestamp;
		sourceTimestamp = pt.get_child_optional("SourceTimestamp");
		if (sourceTimestamp) {
			if (!sourceTimestamp_.decode(*sourceTimestamp)) return false;
		}

		// SourcePicoseconds
		boost::optional<boost::property_tree::ptree&> SourcePicoseconds;
		SourcePicoseconds = pt.get_child_optional("SourcePicoseconds");
		if (SourcePicoseconds) {
			if (!Json::decode(*SourcePicoseconds, sourcePicoseconds_)) return false;
		}

		// Servertimestamp
		boost::optional<boost::property_tree::ptree&> serverTimestamp;
		serverTimestamp = pt.get_child_optional("ServerTimestamp");
		if (serverTimestamp) {
			if (!sourceTimestamp_.decode(*serverTimestamp)) return false;
		}

		// ServerPicoseconds
		boost::optional<boost::property_tree::ptree&> ServerPicoseconds;
		ServerPicoseconds = pt.get_child_optional("ServerPicoseconds");
		if (ServerPicoseconds) {
			if (!Json::decode(*ServerPicoseconds, serverPicoseconds_)) return false;
		}

		return true;
	}

}
