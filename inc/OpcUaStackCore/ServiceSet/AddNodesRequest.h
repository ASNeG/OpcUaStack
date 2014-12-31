#ifndef __OpcUaStackCore_AddNodesRequest_h__
#define __OpcUaStackCore_AddNodesRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/AddNodesItem.h"
#include "OpcUaStackCore/ServiceSet/DataTypeAttributes.h"
#include "OpcUaStackCore/ServiceSet/MethodAttributes.h"
#include "OpcUaStackCore/ServiceSet/ObjectAttributes.h"
#include "OpcUaStackCore/ServiceSet/ObjectTypeAttributes.h"
#include "OpcUaStackCore/ServiceSet/ReferenceTypeAttributes.h"
#include "OpcUaStackCore/ServiceSet/VariableAttributes.h"
#include "OpcUaStackCore/ServiceSet/VariableTypeAttributes.h"
#include "OpcUaStackCore/ServiceSet/ViewAttributes.h"

namespace OpcUaStackCore
{

	class DLLEXPORT AddNodesRequest : public  ObjectPool<AddNodesRequest>
	{
	  public:
		typedef boost::shared_ptr<AddNodesRequest> SPtr;

		AddNodesRequest(void);
		virtual ~AddNodesRequest(void);

		void nodesToAdd(const AddNodesItemArray::SPtr addNodesItemArray);
		AddNodesItemArray::SPtr nodesToAdd() const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		AddNodesItemArray::SPtr addNodesItemArray_;
	};

}

#endif
