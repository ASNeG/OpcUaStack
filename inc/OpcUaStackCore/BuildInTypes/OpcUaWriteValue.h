#ifndef __OpcUaStackCore_OpcUaWriteValue_h__
#define __OpcUaStackCore_OpcUaWriteValue_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaWriteValue : public  ObjectPool<OpcUaWriteValue>
	{
	  public:
		OpcUaWriteValue(void);
		virtual ~OpcUaWriteValue(void);

		void nodeId(const OpcUaNodeId& nodeId);
		OpcUaNodeId nodeId(void) const;
		void attributeId(const OpcUaUInt32& attributeId);
		OpcUaUInt32 attributeId(void) const;
		void indexRange(const OpcUaString& indexRange);
		OpcUaString indexRange(void) const;
		void dataValue(const OpcUaDataValue& dataValue);
		OpcUaDataValue dataValue(void) const;

		void nodeId(const OpcUaInt16& namespaceId, const OpcUaInt32& identifier);
		void indexRange(const std::string value);
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaNodeId nodeId_;
		OpcUaInt32 attributeId_;
		OpcUaString indexRange_;
		OpcUaDataValue dataValue_;

	};

	class OpcUaWriteValueArray : public OpcUaArray<OpcUaWriteValue::SPtr, SPtrTypeCoder<OpcUaWriteValue> >, public ObjectPool<OpcUaWriteValueArray> {};

}

#endif