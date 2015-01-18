#ifndef __OpcUaStackCore_ReferenceDescription_h__
#define __OpcUaStackCore_ReferenceDescription_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"
#include "OpcUaStackCore/ServiceSet/NodeClass.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ReferenceDescription : public  ObjectPool<ReferenceDescription>
	{
	  public:
		typedef boost::shared_ptr<ReferenceDescription> SPtr;
		typedef std::vector<ReferenceDescription::SPtr> Vec;

		ReferenceDescription(void);
		virtual ~ReferenceDescription(void);

		void referenceTypeId(const OpcUaNodeId::SPtr referenceTypeId);
		OpcUaNodeId::SPtr referenceTypeId(void) const;
		void isForward(const OpcUaBoolean& isForward);
		OpcUaBoolean isForward(void);
		void expandedNodeId(const OpcUaExpandedNodeId::SPtr nodeId);
		OpcUaExpandedNodeId::SPtr expandedNodeId(void) const;
		void browseName(const OpcUaQualifiedName& browseName);
		OpcUaQualifiedName& browseName(void);
		void displayName(const OpcUaLocalizedText& displayName);
		OpcUaLocalizedText& displayName(void);
		void nodeClass(const NodeClassType nodeClass);
		NodeClassType nodeClass(void);
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
		NodeClassType nodeClass_;
		OpcUaExpandedNodeId::SPtr typeDefinitionSPtr_;
	};

	class ReferenceDescriptionArray : public OpcUaArray<ReferenceDescription::SPtr, SPtrTypeCoder<ReferenceDescription> >, public ObjectPool<ReferenceDescriptionArray> 
	{
	  public:
		typedef boost::shared_ptr<ReferenceDescriptionArray> SPtr;
	};

}

#endif