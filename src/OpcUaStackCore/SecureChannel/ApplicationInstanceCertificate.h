#ifndef __OpcUaStackCore_ApplicationInstanceCertificate_h__
#define __OpcUaStackCore_ApplicationInstanceCertificate_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"

namespace OpcUaStackCore
{

	class ApplicationInstanceCertificate : public ObjectPool<ApplicationInstanceCertificate>
	{
	  public:
		ApplicationInstanceCertificate(void);
		virtual ~ApplicationInstanceCertificate(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
	};

}

#endif