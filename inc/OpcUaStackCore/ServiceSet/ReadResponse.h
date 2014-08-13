#ifndef __OpcUaStackCore_ReadResponse_h__
#define __OpcUaStackCore_ReadResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ReadResponse : public  ObjectPool<ReadResponse>
	{
	  public:
		ReadResponse(void);
		virtual ~ReadResponse(void);

		void responseHeader(const ResponseHeader::SPtr responseHeaderSPtr);
		ResponseHeader::SPtr responseHeader(void) const;
		void dataValueArray(const OpcUaDataValueArray::SPtr dataValueArraySPtr);
		OpcUaDataValueArray::SPtr dataValueArray(void) const;
		void diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr);
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfos(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ResponseHeader::SPtr responseHeaderSPtr_;
		OpcUaDataValueArray::SPtr dataValueArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr_;
	};

}

#endif