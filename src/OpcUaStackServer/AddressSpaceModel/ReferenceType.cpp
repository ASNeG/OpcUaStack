#include "OpcUaStackServer/AddressSpaceModel/ReferenceType.h"

namespace OpcUaStackServer
{
	std::string 
	ReferenceTypeMap::typeToString(ReferenceType referenceType)
	{
		switch (referenceType)
		{
			case ReferenceType_Unknown:
				return "Unknown";
			case ReferenceType_HasComponent:
				return "HasComponent";
			case ReferenceType_HasProperty:
				return "HasProperty";
			case ReferenceType_HasModellingRule:
				return "HasModellingRule";
			case ReferenceType_HasTypeDefinition:
				return "HasTypeDefinition";
			case ReferenceType_HasModelParent:
				return "HasModelParent";
			case ReferenceType_HasEventSource:
				return "HasEventSource";
			case ReferenceType_HasNotifier:
				return "HasNotifier";
			case ReferenceType_Organizes:
				return "Organizes";
			case ReferenceType_HasDescription:
				return "HasDescription";
			case ReferenceType_HasEncoding:
				return "HasEncoding";
		}
		return "Unknown";
	}

	ReferenceType 
	ReferenceTypeMap::stringToType(std::string referenceTypeString)
	{
		if (referenceTypeString == "HasComponent") return ReferenceType_HasComponent;
		else if (referenceTypeString == "HasProperty") return ReferenceType_HasProperty;
		else if (referenceTypeString == "HasModellingRule") return ReferenceType_HasModellingRule;
		else if (referenceTypeString == "HasTypeDefinition") return ReferenceType_HasTypeDefinition;
		else if (referenceTypeString == "HasModelParent") return ReferenceType_HasModelParent;
		else if (referenceTypeString == "HasEventSource") return ReferenceType_HasEventSource;
		else if (referenceTypeString == "HasNotifier") return ReferenceType_HasNotifier;
		else if (referenceTypeString == "Organizes") return ReferenceType_Organizes;
		else if (referenceTypeString == "HasDescription") return ReferenceType_HasDescription;
		else if (referenceTypeString == "HasEncoding") return ReferenceType_HasEncoding;
		return ReferenceType_Unknown;
	}

}
