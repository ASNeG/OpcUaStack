#include "OpcUaStackCore/BuildInTypes/OpcUaDiagnosticInfo.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaDiagnosticInfo
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaDiagnosticInfo::OpcUaDiagnosticInfo(void)
	:  ObjectPool<OpcUaDiagnosticInfo>()
	, symbolicId_(-1)
	, namespaceUri_(-1)
	, localizedText_(-1)		
	, locale_(-1)
	, additionalInfo_()
	, innerStatusCode_((OpcUaStatusCode)0)
	{
	}
	
	OpcUaDiagnosticInfo::~OpcUaDiagnosticInfo(void)
	{
	}

	void 
	OpcUaDiagnosticInfo::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaByte encodingMask = 0x00;

		if (symbolicId_ != -1) {
			encodingMask += 0x01;
		}
		if (namespaceUri_ != -1) {
			encodingMask += 0x02;
		}
		if (localizedText_ != -1) {
			encodingMask += 0x04;
		}
		if (locale_ != -1) {
			encodingMask += 0x08;
		}
		if (additionalInfo_.exist()) {
			encodingMask += 0x10;
		}
		if (innerStatusCode_ != 0) {
			encodingMask += 0x20;
		}

		OpcUaNumber::opcUaBinaryEncode(os,encodingMask);
		if (symbolicId_ != -1) {
			OpcUaNumber::opcUaBinaryEncode(os,symbolicId_);
		}
		if (namespaceUri_ != -1) {
			OpcUaNumber::opcUaBinaryEncode(os,namespaceUri_);
		}
		if (localizedText_ != -1) {
			OpcUaNumber::opcUaBinaryEncode(os,localizedText_);
		}
		if (locale_ != -1) {
			OpcUaNumber::opcUaBinaryEncode(os,locale_);
		}
		if (additionalInfo_.exist()) {
			additionalInfo_.opcUaBinaryEncode(os);
		}
		if (innerStatusCode_ != 0) {
			OpcUaNumber::opcUaBinaryEncode(os, innerStatusCode_);
		}
	}
		
	void 
	OpcUaDiagnosticInfo::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByte encodingMask;
		OpcUaNumber::opcUaBinaryDecode(is,encodingMask);

		if ((encodingMask & 0x01) == 0x01) {
			OpcUaNumber::opcUaBinaryDecode(is,symbolicId_);
		}
		if ((encodingMask & 0x02) == 0x02) {
			OpcUaNumber::opcUaBinaryDecode(is,namespaceUri_);
		}
		if ((encodingMask & 0x04) == 0x04) {
			OpcUaNumber::opcUaBinaryDecode(is,localizedText_);
		}
		if ((encodingMask & 0x08) == 0x08) {
			OpcUaNumber::opcUaBinaryDecode(is,locale_);
		}
		if ((encodingMask & 0x10) == 0x10) {
			additionalInfo_.opcUaBinaryDecode(is);
		}
		if ((encodingMask & 0x20) == 0x20) {
			OpcUaInt32 tmp;
			OpcUaNumber::opcUaBinaryDecode(is, tmp); innerStatusCode_ = (OpcUaStatusCode)tmp;
		}
	}

};