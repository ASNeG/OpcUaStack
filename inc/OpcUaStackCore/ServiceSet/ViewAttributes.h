#ifndef __OpcUaStackCore_ViewAttributes_h__
#define __OpcUaStackCore_ViewAttributes_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"
#include "OpcUaStackCore/ServiceSet/AttributesDescription.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ViewAttributes : public  ObjectPool<ViewAttributes>, public ExtensibleParameterBase
	{
	  public:
		ViewAttributes(void);
		virtual ~ViewAttributes(void);

        //- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::BSPtr factory(void);
		virtual void opcUaBinaryEncode(std::ostream& os) const;
		virtual void opcUaBinaryDecode(std::istream& is);
		//- ExtensibleParameterBase -------------------------------------------

        OpcUaUInt32 specifiedAttributes(void) const;
        void displayName(const OpcUaLocalizedText::SPtr displayNameSPtr);
        OpcUaLocalizedText::SPtr displayName(void) const;
        void description(const OpcUaLocalizedText::SPtr descriptionSPtr);
        OpcUaLocalizedText::SPtr description(void) const;
		void containsNoLoops(const OpcUaBoolean containsNoLoops);
        OpcUaBoolean containsNoLoops(void) const;
        void eventNotifier(const EventNotifierAttribute eventNotifier);
        OpcUaByte eventNotifier(void) const;
        void writeMask(const WriteableAttribute writeMask);
        OpcUaUInt32 writeMask(void) const;
        void userWriteMask(const WriteableAttribute userWriteMask);
        OpcUaUInt32 userWriteMask(void) const;
		
	  private:
		OpcUaUInt32 specifiedAttributes_;
		OpcUaLocalizedText::SPtr displayName_;
		OpcUaLocalizedText::SPtr description_;
		OpcUaBoolean containsNoLoops_;
		OpcUaByte eventNotifier_;
		OpcUaUInt32 writeMask_;
		OpcUaUInt32 userWriteMask_;
	};

}

#endif
