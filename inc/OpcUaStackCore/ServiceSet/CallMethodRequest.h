#ifndef __OpcUaStackCore_CallMethodRequest_h__
#define __OpcUaStackCore_CallMethodRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CallMethodRequest : public  ObjectPool<CallMethodRequest>
	{
	  public:
		CallMethodRequest(void);
		virtual ~CallMethodRequest(void);

		void objectId(const OpcUaNodeId::SPtr objectId);
		OpcUaNodeId::SPtr objectId(void) const;
		void methodId(const OpcUaNodeId::SPtr methodId);
		OpcUaNodeId::SPtr methodId(void) const;
		void inputArguments(const OpcUaVariantArray::SPtr inputArguments);
		OpcUaVariantArray::SPtr inputArguments(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		  OpcUaNodeId::SPtr objectIdSPtr_;
		  OpcUaNodeId::SPtr methodIdSPtr_;
		  OpcUaVariantArray::SPtr inputArgumentArraySPtr_;
	};

	class CallMethodRequestArray : public OpcUaArray<CallMethodRequest::SPtr, SPtrTypeCoder<CallMethodRequest> >, public ObjectPool<CallMethodRequestArray> {};

}

#endif