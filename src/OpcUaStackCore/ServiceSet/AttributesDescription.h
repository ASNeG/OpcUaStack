/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_AttributesDescription_h__
#define __OpcUaStackCore_AttributesDescription_h__

#include <stdint.h>

namespace OpcUaStackCore
{

	typedef enum {
		SpecifiedAttributes_AccessLevel = 1, // Indicates if the AccessLevel Attribute is set.
		SpecifiedAttributes_ArrayDimensions = (2 << 1), // Indicates if the ArrayDimensions Attribute is set.
		SpecifiedAttributes_Reserved1 = (3 << 1), // Reserved to be consistent with WriteMask defined in Part 3.
		SpecifiedAttributes_ContainsNoLoops = (4 << 1), // Indicates if the ContainsNoLoops Attribute is set.
		SpecifiedAttributes_DataType = (5 << 1), // Indicates if the DataType Attribute is set.
		SpecifiedAttributes_Description = (6 << 1), // Indicates if the Description Attribute is set.
		SpecifiedAttributes_DisplayName = (7 << 1), // Indicates if the DisplayName Attribute is set.
		SpecifiedAttributes_EventNotifier = (8 << 1), // Indicates if the EventNotifier Attribute is set.
		SpecifiedAttributes_Executable = (9 << 1), // Indicates if the Executable Attribute is set.
		SpecifiedAttributes_Historizing = (10 << 1), // Indicates if the Historizing Attribute is set.
		SpecifiedAttributes_InverseName = (11 << 1), // Indicates if the InverseName Attribute is set.
		SpecifiedAttributes_IsAbstract = (12 << 1), // Indicates if the IsAbstract Attribute is set.
		SpecifiedAttributes_MinimumSamplingInterval = (13 << 1), // Indicates if the MinimumSamplingInterval Attribute is set.
		SpecifiedAttributes_Reserved2 = (14 << 1), // Reserved to be consistent with WriteMask defined in Part 3.
		SpecifiedAttributes_Reserved3 = (15 << 1), // Reserved to be consistent with WriteMask defined in Part 3.
		SpecifiedAttributes_Symmetric = (16 << 1), // Indicates if the Symmetric Attribute is set.
		SpecifiedAttributes_UserAccessLevel = (17 << 1), // Indicates if the UserAccessLevel Attribute is set.
		SpecifiedAttributes_UserExecutable = (18 << 1), // Indicates if the UserExecutable Attribute is set.
		SpecifiedAttributes_UserWriteMask = (19 << 1), // Indicates if the UserWriteMask Attribute is set.
		SpecifiedAttributes_ValueRank = (20 << 1), // Indicates if the ValueRank Attribute is set.
		SpecifiedAttributes_WriteMask = (21 << 1), // Indicates if the WriteMask Attribute is set.
		SpecifiedAttributes_Value = (22 << 1), // Indicates if the Value Attribute is set.
	} SpecifiedAttributes;


	typedef enum {
		WriteableAttribute_AccessLevel = 1, // Indicates if the AccessLevel Attribute is writable.
		WriteableAttribute_ArrayDimensions = (2 << 1), // Indicates if the ArrayDimensions Attribute is writable.
		WriteableAttribute_BrowseName = (3 << 1), // Indicates if the BrowseName Attribute is writable.
		WriteableAttribute_ContainsNoLoops = (4 << 1), // Indicates if the ContainsNoLoops Attribute is writable.
		WriteableAttribute_DataType = (5 << 1), // Indicates if the DataType Attribute is writable.
		WriteableAttribute_Description = (6 << 1), // Indicates if the Description Attribute is writable.
		WriteableAttribute_DisplayName = (7 << 1), // Indicates if the DisplayName Attribute is writable.
		WriteableAttribute_EventNotifier = (8 << 1), // Indicates if the EventNotifier Attribute is writable.
		WriteableAttribute_Executable = (9 << 1), // Indicates if the Executable Attribute is writable.
		WriteableAttribute_Historizing = (10 << 1), // Indicates if the Historizing Attribute is writable.
		WriteableAttribute_InverseName = (11 << 1), // Indicates if the InverseName Attribute is writable.
		WriteableAttribute_IsAbstract = (12 << 1), // Indicates if the IsAbstract Attribute is writable.
		WriteableAttribute_MinimumSamplingInterval = (13 << 1), // Indicates if the MinimumSamplingInterval Attribute is writable.
		WriteableAttribute_NodeClass = (14 << 1), // Indicates if the NodeClass Attribute is writable.
		WriteableAttribute_NodeId = (15 << 1), // Indicates if the NodeId Attribute is writable.
		WriteableAttribute_Symmetric = (16 << 1), // Indicates if the Symmetric Attribute is writable.
		WriteableAttribute_UserAccessLevel = (17 << 1), // Indicates if the UserAccessLevel Attribute is writable.
		WriteableAttribute_UserExecutable = (18 << 1), // Indicates if the UserExecutable Attribute is writable.
	    WriteableAttribute_UserWriteMask = (19 << 1), // Indicates if the UserWriteMask Attribute is writable.
		WriteableAttribute_ValueRank = (20 << 1), // Indicates if the ValueRank Attribute is writable.
		WriteableAttribute_WriteMask = (21 << 1), // Indicates if the WriteMask Attribute is writable.
		WriteableAttribute_ValueForVariableType = (22 << 1), // Indicates if the Value Attribute is writable.
	} WriteableAttribute;

	typedef enum {
		EventNotifierAttribute_SubscribeToEvents = 1, // Indicates if it can be used to subscribe to Events.
		EventNotifierAttribute_HistoryRead = 4, // Indicates if the history of the Events is readable.
		EventNotifierAttribute_HistoryWrite = 8, // Indicates if the history of the Events is writable.
	} EventNotifierAttribute;

}

#endif
