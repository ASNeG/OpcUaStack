#ifndef __OpcUaStackCore_MethodAttributes_h__
#define __OpcUaStackCore_MethodAttributes_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"


namespace OpcUaStackCore
{

	class DLLEXPORT MethodAttributes : public  ObjectPool<MethodAttributes>, public ExtensibleParameterBase
	{
	  public:
		MethodAttributes(void);
		virtual ~MethodAttributes(void);

        ExtensibleParameterBase::SPtr factory(void) { return MethodAttributes::construct();  }

        OpcUaUInt32 specifiedAttributes(void) const;
        void displayName(const OpcUaLocalizedText::SPtr displayNameSPtr);
        OpcUaLocalizedText::SPtr displayName(void) const;
        void description(const OpcUaLocalizedText::SPtr descriptionSPtr);
        OpcUaLocalizedText::SPtr description(void) const;        
		void executable(const OpcUaBoolean executable);
        OpcUaBoolean executable(void) const;        
		void userExecutable(const OpcUaBoolean userExecutable);
        OpcUaBoolean userExecutable(void) const;        
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
		OpcUaBoolean executable_;
		OpcUaBoolean userExecutable_;
		OpcUaUInt32 writeMask_;
		OpcUaUInt32 userWriteMask_;
	};

}

#endif
