#ifndef __OpcUaStackCore_ObjectAttributes_h__
#define __OpcUaStackCore_ObjectAttributes_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"


namespace OpcUaStackCore
{

	class DLLEXPORT ObjectAttributes : public  ObjectPool<ObjectAttributes>
	{
	  public:
		ObjectAttributes(void);
		virtual ~ObjectAttributes(void);

                OpcUaUInt32 specifiedAttributes(void) const;
                void displayName(const OpcUaLocalizedText::SPtr displayNameSPtr);
                OpcUaLocalizedText::SPtr displayName(void) const;
                void description(const OpcUaLocalizedText::SPtr descriptionSPtr);
                OpcUaLocalizedText::SPtr description(void) const;
                void eventNotifier(const OpcUaByte eventNotifier);
                OpcUaByte eventNotifier(void) const;
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
		OpcUaByte eventNotifier_;
		OpcUaUInt32 writeMask_;
		OpcUaUInt32 userWriteMask_;
	};

	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const ObjectAttributes& value);
	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const ObjectAttributes::SPtr& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, ObjectAttributes& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, ObjectAttributes::SPtr& value);
}

#endif
