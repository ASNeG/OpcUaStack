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

#ifndef __OpcUaStackCore_AggregateFilterResult_h__
#define __OpcUaStackCore_AggregateFilterResult_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT AggregateFilterResult
	: public  Object
	, public ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<AggregateFilterResult> SPtr;

		AggregateFilterResult(void);
		virtual ~AggregateFilterResult(void);

		void revisedStartTime(const UtcTime& time);
		void revisedStartTime(const boost::posix_time::ptime& time);
		UtcTime revisedStartTime(void) const;
		void revisedProcessingInterval(const OpcUaDouble& revisedProcessingInterval);
		OpcUaDouble revisedProcessingInterval(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::SPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		UtcTime revisedStartTime_;
		OpcUaDouble revisedProcessingInterval_;
	};

}

#endif
