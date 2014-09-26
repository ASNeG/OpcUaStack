#ifndef __OpcUaStackServer_MethodNodeClass_h__
#define __OpcUaStackServer_MethodNodeClass_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

namespace OpcUaStackServer
{

	class DLLEXPORT MethodNodeClass : public BaseNodeClass, public ObjectPool<MethodNodeClass>
	{
	  public:
		typedef boost::shared_ptr<MethodNodeClass> SPtr;

		MethodNodeClass(void);
		~MethodNodeClass(void);

		ExecutableAttribute& executable(void);
		UserExecutableAttribute& userExecutable(void);

		Attribute* executableAttribute(void);
		Attribute* userExecutableAttribute(void);

		void addReference(ReferenceType referenceType, OpcUaNodeId& opcUaNodeId);
		void getReference(OpcUaNodeIdList& list, ReferenceType referenceType);

	  private:
		// attributes mandatory
		ExecutableAttribute executable_;
		UserExecutableAttribute userExecutable_;

		// references
		OpcUaNodeIdList hasProperty_;
		OpcUaNodeIdList hasModellingRule_;
		OpcUaNodeIdList hasModelParameter_;
		OpcUaNodeIdList generateEvents_;
		OpcUaNodeIdList alwaysGeneratesEvent_;

		// standard properties - all optional
		OpcUaString nodeVersion_;  
		//FIXME ArgumentArray inputArguments_;
		//FIXME ArgumentArray outputArguments_;
	};

}

#endif