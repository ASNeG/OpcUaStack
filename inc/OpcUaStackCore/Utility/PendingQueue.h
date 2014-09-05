#ifndef __OpcUaStackCore_PendingQueue_h__
#define __OpcUaStackCore_PendingQueue_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Object.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/Callback.h"
#include "OpcUaStackCore/Utility/Timer.h"

namespace OpcUaStackCore
{

	class DLLEXPORT PendingQueueElement : public ObjectPool<PendingQueueElement>
	{
	  public:
		PendingQueueElement(IOService& ioService);
		~PendingQueueElement(void);

		void key(uint32_t key);
		uint32_t key(void);
		void element(const Object::SPtr element);
		Object::SPtr element(void);

		Timer::SPtr timer(void);

	  private:
		uint32_t key_;
		Timer::SPtr timer_;
		Object::SPtr element_;
	};


	class DLLEXPORT PendingQueue
	{
	  public:
		PendingQueue(IOService& ioService);
		~PendingQueue(void);

		Callback& timeoutCallback(void);

		bool insert(uint32_t key, Object::SPtr object, uint32_t timeoutMSec);
		Object::SPtr remove(uint32_t key);

	  private:
		void onTimeout(PendingQueueElement::SPtr pendingQueueElementSPtr);

		IOService* ioService_;
		typedef std::map<uint32_t, PendingQueueElement::SPtr> PendingQueueMap;
		PendingQueueMap pendingQueueMap_;
		Callback timeoutCallback_;
	};

}

#endif