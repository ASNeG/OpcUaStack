/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_IOService_h__
#define __OpcUaStackCore_IOService_h__

#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/thread/condition.hpp>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT IOService
	{
	  public:
		typedef boost::shared_ptr<IOService> SPtr;

		IOService();
		virtual ~IOService();

		static void secSleep(uint32_t sec);
		static void msecSleep(uint32_t msec);

		void start(uint32_t numberThreads = 1);
		void stop(void);
		void threadIdVec(std::vector<std::string>& threadIdVec);
		template<typename HANDLER>
		  void run(HANDLER handler);
		boost::asio::io_service& io_service(void);

	  private:
		void runThreads(void);

		uint32_t numberThreads_;
		uint32_t runningThreads_;
		boost::asio::io_service io_service_;
		boost::asio::io_service::work *work_;

		boost::mutex startMutex_;
		boost::condition startCondition_;
		boost::mutex stopMutex_;
		boost::condition stopCondition_;

		typedef std::vector<boost::thread*> ThreadVec;
		ThreadVec threadVec_;
		std::vector<std::string> threadIdVec_;
	};


	template<typename HANDLER>
	  void 
	  IOService::run(HANDLER handler)
	  {
		  io_service_.post(
		      handler
	      );
      }

}

#endif
