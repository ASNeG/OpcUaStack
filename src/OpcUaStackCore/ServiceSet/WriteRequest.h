#ifndef __OpcUaStackCore_WriteRequest_h__
#define __OpcUaStackCore_WriteRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/WriteValue.h"

namespace OpcUaStackCore
{

	class DLLEXPORT WriteRequest : public  ObjectPool<WriteRequest>
	{
	  public:
		typedef boost::shared_ptr<WriteRequest> SPtr;

		WriteRequest(void);
		virtual ~WriteRequest(void);

		void writeValueArray(const WriteValueArray::SPtr writeValueArray);
		WriteValueArray::SPtr writeValueArray(void) const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		  RequestHeader::SPtr requestHeaderSPtr_;
		  WriteValueArray::SPtr writeValueArraySPtr_;

	};

}

#endif