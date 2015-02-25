#ifndef __OpcUaStackServer_AttributeBase_h__
#define __OpcUaStackServer_AttributeBase_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/AddressSpaceModel/Attribute.h"

namespace OpcUaStackServer
{

	class DLLEXPORT AttributeBase
	{
	  public:
		AttributeBase(void);
		~AttributeBase(void);

		Attribute* attribute(AttributeId attributeId);

		virtual Attribute* nodeIdAttribute(void);
		virtual Attribute* nodeClassAttribute(void);
		virtual Attribute* browseNameAttribute(void);
		virtual Attribute* displayNameAttribute(void);
		virtual Attribute* descriptionAttribute(void);
		virtual Attribute* writeMaskAttribute(void);
		virtual Attribute* userWriteMaskAttribute(void);
		virtual Attribute* isAbstractAttribute(void);
		virtual Attribute* symmetricAttribute(void);
		virtual Attribute* inverseNameAttribute(void);
		virtual Attribute* containsNoLoopsAttribute(void);
		virtual Attribute* eventNotifierAttribute(void);
		virtual Attribute* valueAttribute(void);
		virtual Attribute* dataTypeAttribute(void);
		virtual Attribute* valueRankAttribute(void);
		virtual Attribute* arrayDimensionsAttribute(void);
		virtual Attribute* accessLevelAttribute(void);
		virtual Attribute* userAccessLevelAttribute(void);
		virtual Attribute* historizingAttribute(void);
		virtual Attribute* executableAttribute(void);
		virtual Attribute* userExecutableAttribute(void);
		virtual Attribute* minimumSamplingIntervalAttribute(void);
	};

}

#endif