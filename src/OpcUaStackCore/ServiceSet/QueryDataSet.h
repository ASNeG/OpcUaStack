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

#ifndef __OpcUaStackCore_QueryDataSet_h__
#define __OpcUaStackCore_QueryDataSet_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaVariant.h"

namespace OpcUaStackCore
{

	class DLLEXPORT QueryDataSet
	: public Object
	, public JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<QueryDataSet> SPtr;

		QueryDataSet(void);
		virtual ~QueryDataSet(void);

		void nodeId(const OpcUaExpandedNodeId::SPtr nodeId);
		OpcUaExpandedNodeId::SPtr nodeId(void) const;
		void typeDefinitionNode(const OpcUaExpandedNodeId::SPtr typeDefinitionNode);
		OpcUaExpandedNodeId::SPtr typeDefinitionNode(void) const;
		void values(const OpcUaVariantArray::SPtr values);
		OpcUaVariantArray::SPtr values(void) const;

		void copyTo(QueryDataSet& queryDataSet) {}
		void out(std::ostream& os) const {};

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
		OpcUaExpandedNodeId::SPtr nodeIdSPtr_;
		OpcUaExpandedNodeId::SPtr typeDefinitionNodeSPtr_;
		OpcUaVariantArray::SPtr valueArraySPtr_;
	};

	class DLLEXPORT QueryDataSetArray
	: public OpcUaArray<QueryDataSet::SPtr, SPtrTypeCoder<QueryDataSet> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<QueryDataSetArray> SPtr;
	};

}

#endif
