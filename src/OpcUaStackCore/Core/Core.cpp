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

#include "OpcUaStackCore/Base/Log.h"
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
#include "OpcUaStackCore/StandardDataTypes/DataTypeDefinition.h"
#include "OpcUaStackCore/StandardDataTypes/RolePermissionType.h"

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

		bool rc = eo.registerFactoryObject<LiteralOperand>();
		rc &= eo.registerFactoryObject<ElementOperand>();
		rc &= eo.registerFactoryObject<AttributeOperand>();
		rc &= eo.registerFactoryObject<SimpleAttributeOperand>();
		rc &= eo.registerFactoryObject<Range>();
		rc &= eo.registerFactoryObject<BuildInfo>();
		rc &= eo.registerFactoryObject<ServerStatusDataType>();
		rc &= eo.registerFactoryObject<ModelChangeStructureDataType>();
		rc &= eo.registerFactoryObject<RedundantServerDataType>();
		rc &= eo.registerFactoryObject<SamplingIntervalDiagnosticsDataType>();
		rc &= eo.registerFactoryObject<SemanticChangeStructureDataType>();
		rc &= eo.registerFactoryObject<ServiceCounterDataType>();
		rc &= eo.registerFactoryObject<SessionDiagnosticsDataType>();
		rc &= eo.registerFactoryObject<SessionSecurityDiagnosticsDataType>();
		rc &= eo.registerFactoryObject<StatusResult>();
		rc &= eo.registerFactoryObject<SubscriptionDiagnosticsDataType>();
		rc &= eo.registerFactoryObject<ServerDiagnosticsSummaryDataType>();
		rc &= eo.registerFactoryObject<Argument>();
		rc &= eo.registerFactoryObject<ObjectAttributes>();
		rc &= eo.registerFactoryObject<DataTypeAttributes>();
		rc &= eo.registerFactoryObject<MethodAttributes>();
		rc &= eo.registerFactoryObject<ObjectTypeAttributes>();
		rc &= eo.registerFactoryObject<ReferenceTypeAttributes>();
		rc &= eo.registerFactoryObject<ViewAttributes>();
		rc &= eo.registerFactoryObject<HistoryEvent>();
		rc &= eo.registerFactoryObject<HistoryData>();
		rc &= eo.registerFactoryObject<EventFilter>();
		rc &= eo.registerFactoryObject<AnonymousIdentityToken>();
		rc &= eo.registerFactoryObject<UserNameIdentityToken>();
		rc &= eo.registerFactoryObject<X509IdentityToken>();
		rc &= eo.registerFactoryObject<IssuedIdentityToken>();
		rc &= eo.registerFactoryObject<EventFilterResult>();
		rc &= eo.registerFactoryObject<DataChangeNotification>();
		rc &= eo.registerFactoryObject<StatusChangeNotification>();
		rc &= eo.registerFactoryObject<EventNotificationList>();
		rc &= eo.registerFactoryObject<ReadEventDetails>();
		rc &= eo.registerFactoryObject<HistoryReadDetails>();
		rc &= eo.registerFactoryObject<ReadRawModifiedDetails>();
		rc &= eo.registerFactoryObject<ReadProcessedDetails>();
		rc &= eo.registerFactoryObject<ReadAtTimeDetails>();
		rc &= eo.registerFactoryObject<HistoryModifiedData>();
		rc &= eo.registerFactoryObject<ModificationInfo>();
		rc &= eo.registerFactoryObject<UpdateDataDetails>();
		rc &= eo.registerFactoryObject<HistoryUpdateDetails>();
		rc &= eo.registerFactoryObject<UpdateStructureDataDetails>();
		rc &= eo.registerFactoryObject<UpdateEventDetails>();
		rc &= eo.registerFactoryObject<DeleteRawModifiedDetails>();
		rc &= eo.registerFactoryObject<DeleteAtTimeDetails>();
		rc &= eo.registerFactoryObject<DeleteEventDetails>();
		rc &= eo.registerFactoryObject<NodeAttributes>();
		rc &= eo.registerFactoryObject<VariableAttributes>();
		rc &= eo.registerFactoryObject<VariableTypeAttributes>();
		rc &= eo.registerFactoryObject<AggregateFilter>();
		rc &= eo.registerFactoryObject<EUInformation>();
		rc &= eo.registerFactoryObject<EnumValueType>();
		rc &= eo.registerFactoryObject<DataTypeDefinition>();
		rc &= eo.registerFactoryObject<RolePermissionType>();

		if (!rc) {
			Log(Error, "register extension objects error");
		}
	}

	void
	Core::cleanupExtensionObject(void)
	{
		OpcUaExtensionObject eo;
		if (!eo.deregisterFactoryElements()) {
			Log(Error, "deregister extension objects error");
		}
	}

}
