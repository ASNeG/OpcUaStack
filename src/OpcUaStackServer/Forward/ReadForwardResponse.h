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

#ifndef __OpcUaStackCore_ReadForwardResponse_h__
#define __OpcUaStackCore_ReadForwardResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaDataValue.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ReadForwardResponse
	: public OpcUaStackCore::Object
	{
	  public:
		typedef boost::shared_ptr<ReadForwardResponse> SPtr;

		ReadForwardResponse(void);
		virtual ~ReadForwardResponse(void);

		void dataValue(const OpcUaStackCore::OpcUaDataValue::SPtr& dataValue);
		OpcUaStackCore::OpcUaDataValue::SPtr dataValue(void) const;

	  private:
		OpcUaStackCore::OpcUaDataValue::SPtr dataValue_ = nullptr;
	};

}

#endif
