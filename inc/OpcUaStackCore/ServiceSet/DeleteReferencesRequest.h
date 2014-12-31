#ifndef __OpcUaStackCore_DeleteReferencesRequest_h__
#define __OpcUaStackCore_DeleteReferencesRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/DeleteReferencesItem.h"

namespace OpcUaStackCore
{

	class DLLEXPORT DeleteReferencesRequest : public  ObjectPool<DeleteReferencesRequest>
	{
	  public:
		typedef boost::shared_ptr<DeleteReferencesRequest> SPtr;

		DeleteReferencesRequest(void);
		virtual ~DeleteReferencesRequest(void);

		void referencesToDelete(const DeleteReferencesItemArray::SPtr deleteReferencesItemArray);
		DeleteReferencesItemArray::SPtr referencesToDelete() const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		DeleteReferencesItemArray::SPtr deleteReferencesItemArray_;
	};

}

#endif
