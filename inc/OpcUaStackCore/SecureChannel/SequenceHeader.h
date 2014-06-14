#ifndef __OpcUaStackCore_SequenceHeader_h__
#define __OpcUaStackCore_SequenceHeader_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SequenceHeader : public  ObjectPool<SequenceHeader>
	{
	  public:
		SequenceHeader(void);
		virtual ~SequenceHeader(void);

		void sequenceNumber(const OpcUaUInt32& sequenceNumber);
		OpcUaUInt32 sequenceNumber(void) const;
		void requestId(const OpcUaUInt32& requestId);
		OpcUaUInt32 requestId(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 sequenceNumber_;
		OpcUaUInt32 requestId_;
	};

}

#endif