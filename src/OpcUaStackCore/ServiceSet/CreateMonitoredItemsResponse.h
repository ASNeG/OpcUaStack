/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_CreateMonitoredItemsResponse_h__
#define __OpcUaStackCore_CreateMonitoredItemsResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/StandardDataTypes/MonitoredItemCreateResult.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CreateMonitoredItemsResponse
	: public Object
	, public JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<CreateMonitoredItemsResponse> SPtr;

		CreateMonitoredItemsResponse(void);
		virtual ~CreateMonitoredItemsResponse(void);

		void results(const MonitoredItemCreateResultArray::SPtr results);
		MonitoredItemCreateResultArray::SPtr results(void) const;
		void diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos);
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfos(void) const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  protected:
		bool jsonEncodeImpl(boost::property_tree::ptree &pt) const;
		bool jsonDecodeImpl(const boost::property_tree::ptree &pt);

	  private:
		MonitoredItemCreateResultArray::SPtr resultArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr_;
	};

}

#endif
