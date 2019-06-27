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

#ifndef __OpcUaStackCore_ReadProcessedDetails_h__
#define __OpcUaStackCore_ReadProcessedDetails_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/AggregateConfiguration.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ReadProcessedDetails
	: public  Object
	, public ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<ReadProcessedDetails> SPtr;

		ReadProcessedDetails(void);
		virtual ~ReadProcessedDetails(void);

		void startTime(const UtcTime& startTime);
		void startTime(const boost::posix_time::ptime& startTime);
		UtcTime& startTime(void);
		void endTime(const UtcTime& endTime);
		void endTime(const boost::posix_time::ptime& endTime);
		UtcTime& endTime(void);
		void resampleInterval(const OpcUaDouble& resampleInterval);
		OpcUaDouble resampleInterval(void);
		void aggregateType(const OpcUaNodeIdArray::SPtr aggregateType);
		OpcUaNodeIdArray::SPtr aggregateType(void) const;
		void aggregateConfiguration(const AggregateConfiguration& aggregateConfiguration);
		AggregateConfiguration& aggregateConfiguration(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::SPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		UtcTime startTime_;
		UtcTime endTime_;
		OpcUaDouble resampleInterval_;
		OpcUaNodeIdArray::SPtr aggregateTypeArraySPtr_;
		AggregateConfiguration aggregateConfiguration_;
	};

}

#endif
