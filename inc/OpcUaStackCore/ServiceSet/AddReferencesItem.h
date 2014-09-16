#ifndef __OpcUaStackCore_AddReferencesItem_h__
#define __OpcUaStackCore_AddReferencesItem_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/NodeClass.h"


namespace OpcUaStackCore
{

	class DLLEXPORT AddReferencesItem : public ObjectPool<AddReferencesItem>
	{
	  public:
	    AddReferencesItem(void);
		~AddReferencesItem(void);

		void sourceNodeId(const OpcUaNodeId::SPtr sourceNodeIdSPtr);
		OpcUaNodeId::SPtr sourceNodeId(void) const;
		void referenceTypeId(const OpcUaNodeId::SPtr referenceTypeIdSPtr);
		OpcUaNodeId::SPtr referenceTypeId(void) const;
		void isForward(const OpcUaBoolean isForward);
        OpcUaBoolean isForward(void) const;
		void targetServerUri(const OpcUaString::SPtr targetServerUriSPtr);
		OpcUaString::SPtr targetServerUri(void) const;
		void targetNodeId(const OpcUaExpandedNodeId::SPtr targetNodeIdSPtr);
		OpcUaExpandedNodeId::SPtr targetNodeId(void) const;
		void targetNodeClass(const NodeClass::SPtr targetNodeClassSPtr);
		NodeClass::SPtr targetNodeClass(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaNodeId::SPtr sourceNodeIdSPtr_;
		OpcUaNodeId::SPtr referenceTypeIdSPtr_;
		OpcUaBoolean isForward_;
		OpcUaString::SPtr targetServerUriSPtr_;
		OpcUaExpandedNodeId::SPtr targetNodeIdSPtr_;
		NodeClass::SPtr targetNodeClassSPtr_;
	};

	class AddReferencesItemArray : public OpcUaArray<AddReferencesItem::SPtr, SPtrTypeCoder<AddReferencesItem> >, public ObjectPool<AddReferencesItemArray> {};
}

#endif
