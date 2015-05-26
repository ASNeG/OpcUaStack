#ifndef __OpcUaStackServer_BaseNodeClass_h__
#define __OpcUaStackServer_BaseNodeClass_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSetApplication/ForwardInfoAsync.h"
#include "OpcUaStackCore/ServiceSetApplication/ForwardInfoSync.h"
#include "OpcUaStackServer/AddressSpaceModel/Attribute.h"
#include "OpcUaStackServer/AddressSpaceModel/ReferenceType.h"
#include "OpcUaStackServer/AddressSpaceModel/AttributeBase.h"
#include "OpcUaStackServer/AddressSpaceModel/ReferenceItemMap.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT BaseNodeClass
	: public AttributeBase
	{
	  public: 
		typedef boost::shared_ptr<BaseNodeClass> SPtr;
		typedef boost::weak_ptr<BaseNodeClass> WPtr;

		BaseNodeClass(void);
		BaseNodeClass(NodeClassType nodeClass);
		virtual ~BaseNodeClass(void);

		NodeIdAttribute& nodeId(void);
		NodeClassAttribute& nodeClass(void);
		BrowseNameAttribute& browseName(void);
		DisplayNameAttribute& displayName(void);
		DescriptionAttribute& description(void);
		WriteMaskAttribute& writeMask(void);
		UserWriteMaskAttribute& userWriteMask(void);

		Attribute* nodeIdAttribute(void); 
		Attribute* nodeClassAttribute(void); 
		Attribute* browseNameAttribute(void); 
		Attribute* displayNameAttribute(void); 
		Attribute* descriptionAttribute(void); 
		Attribute* writeMaskAttribute(void); 
		Attribute* userWriteMaskAttribute(void); 

		ReferenceItemMap& referenceItemMap(void);

		void forwardInfoAsync(ForwardInfoAsync::SPtr forwardInfo);
		ForwardInfoAsync::SPtr forwardInfoAsync(void);
		void forwardInfoSync(ForwardInfoSync::SPtr forwardInfo);
		ForwardInfoSync::SPtr forwardInfoSync(void);

	  private:
		NodeIdAttribute nodeId_;
		NodeClassAttribute nodeClass_;
		BrowseNameAttribute browseName_;
		DisplayNameAttribute displayName_;
		DescriptionAttribute description_;
		WriteMaskAttribute writeMask_;
		UserWriteMaskAttribute userWriteMask_;

		ReferenceItemMap referenceItemMap_;

		ForwardInfoAsync::SPtr forwardInfoAsync_;
		ForwardInfoSync::SPtr forwardInfoSync_;
	};

}

#endif
