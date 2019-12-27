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

#ifndef __OpcUaStackCore_AddNodesResult_h__
#define __OpcUaStackCore_AddNodesResult_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"

namespace OpcUaStackCore
{

	class DLLEXPORT AddNodesResult
	: public Object
	, public JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<AddNodesResult> SPtr;

	    AddNodesResult(void);
		~AddNodesResult(void);

		void statusCode(OpcUaStatusCode statusCode);
		OpcUaStatusCode statusCode(void) const;

		void addedNodeId(const OpcUaNodeId::SPtr addedNodeIdSPtr);
		OpcUaNodeId::SPtr addedNodeId(void) const;

		void copyTo(AddNodesResult& addNodesResult);
		void out(std::ostream& os) const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return false; }
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return false; }

	 protected:
	    bool jsonEncodeImpl(boost::property_tree::ptree &pt) const { return false; }
	    bool jsonDecodeImpl(const boost::property_tree::ptree &pt) { return false; }

	  private:
		OpcUaStatusCode statusCode_;
		OpcUaNodeId::SPtr addedNodeIdSPtr_;		
	};

	class DLLEXPORT AddNodesResultArray
	: public OpcUaArray<AddNodesResult::SPtr, SPtrTypeCoder<AddNodesResult> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<AddNodesResultArray> SPtr;
	};
}

#endif
