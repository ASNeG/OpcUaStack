/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_IOThread_h__
#define __OpcUaStackCore_IOThread_h__

#include <boost/shared_ptr.hpp>
#include <boost/asio/strand.hpp>
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Utility/SlotTimer.h"

namespace OpcUaStackCore
{
	class DLLEXPORT IOThread
	{
	  public:
		typedef boost::shared_ptr<IOThread> SPtr;
		typedef std::map<std::string, IOThread::SPtr> Map;

		typedef std::function<void (void)> AsyncCallback;

		IOThread(void);
		IOThread(const std::string& name);
		~IOThread(void);

		void name(const std::string& name);
		std::string name(void);
		void ioService(const IOService::SPtr& ioService);
		IOService::SPtr& ioService(void);
		void slotTimer(const SlotTimer::SPtr& slotTimer);
		SlotTimer::SPtr& slotTimer(void);
		uint32_t numberThreads(void);
		void numberThreads(uint32_t numberThreads);
		void threadIdVec(std::vector<std::string>& threadIdVec);
		boost::shared_ptr<boost::asio::io_service::strand> createStrand(void);
		bool isOwnThread(void);
		bool isOwnThread(const std::string& threadId);

		bool startup(void);
		bool shutdown(void);

		void run(
			const AsyncCallback& asyncCallback
		);
		void run(
		    const boost::shared_ptr<boost::asio::io_service::strand>& strand,
			const AsyncCallback& asyncCallback
		);

	  private:
		void createIOService(void);
		void deleteIOService(void);
		void createSlotTimer(void);
		void deleteSlotTimer(void);

		std::string name_ = "";
		uint32_t numberThreads_;
		IOService::SPtr ioService_;
		SlotTimer::SPtr slotTimer_;
		bool ioServiceCreateFlag_;
		bool slotTimerCreateFlag_;
	};

}

#endif
