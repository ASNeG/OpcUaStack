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

		void copyTo(OpcUaExpandedNodeId& opcUaExpandedNodeId);

		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const OpcUaExpandedNodeId& value) {
			value.out(os);
			return os;
		}

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaByte expandedEncodingFlag_;
		OpcUaString namespaceUri_; 
		OpcUaUInt32 serverIndex_; 
	};


	class OpcUaExpandedNodeIdArray : public OpcUaArray<OpcUaExpandedNodeId::SPtr, SPtrTypeCoder<OpcUaExpandedNodeId> >, public ObjectPool<OpcUaExpandedNodeId> {};

}

#endif