/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_BuildInTypes_h__
#define __OpcUaStackCore_BuildInTypes_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaDateTime.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaGuid.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaXmlElement.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExpandedNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaQualifiedName.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaLocalizedText.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaVariant.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaDataValue.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaDiagnosticInfo.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatus.h"


namespace OpcUaStackCore
{

	typedef OpcUaDateTime OpcUaUtcTime;
	typedef OpcUaDateTimeArray OpcUaUtcTimeArray;
	typedef OpcUaUInt16 OpcUaDataSetFieldFlag;
	typedef OpcUaUInt32 OpcUaCounter;
	typedef OpcUaUInt32 OpcUaIntegerId;
	typedef OpcUaUInt32 OpcUaVersionTime;
	typedef OpcUaUInt32 OpcUaDataSetFieldContentMask;
	typedef OpcUaUInt32 OpcUaJsonNetworkMessageContentMask;
	typedef OpcUaUInt32 OpcUaUadpNetworkMessageContentMask;
	typedef OpcUaUInt32 OpcUaJsonDataSetMessageContentMask;
	typedef OpcUaUInt32 OpcUaUadpDataSetMessageContentMask;
	typedef OpcUaUInt32 OpcUaPermissionType;
	typedef OpcUaDouble OpcUaDuration;
	typedef OpcUaDoubleArray OpcUaDurationArray;
	typedef OpcUaString OpcUaNumericRange;
	typedef OpcUaString OpcUaLocaleId;
	typedef OpcUaStringArray OpcUaLocaleIdArray;
	typedef OpcUaByteString OpcUaApplicationInstanceCertificate;
	typedef OpcUaUInt16 AccessRestrictionType;
	typedef OpcUaUInt32 AccessLevelExType;

};

#endif
