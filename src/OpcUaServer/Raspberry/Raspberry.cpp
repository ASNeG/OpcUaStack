#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaServer/Raspberry/Raspberry.h"
#ifdef RASPBERRY
#include <wiringPi.h>
#endif

using namespace OpcUaStackCore;

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
#ifndef RASPBERRY
		return;
#endif
		OpcUaNodeId nodeId;
		OpcUaString::SPtr nodeIdString;
		BaseNodeClass::SPtr baseNodeClass;
		GpioBinaryItemVec::iterator it;

		Log(Info, "init component raspberry");

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
		if (wiringPiSetup() == -1) {
			Log(Error, "wiring pipe setup error");
			return;
		}
#endif

		for (it=outputGpioBinaryItemVec_.begin(); it!=outputGpioBinaryItemVec_.end(); it++) {

			if (!pinTowPi(it->pin_, it->wPi_)) {
				Log(Error, "cannot map pin to wPi")
					.parameter("Pin", (uint32_t)it->pin_)
					.parameter("NodeId", it->nodeIdValue_);
				return;

			}

			Log(Debug, "init output pin")
				.parameter("Pin", (uint32_t)it->pin_)
				.parameter("NodeId", it->nodeIdValue_)
				.parameter("wPi", it->wPi_);

#ifdef RASPBERRY
			pinMode(it->wPi_, OUTPUT);
#endif
		}

		for (it=inputGpioBinaryItemVec_.begin(); it!=inputGpioBinaryItemVec_.end(); it++) {

			if (!pinTowPi(it->pin_, it->wPi_)) {
				Log(Error, "cannot map pin to wPi")
					.parameter("Pin", (uint32_t)it->pin_)
					.parameter("NodeId", it->nodeIdValue_);
				return;

			}


			Log(Debug, "init input pin")
				.parameter("Pin", (uint32_t)it->pin_)
				.parameter("NodeId", it->nodeIdValue_)
				.parameter("wPi", it->wPi_);

#ifdef RASPBERRY
			pinMode(it->wPi_, INPUT);
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


			Log(Debug, "Set output pin")
				.parameter("Pin", (uint32_t)it->pin_)
				.parameter("wPi", it->wPi_)
				.parameter("NodeId", it->nodeIdValue_)
				.parameter("Value", value);

#ifdef RASPBERRY
			if (value) digitalWrite(it->wPi_, 1);
			else digitalWrite(it->wPi_, 0);
#endif
		}

		for (it=inputGpioBinaryItemVec_.begin(); it!=inputGpioBinaryItemVec_.end(); it++) {
			int value = 0;
#ifdef RASPBERRY
			value = digitalRead(it->wPi_);
#endif

			bool val;
		    if (value == 1) val = true;
			else val = false;


			Log(Debug, "Get input pin")
				.parameter("Pin", (uint32_t)it->pin_)
				.parameter("wPi", it->wPi_)
				.parameter("NodeId", it->nodeIdValue_)
				.parameter("Value", val);

            setValue(it->nodeIdValue_, val);
		}

		timer_->expires_from_now(boost::posix_time::millisec(1000));
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

	bool 
	Raspberry::pinTowPi(OpcUaByte pin, uint32_t& wPi)
	{
		switch((uint32_t)pin)
		{
			case 3: wPi = 8; break;
			case 5: wPi = 9; break;
			case 7: wPi = 7; break;
			case 8: wPi = 15; break;
			case 10: wPi = 16; break;
			case 11: wPi = 0; break;
			case 12: wPi = 1; break;
			case 13: wPi = 2; break;
			case 15: wPi = 3; break;
			case 16: wPi = 4; break;
			case 18: wPi = 5; break;
			case 19: wPi = 12; break;
			case 21: wPi = 13; break;
			case 22: wPi = 6; break;
			case 23: wPi = 14; break;
			case 24: wPi = 10; break;
			case 26: wPi = 11; break;
			case 27: wPi = 30; break;
			case 28: wPi = 31; break;
			case 29: wPi = 21; break;
			case 31: wPi = 22; break;
			case 32: wPi = 26; break;
			case 33: wPi = 23; break;
			case 35: wPi = 24; break;
			case 36: wPi = 27; break;
			case 37: wPi = 25; break;
			case 38: wPi = 28; break;
			case 40: wPi = 29; break;
			default: return false; 
		}
		return true;
	}

}
