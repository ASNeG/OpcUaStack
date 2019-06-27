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

#ifndef __OpcUaStackCore_CallRequest_h__
#define __OpcUaStackCore_CallRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/CallMethodRequest.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CallRequest
	: public Object
	, public JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<CallRequest> SPtr;

		CallRequest(void);
		virtual ~CallRequest(void);

		void requestHeader(const RequestHeader::SPtr requestHeader);
		RequestHeader::SPtr requestHeader(void) const;
		void methodsToCall(const CallMethodRequestArray::SPtr methodsToCall);
		CallMethodRequestArray::SPtr methodsToCall(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  protected:
	    bool jsonEncodeImpl(boost::property_tree::ptree &pt) const override;
	    bool jsonDecodeImpl(const boost::property_tree::ptree &pt) override;

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		CallMethodRequestArray::SPtr callMethodRequestArraySPtr_;
	};

}

#endif
