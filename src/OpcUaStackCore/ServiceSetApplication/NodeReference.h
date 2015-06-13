#ifndef __OpcUaStackCore_NodeReference_h__
#define __OpcUaStackCore_NodeReference_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"

namespace OpcUaStackCore
{

	class DLLEXPORT NodeReference
	{
	  public:
		typedef boost::shared_ptr<NodeReference> SPtr;

		NodeReference(void);
		virtual ~NodeReference(void);

		void statusCode(OpcUaStatusCode statusCode);
		OpcUaStatusCode statusCode(void);

		void copyTo(NodeReference& nodeReference);
		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const NodeReference& value) {
			value.out(os);
			return os;
		}

		void opcUaBinaryEncode(std::ostream& os) {}
		void opcUaBinaryDecode(std::istream& is) {}
		
	  private:
		OpcUaStatusCode statusCode_;
	};

	class DLLEXPORT NodeReferenceArray
	: public OpcUaArray<NodeReference::SPtr
	, SPtrTypeCoder<NodeReference> >
	, public ObjectPool<NodeReferenceArray>
	{
	  public:
		typedef boost::shared_ptr<NodeReferenceArray> SPtr;
	};

}

#endif
