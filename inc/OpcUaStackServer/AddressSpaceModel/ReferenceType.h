#ifndef __OpcUaStackServer_ReferenceType_h__
#define __OpcUaStackServer_ReferenceType_h__

#include "OpcUaStackCore/Base/os.h"
#include <string>

namespace OpcUaStackServer
{

	typedef enum {
		ReferenceType_Unknown,
		ReferenceType_HasComponent,
		ReferenceType_HasProperty,
		ReferenceType_HasModellingRule,
		ReferenceType_HasTypeDefinition,
		ReferenceType_HasModelParent,
		ReferenceType_HasEventSource,
		ReferenceType_HasNotifier,
		ReferenceType_Organizes,
		ReferenceType_HasDescription,
		ReferenceType_HasEncoding,
		ReferenceType_HasSubtype,
		ReferenceType_NodeId,
		ReferenceType_HasModelParameter,
		ReferenceType_GenerateEvents,
		ReferenceType_AlwaysGeneratesEvent,
		ReferenceType_HierarchicalReferences
	} ReferenceType;

	class DLLEXPORT ReferenceTypeMap
	{
	  public:
		static std::string typeToString(ReferenceType referenceType);
		static ReferenceType stringToType(std::string referenceTypeString);
	};

}

#endif