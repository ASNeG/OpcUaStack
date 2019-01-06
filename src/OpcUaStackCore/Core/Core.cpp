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

#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"

#include "OpcUaStackCore/StandardDataTypes/EventNotificationList.h"
#include "OpcUaStackCore/StandardDataTypes/DataChangeNotification.h"
#include "OpcUaStackCore/StandardDataTypes/StatusChangeNotification.h"
#include "OpcUaStackCore/StandardDataTypes/EventFilterResult.h"
#include "OpcUaStackCore/StandardDataTypes/UserNameIdentityToken.h"
#include "OpcUaStackCore/StandardDataTypes/X509IdentityToken.h"
#include "OpcUaStackCore/StandardDataTypes/IssuedIdentityToken.h"
#include "OpcUaStackCore/StandardDataTypes/AnonymousIdentityToken.h"
#include "OpcUaStackCore/StandardDataTypes/EventFilter.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryEvent.h"
#include "OpcUaStackCore/StandardDataTypes/SimpleAttributeOperand.h"
#include "OpcUaStackCore/StandardDataTypes/ElementOperand.h"
#include "OpcUaStackCore/StandardDataTypes/LiteralOperand.h"
#include "OpcUaStackCore/StandardDataTypes/AttributeOperand.h"
#include "OpcUaStackCore/StandardDataTypes/BuildInfo.h"
#include "OpcUaStackCore/StandardDataTypes/ServerStatusDataType.h"
#include "OpcUaStackCore/StandardDataTypes/ModelChangeStructureDataType.h"
#include "OpcUaStackCore/StandardDataTypes/RedundantServerDataType.h"
#include "OpcUaStackCore/StandardDataTypes/SamplingIntervalDiagnosticsDataType.h"
#include "OpcUaStackCore/StandardDataTypes/SemanticChangeStructureDataType.h"
#include "OpcUaStackCore/StandardDataTypes/ServiceCounterDataType.h"
#include "OpcUaStackCore/StandardDataTypes/SessionDiagnosticsDataType.h"
#include "OpcUaStackCore/StandardDataTypes/SessionSecurityDiagnosticsDataType.h"
#include "OpcUaStackCore/StandardDataTypes/StatusResult.h"
#include "OpcUaStackCore/StandardDataTypes/SubscriptionDiagnosticsDataType.h"
#include "OpcUaStackCore/StandardDataTypes/ServerDiagnosticsSummaryDataType.h"
#include "OpcUaStackCore/StandardDataTypes/Argument.h"
#include "OpcUaStackCore/StandardDataTypes/ReadEventDetails.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryReadDetails.h"
#include "OpcUaStackCore/StandardDataTypes/ReadRawModifiedDetails.h"
#include "OpcUaStackCore/StandardDataTypes/ReadProcessedDetails.h"
#include "OpcUaStackCore/StandardDataTypes/ReadAtTimeDetails.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryData.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryModifiedData.h"
#include "OpcUaStackCore/StandardDataTypes/ModificationInfo.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryEvent.h"
#include "OpcUaStackCore/StandardDataTypes/UpdateDataDetails.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryUpdateDetails.h"
#include "OpcUaStackCore/StandardDataTypes/UpdateStructureDataDetails.h"
#include "OpcUaStackCore/StandardDataTypes/UpdateEventDetails.h"
#include "OpcUaStackCore/StandardDataTypes/DeleteRawModifiedDetails.h"
#include "OpcUaStackCore/StandardDataTypes/DeleteAtTimeDetails.h"
#include "OpcUaStackCore/StandardDataTypes/DeleteEventDetails.h"
#include "OpcUaStackCore/StandardDataTypes/ObjectAttributes.h"
#include "OpcUaStackCore/StandardDataTypes/NodeAttributes.h"
#include "OpcUaStackCore/StandardDataTypes/VariableAttributes.h"
#include "OpcUaStackCore/StandardDataTypes/VariableTypeAttributes.h"
#include "OpcUaStackCore/StandardDataTypes/MethodAttributes.h"
#include "OpcUaStackCore/StandardDataTypes/ObjectTypeAttributes.h"
#include "OpcUaStackCore/StandardDataTypes/DataTypeAttributes.h"
#include "OpcUaStackCore/StandardDataTypes/ReferenceTypeAttributes.h"
#include "OpcUaStackCore/StandardDataTypes/ViewAttributes.h"
#include "OpcUaStackCore/StandardDataTypes/AggregateFilter.h"
#include "OpcUaStackCore/StandardDataTypes/EnumValueType.h"
#include "OpcUaStackCore/StandardDataTypes/Range.h"
#include "OpcUaStackCore/StandardDataTypes/EUInformation.h"

