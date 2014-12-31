#ifndef __OpcUaStackCore_UserIdentityToken_h__
#define __OpcUaStackCore_UserIdentityToken_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"


namespace OpcUaStackCore
{

	class DLLEXPORT UserIdentityToken : public  ObjectPool<UserIdentityToken>
	{
	  public:
		typedef boost::shared_ptr<UserIdentityToken> SPtr;

		UserIdentityToken(void);
		virtual ~UserIdentityToken(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
	};

}

#endif