#ifndef __OpcUaStackCore_ErrorMessage_h__
#define __OpcUaStackCore_ErrorMessage_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ErrorMessage : public  ObjectPool<ErrorMessage>
	{
	  public:
		ErrorMessage(void);
		virtual ~ErrorMessage(void);

		void error(const OpcUaUInt32& error);
		OpcUaUInt32 error(void) const;
		void reason(const std::string& reason);
		std::string reason(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 error_;
		OpcUaString reason_;
	};

}

#endif