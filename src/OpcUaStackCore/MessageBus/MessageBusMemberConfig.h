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

#ifndef __OpcUaStackCore_MessageBusMemberConfig_h__
#define __OpcUaStackCore_MessageBusMemberConfig_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Utility/IOThread.h"

namespace OpcUaStackCore
{

	class DLLEXPORT MessageBusMemberConfig
	{
	  public:
		MessageBusMemberConfig(void);
		MessageBusMemberConfig(MessageBusMemberConfig& messageBusConfig);
		~MessageBusMemberConfig(void);

		void maxReceiveQueueSize(uint32_t maxReceiveQueueSize);
		uint32_t maxReceiveQueueSize(void);
		void ioThread(IOThread::SPtr& ioThread);
		IOThread::SPtr& ioThread(void);
		void strand(const boost::shared_ptr<boost::asio::io_service::strand>& strand);
		boost::shared_ptr<boost::asio::io_service::strand>& strand(void);

	  private:
		uint32_t maxReceiveQueueSize_ = 0;
		IOThread::SPtr ioThread_ = nullptr;			// IOThread to execute callbacks. This value can be
		                                            // overwritten by strands in the functions and by the
		                                            // strand in the message bus configuration.
		boost::shared_ptr<boost::asio::io_service::strand> strand_ = nullptr; // Strand to execute callbacks.
		                                            // This value can be overwritten by strands in the functions

	};

}

#endif
