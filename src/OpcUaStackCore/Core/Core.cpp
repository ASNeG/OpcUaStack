/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/ServiceSet/EventFilter.h"
#include "OpcUaStackCore/ServiceSet/LiteralOperand.h"
#include "OpcUaStackCore/ServiceSet/DataChangeNotification.h"
#include "OpcUaStackCore/ServiceSet/ObjectAttributes.h"
#include "OpcUaStackCore/ServiceSet/VariableAttributes.h"
#include "OpcUaStackCore/ServiceSet/MethodAttributes.h"
#include "OpcUaStackCore/ServiceSet/ObjectTypeAttributes.h"
#include "OpcUaStackCore/ServiceSet/VariableTypeAttributes.h"
#include "OpcUaStackCore/ServiceSet/ReferenceTypeAttributes.h"
#include "OpcUaStackCore/ServiceSet/DataTypeAttributes.h"
#include "OpcUaStackCore/ServiceSet/ViewAttributes.h"

#include "OpcUaStackCore/StandardDataTypes/BuildInfo.h"
#include "OpcUaStackCore/StandardDataTypes/ServerStatusDataType.h"

namespace OpcUaStackCore
{

	Core::Core(void)
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
		initExtensibleParameter();
		initExtensionObject();
		return true;
	}

	void
	Core::cleanup(void)
	{
		cleanupExtensionObject();
		cleanupExtensibleParameter();
	}

	void
	Core::initExtensibleParameter(void)
	{
		ExtensibleParameter ep;
		ep.registerFactoryElement<AnonymousIdentityToken>(OpcUaId_AnonymousIdentityToken_Encoding_DefaultBinary);
		ep.registerFactoryElement<EventFilter>(OpcUaId_EventFilter_Encoding_DefaultBinary);
		ep.registerFactoryElement<LiteralOperand>(OpcUaId_LiteralOperand_Encoding_DefaultBinary);
		ep.registerFactoryElement<DataChangeNotification>(OpcUaId_DataChangeNotification_Encoding_DefaultBinary);

		ep.registerFactoryElement<ObjectAttributes>(OpcUaId_ObjectAttributes);
		ep.registerFactoryElement<VariableAttributes>(OpcUaId_VariableAttributes);
		ep.registerFactoryElement<MethodAttributes>(OpcUaId_MethodAttributes);
		ep.registerFactoryElement<ObjectTypeAttributes>(OpcUaId_ObjectTypeAttributes);
		ep.registerFactoryElement<VariableTypeAttributes>(OpcUaId_VariableTypeAttributes);
		ep.registerFactoryElement<ReferenceTypeAttributes>(OpcUaId_ReferenceTypeAttributes);
		ep.registerFactoryElement<DataTypeAttributes>(OpcUaId_DataTypeAttributes);
		ep.registerFactoryElement<ViewAttributes>(OpcUaId_ViewAttributes);
	}

	void
	Core::initExtensionObject(void)
	{
		OpcUaExtensionObject eo;
		eo.registerFactoryElement<BuildInfo>(OpcUaId_BuildInfo_Encoding_DefaultBinary);
		eo.registerFactoryElement<ServerStatusDataType>(OpcUaId_ServerStatusDataType_Encoding_DefaultBinary);
	}

	void
	Core::cleanupExtensibleParameter(void)
	{
		ExtensibleParameter ep;
		ep.deregisterFactoryElement(OpcUaId_AnonymousIdentityToken_Encoding_DefaultBinary);
		ep.deregisterFactoryElement(OpcUaId_EventFilter_Encoding_DefaultBinary);
		ep.deregisterFactoryElement(OpcUaId_LiteralOperand_Encoding_DefaultBinary);
		ep.deregisterFactoryElement(OpcUaId_DataChangeNotification_Encoding_DefaultBinary);

		ep.deregisterFactoryElement(OpcUaId_ObjectAttributes);
		ep.deregisterFactoryElement(OpcUaId_VariableAttributes);
		ep.deregisterFactoryElement(OpcUaId_MethodAttributes);
		ep.deregisterFactoryElement(OpcUaId_ObjectTypeAttributes);
		ep.deregisterFactoryElement(OpcUaId_VariableTypeAttributes);
		ep.deregisterFactoryElement(OpcUaId_ReferenceTypeAttributes);
		ep.deregisterFactoryElement(OpcUaId_DataTypeAttributes);
		ep.deregisterFactoryElement(OpcUaId_ViewAttributes);
	}

	void
	Core::cleanupExtensionObject(void)
	{
		OpcUaExtensionObject eo;
		eo.deregisterFactoryElement(OpcUaId_BuildInfo_Encoding_DefaultBinary);
		eo.deregisterFactoryElement(OpcUaId_ServerStatusDataType_Encoding_DefaultBinary);
	}

}
