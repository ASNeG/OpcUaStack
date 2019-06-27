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

#ifndef __OpcUaStackCore_ReadEventDetails_h__
#define __OpcUaStackCore_ReadEventDetails_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/EventFilter.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ReadEventDetails
	: public Object
	, public ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<ReadEventDetails> SPtr;

		ReadEventDetails(void);
		virtual ~ReadEventDetails(void);

		void numValuesPerNode(const OpcUaUInt32& numValuesPerNode);
		OpcUaUInt32 numValuesPerNode(void) const;
		void startTime(const UtcTime& startTime);
		void startTime(const boost::posix_time::ptime& startTime);
		UtcTime& startTime(void);
		void endTime(const UtcTime& endTime);
		void endTime(const boost::posix_time::ptime& endTime);
		UtcTime& endTime(void);
		void filter(const EventFilter::SPtr& filter);
		EventFilter::SPtr& filter(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::SPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		OpcUaUInt32 numValuesPerNode_;
		UtcTime startTime_;
		UtcTime endTime_;
		EventFilter::SPtr filterSPtr_;
	};

}

#endif
