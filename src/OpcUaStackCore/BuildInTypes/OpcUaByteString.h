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

#ifndef __OpcUaStackCore_OpcUaByteString_h__
#define __OpcUaStackCore_OpcUaByteString_h__

#include "OpcUaStackCore/Base/os.h"
#include <boost/property_tree/ptree.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"


namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaByteString
	: public Object
	, public JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<OpcUaByteString> SPtr;

	    OpcUaByteString(void);
	    OpcUaByteString(const OpcUaByteString& byteString);
	    OpcUaByteString(const std::string& value);
	    OpcUaByteString(const OpcUaByte* value, OpcUaInt32 length);
		~OpcUaByteString(void);

		void value(OpcUaByte** value, OpcUaInt32* lenth) const;
		void value(char** value, OpcUaInt32* lenth) const;
		void value(const OpcUaByte* value, OpcUaInt32 length);
		void value(const char* value, OpcUaInt32 length);
		void value(const std::string& value);
		OpcUaInt32 size(void) const;
		char* memBuf(void);
		bool resize(uint32_t size);
		void reset(void);
		bool exist(void) const;
		bool isNull(void) const override;

		bool fromHexString(const std::string& hexString);
		std::string toHexString(void) const;
		std::string toString(void) const;
		void fromString(const std::string& string);
		OpcUaByteString& operator=(const std::string& string); 
		OpcUaByteString& operator=(const OpcUaByteString& value);
		operator std::string(void) const;

		void copyTo(OpcUaByteString& opcUaByteString);
		bool operator<(const OpcUaByteString& opcUaByteString) const;
		bool operator!=(const OpcUaByteString& opcUaByteString) const;
		bool operator==(const OpcUaByteString& opcUaByteString) const;

		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const OpcUaByteString& value) {
			value.out(os);
			return os;
		}

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);

    protected:
        bool jsonEncodeImpl(boost::property_tree::ptree &pt) const override;
        bool jsonDecodeImpl(const boost::property_tree::ptree &pt) override;

    private:
		OpcUaInt32 length_;
		OpcUaByte* value_; 
	};

	class DLLEXPORT OpcUaByteStringArray
	: public OpcUaArray<OpcUaByteString::SPtr, SPtrTypeCoder<OpcUaByteString> >
	{
	  public:
		typedef boost::shared_ptr<OpcUaByteStringArray> SPtr;
	};

}

#endif
