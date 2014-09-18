#ifndef __OpcUaStackCore_DeleteReferencesItem_h__
#define __OpcUaStackCore_DeleteReferencesItem_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"


namespace OpcUaStackCore
{

	class DLLEXPORT DeleteReferencesItem : public ObjectPool<DeleteReferencesItem>
	{
	  public:
	    DeleteReferencesItem(void);
		~DeleteReferencesItem(void);

		void sourceNodeId(const OpcUaNodeId::SPtr sourceNodeIdSPtr);
		OpcUaNodeId::SPtr sourceNodeId(void) const;
		void referenceTypeId(const OpcUaNodeId::SPtr referenceTypeIdSPtr);
		OpcUaNodeId::SPtr referenceTypeId(void) const;
		void isForward(const OpcUaBoolean isForward);
        OpcUaBoolean isForward(void) const;
		void targetNodeId(const OpcUaExpandedNodeId::SPtr targetNodeIdSPtr);
		OpcUaExpandedNodeId::SPtr targetNodeId(void) const;
		void deleteBidirectional(const OpcUaBoolean isForward);
        OpcUaBoolean deleteBidirectional(void) const;

		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaNodeId::SPtr sourceNodeIdSPtr_;
		OpcUaNodeId::SPtr referenceTypeIdSPtr_;
		OpcUaBoolean isForward_;
		OpcUaExpandedNodeId::SPtr targetNodeIdSPtr_;
		OpcUaBoolean deleteBidirectional_;
	};

	class DeleteReferencesItemArray : public OpcUaArray<DeleteReferencesItem::SPtr, SPtrTypeCoder<DeleteReferencesItem> >, public ObjectPool<DeleteReferencesItemArray> {};
}

#endif
