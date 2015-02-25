#ifndef __OpcUaStackCore_HistoryReadResult_h__
#define __OpcUaStackCore_HistoryReadResult_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"

namespace OpcUaStackCore
{

	class DLLEXPORT HistoryReadResult : public  ObjectPool<HistoryReadResult>
	{
	  public:
		typedef boost::shared_ptr<HistoryReadResult> SPtr;

		HistoryReadResult(void);
		virtual ~HistoryReadResult(void);

		void statusCode(const OpcUaStatusCode& statusCode);
		OpcUaStatusCode& statusCode(void);
		void continuationPoint(const OpcUaByteString& continuationPoint);
		OpcUaByteString& continuationPoint(void);
		void historyData(const ExtensibleParameter::SPtr historyData);
		ExtensibleParameter::SPtr historyData(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaStatusCode statusCode_;
		OpcUaByteString continuationPoint_;
		ExtensibleParameter::SPtr historyData_;
	};

	class HistoryReadResultArray : public OpcUaArray<HistoryReadResult::SPtr, SPtrTypeCoder<HistoryReadResult> >, public ObjectPool<HistoryReadResultArray> 
	{
	  public:
		typedef boost::shared_ptr<HistoryReadResultArray> SPtr;
	};

}

#endif