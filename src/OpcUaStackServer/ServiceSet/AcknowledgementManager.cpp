/*
   Copyright 2017-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/ServiceSet/AcknowledgementManager.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// AcknowledgementElement
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	AcknowledgementElement::AcknowledgementElement(void)
	: sequenceNumber_(0)
	, notification_()
	{
	}

	AcknowledgementElement::~AcknowledgementElement(void)
	{
	}

	void
	AcknowledgementElement::sequenceNumber(uint32_t sequenceNumber)
	{
		sequenceNumber_ = sequenceNumber;
	}

	uint32_t
	AcknowledgementElement::sequenceNumber(void)
	{
		return sequenceNumber_;
	}

	void
	AcknowledgementElement::notification(OpcUaExtensibleParameter::SPtr& notification)
	{
		notification_ = notification;
	}

	OpcUaExtensibleParameter::SPtr
	AcknowledgementElement::notification(void)
	{
		return notification_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// AcknowledgementManager
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	AcknowledgementManager::AcknowledgementManager(void)
	: maxListSize_(20)
	, acknowledgementList_()
	, sequenceNumber_(0)
	, keepalive_(false)
	{
	}

	AcknowledgementManager::~AcknowledgementManager(void)
	{
	}

	uint32_t
	AcknowledgementManager::nextSequenceNumber(bool keepalive)
	{
		if (keepalive_) {
			if (keepalive) return sequenceNumber_;
			if (!keepalive) {
				keepalive_ = false;
				return sequenceNumber_;
			}
		}
		else {
			if (keepalive) keepalive_ = true;
		}

		sequenceNumber_++;
		if (sequenceNumber_ == 0) sequenceNumber_ = 1;
		return sequenceNumber_;
	}

	uint32_t
	AcknowledgementManager::actSequenceNumber(void)
	{
		if (sequenceNumber_ == 0) sequenceNumber_ = 1;
		return sequenceNumber_;
	}

	uint32_t
	AcknowledgementManager::size(void)
	{
		return acknowledgementList_.size();
	}

	void
	AcknowledgementManager::maxListSize(uint32_t maxListSize)
	{
		maxListSize_ = maxListSize;
	}

	uint32_t
	AcknowledgementManager::maxListSize(void)
	{
		return maxListSize_;
	}

	void
	AcknowledgementManager::addNotification(
		uint32_t sequenceNumber,
		OpcUaExtensibleParameter::SPtr& notification
	)
	{
		AcknowledgementElement::SPtr acknowledgementElement = boost::make_shared<AcknowledgementElement>();
		acknowledgementElement->sequenceNumber(sequenceNumber);
		acknowledgementElement->notification(notification);
		acknowledgementList_.push_back(acknowledgementElement);

		if (maxListSize_ != 0 && acknowledgementList_.size() > maxListSize_) {
			// remove oldest element
			acknowledgementList_.pop_front();
		}
	}

	void AcknowledgementManager::deleteNotification(
		uint32_t sequenceNumber
	)
	{
		AcknowledgementList::iterator it;
		for (it = acknowledgementList_.begin(); it != acknowledgementList_.end(); it++) {
			AcknowledgementElement::SPtr& acknowledgementElement = *it;
			if (acknowledgementElement->sequenceNumber() == sequenceNumber) {
				acknowledgementList_.erase(it);
				return;
			}
		}
	}

	bool
	AcknowledgementManager::firstNotification(
		uint32_t& sequenceNumber,
		OpcUaExtensibleParameter::SPtr& notification
	)
	{
		if (acknowledgementList_.size() == 0) {
			return false;
		}

		sequenceNumber_ = acknowledgementList_.front()->sequenceNumber();
		notification = acknowledgementList_.front()->notification();
		return true;
	}

	bool
	AcknowledgementManager::getNotification(
		uint32_t sequenceNumber,
		OpcUaExtensibleParameter::SPtr& notification
	)
	{
		AcknowledgementList::iterator it;
		for (it = acknowledgementList_.begin(); it != acknowledgementList_.end(); it++) {
			AcknowledgementElement::SPtr& acknowledgementElement = *it;
			if (acknowledgementElement->sequenceNumber() == sequenceNumber) {
				notification = acknowledgementElement->notification();
				return true;
			}
		}
		return false;
	}

	void
	AcknowledgementManager::availableSequenceNumbers(
		OpcUaUInt32Array::SPtr& availableSequenceNumbers
	)
	{
		if (acknowledgementList_.size() == 0) return;

		AcknowledgementList::iterator it;
		availableSequenceNumbers->resize(acknowledgementList_.size());
		for (it = acknowledgementList_.begin(); it != acknowledgementList_.end(); it++) {
			availableSequenceNumbers->push_back((*it)->sequenceNumber());
		}
	}

}
