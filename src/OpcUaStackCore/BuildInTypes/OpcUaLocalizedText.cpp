#include "OpcUaStackCore/BuildInTypes/OpcUaLocalizedText.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

namespace OpcUaStackCore
{

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

		OpcUaStackCore::opcUaBinaryEncode(os, encodingMask);
		if (locale_.exist()) {
			OpcUaStackCore::opcUaBinaryEncode(os, locale_);
		}
		if (text_.exist()) {
			OpcUaStackCore::opcUaBinaryEncode(os, text_);
		}
	}
		
	void 
	OpcUaLocalizedText::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByte encodingMask;
		OpcUaStackCore::opcUaBinaryDecode(is, encodingMask);

		if ((encodingMask & 0x01) == 0x01) {
			OpcUaStackCore::opcUaBinaryDecode(is, locale_);
		}
		if ((encodingMask & 0x02) == 0x02) {
			OpcUaStackCore::opcUaBinaryDecode(is, text_);
		}
	}

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaLocalizedText& value)
	{
		value.opcUaBinaryEncode(os);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaLocalizedText& value)
	{
		value.opcUaBinaryDecode(is);
	}

};