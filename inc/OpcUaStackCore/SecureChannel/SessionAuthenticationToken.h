#ifndef __OpcUaStackCore_SessionAuthenticationToken_h__
#define __OpcUaStackCore_SessionAuthenticationToken_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OPcUaNumber.h"


namespace OpcUaStackCore
{

	class DLLEXPORT SessionAuthenticationToken : public  ObjectPool<SessionAuthenticationToken>
	{
	  public:
		SessionAuthenticationToken(void);
		virtual ~SessionAuthenticationToken(void);

		void token(const OpcUaUInt32& token);
		OpcUaUInt32 token(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		
	  private:
		OpcUaUInt32 token_;
	};

}

#endif