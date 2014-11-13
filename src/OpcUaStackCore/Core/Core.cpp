#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
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
		return true;
	}

	void
	Core::cleanup(void)
	{
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

}