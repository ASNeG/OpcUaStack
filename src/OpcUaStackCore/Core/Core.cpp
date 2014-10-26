#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/AnonymousIdentityToken.h"
#include "OpcUaStackCore/ServiceSet/EventFilter.h"
#include "OpcUaStackCore/ServiceSet/LiteralOperand.h"

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
	}

	void
	Core::cleanupExtensibleParameter(void)
	{
		ExtensibleParameter ep;
		ep.deregisterFactoryElement(OpcUaId_AnonymousIdentityToken_Encoding_DefaultBinary);
		ep.deregisterFactoryElement(OpcUaId_EventFilter_Encoding_DefaultBinary);
		ep.deregisterFactoryElement(OpcUaId_LiteralOperand_Encoding_DefaultBinary);
	}

}