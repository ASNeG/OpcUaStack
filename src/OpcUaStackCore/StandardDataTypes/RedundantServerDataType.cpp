/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Samuel Huebl (samuel.huebl@asneg.de)
 */

#include "OpcUaStackCore/StandardDataTypes/RedundantServerDataType.h"

namespace OpcUaStackCore
{

	RedundantServerDataType::RedundantServerDataType(void)
	: Object()
	, serverId_()
	, serviceLevel_()
	, serverState_()
	{
	}

	RedundantServerDataType::~RedundantServerDataType(void)
	{
	}

	OpcUaString&
	RedundantServerDataType::serverId(void)
	{
		return serverId_;
	}

	void
	RedundantServerDataType::serverId(OpcUaString serverId)
	{
		serverId_ = serverId;
	}

	OpcUaByte&
	RedundantServerDataType::serviceLevel(void)
	{
		return serviceLevel_;
	}

	void
	RedundantServerDataType::serviceLevel(OpcUaByte serviceLevel)
	{
		serviceLevel_ = serviceLevel;
	}

	OpcUaInt32&
	RedundantServerDataType::serverState(void)
	{
		return serverState_;
	}

	void
	RedundantServerDataType::serverState(OpcUaInt32 serverState)
	{
		serverState_ = serverState;
	}

	void
	RedundantServerDataType::copyTo(RedundantServerDataType& redundantServerDataType)
	{
		serverId_.copyTo(redundantServerDataType.serverId());
		redundantServerDataType.serviceLevel(serviceLevel_);
		redundantServerDataType.serverState(serverState_);
	}

	bool
	RedundantServerDataType::operator==(const RedundantServerDataType& redundantServerDataType) const
	{
		RedundantServerDataType* dst = const_cast<RedundantServerDataType*>(&redundantServerDataType);
		return
			serverId_ == dst->serverId() &&
			serviceLevel_ == dst->serviceLevel() &&
			serverState_ == dst->serverState();
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ExtensionObjectBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ExtensionObjectBase::SPtr
	RedundantServerDataType::factory(void)
	{
		return constructSPtr<RedundantServerDataType>();
	}

	void
	RedundantServerDataType::opcUaBinaryEncode(std::ostream& os) const
	{
		serverId_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, serviceLevel_);
		OpcUaNumber::opcUaBinaryEncode(os, serverState_);
	}

	void
	RedundantServerDataType::opcUaBinaryDecode(std::istream& is)
	{
		serverId_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, serviceLevel_);
		OpcUaNumber::opcUaBinaryDecode(is, serverState_);
	}

	bool
	RedundantServerDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	RedundantServerDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	RedundantServerDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	void
	RedundantServerDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		RedundantServerDataType* dst = dynamic_cast<RedundantServerDataType*>(&extensionObjectBase);
		copyTo(*dst);
	}

	bool
	RedundantServerDataType::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		RedundantServerDataType* dst = dynamic_cast<RedundantServerDataType*>(&extensionObjectBase);
		return *this == *dst;
	}

	void
	RedundantServerDataType::out(std::ostream& os)
	{
		os << "ServerId="; serverId_.out(os);
		os << ", ServiceLevel=" << serviceLevel_;
		os << ", ServerState=" << serverState_;
	}

}