namespace OpcUaStackCore
{

	bool Core::init_ = false;

	Core::Core(void)
	: config_()
	{
	}

	Core::~Core(void)
	{
	}

	void 
	Core::config(Config& config)
	{
		config_ = &config;
	}

	Config& 
	Core::config(void)
	{
		return *config_;
	}

	bool
	Core::init(void)
	{
		if (init_) return true;
		init_ = true;
		initExtensionObject();
		return true;
	}

	void
	Core::cleanup(void)
	{
		cleanupExtensionObject();

		init_ = false;
	}

	void
	Core::initExtensionObject(void)
	{
		OpcUaExtensionObject eo;

		// objects
		eo.registerFactoryElement<LiteralOperand>(OpcUaId_LiteralOperand);
		eo.registerFactoryElement<ElementOperand>(OpcUaId_ElementOperand);
		eo.registerFactoryElement<AttributeOperand>(OpcUaId_AttributeOperand);
		eo.registerFactoryElement<SimpleAttributeOperand>(OpcUaId_SimpleAttributeOperand);
		eo.registerFactoryElement<Range>(OpcUaId_Range);
		eo.registerFactoryElement<Range>(OpcUaId_EUInformation);

		// binary
		eo.registerFactoryElement<BuildInfo>(OpcUaId_BuildInfo_Encoding_DefaultBinary);
		eo.registerFactoryElement<ServerStatusDataType>(OpcUaId_ServerStatusDataType_Encoding_DefaultBinary);
		eo.registerFactoryElement<ModelChangeStructureDataType>(OpcUaId_ModelChangeStructureDataType_Encoding_DefaultBinary);
		eo.registerFactoryElement<RedundantServerDataType>(OpcUaId_RedundantServerDataType_Encoding_DefaultBinary);
		eo.registerFactoryElement<SamplingIntervalDiagnosticsDataType>(OpcUaId_SamplingIntervalDiagnosticsDataType_Encoding_DefaultBinary);
		eo.registerFactoryElement<SemanticChangeStructureDataType>(OpcUaId_SemanticChangeStructureDataType_Encoding_DefaultBinary);
		eo.registerFactoryElement<ServiceCounterDataType>(OpcUaId_ServiceCounterDataType_Encoding_DefaultBinary);
		eo.registerFactoryElement<SessionDiagnosticsDataType>(OpcUaId_SessionDiagnosticsDataType_Encoding_DefaultBinary);
		eo.registerFactoryElement<SessionSecurityDiagnosticsDataType>(OpcUaId_SessionSecurityDiagnosticsDataType_Encoding_DefaultBinary);
		eo.registerFactoryElement<StatusResult>(OpcUaId_StatusResult_Encoding_DefaultBinary);
		eo.registerFactoryElement<SubscriptionDiagnosticsDataType>(OpcUaId_SubscriptionDiagnosticsDataType_Encoding_DefaultBinary);
		eo.registerFactoryElement<ServerDiagnosticsSummaryDataType>(OpcUaId_ServerDiagnosticsSummaryDataType_Encoding_DefaultBinary);
		eo.registerFactoryElement<Argument>(OpcUaId_Argument_Encoding_DefaultBinary);
		eo.registerFactoryElement<ObjectAttributes>(OpcUaId_ObjectAttributes);
		eo.registerFactoryElement<DataTypeAttributes>(OpcUaId_DataTypeAttributes);
		eo.registerFactoryElement<MethodAttributes>(OpcUaId_MethodAttributes);
		eo.registerFactoryElement<ObjectTypeAttributes>(OpcUaId_ObjectTypeAttributes);
		eo.registerFactoryElement<ReferenceTypeAttributes>(OpcUaId_ReferenceTypeAttributes);
		eo.registerFactoryElement<ViewAttributes>(OpcUaId_ViewAttributes);
		eo.registerFactoryElement<ElementOperand>(OpcUaId_ElementOperand_Encoding_DefaultBinary);
		eo.registerFactoryElement<LiteralOperand>(OpcUaId_LiteralOperand_Encoding_DefaultBinary);
		eo.registerFactoryElement<AttributeOperand>(OpcUaId_AttributeOperand_Encoding_DefaultBinary);
		eo.registerFactoryElement<SimpleAttributeOperand>(OpcUaId_SimpleAttributeOperand_Encoding_DefaultBinary);
		eo.registerFactoryElement<HistoryEvent>(OpcUaId_HistoryEvent_Encoding_DefaultBinary);
		eo.registerFactoryElement<HistoryData>(OpcUaId_HistoryData_Encoding_DefaultBinary);
		eo.registerFactoryElement<EventFilter>(OpcUaId_EventFilter_Encoding_DefaultBinary);
		eo.registerFactoryElement<AnonymousIdentityToken>(OpcUaId_AnonymousIdentityToken_Encoding_DefaultBinary);
		eo.registerFactoryElement<UserNameIdentityToken>(OpcUaId_UserNameIdentityToken_Encoding_DefaultBinary);
		eo.registerFactoryElement<X509IdentityToken>(OpcUaId_X509IdentityToken_Encoding_DefaultBinary);
		eo.registerFactoryElement<IssuedIdentityToken>(OpcUaId_IssuedIdentityToken_Encoding_DefaultBinary);
		eo.registerFactoryElement<EventFilterResult>(OpcUaId_EventFilterResult_Encoding_DefaultBinary);
		eo.registerFactoryElement<DataChangeNotification>(OpcUaId_DataChangeNotification_Encoding_DefaultBinary);
		eo.registerFactoryElement<StatusChangeNotification>(OpcUaId_StatusChangeNotification_Encoding_DefaultBinary);
		eo.registerFactoryElement<EventNotificationList>(OpcUaId_EventNotificationList_Encoding_DefaultBinary);
		eo.registerFactoryElement<ReadEventDetails>(OpcUaId_ReadEventDetails_Encoding_DefaultBinary);
		eo.registerFactoryElement<HistoryReadDetails>(OpcUaId_HistoryReadDetails_Encoding_DefaultBinary);
		eo.registerFactoryElement<ReadRawModifiedDetails>(OpcUaId_ReadRawModifiedDetails_Encoding_DefaultBinary);
		eo.registerFactoryElement<ReadProcessedDetails>(OpcUaId_ReadProcessedDetails_Encoding_DefaultBinary);
		eo.registerFactoryElement<ReadAtTimeDetails>(OpcUaId_ReadAtTimeDetails_Encoding_DefaultBinary);
		eo.registerFactoryElement<HistoryData>(OpcUaId_HistoryData_Encoding_DefaultBinary);
		eo.registerFactoryElement<HistoryModifiedData>(OpcUaId_HistoryModifiedData_Encoding_DefaultBinary);
		eo.registerFactoryElement<ModificationInfo>(OpcUaId_ModificationInfo_Encoding_DefaultBinary);
		eo.registerFactoryElement<HistoryEvent>(OpcUaId_HistoryEvent_Encoding_DefaultBinary);
		eo.registerFactoryElement<UpdateDataDetails>(OpcUaId_UpdateDataDetails_Encoding_DefaultBinary);
		eo.registerFactoryElement<HistoryUpdateDetails>(OpcUaId_HistoryUpdateDetails_Encoding_DefaultBinary);
		eo.registerFactoryElement<UpdateStructureDataDetails>(OpcUaId_UpdateStructureDataDetails_Encoding_DefaultBinary);
		eo.registerFactoryElement<UpdateEventDetails>(OpcUaId_UpdateEventDetails_Encoding_DefaultBinary);
		eo.registerFactoryElement<DeleteRawModifiedDetails>(OpcUaId_DeleteRawModifiedDetails_Encoding_DefaultBinary);
		eo.registerFactoryElement<DeleteAtTimeDetails>(OpcUaId_DeleteAtTimeDetails_Encoding_DefaultBinary);
		eo.registerFactoryElement<DeleteEventDetails>(OpcUaId_DeleteEventDetails_Encoding_DefaultBinary);
		eo.registerFactoryElement<ObjectAttributes>(OpcUaId_ObjectAttributes_Encoding_DefaultBinary);
		eo.registerFactoryElement<NodeAttributes>(OpcUaId_NodeAttributes_Encoding_DefaultBinary);
		eo.registerFactoryElement<VariableAttributes>(OpcUaId_VariableAttributes_Encoding_DefaultBinary);
		eo.registerFactoryElement<VariableTypeAttributes>(OpcUaId_VariableTypeAttributes_Encoding_DefaultBinary);
		eo.registerFactoryElement<MethodAttributes>(OpcUaId_MethodAttributes_Encoding_DefaultBinary);
		eo.registerFactoryElement<ObjectTypeAttributes>(OpcUaId_ObjectTypeAttributes_Encoding_DefaultBinary);
		eo.registerFactoryElement<DataTypeAttributes>(OpcUaId_DataTypeAttributes_Encoding_DefaultBinary);
		eo.registerFactoryElement<ReferenceTypeAttributes>(OpcUaId_ReferenceTypeAttributes_Encoding_DefaultBinary);
		eo.registerFactoryElement<ViewAttributes>(OpcUaId_ViewAttributes_Encoding_DefaultBinary);
		eo.registerFactoryElement<AggregateFilter>(OpcUaId_AggregateFilter_Encoding_DefaultBinary);
		eo.registerFactoryElement<Range>(OpcUaId_Range_Encoding_DefaultBinary);
		eo.registerFactoryElement<EUInformation>(OpcUaId_EUInformation_Encoding_DefaultBinary);

		// xml
		eo.registerFactoryElement<Argument>(OpcUaId_Argument_Encoding_DefaultXml);
		eo.registerFactoryElement<BuildInfo>(OpcUaId_BuildInfo_Encoding_DefaultXml);
		eo.registerFactoryElement<EnumValueType>(OpcUaId_EnumValueType_Encoding_DefaultXml);

		// json
	}

