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
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"

#include "OpcUaStackCore/ServiceSet/AnonymousIdentityToken.h"
#include "OpcUaStackCore/ServiceSet/UserNameIdentityToken.h"
#include "OpcUaStackCore/ServiceSet/X509IdentityToken.h"
#include "OpcUaStackCore/ServiceSet/IssuedIdentityToken.h"
#include "OpcUaStackCore/ServiceSet/ElementOperand.h"
#include "OpcUaStackCore/ServiceSet/LiteralOperand.h"
#include "OpcUaStackCore/ServiceSet/AttributeOperand.h"
#include "OpcUaStackCore/ServiceSet/SimpleAttributeOperand.h"
#include "OpcUaStackCore/ServiceSet/EventFilter.h"
#include "OpcUaStackCore/ServiceSet/EventFilterResult.h"
#include "OpcUaStackCore/ServiceSet/LiteralOperand.h"
#include "OpcUaStackCore/ServiceSet/DataChangeNotification.h"
#include "OpcUaStackCore/ServiceSet/EventNotificationList.h"
#include "OpcUaStackCore/ServiceSet/ObjectAttributes.h"
#include "OpcUaStackCore/ServiceSet/VariableAttributes.h"
#include "OpcUaStackCore/ServiceSet/MethodAttributes.h"
#include "OpcUaStackCore/ServiceSet/ObjectTypeAttributes.h"
#include "OpcUaStackCore/ServiceSet/VariableTypeAttributes.h"
#include "OpcUaStackCore/ServiceSet/ReferenceTypeAttributes.h"
#include "OpcUaStackCore/ServiceSet/DataTypeAttributes.h"
#include "OpcUaStackCore/ServiceSet/ViewAttributes.h"
#include "OpcUaStackCore/ServiceSet/ReadRawModifiedDetails.h"
#include "OpcUaStackCore/ServiceSet/ReadEventDetails.h"
#include "OpcUaStackCore/ServiceSet/UpdateStructureDataDetails.h"
#include "OpcUaStackCore/ServiceSet/HistoryData.h"
#include "OpcUaStackCore/ServiceSet/HistoryEvent.h"

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
		initExtensibleParameter();
		initExtensionObject();
		return true;
	}

	void
	Core::cleanup(void)
	{
		cleanupExtensionObject();
		cleanupExtensibleParameter();

		init_ = false;
	}

	void
	Core::initExtensibleParameter(void)
	{
		ExtensibleParameter ep;
		ep.registerFactoryElement<AnonymousIdentityToken>(OpcUaId_AnonymousIdentityToken_Encoding_DefaultBinary);
		ep.registerFactoryElement<UserNameIdentityToken>(OpcUaId_UserNameIdentityToken_Encoding_DefaultBinary);
		ep.registerFactoryElement<X509IdentityToken>(OpcUaId_X509IdentityToken_Encoding_DefaultBinary);
		ep.registerFactoryElement<IssuedIdentityToken>(OpcUaId_IssuedIdentityToken_Encoding_DefaultBinary);
		ep.registerFactoryElement<EventFilter>(OpcUaId_EventFilter_Encoding_DefaultBinary);
		ep.registerFactoryElement<EventFilterResult>(OpcUaId_EventFilterResult_Encoding_DefaultBinary);
		ep.registerFactoryElement<ElementOperand>(OpcUaId_ElementOperand_Encoding_DefaultBinary);
		ep.registerFactoryElement<LiteralOperand>(OpcUaId_LiteralOperand_Encoding_DefaultBinary);
		ep.registerFactoryElement<AttributeOperand>(OpcUaId_AttributeOperand_Encoding_DefaultBinary);
		ep.registerFactoryElement<SimpleAttributeOperand>(OpcUaId_SimpleAttributeOperand_Encoding_DefaultBinary);
		ep.registerFactoryElement<LiteralOperand>(OpcUaId_LiteralOperand_Encoding_DefaultBinary);
		ep.registerFactoryElement<DataChangeNotification>(OpcUaId_DataChangeNotification_Encoding_DefaultBinary);
		ep.registerFactoryElement<EventNotificationList>(OpcUaId_EventNotificationList_Encoding_DefaultBinary);

		ep.registerFactoryElement<ObjectAttributes>(OpcUaId_ObjectAttributes);
		ep.registerFactoryElement<VariableAttributes>(OpcUaId_VariableAttributes);
		ep.registerFactoryElement<MethodAttributes>(OpcUaId_MethodAttributes);
		ep.registerFactoryElement<ObjectTypeAttributes>(OpcUaId_ObjectTypeAttributes);
		ep.registerFactoryElement<VariableTypeAttributes>(OpcUaId_VariableTypeAttributes);
		ep.registerFactoryElement<ReferenceTypeAttributes>(OpcUaId_ReferenceTypeAttributes);
		ep.registerFactoryElement<DataTypeAttributes>(OpcUaId_DataTypeAttributes);
		ep.registerFactoryElement<ViewAttributes>(OpcUaId_ViewAttributes);

		ep.registerFactoryElement<ReadRawModifiedDetails>(OpcUaId_ReadRawModifiedDetails_Encoding_DefaultBinary);
		ep.registerFactoryElement<ReadEventDetails>(OpcUaId_ReadEventDetails_Encoding_DefaultBinary);
		ep.registerFactoryElement<UpdateStructureDataDetails>(OpcUaId_UpdateStructureDataDetails_Encoding_DefaultBinary);
		ep.registerFactoryElement<HistoryData>(OpcUaId_HistoryData_Encoding_DefaultBinary);
		ep.registerFactoryElement<HistoryEvent>(OpcUaId_HistoryEvent_Encoding_DefaultBinary);
		ep.registerFactoryElement<EventFilter>(OpcUaId_EventFilter_Encoding_DefaultBinary);
	}

	void
	Core::initExtensionObject(void)
	{
		OpcUaExtensionObject eo;

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

		// xml
		eo.registerFactoryElement<Argument>(OpcUaId_Argument_Encoding_DefaultXml);
	}

	void
	Core::cleanupExtensibleParameter(void)
	{
		ExtensibleParameter ep;
		ep.deregisterFactoryElement(OpcUaId_AnonymousIdentityToken_Encoding_DefaultBinary);
		ep.deregisterFactoryElement(OpcUaId_UserNameIdentityToken_Encoding_DefaultBinary);
		ep.deregisterFactoryElement(OpcUaId_X509IdentityToken_Encoding_DefaultBinary);
		ep.deregisterFactoryElement(OpcUaId_IssuedIdentityToken_Encoding_DefaultBinary);
		ep.deregisterFactoryElement(OpcUaId_ElementOperand_Encoding_DefaultBinary);
		ep.deregisterFactoryElement(OpcUaId_LiteralOperand_Encoding_DefaultBinary);
		ep.deregisterFactoryElement(OpcUaId_AttributeOperand_Encoding_DefaultBinary);
		ep.deregisterFactoryElement(OpcUaId_SimpleAttributeOperand_Encoding_DefaultBinary);
		ep.deregisterFactoryElement(OpcUaId_EventFilter_Encoding_DefaultBinary);
		ep.deregisterFactoryElement(OpcUaId_EventFilterResult_Encoding_DefaultBinary);
		ep.deregisterFactoryElement(OpcUaId_LiteralOperand_Encoding_DefaultBinary);
		ep.deregisterFactoryElement(OpcUaId_DataChangeNotification_Encoding_DefaultBinary);
		ep.deregisterFactoryElement(OpcUaId_EventNotificationList_Encoding_DefaultBinary);

		ep.deregisterFactoryElement(OpcUaId_ObjectAttributes);
		ep.deregisterFactoryElement(OpcUaId_VariableAttributes);
		ep.deregisterFactoryElement(OpcUaId_MethodAttributes);
		ep.deregisterFactoryElement(OpcUaId_ObjectTypeAttributes);
		ep.deregisterFactoryElement(OpcUaId_VariableTypeAttributes);
		ep.deregisterFactoryElement(OpcUaId_ReferenceTypeAttributes);
		ep.deregisterFactoryElement(OpcUaId_DataTypeAttributes);
		ep.deregisterFactoryElement(OpcUaId_ViewAttributes);

		ep.deregisterFactoryElement(OpcUaId_ReadRawModifiedDetails_Encoding_DefaultBinary);
		ep.deregisterFactoryElement(OpcUaId_ReadEventDetails_Encoding_DefaultBinary);
		ep.deregisterFactoryElement(OpcUaId_UpdateStructureDataDetails_Encoding_DefaultBinary);
		ep.deregisterFactoryElement(OpcUaId_HistoryData_Encoding_DefaultBinary);
		ep.deregisterFactoryElement(OpcUaId_HistoryEvent_Encoding_DefaultBinary);
		ep.deregisterFactoryElement(OpcUaId_EventFilter_Encoding_DefaultBinary);
	}

	void
	Core::cleanupExtensionObject(void)
	{
		OpcUaExtensionObject eo;

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

		// xml
		eo.deregisterFactoryElement(OpcUaId_Argument_Encoding_DefaultXml);
	}

}
