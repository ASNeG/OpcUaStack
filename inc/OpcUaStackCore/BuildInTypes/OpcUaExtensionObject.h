#ifndef __OpcUaStackCore_OpcUaExtensionObject_h__
#define __OpcUaStackCore_OpcUaExtensionObject_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaExtensionObject : public ObjectPool<OpcUaExtensionObject>
	{
	  public:
	    OpcUaExtensionObject(void);
		~OpcUaExtensionObject(void);

		void typeId(const OpcUaNodeId& typeId);
		OpcUaNodeId& typeId(void);
		void body(const OpcUaByteString& body);
		OpcUaByteString& body(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaNodeId typeId_;
		OpcUaByteString body_;
	};

	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaExtensionObject& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaExtensionObject& value);
}

#endif