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

#ifndef __OpcUaStackCore_FindServersRequest_h__
#define __OpcUaStackCore_FindServersRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT FindServersRequest
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<FindServersRequest> SPtr;

		FindServersRequest(void);
		virtual ~FindServersRequest(void);

		void requestHeader(const RequestHeader::SPtr requestHeaderSPtr);
		RequestHeader::SPtr requestHeader(void) const;
		void endpointUrl(const OpcUaString& endpointUrl);
		void endpointUrl(const std::string& endpointUrl);
		OpcUaString& endpointUrl(void);
		void localeIds(const OpcUaStringArray::SPtr localIds);
		OpcUaStringArray::SPtr localeIds(void) const;
		void serverUris(const OpcUaStringArray::SPtr serverUris);
		OpcUaStringArray::SPtr serverUris(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		OpcUaString endpointUrl_;
		OpcUaStringArray::SPtr localeIdArraySPtr_;
		OpcUaStringArray::SPtr serverUriArraySPtr_;
	};

}

#endif
