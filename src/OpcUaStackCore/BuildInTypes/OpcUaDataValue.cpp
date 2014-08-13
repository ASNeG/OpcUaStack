#include "OpcUaStackCore/BuildInTypes/OpcUaDataValue.h"

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


}
