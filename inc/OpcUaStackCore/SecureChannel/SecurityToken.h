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

		void channelId(const OpcUaUInt32& channelId);
		OpcUaUInt32 channelId(void) const;
		void tokenId(const OpcUaUInt32& tokenId);
		OpcUaUInt32 tokenId(void) const;
		void createAt(const UtcTime& createAt);
		UtcTime createAt(void) const;
		void revisedLifetime(const OpcUaInt32& revisedLifetime);
		OpcUaInt32 revisedLifetime(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 channelId_;
		OpcUaUInt32 tokenId_;
		UtcTime createAt_;
		OpcUaInt32 revisedLifetime_;
	};

	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const SecurityToken& value);
	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const SecurityToken::SPtr& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, SecurityToken& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, SecurityToken::SPtr& value);

}

#endif