#ifndef __OpcUaStackCore_SecurityToken_h__
#define __OpcUaStackCore_SecurityToken_h__

#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
	class DLLEXPORT SecurityToken : public  ObjectPool<SecurityToken>
	{
	  public:
		SecurityToken(void);
		virtual ~SecurityToken(void);

		void channelId(const OpcUaByte* buf, OpcUaInt32 bufLen);
		void channelId(OpcUaByte** buf, OpcUaInt32* bufLen) const;
		void tokenId(const OpcUaByte* nuf, OpcUaInt32 bufLen);
		void tokenId(OpcUaByte** buf, OpcUaInt32 *bufLen) const;
		void createAt(const UtcTime& createAt);
		UtcTime createAt(void) const;
		void revisedLifetime(const Duration& revisedLifetime);
		Duration revisedLiefetime(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaByteString channelId_;
		OpcUaByteString tokenId_;
		UtcTime createAt_;
		Duration revisedLifetime_;
	};

	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const SecurityToken& value);
	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const SecurityToken::SPtr& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, SecurityToken& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, SecurityToken::SPtr& value);

}

#endif