#ifndef __OpcUaStackCore_QueryDataSet_h__
#define __OpcUaStackCore_QueryDataSet_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT QueryDataSet : public  ObjectPool<QueryDataSet>
	{
	  public:
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

	class QueryDataSetArray : public OpcUaArray<QueryDataSet::SPtr, SPtrTypeCoder<QueryDataSet> >, public ObjectPool<QueryDataSetArray> {};

}

#endif