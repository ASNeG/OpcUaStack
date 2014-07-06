#ifndef __OpcUaStackCore_RequestHeader_h__
#define __OpcUaStackCore_RequestHeader_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/SessionAuthenticationToken.h"

namespace OpcUaStackCore
{
	class DLLEXPORT RequestHeader : public  ObjectPool<RequestHeader>
	{
	  public:
		RequestHeader(void);
		virtual ~RequestHeader(void);

		void sessionAuthenticationToken(const SessionAuthenticationToken::SPtr& SessionAuthenticationTokenSPtr);
		SessionAuthenticationToken::SPtr sessionAuthenticationToken(void) const;
		void time(const UtcTime& time);
		UtcTime time(void) const;
		void requestHandle(const IntegerId& requestHandle);
		IntegerId requestHandle(void) const;
		void returnDisagnostics(const OpcUaUInt32& returnDisagnostics);
		OpcUaUInt32 returnDisagnostics(void) const;
		void auditEntryId(const std::string& auditEntryId);
		std::string auditEntryId(void) const;
		void timeoutHint(const OpcUaUInt32& timeoutHint);
		OpcUaUInt32 timeoutHint(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		SessionAuthenticationToken::SPtr SessionAuthenticationTokenSPtr_;
		UtcTime time_;
		IntegerId requestHandle_;
		OpcUaUInt32 returnDisagnostics_;
		OpcUaString auditEntryId_;
		OpcUaUInt32 timeoutHint_;
	};

}

#endif