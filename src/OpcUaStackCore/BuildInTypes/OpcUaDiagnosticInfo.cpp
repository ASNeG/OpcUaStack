#include "OpcUaStackCore/BuildInTypes/OpcUaDiagnosticInfo.h"

namespace OpcUaStackCore
{

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

		OpcUaStackCore::opcUaBinaryEncode(os,encodingMask);
		if (symbolicId_ != -1) {
			OpcUaStackCore::opcUaBinaryEncode(os,symbolicId_);
		}
		if (namespaceUri_ != -1) {
			OpcUaStackCore::opcUaBinaryEncode(os,namespaceUri_);
		}
		if (localizedText_ != -1) {
			OpcUaStackCore::opcUaBinaryEncode(os,localizedText_);
		}
		if (locale_ != -1) {
			OpcUaStackCore::opcUaBinaryEncode(os,locale_);
		}
		if (additionalInfo_.exist()) {
			OpcUaStackCore::opcUaBinaryEncode(os,additionalInfo_);
		}
		if (innerStatusCode_ != 0) {
			OpcUaStackCore::opcUaBinaryEncode(os,innerStatusCode_);
		}
	}
		
	void 
	OpcUaDiagnosticInfo::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByte encodingMask;
		OpcUaStackCore::opcUaBinaryDecode(is,encodingMask);

		if ((encodingMask & 0x01) == 0x01) {
			OpcUaStackCore::opcUaBinaryDecode(is,symbolicId_);
		}
		if ((encodingMask & 0x02) == 0x02) {
			OpcUaStackCore::opcUaBinaryDecode(is,namespaceUri_);
		}
		if ((encodingMask & 0x04) == 0x04) {
			OpcUaStackCore::opcUaBinaryDecode(is,localizedText_);
		}
		if ((encodingMask & 0x08) == 0x08) {
			OpcUaStackCore::opcUaBinaryDecode(is,locale_);
		}
		if ((encodingMask & 0x10) == 0x10) {
			OpcUaStackCore::opcUaBinaryDecode(is,additionalInfo_);
		}
		if ((encodingMask & 0x20) == 0x20) {
			OpcUaStackCore::opcUaBinaryDecode(is,innerStatusCode_);
		}
	}

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaDiagnosticInfo& value)
	{
		value.opcUaBinaryEncode(os);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaDiagnosticInfo& value)
	{
		value.opcUaBinaryDecode(is);
	}

};