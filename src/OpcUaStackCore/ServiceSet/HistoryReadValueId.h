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

#ifndef __OpcUaStackCore_HistoryReadValueId_h__
#define __OpcUaStackCore_HistoryReadValueId_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaQualifiedName.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT HistoryReadValueId
	: public Object
	, public JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<HistoryReadValueId> SPtr;

		HistoryReadValueId(void);
		virtual ~HistoryReadValueId(void);

		void nodeId(const OpcUaNodeId::SPtr nodeId);
		OpcUaNodeId::SPtr nodeId(void);
		void indexRange(const OpcUaString& indexRange);
		std::string indexRange(void) const;
		void dataEncoding(const OpcUaQualifiedName& dataEncoding);
		OpcUaQualifiedName& dataEncoding(void);
		void continuationPoint(const OpcUaByteString& continuationPoint);
		OpcUaByteString& continuationPoint(void);

		void nodeId(const OpcUaInt16& namespaceId, const OpcUaInt32& identifier);
		void indexRange(const std::string& value);
		void dataEncoding(const OpcUaInt16& namespaceIndex, const std::string& name);
		void dataEncoding(const std::string& name);

		void out(std::ostream& os) const {};
		void copyTo(HistoryReadValueId& historyReadValueId) {}

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
		OpcUaString indexRange_;
		OpcUaQualifiedName dataEncoding_;
		OpcUaByteString continuationPoint_;
	};

	class DLLEXPORT HistoryReadValueIdArray
	: public OpcUaArray<HistoryReadValueId::SPtr, SPtrTypeCoder<HistoryReadValueId> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<HistoryReadValueIdArray> SPtr;
	};

}

#endif