	void
	Core::cleanupExtensionObject(void)
	{
		OpcUaExtensionObject eo;

		eo.deregisterFactoryElement(OpcUaId_LiteralOperand);
		eo.deregisterFactoryElement(OpcUaId_ElementOperand);
		eo.deregisterFactoryElement(OpcUaId_AttributeOperand);
		eo.deregisterFactoryElement(OpcUaId_SimpleAttributeOperand);
		eo.deregisterFactoryElement(OpcUaId_Range);

		// binary
		eo.deregisterFactoryElement(OpcUaId_BuildInfo_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_ServerStatusDataType_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_ModelChangeStructureDataType_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_RedundantServerDataType_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_SamplingIntervalDiagnosticsDataType_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_SemanticChangeStructureDataType_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_ServiceCounterDataType_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_SessionDiagnosticsDataType_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_SessionSecurityDiagnosticsDataType_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_StatusResult_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_SubscriptionDiagnosticsDataType_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_ServerDiagnosticsSummaryDataType_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_Argument_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_ObjectAttributes);
		eo.deregisterFactoryElement(OpcUaId_DataTypeAttributes);
		eo.deregisterFactoryElement(OpcUaId_MethodAttributes);
		eo.deregisterFactoryElement(OpcUaId_ObjectTypeAttributes);
		eo.deregisterFactoryElement(OpcUaId_ReferenceTypeAttributes);
		eo.deregisterFactoryElement(OpcUaId_ViewAttributes);
		eo.deregisterFactoryElement(OpcUaId_ElementOperand_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_LiteralOperand_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_AttributeOperand_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_SimpleAttributeOperand_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_HistoryEvent_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_HistoryData_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_EventFilter_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_AnonymousIdentityToken_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_UserNameIdentityToken_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_X509IdentityToken_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_IssuedIdentityToken_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_EventFilterResult_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_DataChangeNotification_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_StatusChangeNotification_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_EventNotificationList_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_ReadEventDetails_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_HistoryReadDetails_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_ReadRawModifiedDetails_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_ReadProcessedDetails_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_ReadAtTimeDetails_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_HistoryData_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_HistoryModifiedData_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_ModificationInfo_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_HistoryEvent_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_UpdateDataDetails_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_HistoryUpdateDetails_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_UpdateStructureDataDetails_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_UpdateEventDetails_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_DeleteRawModifiedDetails_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_DeleteAtTimeDetails_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_DeleteEventDetails_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_ObjectAttributes_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_NodeAttributes_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_VariableAttributes_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_VariableTypeAttributes_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_MethodAttributes_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_ObjectTypeAttributes_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_DataTypeAttributes_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_ReferenceTypeAttributes_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_ViewAttributes_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_AggregateFilter_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_Range_Encoding_DefaultBinary);

		// xml
		eo.deregisterFactoryElement(OpcUaId_Argument_Encoding_DefaultXml);
		eo.deregisterFactoryElement(OpcUaId_EnumValueType_Encoding_DefaultXml);

		// json
	}

}
