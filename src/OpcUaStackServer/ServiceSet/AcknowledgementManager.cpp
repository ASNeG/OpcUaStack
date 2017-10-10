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

#include "OpcUaStackServer/ServiceSet/AcknowledgementManager.h"

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
	, dataChangeNotification_()
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
	AcknowledgementElement::dataChangeNotification(DataChangeNotification::SPtr& dataChangeNotification)
	{
		dataChangeNotification_ = dataChangeNotification;
	}

	DataChangeNotification::SPtr
	AcknowledgementElement::dataChangeNotification(void)
	{
		return dataChangeNotification_;
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
	{
	}

	AcknowledgementManager::~AcknowledgementManager(void)
	{
	}

	uint32_t
	AcknowledgementManager::nextSequenceNumber(void)
	{
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
	AcknowledgementManager::addDataChangeNotification(
		uint32_t sequenceNumber,
		DataChangeNotification::SPtr& dataChangeNotification
	)
	{
		AcknowledgementElement::SPtr acknowledgementElement = constructSPtr<AcknowledgementElement>();
		acknowledgementElement->sequenceNumber(sequenceNumber);
		acknowledgementElement->dataChangeNotification(dataChangeNotification);
		acknowledgementList_.push_back(acknowledgementElement);

		if (maxListSize_ != 0 && acknowledgementList_.size() > maxListSize_) {
			// remove oldest element
			acknowledgementList_.pop_back();
		}
	}

	void AcknowledgementManager::deleteDataChangeNotification(
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
	AcknowledgementManager::firstDataChangeNotification(
		uint32_t& sequenceNumber,
		DataChangeNotification::SPtr& dataChangeNotification
	)
	{
		if (acknowledgementList_.size() == 0) {
			return false;
		}

		sequenceNumber_ = acknowledgementList_.front()->sequenceNumber();
		dataChangeNotification = acknowledgementList_.front()->dataChangeNotification();
		return true;
	}

	bool
	AcknowledgementManager::getDataChangeNotification(
		uint32_t sequenceNumber,
		DataChangeNotification::SPtr& dataChangeNotification
	)
	{
		AcknowledgementList::iterator it;
		for (it = acknowledgementList_.begin(); it != acknowledgementList_.end(); it++) {
			AcknowledgementElement::SPtr& acknowledgementElement = *it;
			if (acknowledgementElement->sequenceNumber() == sequenceNumber) {
				dataChangeNotification = acknowledgementElement->dataChangeNotification();
				return true;
			}
		}
		return false;
	}

}
