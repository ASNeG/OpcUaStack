#ifndef __OpcUaStackCore_AddNodesResult_h__
#define __OpcUaStackCore_AddNodesResult_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"


namespace OpcUaStackCore
{

	class DLLEXPORT AddNodesResult : public ObjectPool<AddNodesResult>
	{
	  public:
		typedef boost::shared_ptr<AddNodesResult> SPtr;

	    AddNodesResult(void);
		~AddNodesResult(void);

		void statusCode(OpcUaStatusCode statusCode);
		OpcUaStatusCode statusCode(void) const;

		void addedNodeId(const OpcUaNodeId::SPtr addedNodeIdSPtr);
		OpcUaNodeId::SPtr addedNodeId(void) const;

		void opcUaBinaryEncode(std::ostream& os) const; 
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaStatusCode statusCode_;
		OpcUaNodeId::SPtr addedNodeIdSPtr_;		
	};

	class AddNodesResultArray : public OpcUaArray<AddNodesResult::SPtr, SPtrTypeCoder<AddNodesResult> >, public ObjectPool<AddNodesResultArray> 
	{
	  public:
		typedef boost::shared_ptr<AddNodesResultArray> SPtr;
	};
}

#endif
