#ifndef __OpcUaStackCore_SlotTimer_h__
#define __OpcUaStackCore_SlotTimer_h__

#include "boost/date_time/posix_time/posix_time.hpp"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Callback.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Base/Condition.h"

namespace OpcUaStackCore 
{

	class DLLEXPORT SlotTimerElement
	{
	  public:
		typedef boost::shared_ptr<SlotTimerElement> SPtr;

		SlotTimerElement(void);
		~SlotTimerElement(void);

		Callback& callback(void);

		void expireFromNow(uint32_t msecInterval);
		void expireTime(boost::posix_time::ptime expireTime, uint32_t msecInterval);
		void expireTime(boost::posix_time::ptime expireTime);
		void interval(uint32_t msecInterval);

		boost::posix_time::ptime expireTime(void);
		uint32_t interval(void);

		bool isRunning(void);
		void tick(uint64_t tick);
		uint64_t tick(void);
		void handle(uint16_t handle);
		uint16_t handle(void);
		void next(SlotTimerElement::SPtr next);
		SlotTimerElement::SPtr& next(void);
		void last(SlotTimerElement::SPtr last);
		SlotTimerElement::SPtr& last(void);

	  private:
		Callback callback_;
		boost::posix_time::ptime expireTime_;
		uint32_t interval_;

		uint16_t handle_;
		uint64_t tick_;
		SlotTimerElement::SPtr next_;
		SlotTimerElement::SPtr last_;
	};

	class SlotTimer;
	class DLLEXPORT SlotArray
	{
	  public:
		SlotArray(uint8_t numberSlots, uint32_t ticksPerSlot);
		~SlotArray(void);

		void slotTimer(SlotTimer* slotTimer);
		void next(SlotArray* next);
		void init(uint64_t tickOffset = 0, uint8_t id = 0);
		void insert(SlotTimerElement::SPtr slotTimerElement);
		void remove(SlotTimerElement::SPtr slotTimerElement);
		uint32_t count(void);
		uint64_t run(boost::mutex* mutex);

		SlotTimerElement::SPtr removeActSlot(void);
		
	  private:
		void moveSlot(void);
		void add(uint8_t slotNumber, SlotTimerElement::SPtr slotTimerElement);
		void del(uint8_t slotNumber, SlotTimerElement::SPtr SlotTimerElement);

		uint8_t id_;
		uint8_t numberSlots_;
		uint32_t ticksPerSlot_;
		uint32_t ticksPerArray_;
		SlotTimerElement::SPtr* slotList_;
		uint32_t actSlot_;
		uint64_t tickOffset_;
		uint32_t count_;

		SlotTimer* slotTimer_;
		SlotArray* next_;
	};

	class DLLEXPORT SlotTimer
	{
	  public:
		typedef boost::shared_ptr<SlotTimer> SPtr;

		SlotTimer(void);
		~SlotTimer(void);

		void start(SlotTimerElement::SPtr slotTimerElement);
		void stop(SlotTimerElement::SPtr slotTimerElement);

		void startSlotTimerLoop(IOService* ioService);
		void stopSlotTimerLoop(void);
		void stopSlotTimerLoopSync(void);
		void stopSlotTimerLoop(SlotTimer::SPtr onwSPtr);

		void insert(SlotTimerElement::SPtr slotTimerElement);
		void remove(SlotTimerElement::SPtr slotTimerElement);
		uint32_t count(void);
		uint64_t run(void);
		
		void internalStart(SlotTimerElement::SPtr slotTimerElement);

	  private:
		void loop(const boost::system::error_code& error);

		bool debug_;
		SlotArray slotArray1_;
		SlotArray slotArray2_;
		SlotArray slotArray3_;
		SlotArray slotArray4_;
		SlotArray slotArray5_;

		boost::mutex mutex_;
		bool running_;
		boost::asio::deadline_timer* timer_;
		IOService* ioService_;
		boost::posix_time::ptime startTime_;
		uint32_t nextTick_;

		Condition stopCondition_;
		SlotTimer::SPtr ownSPtr_;
	};

}

#endif
