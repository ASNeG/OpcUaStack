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

#include "OpcUaStackCore/EventType/BaseEventType.h"

namespace OpcUaStackCore
{

	BaseEventType::BaseEventType(void)
	: Object()
	, ExtensionObjectBase()
	, eventId_()
	, eventType_()
	, sourceNode_()
	, sourceName_()
	, time_()
	, receiveTime_()
	// , TimeZoneDataType localTime_()
	, message_()
	, severity_()
	{
	}

	BaseEventType::~BaseEventType(void)
	{
	}

	ExtensionObjectBase::SPtr
	BaseEventType::factory(void)
	{
		BaseEventType::SPtr baseEventType = constructSPtr<BaseEventType>();
		return baseEventType;
	}

	OpcUaNodeId
	BaseEventType::binaryTypeId(void)
	{
		return OpcUaNodeId(2041);
	}

	OpcUaNodeId
	BaseEventType::xmlTypeId(void)
	{
		return OpcUaNodeId("Unknown-Type-Id");
	}

	void
	BaseEventType::opcUaBinaryEncode(std::ostream& os) const
	{
		eventId_.opcUaBinaryEncode(os);
		eventType_.opcUaBinaryEncode(os);
		sourceNode_.opcUaBinaryEncode(os);
		sourceName_.opcUaBinaryEncode(os);
		time_.opcUaBinaryEncode(os);
		receiveTime_.opcUaBinaryEncode(os);
		//localTime_.opcUaBinaryEncode(os);
		message_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, severity_);
	}

	void
	BaseEventType::opcUaBinaryDecode(std::istream& is)
	{
		eventId_.opcUaBinaryDecode(is);
		eventType_.opcUaBinaryDecode(is);
		sourceNode_.opcUaBinaryDecode(is);
		sourceName_.opcUaBinaryDecode(is);
		time_.opcUaBinaryDecode(is);
		receiveTime_.opcUaBinaryDecode(is);
		//localTime_.opcUaBinaryDecode(is);
		message_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, severity_);
	}

	bool
	BaseEventType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
	{
		return false;
	}

	bool
	BaseEventType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		return false;
	}

	void
	BaseEventType::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		BaseEventType* dst = dynamic_cast<BaseEventType*>(&extensionObjectBase);
		copyTo(*dst);
	}

	bool
	BaseEventType::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		BaseEventType* dst = dynamic_cast<BaseEventType*>(&extensionObjectBase);
		return *this == *dst;
	}

	void
	BaseEventType::out(std::ostream& os)
	{
		os << "EventId="; eventId_.out(os);
		os << ", EventType="; eventType_.out(os);
		os << ", SourceNode="; sourceNode_.out(os);
		os << ", SourceName="; sourceName_.out(os);
		os << ", Time="; time_.out(os);
		os << ", ReceiveTime="; receiveTime_.out(os);
		//os << ", LocalTime="; localTime_.opcUaBinaryDecode(os);
		os << ", Message="; message_.out(os);
		os << ", Severity=" << severity_;
	}

	void
	BaseEventType::copyTo(BaseEventType& baseEventType)
	{
		eventId_.copyTo(baseEventType.eventId_);
		eventType_.copyTo(baseEventType.eventType_);
		sourceNode_.copyTo(baseEventType.sourceNode_);
		sourceName_.copyTo(baseEventType.sourceName_);
		time_.copyTo(baseEventType.time_);
		receiveTime_.copyTo(baseEventType.receiveTime_);
		// localTime_.copyTo(*baseEventType.localTime_);
		message_.copyTo(baseEventType.message_);
		baseEventType.severity_ = severity_;

	}

	bool
	BaseEventType::operator==(const BaseEventType& baseEventType) const
	{
		BaseEventType* ptr = const_cast<BaseEventType*>(&baseEventType);
		bool rc = true;

		rc &= (eventId_ == ptr->eventId_);
		rc &= (eventType_ == ptr->eventType_);
		rc &= (sourceNode_ == ptr->sourceNode_);
		rc &= (time_ == ptr->time_);
		rc &= (receiveTime_ == ptr->receiveTime_);
		// rc &= (*localTime_ == ptr->localTime_);
		rc &= (message_ == ptr->message_);
		rc &= (severity_ == ptr->severity_);

		return rc;
	}

}


