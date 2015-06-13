#ifndef __OpcUaStackServer_NodeReferenceApplication_h__
#define __OpcUaStackServer_NodeReferenceApplication_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/ServiceSetApplication/NodeReference.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT NodeReferenceApplication
	: public  ObjectPool<NodeReferenceApplication>
	, public NodeReference
	{
	  public:
		typedef boost::shared_ptr<NodeReferenceApplication> SPtr;

		NodeReferenceApplication(void);
		virtual ~NodeReferenceApplication(void);

		void baseNodeClass(BaseNodeClass::WPtr baseNodeClass);
		BaseNodeClass::WPtr baseNodeClass(void);

	  private:
		BaseNodeClass::WPtr baseNodeClass_;
	};

}
#endif
