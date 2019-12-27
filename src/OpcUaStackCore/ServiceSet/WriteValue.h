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

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_WriteValue_h__
#define __OpcUaStackCore_WriteValue_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaDataValue.h"

namespace OpcUaStackCore
{

	class DLLEXPORT WriteValue
	: public Object
	, public JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<WriteValue> SPtr;

		WriteValue(void);
		virtual ~WriteValue(void);

		void nodeId(const OpcUaNodeId::SPtr nodeIdSPtr);
		OpcUaNodeId::SPtr nodeId(void);
		void attributeId(const OpcUaUInt32& attributeId);
		OpcUaUInt32 attributeId(void) const;
		void indexRange(const std::string& indexRange);
		std::string indexRange(void) const;
		void dataValue(const OpcUaDataValue& dataValue);
		OpcUaDataValue& dataValue(void);

		void nodeId(const OpcUaInt16& namespaceId, const OpcUaInt32& identifier);
		
		void copyTo(WriteValue& writeValue) {}
		void out(std::ostream& os) const {};

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return false; }
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return false; }

	  protected:
	    bool jsonEncodeImpl(boost::property_tree::ptree &pt) const override;
	    bool jsonDecodeImpl(const boost::property_tree::ptree &pt) override;

	  private:
		OpcUaNodeId::SPtr nodeIdSPtr_;
		OpcUaInt32 attributeId_;
		OpcUaString indexRange_;
		OpcUaDataValue dataValue_;

	};

	class DLLEXPORT WriteValueArray
	: public OpcUaArray<WriteValue::SPtr, SPtrTypeCoder<WriteValue> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<WriteValueArray> SPtr;
	};

}

#endif
