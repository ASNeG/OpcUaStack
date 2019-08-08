/*
   Copyright 2016-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_ApplicationHReadContext_h__
#define __OpcUaStackCore_ApplicationHReadContext_h__

#include "OpcUaStackCore/Base/BaseClass.h"
#include "OpcUaStackCore/Base/UserContext.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaDataValue.h"
#include "OpcUaStackCore/ServiceSet/TimestampsToReturn.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ApplicationHReadContext
	{
	  public:
		ApplicationHReadContext(void);
		~ApplicationHReadContext(void);

		BaseClass::SPtr applicationContext_;		// IN - application context from register call
		OpcUaNodeId nodeId_;						// IN - node id to be read
		boost::posix_time::ptime startTime_;		// IN - Start time of variables
		boost::posix_time::ptime stopTime_;			// IN - stop time of variables
		TimestampsToReturn timestampsToReturn_;		// IN - what timestamps are to be returned
		OpcUaBoolean releaseContinuationPoints_;	// IN - info about whether the continous
													//      point schould be deleted
		std::string continousPoint_;				// IN - continous point or empty string
		uint32_t numValuesPerNode_;					// IN - maximum number of data values in result array
		UserContext::SPtr userContext_;				// IN - user context
		OpcUaDataValueArray::SPtr dataValueArray_;	// OUT - result data array
		OpcUaStatusCode statusCode_;				// OUT - status code of the read operation
	};

}

#endif
