/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/EventType/AuditEventType.h"

namespace OpcUaStackCore
{

	AuditEventType::AuditEventType(void)
	: BaseEventType()
	, actionTimeStamp_()
	, status_(true)
	, serverId_()
	, clientAuditEntryId_()
	, clientUserId_()
	{
	}

	AuditEventType::~AuditEventType(void)
	{
	}

	ExtensionObjectBase::SPtr
	AuditEventType::factory(void)
	{
		AuditEventType::SPtr auditEventType = constructSPtr<AuditEventType>();
		return auditEventType;
	}

	OpcUaNodeId
	AuditEventType::binaryTypeId(void)
	{
		return OpcUaNodeId(2041);
	}

	OpcUaNodeId
	AuditEventType::xmlTypeId(void)
	{
		return OpcUaNodeId("Unknown-Type-Id");
	}

	void
	AuditEventType::opcUaBinaryEncode(std::ostream& os) const
	{
		BaseEventType::opcUaBinaryEncode(os);
		actionTimeStamp_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, status_);
		serverId_.opcUaBinaryEncode(os);
		clientAuditEntryId_.opcUaBinaryEncode(os);
		clientUserId_.opcUaBinaryEncode(os);
	}

	void
	AuditEventType::opcUaBinaryDecode(std::istream& is)
	{
		BaseEventType::opcUaBinaryDecode(is);
		actionTimeStamp_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, status_);
		serverId_.opcUaBinaryDecode(is);
		clientAuditEntryId_.opcUaBinaryDecode(is);
		clientUserId_.opcUaBinaryDecode(is);
	}

	bool
	AuditEventType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
	{
		return false;
	}

	bool
	AuditEventType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		return false;
	}

	void
	AuditEventType::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		AuditEventType* dst = dynamic_cast<AuditEventType*>(&extensionObjectBase);
		copyTo(*dst);
	}

	bool
	AuditEventType::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		AuditEventType* dst = dynamic_cast<AuditEventType*>(&extensionObjectBase);
		return *this == *dst;
	}

	void
	AuditEventType::out(std::ostream& os)
	{
		BaseEventType::out(os);
		os << ", ActionTimeStamp="; actionTimeStamp_.out(os);
		os << ", Status=" << status_;
		os << ", ServerId="; serverId_.out(os);
		os << ", ClientAuditEntryId="; clientAuditEntryId_.out(os);
		os << ", ClientUserId="; clientUserId_.out(os);
	}

	void
	AuditEventType::copyTo(AuditEventType& auditEventType)
	{
		actionTimeStamp_.copyTo(auditEventType.actionTimeStamp_);
		auditEventType.status_ = status_;
		serverId_.copyTo(auditEventType.serverId_);
		clientAuditEntryId_.copyTo(auditEventType.clientAuditEntryId_);
		clientUserId_.copyTo(auditEventType.clientUserId_);
	}

	bool
	AuditEventType::operator==(const AuditEventType& auditEventType) const
	{
		AuditEventType* ptr = const_cast<AuditEventType*>(&auditEventType);
		bool rc = true;

		rc &= (actionTimeStamp_ == ptr->actionTimeStamp_);
		rc &= (status_ == ptr->status_);
		rc &= (serverId_ == ptr->serverId_);
		rc &= (clientAuditEntryId_ == ptr->clientAuditEntryId_);
		rc &= (clientUserId_ == ptr->clientUserId_);

		return rc;
	}

}


