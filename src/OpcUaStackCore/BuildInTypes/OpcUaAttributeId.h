#ifndef __OpcUaStackCore_AttributeId_h__
#define __OpcUaStackCore_AttributeId_h__

namespace OpcUaStackCore
{

	typedef enum
	{
		AttributeId_NodeId = 1,
		AttributeId_NodeClass = 2,
		AttributeId_BrowseName = 3,
		AttributeId_DisplayName = 4,
		AttributeId_Description = 5,
		AttributeId_WriteMask = 6,
		AttributeId_UserWriteMask = 7,
		AttributeId_IsAbstract = 8,
		AttributeId_Symmetric = 9,
		AttributeId_InverseName = 10,
		AttributeId_ContainsNoLoops = 11,
		AttributeId_EventNotifier = 12,
		AttributeId_Value = 13,
		AttributeId_DataType = 14,
		AttributeId_ValueRank = 15,
		AttributeId_ArrayDimensions = 16,
		AttributeId_AccessLevel = 17,
		AttributeId_UserAccessLevel = 18,
		AttributeId_MinimumSamplingInterval = 19,
		AttributeId_Historizing = 20,
		AttributeId_Executable = 21,
		AttributeId_UserExecutable = 22,
	} AttributeId;

}

#endif
