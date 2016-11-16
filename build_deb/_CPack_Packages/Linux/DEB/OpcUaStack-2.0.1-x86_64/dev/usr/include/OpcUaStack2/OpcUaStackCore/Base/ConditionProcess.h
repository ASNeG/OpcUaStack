/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_ConditionProcess_h__
#define __OpcUaStackCore_ConditionProcess_h__

#include <boost/thread/condition.hpp>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ConditionProcess
	{
	  public:
		ConditionProcess(void);
		virtual ~ConditionProcess(void);

		void start(void);
		void ready(void);
		void waitForReady(void);
		bool waitForReady(uint32_t msec);
		bool isStart(void);
		bool isReady(void);

	  private:
		typedef enum {
			ProcessOff,
			ProcessStart,
			ProcessReady
		} State;

		State conditionValue_;
		boost::mutex mutex_;
		boost::condition condition_;
	};

}

#endif
