#ifndef __OpcUaStackServer_ObjectNodeClass_h__
#define __OpcUaStackServer_ObjectNodeClass_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ReferenceList.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ObjectNodeClass : public BaseNodeClass, public ObjectPool<ObjectNodeClass>
	{
	  public:
		typedef boost::shared_ptr<ObjectNodeClass> SPtr;

		ObjectNodeClass(void);
		~ObjectNodeClass(void);

		EventNotifierAttribute& eventNotifier(void);

		Attribute* eventNotifierAttribute(void);

		void addReference(ReferenceType referenceType, ReferenceItem::SPtr referenceItem);
		void getReference(ReferenceList& list, ReferenceType referenceType);

	  private:
		// attributes mandatory
		EventNotifierAttribute eventNotifier_;

		// references
		ReferenceList hasComponent_;
		ReferenceList hasProperty_;
		ReferenceList hasModellingRule_;
		ReferenceList hasTypeDefinition_;
		ReferenceList hasModelParent_;
		ReferenceList hasEventSource_;
		ReferenceList hasNotifier_;
		ReferenceList organizes_;
		ReferenceList hasDescription_;

		// standard properties
		OpcUaString::SPtr nodeVersion_;  // optional
		// FIXME: Image icon_;	// optional
		// FIXME: NamingRuleType nameingRule_;	// optional 
	};

}

#endif