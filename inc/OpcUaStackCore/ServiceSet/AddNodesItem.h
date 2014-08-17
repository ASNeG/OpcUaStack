#ifndef __OpcUaStackCore_AddNodesItem_h__
#define __OpcUaStackCore_AddNodesItem_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/NodeClass.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"


namespace OpcUaStackCore
{

// Unitest
// AddNodesItem ani;
// ani.nodeAttributes().nodeId((OpcUaUInt32)12345);
// ObjectAttributes::SPtr attr = ani.nodeAttributes().parameter<ObjectAttributes>();
// attr->dislayName("ABC"),
//
// ani.opcUABinaryEncode..

// ep.ObjectAttributes().nodeId((OpcUaUInt32)12345);
// ObjectAttributes_::SPtr attr = ep.parameter<ObjectAttributes>();
// atrr->dislayName("ABC"),

	class DLLEXPORT AddNodesItem : public ObjectPool<AddNodesItem>
	{
	  public:
	    AddNodesItem(void);
		~AddNodesItem(void);

		void parentNodeId(const OpcUaExpandedNodeId::SPtr parentNodeIdSPtr);
		OpcUaExpandedNodeId::SPtr parentNodeId(void) const;
		void referenceTypeId(const OpcUaNodeId::SPtr referenceTypeIdSPtr);
		OpcUaNodeId::SPtr referenceTypeId(void) const;
		void requestedNewNodeId(const OpcUaExpandedNodeId::SPtr requestedNewNodeIdSPtr);
		OpcUaExpandedNodeId::SPtr requestedNewNodeId(void) const;
		void browseName(const OpcUaQualifiedName::SPtr browseNameSPtr);
		OpcUaQualifiedName::SPtr browseName(void) const;
		void nodeClass(const NodeClass::SPtr nodeClassSPtr);
		NodeClass::SPtr nodeClass(void) const;
		const ExtensibleParameter& nodeAttributes(void) const;
		void typeDefinition(const OpcUaExpandedNodeId::SPtr typeDefinitionSPtr);
		OpcUaExpandedNodeId::SPtr typeDefinition(void) const;

		void opcUaBinaryEncode(std::ostream& os) const; // nodeAttributes_.opcUaBinaryEncode(..)
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaExpandedNodeId::SPtr parentNodeId_;
		OpcUaNodeId::SPtr referenceTypeId_;
		OpcUaExpandedNodeId::SPtr requestedNewNodeId_;
		OpcUaQualifiedName::SPtr browseName_;
		NodeClass::SPtr nodeClass_;
		ExtensibleParameter nodeAttributes_;
		OpcUaExpandedNodeId::SPtr typeDefinition_;
	};

	class AddNodesItemArray : public OpcUaArray<AddNodesItem::SPtr, SPtrTypeCoder<AddNodesItem>>, public ObjectPool<AddNodesItemArray> {};
}

#endif
