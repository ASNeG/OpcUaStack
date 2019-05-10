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

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaStackCore_OpcUaLocalizedText_h__
#define __OpcUaStackCore_OpcUaLocalizedText_h__

#include <boost/property_tree/ptree.hpp>
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaLocalizedText
	: public Object
	, public JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<OpcUaLocalizedText> SPtr;

	    OpcUaLocalizedText(void);
	    OpcUaLocalizedText(const OpcUaLocalizedText& value);
	    OpcUaLocalizedText(const std::string& locale, const std::string& text);
		~OpcUaLocalizedText(void);

		void set(const std::string& locale, const std::string& text);
		void get(std::string& locale, std::string& text);

		void locale(const OpcUaString& locale);
		void locale(const std::string& locale);
		OpcUaString& locale(void);
		void text(const OpcUaString& text);
		void text(const std::string& text);
		OpcUaString& text(void);

		void copyTo(OpcUaLocalizedText& localizedText);

		bool fromString(const std::string& string);
		std::string toString(void);
		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const OpcUaLocalizedText& value) {
			value.out(os);
			return os;
		}
		bool operator!=(const OpcUaLocalizedText& opcUaLocalizedText) const;
		bool operator==(const OpcUaLocalizedText& opcUaLocalizedText) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);

      protected:
		bool jsonEncodeImpl(boost::property_tree::ptree& pt) const override;
		bool jsonDecodeImpl(const boost::property_tree::ptree& pt) override;

	  private:
		OpcUaString locale_;
		OpcUaString text_;
	};


	class OpcUaLocalizedTextArray
	: public OpcUaArray<OpcUaLocalizedText::SPtr, SPtrTypeCoder<OpcUaLocalizedText> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<OpcUaLocalizedTextArray> SPtr;
	};

}

#endif
