#ifndef __OpcUaStackCore_SignatureData_h__
#define __OpcUaStackCore_SignatureData_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SignatureData : public  ObjectPool<SignatureData>
	{
	  public:
		typedef boost::shared_ptr<SignatureData> SPtr;

		SignatureData(void);
		virtual ~SignatureData(void);

		void signature(const OpcUaByte* buf, OpcUaInt32 bufLen);
		void signature(OpcUaByte** buf, OpcUaInt32* bufLen) const;
		void algorithm(const std::string& algorithm);
		std::string algorithm(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaByteString signature_;
		OpcUaString algorithm_;
		
	};
}

#endif
