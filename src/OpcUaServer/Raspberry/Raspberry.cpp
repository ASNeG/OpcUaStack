#define RASPBERRY

#include "OpcUaServer/Raspberry/Raspberry.h"
#ifdef RASPBERRY
#include <wiringPi.h>
#endif

namespace OpcUaServer
{

	Raspberry::Raspberry(void)
	: timer_(nullptr)
	{
	}

	Raspberry::~Raspberry(void)
	{
		if (timer_ != nullptr) {
			delete timer_;
			timer_ = nullptr;
		}
	}

	void 
	Raspberry::informationModel(InformationModel::SPtr informationModel)
	{
		informationModel_ = informationModel;
	}

	void 
	Raspberry::ioService(IOService& ioService)
	{
		ioService_ = &ioService;
	}

	void
	Raspberry::start(void)
	{
		OpcUaNodeId nodeId;
		OpcUaString::SPtr nodeIdString;
		BaseNodeClass::SPtr baseNodeClass;
		GpioBinaryItemVec::iterator it;

		nodeId.namespaceIndex(1);
		nodeIdString = OpcUaString::construct();
		nodeIdString->value("Raspberry.BinaryOutput");
		nodeId.nodeId(nodeIdString);
		baseNodeClass = informationModel_->find(nodeId);
		if (baseNodeClass.get() != nullptr) readValues(baseNodeClass, outputGpioBinaryItemVec_);

		nodeId.namespaceIndex(1);
		nodeIdString = OpcUaString::construct();
		nodeIdString->value("Raspberry.BinaryInput");
		nodeId.nodeId(nodeIdString);
		baseNodeClass = informationModel_->find(nodeId);
		if (baseNodeClass.get() != nullptr) readValues(baseNodeClass, inputGpioBinaryItemVec_);

#ifdef RASPBERRY
		wiringPiSetup();
#endif

		for (it=outputGpioBinaryItemVec_.begin(); it!=outputGpioBinaryItemVec_.end(); it++) {
#ifdef RASPBERRY
			pinMode(it->pin_, OUTPUT);
#endif
		}

		for (it=inputGpioBinaryItemVec_.begin(); it!=inputGpioBinaryItemVec_.end(); it++) {
#ifdef RASPBERRY
			pinMode(it->pin_, INPUT);
#endif
		}

		timer_ = new boost::asio::deadline_timer(ioService_->io_service());
		timer_->expires_from_now(boost::posix_time::millisec(0));
		timer_->async_wait(
			boost::bind(&Raspberry::onTimeout, this, boost::asio::placeholders::error)
		);
	}

	void 
	Raspberry::onTimeout(const boost::system::error_code& ec)
	{
		GpioBinaryItemVec::iterator it;
		if (ec) return;

		for (it=outputGpioBinaryItemVec_.begin(); it!=outputGpioBinaryItemVec_.end(); it++) {
                        bool value;
			getValue(it->nodeIdValue_, value);
#ifdef RASPBERRY
			if (value) digitalWrite(it->pin_, 1);
			else digitalWrite(it->pin_, 0);
#endif
		}

		for (it=inputGpioBinaryItemVec_.begin(); it!=inputGpioBinaryItemVec_.end(); it++) {
			int value = 0;
#ifdef RASPBERRY
			value = digitalRead(it->pin_);
#endif
                        if (value == 1) setValue(it->nodeIdValue_, true);
			else setValue(it->nodeIdValue_, false);
		}

		timer_->expires_from_now(boost::posix_time::millisec(100));
		timer_->async_wait(
			boost::bind(&Raspberry::onTimeout, this, boost::asio::placeholders::error)
		);
	}

	bool
	Raspberry::setValue(OpcUaNodeId& nodeId, bool value)
	{
		BaseNodeClass::SPtr baseNodeClassTarget = informationModel_->find(nodeId);
		if (baseNodeClassTarget.get() == nullptr) return false;

		ValueAttribute *valueAttribute = reinterpret_cast<ValueAttribute*>(baseNodeClassTarget->valueAttribute());
		valueAttribute->data().variant()->variant(value);
		return true;
	}

	bool
	Raspberry::getValue(OpcUaNodeId& nodeId, bool& value)
	{
		BaseNodeClass::SPtr baseNodeClassTarget = informationModel_->find(nodeId);
		if (baseNodeClassTarget.get() == nullptr) return false;

		ValueAttribute *valueAttribute = reinterpret_cast<ValueAttribute*>(baseNodeClassTarget->valueAttribute());
		value = valueAttribute->data().variant()->variant<OpcUaBoolean>();
		return true;
	}

	bool 
	Raspberry::readValues(BaseNodeClass::SPtr baseNodeClass, GpioBinaryItemVec& gpioBinaryItemVec)
	{
		std::pair<ReferenceItemMultiMap::iterator,ReferenceItemMultiMap::iterator> it;
		it = baseNodeClass->referenceItemMap().referenceItemMultiMap().equal_range(*ReferenceTypeMap::hasComponentTypeNodeId());

		ReferenceItemMultiMap::iterator itl;
		for (itl = it.first; itl != it.second; itl++) {
			ReferenceItem::SPtr referenceItem  = itl->second;

			BaseNodeClass::SPtr baseNodeClassTarget = informationModel_->find(referenceItem->nodeId_);
			if (baseNodeClassTarget.get() == nullptr) continue;

			GpioBinaryItem gpioBinaryItem;
			gpioBinaryItem.nodeIdValue_ = baseNodeClassTarget->nodeId().data();

			if (readPropertyPin(baseNodeClassTarget, gpioBinaryItem)) {
				gpioBinaryItemVec.push_back(gpioBinaryItem);
			}
		}
		
		return true;
	}

	bool
	Raspberry::readPropertyPin(BaseNodeClass::SPtr baseNodeClass, GpioBinaryItem& gpioBinaryItem)
	{
		std::pair<ReferenceItemMultiMap::iterator,ReferenceItemMultiMap::iterator> it;
		it = baseNodeClass->referenceItemMap().referenceItemMultiMap().equal_range(*ReferenceTypeMap::hasPropertyTypeNodeId());

		ReferenceItemMultiMap::iterator itl;
		for (itl = it.first; itl != it.second; itl++) {
			ReferenceItem::SPtr referenceItem  = itl->second;

			BaseNodeClass::SPtr baseNodeClassTarget = informationModel_->find(referenceItem->nodeId_);
			if (baseNodeClassTarget.get() == nullptr) continue;

			if (baseNodeClassTarget->browseName().data().name().value() == "Pin") {
				ValueAttribute *valueAttribute = reinterpret_cast<ValueAttribute*>(baseNodeClassTarget->valueAttribute());
				gpioBinaryItem.pin_ = valueAttribute->data().variant()->variant<OpcUaByte>();
				return true;
			}
		}

		return false;
	}

}
