#include "OpcUaStackCore/BuildInTypes/OpcUaLocalizedText.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	// 
	// OpcUaLocalizedText
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaLocalizedText::OpcUaLocalizedText(void)
	: ObjectPool<OpcUaLocalizedText>()
	, locale_()
	, text_()
	{
	}
		
	OpcUaLocalizedText::~OpcUaLocalizedText(void)
	{
	}

	void 
	OpcUaLocalizedText::locale(const OpcUaString& locale)
	{
		locale_ = locale;
	}
		
	void 
	OpcUaLocalizedText::locale(const std::string& locale)
	{
		locale_ = locale;
	}
		
	OpcUaString& 
	OpcUaLocalizedText::locale(void)
	{
		return locale_;
	}
		
	void 
	OpcUaLocalizedText::text(const OpcUaString& text)
	{
		text_ = text;
	}
		
	void 
	OpcUaLocalizedText::text(const std::string& text)
	{
		text_ = text;
	}
	
	OpcUaString& 
	OpcUaLocalizedText::text(void)
	{
		return text_;
	}

	void 
	OpcUaLocalizedText::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaByte encodingMask = 0x00;
		if (locale_.exist()) {
			encodingMask += 0x01;
		}
		if (text_.exist()) {
			encodingMask += 0x02;
		}

		OpcUaNumber::opcUaBinaryEncode(os, encodingMask);
		if (locale_.exist()) {
			locale_.opcUaBinaryEncode(os);
		}
		if (text_.exist()) {
			text_.opcUaBinaryEncode(os);
		}
	}
		
	void 
	OpcUaLocalizedText::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByte encodingMask;
		OpcUaNumber::opcUaBinaryDecode(is, encodingMask);

		if ((encodingMask & 0x01) == 0x01) {
			locale_.opcUaBinaryDecode(is);
		}
		if ((encodingMask & 0x02) == 0x02) {
			text_.opcUaBinaryDecode(is);
		}
	}

};