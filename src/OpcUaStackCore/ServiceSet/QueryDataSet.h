/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT QueryDataSet
	: public  Object
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

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaExpandedNodeId::SPtr nodeIdSPtr_;
		OpcUaExpandedNodeId::SPtr typeDefinitionNodeSPtr_;
		OpcUaVariantArray::SPtr valueArraySPtr_;
	};

	class QueryDataSetArray
	: public OpcUaArray<QueryDataSet::SPtr, SPtrTypeCoder<QueryDataSet> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<QueryDataSetArray> SPtr;
	};

}

#endif
