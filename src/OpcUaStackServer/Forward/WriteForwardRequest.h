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

#ifndef __OpcUaStackCore_WriteForwardRequest_h__
#define __OpcUaStackCore_WriteForwardRequest_h__

#include "OpcUaStackCore/ServiceSet/WriteValue.h"

namespace OpcUaStackServer
{

	class DLLEXPORT WriteForwardRequest
	: public OpcUaStackCore::Object
	{
	  public:
		typedef boost::shared_ptr<WriteForwardRequest> SPtr;

		WriteForwardRequest(void);
		virtual ~WriteForwardRequest(void);

		void writeValue(const OpcUaStackCore::WriteValue::SPtr& writeValue);
		OpcUaStackCore::WriteValue::SPtr writeValue(void) const;

	  private:
		  OpcUaStackCore::WriteValue::SPtr writeValue_ = nullptr;

	};

}

#endif
