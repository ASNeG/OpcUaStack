/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaDataValue.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/ServiceSet/TimestampsToReturn.h"

namespace OpcUaStackCore
{

	class ApplicationHReadContext
	{
	  public:

		OpcUaNodeId nodeId_;
		boost::posix_time::ptime startTime_;
		boost::posix_time::ptime stopTime_;
		TimestampsToReturn timestampsToReturn_;
		OpcUaDataValueArray::SPtr dataValueArray_;
		OpcUaStatusCode statusCode_;
		BaseClass::SPtr applicationContext_;
		OpcUaBoolean releaseContinuationPoints_;
	};

}

#endif
