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

#ifndef __OpcUaStackCore_GetEndpointsResponse_h__
#define __OpcUaStackCore_GetEndpointsResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/EndpointDescription.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT GetEndpointsResponse
	: public Object
	{
	  public:
		typedef boost::shared_ptr<GetEndpointsResponse> SPtr;

		GetEndpointsResponse(void);
		virtual ~GetEndpointsResponse(void);

		void responseHeader(const ResponseHeader::SPtr responseHeader);
		ResponseHeader::SPtr responseHeader(void) const;
		void endpoints(const EndpointDescriptionArray::SPtr endpoints);
		EndpointDescriptionArray::SPtr endpoints(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ResponseHeader::SPtr responseHeader_;
		EndpointDescriptionArray::SPtr endpointArraySPtr_;
	};

}

#endif
