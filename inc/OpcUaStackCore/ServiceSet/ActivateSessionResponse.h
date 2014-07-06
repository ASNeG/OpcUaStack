#ifndef __OpcUaStackCore_ActivateSessionResponse_h__
#define __OpcUaStackCore_ActivateSessionResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OPcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ActivateSessionResponse : public  ObjectPool<ActivateSessionResponse>
	{
	  public:
		ActivateSessionResponse(void);
		virtual ~ActivateSessionResponse(void);

		void responseHeader(const ResponseHeader::SPtr responseHeader);
		ResponseHeader::SPtr responseHeader(void) const;
		void serverNonce(const OpcUaByte* buf, OpcUaInt32 bufLen);
		void serverNonce(OpcUaByte** buf, OpcUaInt32* bufLen);
		void results(const OpcUaStatusCodeArray::SPtr results);
		OpcUaStatusCodeArray::SPtr results(void) const;
		void diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos);
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfos(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ResponseHeader::SPtr responseHeader_;
		OpcUaByteString serverNonce_;
		OpcUaStatusCodeArray::SPtr results_;
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfos_;
	};

}

#endif