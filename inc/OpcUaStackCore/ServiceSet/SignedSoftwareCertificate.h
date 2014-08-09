#ifndef __OpcUaStackCore_SignedSoftwareCertificate_h__
#define __OpcUaStackCore_SignedSoftwareCertificate_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SignedSoftwareCertificate : public  ObjectPool<SignedSoftwareCertificate>
	{
	  public:
		SignedSoftwareCertificate(void);
		virtual ~SignedSoftwareCertificate(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		
	};

	class SignedSoftwareCertificateArray : public OpcUaArray<SignedSoftwareCertificate::SPtr, SPtrTypeCoder<SignedSoftwareCertificate> >, public ObjectPool<SignedSoftwareCertificateArray> {};
}

#endif
