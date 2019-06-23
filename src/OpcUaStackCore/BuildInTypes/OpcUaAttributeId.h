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

#ifndef __OpcUaStackCore_AttributeId_h__
#define __OpcUaStackCore_AttributeId_h__

#include <stdint.h>
#include <vector>
#include "OpcUaStackCore/Base/os.h"

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
		AttributeId_DataTypeDefinition = 23,
		AttributeId_RolePermissions = 24,
		AttributeId_UserRolePermissions = 25,
		AttributeId_AccessRestrictions = 26,
		AttributeId_AccessLevelEx = 27
	} AttributeId;

	class DLLEXPORT AttributeIdMask
	{
	  public:
		typedef std::vector<AttributeId> Vec;

		AttributeIdMask(void);
		~AttributeIdMask(void);

		void add(const AttributeId attributeId);
		void del(const AttributeId attributeId);
		bool exist(const AttributeId attributeId);
		void get(AttributeIdMask::Vec& attributeIdMaskVec);

	  public:
		AttributeIdMask(const AttributeIdMask& value);

		uint32_t attributeIdMask_;
	};

}

#endif
