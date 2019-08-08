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

#ifndef __OpcUaStackCore_HistoryUpdateResponse_h__
#define __OpcUaStackCore_HistoryUpdateResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaDiagnosticInfo.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/ServiceSet/HistoryUpdateResult.h"

namespace OpcUaStackCore
{

	class DLLEXPORT HistoryUpdateResponse
	: public Object
	, public JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<HistoryUpdateResponse> SPtr;

		HistoryUpdateResponse(void);
		virtual ~HistoryUpdateResponse(void);

		void results(const HistoryUpdateResultArray::SPtr results);
		HistoryUpdateResultArray::SPtr results(void) const;
		void diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr);
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfos(void) const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return false; }
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return false; }

	  protected:
		bool jsonEncodeImpl(boost::property_tree::ptree &pt) const { return false; }
		bool jsonDecodeImpl(const boost::property_tree::ptree &pt) { return false; }

	  private:
		ResponseHeader::SPtr responseHeaderSPtr_;
		HistoryUpdateResultArray::SPtr resultArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr_;
	};

}

#endif
