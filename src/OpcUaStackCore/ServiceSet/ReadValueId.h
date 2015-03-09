#ifndef __OpcUaStackCore_ReadValueId_h__
#define __OpcUaStackCore_ReadValueId_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ReadValueId : public  ObjectPool<ReadValueId>
	{
	  public:
		typedef boost::shared_ptr<ReadValueId> SPtr;

		ReadValueId(void);
		virtual ~ReadValueId(void);

		void nodeId(const OpcUaNodeId::SPtr nodeId);
		OpcUaNodeId::SPtr nodeId(void);
		void attributeId(const OpcUaUInt32& attributeId);
		OpcUaUInt32 attributeId(void) const;
		void indexRange(const OpcUaString& indexRange);
		std::string indexRange(void) const;
		void dataEncoding(const OpcUaQualifiedName& dataEncoding);
		OpcUaQualifiedName& dataEncoding(void);

		void nodeId(const OpcUaInt16& namespaceId, const OpcUaInt32& identifier);
		void indexRange(const std::string& value);
		void dataEncoding(const OpcUaInt16& namespaceIndex, const std::string& name);
		void dataEncoding(const std::string& name);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaNodeId::SPtr nodeIdSPtr_;
		OpcUaInt32 attributeId_;
		OpcUaString indexRange_;
		OpcUaQualifiedName dataEncoding_;

	};

	class ReadValueIdArray
	: public OpcUaArray<ReadValueId::SPtr, SPtrTypeCoder<ReadValueId> >
	, public ObjectPool<ReadValueIdArray>
	{
	  public:
		typedef boost::shared_ptr<ReadValueIdArray> SPtr;
	};

}

#endif
