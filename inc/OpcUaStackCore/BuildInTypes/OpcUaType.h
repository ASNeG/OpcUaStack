#ifndef __OpcUaStackCore_OpcUaType_h__
#define __OpcUaStackCore_OpcUaType_h__

namespace OpcUaStackCore
{

	typedef enum 
	{
		OpcUaBuildInType_Unknown = 0,
		OpcUaBuildInType_OpcUaBoolean,
		OpcUaBuildInType_OpcUaSByte,
		OpcUaBuildInType_OpcUaByte,
		OpcUaBuildInType_OpcUaInt16,
		OpcUaBuildInType_OpcUaUInt16,
		OpcUaBuildInType_OpcUaInt32,
		OpcUaBuildInType_OpcUaUInt32,
		OpcUaBuildInType_OpcUaInt64,
		OpcUaBuildInType_OpcUaUInt64,
		OpcUaBuildInType_OpcUaFloat,
		OpcUaBuildInType_OpcUaDouble,
		OpcUaBuildInType_OpcUaString,
		OpcUaBuildInType_OpcUaDateTime,
		OpcUaBuildInType_OpcUaGuid,
		OpcUaBuildInType_OpcUaByteString,
		OpcUaBuildInType_OpcUaXmlElement,
		OpcUaBuildInType_OpcUaNodeId,
		OpcUaBuildInType_OpcUaExpandedNodeId,
		OpcUaBuildInType_OpcUaStatusCode,
		OpcUaBuildInType_OpcUaQualifiedName,
		OpcUaBuildInType_OpcUaLocalizedText,
		OpcUaBuildInType_OpcUaExtensionObject,
		OpcUaBuildInType_OpcUaDataValue,
		OpcUaBuildInType_OpcUaVariant,
		OpcUaBuildInType_OpcUaDiagnosticInfo
	} OpcUaBuildInType;

};

#endif