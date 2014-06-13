#include "OpcUaStackCore/BuildInTypes/OpcUaDataValue.h"

namespace OpcUaStackCore
{

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

	void 
	OpcUaDataValue::variant(const OpcUaVariant::SPtr& opcUaVariantSPtr)
	{
		opcUaVariantSPtr_ = opcUaVariantSPtr;
	}

	OpcUaVariant::SPtr 
	OpcUaDataValue::variant(void)
	{
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

	OpcUaDateTime  
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

	OpcUaDateTime  
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
		if (sourcePicoseconds_ != 0) {
			encodingMask += 0x08;
		}
		if (serverTimestamp_.exist()) {
			encodingMask += 0x10;
		}
		if (serverPicoseconds_ != 0) {
			encodingMask += 0x20;
		}

		OpcUaStackCore::opcUaBinaryEncode(os,encodingMask);
		if (opcUaVariantSPtr_.get() != NULL) {
			OpcUaStackCore::opcUaBinaryEncode(os,*opcUaVariantSPtr_);
		}
		if (opcUaStatusCode_ != 0) {
			OpcUaStackCore::opcUaBinaryEncode(os,opcUaStatusCode_);
		}
		if (sourceTimestamp_.exist()) {
			OpcUaStackCore::opcUaBinaryEncode(os,sourceTimestamp_);
		}
		if (sourcePicoseconds_ != 0) {
			OpcUaStackCore::opcUaBinaryEncode(os,sourcePicoseconds_);
		}
		if (serverTimestamp_.exist()) {
			OpcUaStackCore::opcUaBinaryEncode(os,serverTimestamp_);
		}
		if (serverPicoseconds_ != 0) {
			OpcUaStackCore::opcUaBinaryEncode(os,serverPicoseconds_);
		}
	}
		
	void 
	OpcUaDataValue::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByte encodingMask;
		OpcUaStackCore::opcUaBinaryDecode(is,encodingMask);

		if ((encodingMask & 0x01) == 0x01) {
			opcUaVariantSPtr_ = OpcUaVariant::construct();
			OpcUaStackCore::opcUaBinaryDecode(is,*opcUaVariantSPtr_);
		}
		if ((encodingMask & 0x02) == 0x02) {
			OpcUaStackCore::opcUaBinaryDecode(is,opcUaStatusCode_);
		}
		if ((encodingMask & 0x04) == 0x04) {
			OpcUaStackCore::opcUaBinaryDecode(is,sourceTimestamp_);
		}
		if ((encodingMask & 0x08) == 0x08) {
			OpcUaStackCore::opcUaBinaryDecode(is,sourcePicoseconds_);
		}
		if ((encodingMask & 0x10) == 0x10) {
			OpcUaStackCore::opcUaBinaryDecode(is,serverTimestamp_);
		}
		if ((encodingMask & 0x20) == 0x20) {
			OpcUaStackCore::opcUaBinaryDecode(is,serverPicoseconds_);
		}
	}

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaDataValue& value)
	{
		value.opcUaBinaryEncode(os);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaDataValue& value)
	{
		value.opcUaBinaryDecode(is);
	}

};