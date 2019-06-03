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

#include "OpcUaStackCore/ServiceSet/ReadResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ReadResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ReadResponse::ReadResponse(void)
	: Object()
	, dataValueArraySPtr_(constructSPtr<OpcUaDataValueArray>())
	, diagnosticInfoArraySPtr_(constructSPtr<OpcUaDiagnosticInfoArray>())
	{
	}

	ReadResponse::~ReadResponse(void)
	{
	}

	void 
	ReadResponse::dataValueArray(const OpcUaDataValueArray::SPtr dataValueArraySPtr)
	{
		dataValueArraySPtr_ = dataValueArraySPtr;
	}
	
	OpcUaDataValueArray::SPtr 
	ReadResponse::dataValueArray(void) const
	{
		return dataValueArraySPtr_;
	}

	void 
	ReadResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfoArraySPtr;
	}

	OpcUaDiagnosticInfoArray::SPtr 
	ReadResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	bool 
	ReadResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		dataValueArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
		return true;
	}
	
	bool 
	ReadResponse::opcUaBinaryDecode(std::istream& is)
	{
		dataValueArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
		return true;
	}

	bool
	ReadResponse::jsonEncodeImpl(boost::property_tree::ptree& pt) const
	{
		// encode data value array
		if (!dataValueArraySPtr_->jsonEncode(pt, "Results")) {
			Log(Error, "ReadResponse json encode error")
				.parameter("Element", "Results");
			return false;
		}

		return true;
	}

	bool
	ReadResponse::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		// decode value id array
		if (!dataValueArraySPtr_->jsonDecode(pt, "Results")) {
			Log(Error, "ReadResponse json decode error")
			    .parameter("Element", "Results");
			return false;
		}

		return true;
	}

}
