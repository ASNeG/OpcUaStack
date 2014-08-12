#ifndef __OpcUaStackCore_OpcUaReadValueId_h__
#define __OpcUaStackCore_OpcUaReadValueId_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaReadValueId : public  ObjectPool<OpcUaReadValueId>
	{
	  public:
		OpcUaReadValueId(void);
		virtual ~OpcUaReadValueId(void);

		void nodeId(const OpcUaNodeId& nodeId);
		OpcUaNodeId nodeId(void) const;
		void attributeId(const OpcUaUInt32& attributeId);
		OpcUaUInt32 attributeId(void) const;
		void indexRange(const OpcUaString& indexRange);
		OpcUaString indexRange(void) const;
		void dataEncoding(const OpcUaQualifiedName& dataEncoding);
		OpcUaQualifiedName dataEncoding(void) const;

		void nodeId(const OpcUaInt16& namespaceId, const OpcUaInt32& identifier);
		void indexRange(const std::string value);
		void dataEncoding(const OpcUaInt16& namespaceIndex, const std::string name);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaNodeId nodeId_;
		OpcUaInt32 attributeId_;
		OpcUaString indexRange_;
		OpcUaQualifiedName dataEncoding_;

	};

	class OpcUaReadValueIdArray : public OpcUaArray<OpcUaReadValueId::SPtr, SPtrTypeCoder<OpcUaReadValueId> >, public ObjectPool<OpcUaReadValueIdArray> {};

}

#endif