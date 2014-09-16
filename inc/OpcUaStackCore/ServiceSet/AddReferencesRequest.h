#ifndef __OpcUaStackCore_AddReferencesRequest_h__
#define __OpcUaStackCore_AddReferencesRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/AddReferencesItem.h"

namespace OpcUaStackCore
{

	class DLLEXPORT AddReferencesRequest : public  ObjectPool<AddReferencesRequest>
	{
	  public:
		AddReferencesRequest(void);
		virtual ~AddReferencesRequest(void);

		void requestHeader(const RequestHeader::SPtr requestHeaderSPtr);
		RequestHeader::SPtr requestHeader(void) const;
		void referencesToAdd(const AddReferencesItemArray::SPtr addReferencesItemArray);
		AddReferencesItemArray::SPtr referencesToAdd() const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeader_;
		AddReferencesItemArray::SPtr addReferencesItemArray_;
	};

}

#endif
