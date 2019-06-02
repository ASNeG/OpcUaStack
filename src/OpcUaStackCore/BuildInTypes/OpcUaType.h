/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_OpcUaType_h__
#define __OpcUaStackCore_OpcUaType_h__

#include <string>
#include "OpcUaStackCore/Base/os.h"

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
		OpcUaBuildInType_OpcUaDataSetFieldFlag = 15904,
		OpcUaBuildInType_OpcUaInt32 = 6,
		OpcUaBuildInType_OpcUaUInt32 = 7,
		OpcUaBuildInType_OpcUaIntegerId = 288,
		OpcUaBuildInType_OpcUaCounter = 289,
		OpcUaBuildInType_OpcUaVersionTime = 20998,
		OpcUaBuildInType_OpcUaDataSetFieldContentMask = 15583,
		OpcUaBuildInType_OpcUaJsonNetworkMessageContentMask = 15654,
		OpcUaBuildInType_OpcUaUadpNetworkMessageContentMask = 15642,
		OpcUaBuildInType_OpcUaJsonDataSetMessageContentMask = 15658,
		OpcUaBuildInType_OpcUaUadpDataSetMessageContentMask = 15646,
		OpcUaBuildInType_OpcUaPermissionType = 94,
		OpcUaBuildInType_OpcUaInt64 = 8,
		OpcUaBuildInType_OpcUaUInt64 = 9,
		OpcUaBuildInType_OpcUaFloat = 10,
		OpcUaBuildInType_OpcUaDouble = 11,
		OpcUaBuildInType_OpcUaDuration = 290,
		OpcUaBuildInType_OpcUaString = 12,
		OpcUaBuildInType_OpcUaLocaleId = 295,
		OpcUaBuildInType_OpcUaNumericRange = 291,
		OpcUaBuildInType_OpcUaDateTime = 13,
		OpcUaBuildInType_OpcUaUtcTime = 294,
		OpcUaBuildInType_OpcUaGuid = 14,
		OpcUaBuildInType_OpcUaByteString = 15,
		OpcUaBuildInType_OpcUaApplicationInstanceCertificate = 311,
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

	class DLLEXPORT OpcUaBuildInTypeClass
	{
	  public:
		static bool isBoolean(OpcUaBuildInType buildInType);
		static bool isByte(OpcUaBuildInType buildInType);
	    static bool isNumber(OpcUaBuildInType buildInType);
	    static bool isObject(OpcUaBuildInType buildInType);
	};

	class DLLEXPORT OpcUaBuildInTypeMap
	{
	  public:
		static std::string buildInType2String(OpcUaBuildInType buildInType);
		static OpcUaBuildInType string2BuildInType(const std::string& type);
		static std::string buildInType2CPPType(OpcUaBuildInType buildInType);
	};

};

#endif
