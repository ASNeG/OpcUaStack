#ifndef __OpcUaStackServer_NodeReferenceApplication_h__
#define __OpcUaStackServer_NodeReferenceApplication_h__

#include "OpcUaStackCore/ServiceSetApplication/NodeReference.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT NodeReferenceApplication
	: public NodeReference
	{
	  public:
		typedef boost::shared_ptr<NodeReferenceApplication> SPtr;

		NodeReferenceApplication();
		virtual ~NodeReferenceApplication();

		void baseNodeClass(BaseNodeClass::WPtr baseNodeClass);
		BaseNodeClass::WPtr baseNodeClass(void);

	  private:
		BaseNodeClass::WPtr baseNodeClass_;
	};

#endif
