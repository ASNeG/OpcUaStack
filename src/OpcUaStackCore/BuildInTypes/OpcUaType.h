#ifndef __OpcUaStackCore_OpcUaType_h__
#define __OpcUaStackCore_OpcUaType_h__

namespace OpcUaStackCore
{

	typedef enum 
	{
		OpcUaBuildInType_Unknown = 0,
		OpcUaBuildInType_OpcUaBoolean = 1,
		OpcUaBuildInType_OpcUaSByte = 2,
		OpcUaBuildInType_OpcUaByte = 3,
		OpcUaBuildInType_OpcUaInt16 = 4,
		OpcUaBuildInType_OpcUaUInt16 = 5,
		OpcUaBuildInType_OpcUaInt32 = 6,
		OpcUaBuildInType_OpcUaUInt32 = 7,
		OpcUaBuildInType_OpcUaInt64 = 8,
		OpcUaBuildInType_OpcUaUInt64 = 9,
		OpcUaBuildInType_OpcUaFloat = 10,
		OpcUaBuildInType_OpcUaDouble = 11,
		OpcUaBuildInType_OpcUaString = 12,
		OpcUaBuildInType_OpcUaDateTime = 13,
		OpcUaBuildInType_OpcUaGuid = 14,
		OpcUaBuildInType_OpcUaByteString = 15,
		OpcUaBuildInType_OpcUaXmlElement = 16,
		OpcUaBuildInType_OpcUaNodeId = 17,
		OpcUaBuildInType_OpcUaExpandedNodeId = 18,
		OpcUaBuildInType_OpcUaStatusCode = 19,
		OpcUaBuildInType_OpcUaQualifiedName = 20,
		OpcUaBuildInType_OpcUaLocalizedText = 21,
		OpcUaBuildInType_OpcUaExtensionObject = 22,
		OpcUaBuildInType_OpcUaDataValue = 23,
		OpcUaBuildInType_OpcUaVariant = 24,
		OpcUaBuildInType_OpcUaDiagnosticInfo = 25
	} OpcUaBuildInType;

};

#endif