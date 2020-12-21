/*
   Copyright 2017-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_BrowsePathToNodeIdResponse_h__
#define __OpcUaStackServer_BrowsePathToNodeIdResponse_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"

namespace OpcUaStackServer
{

	class DLLEXPORT NodeIdResult
	: public OpcUaStackCore::JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<NodeIdResult> SPtr;

		NodeIdResult(void);
		~NodeIdResult(void);

		void statusCode(OpcUaStackCore::OpcUaStatusCode statusCode);
		OpcUaStackCore::OpcUaStatusCode statusCode(void);
		void nodeId(OpcUaStackCore::OpcUaNodeId& nodeId);
		OpcUaStackCore::OpcUaNodeId& nodeId(void);

		void copyTo(NodeIdResult& nodeIdResult)  {}
		void out(std::ostream& os) const {}

		bool opcUaBinaryEncode(std::ostream& os) const { return false; }
		bool opcUaBinaryDecode(std::istream& is) { return false; }
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, OpcUaStackCore::Xmlns& xmlns) { return false; }
		bool xmlEncode(boost::property_tree::ptree& pt, OpcUaStackCore::Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, OpcUaStackCore::Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, OpcUaStackCore::Xmlns& xmlns) { return false; }

	  protected:
		bool jsonEncodeImpl(boost::property_tree::ptree &pt) const { return false; }
		bool jsonDecodeImpl(const boost::property_tree::ptree &pt) { return false; }

	  private:
		OpcUaStackCore::OpcUaStatusCode statusCode_;
		OpcUaStackCore::OpcUaNodeId nodeId_;
	};


	class DLLEXPORT NodeIdResultArray
	: public OpcUaStackCore::OpcUaArray<NodeIdResult::SPtr, OpcUaStackCore::SPtrTypeCoder<NodeIdResult> >
	, public OpcUaStackCore::Object
	{
	  public:
		typedef boost::shared_ptr<NodeIdResultArray> SPtr;
	};


	class DLLEXPORT BrowsePathToNodeIdResponse
	: public  OpcUaStackCore::Object
	{
	  public:
		typedef boost::shared_ptr<BrowsePathToNodeIdResponse> SPtr;

		BrowsePathToNodeIdResponse(void);
		virtual ~BrowsePathToNodeIdResponse(void);

		void nodeIdResults(NodeIdResultArray::SPtr& nodeIdResults);
		NodeIdResultArray::SPtr& nodeIdResults(void);

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		NodeIdResultArray::SPtr nodeIdResults_;
	};

}

#endif
