#ifndef __OpcUaStackCore_OpcUaXmlElement_h__
#define __OpcUaStackCore_OpcUaXmlElement_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaXmlElement : public ObjectPool<OpcUaXmlElement>
	{
	  public:
	    OpcUaXmlElement(void);
		~OpcUaXmlElement(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		
	};

	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaXmlElement& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaXmlElement& value);


	class OpcUaXmlElementArray : public OpcUaArray<OpcUaXmlElement::SPtr>, public ObjectPool<OpcUaXmlElementArray> {};

	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaXmlElementArray& value);
	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaXmlElementArray::SPtr& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaXmlElementArray& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaXmlElementArray::SPtr& value);
}

#endif