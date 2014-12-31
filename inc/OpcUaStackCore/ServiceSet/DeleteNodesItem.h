#ifndef __OpcUaStackCore_DeleteNodesItem_h__
#define __OpcUaStackCore_DeleteNodesItem_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"



namespace OpcUaStackCore
{

	class DLLEXPORT DeleteNodesItem : public ObjectPool<DeleteNodesItem>
	{
	  public:
		typedef boost::shared_ptr<DeleteNodesItem> SPtr;

	    DeleteNodesItem(void);
		~DeleteNodesItem(void);

		void nodeId(const OpcUaNodeId::SPtr nodeIdSPtr);
		OpcUaNodeId::SPtr nodeId(void) const;
		void deleteTargetReferences(const OpcUaBoolean deleteTargetReferences);
        OpcUaBoolean deleteTargetReferences(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaNodeId::SPtr nodeIdSPtr_;
		OpcUaBoolean deleteTargetReferences_;
	};

	class DeleteNodesItemArray : public OpcUaArray<DeleteNodesItem::SPtr, SPtrTypeCoder<DeleteNodesItem> >, public ObjectPool<DeleteNodesItemArray> 
	{
	  public:
		typedef boost::shared_ptr<DeleteNodesItemArray> SPtr;
	};
}

#endif
