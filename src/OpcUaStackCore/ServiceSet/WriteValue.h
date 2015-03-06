#ifndef __OpcUaStackCore_WriteValue_h__
#define __OpcUaStackCore_WriteValue_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT WriteValue : public  ObjectPool<WriteValue>
	{
	  public:
		typedef boost::shared_ptr<WriteValue> SPtr;

		WriteValue(void);
		virtual ~WriteValue(void);

		void nodeId(const OpcUaNodeId::SPtr nodeIdSPtr);
		OpcUaNodeId::SPtr nodeId(void);
		void attributeId(const OpcUaUInt32& attributeId);
		OpcUaUInt32 attributeId(void) const;
		void indexRange(const std::string& indexRange);
		std::string indexRange(void) const;
		void dataValue(const OpcUaDataValue& dataValue);
		OpcUaDataValue& dataValue(void);

		void nodeId(const OpcUaInt16& namespaceId, const OpcUaInt32& identifier);
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaNodeId::SPtr nodeIdSPtr_;
		OpcUaInt32 attributeId_;
		OpcUaString indexRange_;
		OpcUaDataValue dataValue_;

	};

	class WriteValueArray : public OpcUaArray<WriteValue::SPtr, SPtrTypeCoder<WriteValue> >, public ObjectPool<WriteValueArray> 
	{
	  public:
		typedef boost::shared_ptr<WriteValueArray> SPtr;
	};

}

#endif
