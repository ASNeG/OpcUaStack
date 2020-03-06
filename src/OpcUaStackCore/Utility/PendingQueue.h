/*
   Copyright 2019-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_PendingQueue_h__
#define __OpcUaStackCore_PendingQueue_h__

#include "OpcUaStackCore/Base/Object.h"
#include "OpcUaStackCore/Utility/Timer.h"

namespace OpcUaStackCore
{

	class DLLEXPORT PendingQueueElement
	{
	  public:
		typedef boost::shared_ptr<PendingQueueElement> SPtr;

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
		typedef boost::shared_ptr<PendingQueue> SPtr;
		using TimeoutCallback = std::function<void (Object::SPtr&)>;

		PendingQueue(void);
		PendingQueue(IOService& ioService);
		~PendingQueue(void);

		void ioService(IOService& ioService);
		void timeoutCallback(const TimeoutCallback timeoutCallback);

		bool insert(uint32_t key, Object::SPtr object, uint32_t timeoutMSec);
		Object::SPtr remove(uint32_t key);

		void keys(std::vector<uint32_t>& keys);

	  private:
		void onTimeout(uint32_t key);

		IOService* ioService_;
		typedef std::map<uint32_t, PendingQueueElement::SPtr> PendingQueueMap;
		PendingQueueMap pendingQueueMap_;
		TimeoutCallback timeoutCallback_;
	};

}

#endif
