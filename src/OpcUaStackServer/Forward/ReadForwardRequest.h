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

#ifndef __OpcUaStackCore_ReadForwardRequest_h__
#define __OpcUaStackCore_ReadForwardRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"
#include "OpcUaStackCore/ServiceSet/ReadValueId.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ReadForwardRequest
	: public OpcUaStackCore::Object
	{
	  public:
		using SPtr = boost::shared_ptr<ReadForwardRequest>;

		ReadForwardRequest(void);
		virtual ~ReadForwardRequest(void);

		void maxAge(const OpcUaStackCore::OpcUaDouble& maxAge);
		OpcUaStackCore::OpcUaDouble maxAge(void) const;
		void timestampsToReturn(const OpcUaStackCore::OpcUaInt32& timestampsToReturn);
		OpcUaStackCore::OpcUaInt32 timestampsToReturn(void) const;
		void readValueId(const OpcUaStackCore::ReadValueId::SPtr readValueId);
		OpcUaStackCore::ReadValueId::SPtr readValueId(void) const;

	  private:
		OpcUaStackCore::OpcUaDouble maxAge_ = 0;
		OpcUaStackCore::OpcUaInt32 timestampsToReturn_ = 0;
		OpcUaStackCore::ReadValueId::SPtr readValueId_ = nullptr;
	};

}

#endif
