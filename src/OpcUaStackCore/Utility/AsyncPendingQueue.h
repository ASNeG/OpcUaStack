/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_AsyncPendingQueue_h__
#define __OpcUaStackCore_AsyncPendingQueue_h__

#include <boost/thread/mutex.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio/strand.hpp>
#include <map>
#include <list>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Object.h"
#include "OpcUaStackCore/Utility/AsyncPendingQueueConfig.h"
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackCore/Utility/SlotTimer.h"

namespace OpcUaStackCore
{

    class DLLEXPORT AsyncPendingQueueElement
    {
      public:
	    using SPtr = boost::shared_ptr<AsyncPendingQueueElement>;
	    using Map = std::map<uint32_t, SPtr>;
	    using List = std::list<SPtr>;

	    AsyncPendingQueueElement(void);
	    ~AsyncPendingQueueElement(void);

	    void key(uint32_t key);
	    uint32_t key(void);
	    void element(const Object::SPtr element);
	    Object::SPtr element(void);

	    SlotTimerElement::SPtr& slotTimerElement(void);

      private:
	    uint32_t key_ = 0;
	    Object::SPtr element_ = nullptr;
	    SlotTimerElement::SPtr slotTimerElement_ = nullptr;
    };


	class DLLEXPORT AsyncPendingQueue
	{
	  public:
		using SPtr = boost::shared_ptr<AsyncPendingQueue>;
		using TimeoutCallback = std::function<void (bool error, uint32_t key, Object::SPtr& object)>;

		AsyncPendingQueue(AsyncPendingQueueConfig& messageBusConfig);
		virtual ~AsyncPendingQueue(void);

		void asyncCancel(void);
		void syncCancel(void);

		bool insert(uint32_t key, Object::SPtr object, uint32_t timeoutMSec);
		Object::SPtr remove(uint32_t key);

		void asyncTimeout(
			const TimeoutCallback& timeoutCallback
		);

		void keys(std::vector<uint32_t>& keys);

	  private:
		void onTimeout(
			uint32_t key
		);
		void runCallback(void);

		bool cancel_ = false;
		AsyncPendingQueueConfig asyncPendingQueueConfig_;
		AsyncPendingQueueElement::Map pendingQueueMap_;
		AsyncPendingQueueElement::List pendingQueueList_;
		TimeoutCallback timeoutCallback_;

	};

}

#endif
