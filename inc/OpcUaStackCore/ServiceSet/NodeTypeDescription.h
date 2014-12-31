#ifndef __OpcUaStackCore_NodeTypeDescription_h__
#define __OpcUaStackCore_NodeTypeDescription_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"
#include "OpcUaStackCore/ServiceSet/QueryDataDescription.h"

namespace OpcUaStackCore
{

	class DLLEXPORT NodeTypeDescription : public  ObjectPool<NodeTypeDescription>
	{
	  public:
		typedef boost::shared_ptr<NodeTypeDescription> SPtr;

		NodeTypeDescription(void);
		virtual ~NodeTypeDescription(void);

		void typeDefinitionNode(const OpcUaExpandedNodeId::SPtr typeDefinitionNode);
		OpcUaExpandedNodeId::SPtr typeDefinitionNode(void) const;
		void includeSubtypes(const OpcUaBoolean& includeSubtypes);
		OpcUaBoolean includeSubtypes(void);
		void dataToReturn(const QueryDataDescriptionArray::SPtr dataToReturn);
		QueryDataDescriptionArray::SPtr dataToReturn(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaExpandedNodeId::SPtr typeDefinitionNodeSPtr_;
		OpcUaBoolean includeSubtypes_;
		QueryDataDescriptionArray::SPtr dataToReturnArraySPtr_;
	};

	class NodeTypeDescriptionArray : public OpcUaArray<NodeTypeDescription::SPtr, SPtrTypeCoder<NodeTypeDescription> >, public ObjectPool<NodeTypeDescriptionArray> 
	{
	  public:
		typedef boost::shared_ptr<NodeTypeDescriptionArray> SPtr;
	};

}

#endif