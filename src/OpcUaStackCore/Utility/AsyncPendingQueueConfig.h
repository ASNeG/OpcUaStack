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

#ifndef __OpcUaStackCore_AsyncPendingQueueConfig_h__
#define __OpcUaStackCore_AsyncPendingQueueConfig_h__

#include <boost/asio/strand.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Utility/IOThread.h"

namespace OpcUaStackCore
{

	class DLLEXPORT AsyncPendingQueueConfig
	{
	  public:
		AsyncPendingQueueConfig(void);
		AsyncPendingQueueConfig(AsyncPendingQueueConfig& asyncPendingQueueConfig);
		~AsyncPendingQueueConfig(void);

		void slotTimer(SlotTimer::SPtr& slotTimer);
		SlotTimer::SPtr& slotTimer(void);
		void strand(boost::shared_ptr<boost::asio::io_service::strand> strand);
		boost::shared_ptr<boost::asio::io_service::strand>& strand(void);

		void maxPendingQueueSize(uint32_t maxPendingQueueSize);
		uint32_t maxPendingQueueSize(void);

	  private:
		SlotTimer::SPtr slotTimer_ = nullptr;
		boost::shared_ptr<boost::asio::io_service::strand> strand_ = nullptr;

		// default parameter for message bus member
		uint32_t maxPendingQueueSize_ = 0;

	};

}

#endif
