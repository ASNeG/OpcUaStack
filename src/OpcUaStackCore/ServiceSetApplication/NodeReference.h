#ifndef __OpcUaStackCore_NodeReference_h__
#define __OpcUaStackCore_NodeReference_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"

namespace OpcUaStackCore
{

	class DLLEXPORT NodeReference
	: public  ObjectPool<NodeReference>
	{
	  public:
		typedef boost::shared_ptr<NodeReference> SPtr;

		NodeReference(void);
		virtual ~NodeReference(void);

		void statusCode(OpcUaStatusCode statusCode);
		OpcUaStatusCode statusCode(void);

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
