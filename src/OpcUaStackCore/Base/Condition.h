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

#ifndef __OpcUaStackCore_Condition_h__
#define __OpcUaStackCore_Condition_h__

#include <boost/thread/condition.hpp>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT Condition
	{
	  public:
		Condition(uint32_t conditionValue = 0, uint32_t conditionValueTrue = 0);
		virtual ~Condition(void);

		void condition(uint32_t conditionValue, uint32_t conditionValueTrue);
		void conditionValueTrue(uint32_t conditionValueTrue);
		uint32_t conditionValueTrue(void);
		void conditionValue(uint32_t conditionValue);
		uint32_t conditionValue(void);
		void conditionValueInc(void);
		void conditionValueDec(void);

		void waitForCondition(void);
		bool waitForCondition(uint32_t msec);

	  private:
		uint32_t conditionValue_;
		uint32_t conditionValueTrue_;
		boost::mutex mutex_;
		boost::condition condition_;
	};

}

#endif
