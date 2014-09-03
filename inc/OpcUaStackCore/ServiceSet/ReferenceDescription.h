#ifndef __OpcUaStackCore_ReferenceDescription_h__
#define __OpcUaStackCore_ReferenceDescription_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	typedef enum {
		NodeClass_Object = 1,
		NodeClass_Variable = 2,
		NodeClass_Method = 4,
		NodeClass_Object_Type = 8,
		NodeClass_Variable_Type = 16,
		NodeClass_Reference_Type = 32,
		NodeClass_Data_Type = 64,
		NodeClass_View = 128
	} NodeClass;

	class DLLEXPORT ReferenceDescription : public  ObjectPool<ReferenceDescription>
	{
	  public:
		ReferenceDescription(void);
		virtual ~ReferenceDescription(void);

		void referenceTypeId(const OpcUaNodeId::SPtr referenceTypeId);
		OpcUaNodeId::SPtr referenceTypeId(void) const;
		void isForward(const OpcUaBoolean& isForward);
		OpcUaBoolean isForward(void);
		void nodeId(const OpcUaExpandedNodeId::SPtr nodeId);
		OpcUaExpandedNodeId::SPtr nodeId(void) const;
		void browseName(const OpcUaQualifiedName& browseName);
		OpcUaQualifiedName& browseName(void);
		void displayName(const OpcUaLocalizedText& displayName);
		OpcUaLocalizedText& displayName(void);
		void nodeClass(const NodeClass nodeClass);
		NodeClass nodeClass(void);
		void typeDefinition(const OpcUaExpandedNodeId::SPtr typeDefinition);
		OpcUaExpandedNodeId::SPtr typeDefinition(void) const;
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaNodeId::SPtr referenceTypeIdSPtr_;
		OpcUaBoolean isForward_;
		OpcUaExpandedNodeId::SPtr nodeIdSPtr_;
		OpcUaQualifiedName browseName_;
		OpcUaLocalizedText displayName_;
		NodeClass nodeClass_;
		OpcUaExpandedNodeId::SPtr typeDefinitionSPtr_;
	};

	class ReferenceDescriptionArray : public OpcUaArray<ReferenceDescription::SPtr, SPtrTypeCoder<ReferenceDescription> >, public ObjectPool<ReferenceDescriptionArray> {};

}

#endif