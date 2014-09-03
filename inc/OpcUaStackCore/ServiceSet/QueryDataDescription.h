#ifndef __OpcUaStackCore_QueryDataDescription_h__
#define __OpcUaStackCore_QueryDataDescription_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"
#include "OpcUaStackCore/ServiceSet/RelativePath.h"

namespace OpcUaStackCore
{

	class DLLEXPORT QueryDataDescription : public  ObjectPool<QueryDataDescription>
	{
	  public:
		QueryDataDescription(void);
		virtual ~QueryDataDescription(void);

		void relativePath(const RelativePath& relativePath);
		RelativePath& relativePath(void);
		void attributeId(const OpcUaUInt32& attributeId);
		OpcUaUInt32 attributeId(void);
		void indexRange(const OpcUaString& indexRange);
		void indexRange(const std::string& indexRange);
		OpcUaString& indexRange(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		RelativePath relativePath_;
		OpcUaUInt32 attributeId_;
		OpcUaString indexRange_;
	};

	class QueryDataDescriptionArray : public OpcUaArray<QueryDataDescription::SPtr, SPtrTypeCoder<QueryDataDescription> >, public ObjectPool<QueryDataDescriptionArray> {};

}

#endif