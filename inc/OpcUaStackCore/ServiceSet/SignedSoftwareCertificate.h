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

	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const SignedSoftwareCertificate& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, SignedSoftwareCertificate& value);


	class SignedSoftwareCertificateArray : public OpcUaArray<SignedSoftwareCertificate::SPtr>, public ObjectPool<SignedSoftwareCertificateArray> {};

	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const SignedSoftwareCertificateArray& value);
	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const SignedSoftwareCertificateArray::SPtr& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, SignedSoftwareCertificateArray& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, SignedSoftwareCertificateArray::SPtr& value);

}

#endif
