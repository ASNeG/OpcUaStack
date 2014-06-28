#ifndef __OpcUaStackCore_OpcUaExpandedNodeId_h__
#define __OpcUaStackCore_OpcUaExpandedNodeId_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeIdBase.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaExpandedNodeId : public ObjectPool<OpcUaExpandedNodeId>, public OpcUaNodeIdBase
	{
	  public:
		OpcUaExpandedNodeId(void);
		~OpcUaExpandedNodeId(void);

		virtual OpcUaByte encodingFlag(void) const;
		virtual void encodingFlag(OpcUaByte expandedEncodingFlag);

		void namespaceUri(OpcUaString& namespaceUri);
		void namespaceUri(const std::string& namespaceUri);
		OpcUaString& namespaceUri(void);
		void serverIndex(OpcUaUInt32 serverIndex);
		OpcUaUInt32 serverIndex(void); 

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaByte expandedEncodingFlag_;
		OpcUaString namespaceUri_; 
		OpcUaUInt32 serverIndex_; 
	};

	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaExpandedNodeId& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaExpandedNodeId& value);


	class OpcUaExpandedNodeIdArray : public OpcUaArray<OpcUaExpandedNodeId::SPtr>, public ObjectPool<OpcUaExpandedNodeId> {};

	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaExpandedNodeIdArray& value);
	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaExpandedNodeIdArray::SPtr& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaExpandedNodeIdArray& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaExpandedNodeIdArray::SPtr& value);

}

#endif