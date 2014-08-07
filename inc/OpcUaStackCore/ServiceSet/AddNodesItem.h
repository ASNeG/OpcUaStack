#ifndef __OpcUaStackCore_AddNodesItem_h__
#define __OpcUaStackCore_AddNodesItem_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExpandedNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaQualifiedName.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSet/NodeClass.h"
#include "OpcUaStackCore/ServiceSet/NodeAttributes.h"

namespace OpcUaStackCore
{

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
		void nodeClass(const NodeClass value);
		NodeClass nodeClass(void) const;
		void nodeAttributes(const NodeAttributesArray::SPtr nodeAttributesSPtr);
		NodeAttributesArray::SPtr nodeAttributes(void) const;
		void typeDefinition(const OpcUaExpandedNodeId::SPtr typeDefinitionSPtr);
		OpcUaExpandedNodeId::SPtr typeDefinition(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaExpandedNodeId::SPtr parentNodeId_;
		OpcUaNodeId::SPtr referenceTypeId_;
		OpcUaExpandedNodeId::SPtr requestedNewNodeId_;
		OpcUaQualifiedName::SPtr browseName_;
		NodeClass nodeClass_;
		NodeAttributesArray::SPtr nodeAttributes_;
		OpcUaExpandedNodeId::SPtr typeDefinition_;
	};

	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaAddNodesItem& value);
	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaAddNodesItem::SPtr& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaAddNodesItem& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaAddNodesItem::SPtr& value);


	class AddNodesItemArray : public OpcUaArray<AddNodesItem::SPtr>, public ObjectPool<AddNodesItemArray> {};

	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const AddNodesItemArray& value);
	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const AddNodesItemArray::SPtr& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is,AddNodesItemArray& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is,AddNodesItemArray::SPtr& value);

}

#endif
