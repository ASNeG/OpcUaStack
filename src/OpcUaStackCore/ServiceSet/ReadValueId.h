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

#ifndef __OpcUaStackCore_ReadValueId_h__
#define __OpcUaStackCore_ReadValueId_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaQualifiedName.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ReadValueId
	: public Object
	, public JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<ReadValueId> SPtr;

		ReadValueId(void);
		virtual ~ReadValueId(void);

		void nodeId(const OpcUaNodeId::SPtr nodeId);
		OpcUaNodeId::SPtr nodeId(void);
		void attributeId(const OpcUaUInt32& attributeId);
		OpcUaUInt32 attributeId(void) const;
		void indexRange(const OpcUaString& indexRange);
		std::string indexRange(void) const;
		void dataEncoding(const OpcUaQualifiedName& dataEncoding);
		OpcUaQualifiedName& dataEncoding(void);

		void nodeId(const OpcUaInt16& namespaceId, const OpcUaInt32& identifier);
		void indexRange(const std::string& value);
		void dataEncoding(const OpcUaInt16& namespaceIndex, const std::string& name);
		void dataEncoding(const std::string& name);

		void copyTo(ReadValueId& readValueId);
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
		OpcUaQualifiedName dataEncoding_;
	};

	class DLLEXPORT ReadValueIdArray
	: public OpcUaArray<ReadValueId::SPtr, SPtrTypeCoder<ReadValueId> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<ReadValueIdArray> SPtr;
	};

}

#endif
