#ifndef __OpcUaStackCore_ObjectTypeAttributes_h__
#define __OpcUaStackCore_ObjectTypeAttributes_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"


namespace OpcUaStackCore
{

	class DLLEXPORT ObjectTypeAttributes : public  ObjectPool<ObjectTypeAttributes>, public ExtensibleParameterBase
	{
	  public:
		ObjectTypeAttributes(void);
		virtual ~ObjectTypeAttributes(void);

        ExtensibleParameterBase::SPtr factory(void) { return ObjectTypeAttributes::construct();  }

        OpcUaUInt32 specifiedAttributes(void) const;
        void displayName(const OpcUaLocalizedText::SPtr displayNameSPtr);
        OpcUaLocalizedText::SPtr displayName(void) const;
        void description(const OpcUaLocalizedText::SPtr descriptionSPtr);
        OpcUaLocalizedText::SPtr description(void) const;        
		void isAbstract(const OpcUaBoolean executable);
        OpcUaBoolean isAbstract(void) const;        
		void writeMask(const OpcUaUInt32 writeMask);
        OpcUaUInt32 writeMask(void) const;
        void userWriteMask(const OpcUaUInt32 userWriteMask);
        OpcUaUInt32 userWriteMask(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		
	  private:
		OpcUaUInt32 specifiedAttributes_;
		OpcUaLocalizedText::SPtr displayName_;
		OpcUaLocalizedText::SPtr description_;
		OpcUaBoolean isAbstract_;
		OpcUaUInt32 writeMask_;
		OpcUaUInt32 userWriteMask_;
	};

}

#endif
