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

#ifndef __OpcUaStackCore_ReadResponse_h__
#define __OpcUaStackCore_ReadResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaDataValue.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ReadResponse
	: public Object
	, public JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<ReadResponse> SPtr;

		ReadResponse(void);
		virtual ~ReadResponse(void);

		void dataValueArray(const OpcUaDataValueArray::SPtr dataValueArraySPtr);
		OpcUaDataValueArray::SPtr dataValueArray(void) const;
		void diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr);
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfos(void) const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  protected:
		bool jsonEncodeImpl(boost::property_tree::ptree &pt) const;
		bool jsonDecodeImpl(const boost::property_tree::ptree &pt);

	  private:
		OpcUaDataValueArray::SPtr dataValueArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr_;
	};

}

#endif
