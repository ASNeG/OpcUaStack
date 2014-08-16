#ifndef __OpcUaStackCore_UserNameIdentityToken_h__
#define __OpcUaStackCore_UserNameIdentityToken_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT UserNameIdentityToken : public  ObjectPool<UserNameIdentityToken>, public ExtensibleParameterBase
	{
	  public:
		UserNameIdentityToken(void);
		~UserNameIdentityToken(void);

		void policyId(const std::string& policyId);
		std::string policyId(void) const;
		void userName(const std::string& userName);
		std::string userName(void) const;
		void password(const OpcUaByte* buf, OpcUaInt32 bufLen);
		void password(OpcUaByte** buf, OpcUaInt32* bufLen) const;
		void encryptionAlgorithm(const std::string& encryptionAlgorithm);
		std::string encryptionAlgorithm(void) const;

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::BSPtr factory(void);
		virtual void opcUaBinaryEncode(std::ostream& os) const;
		virtual void opcUaBinaryDecode(std::istream& is);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		OpcUaString policyId_;
		OpcUaString userName_;
		OpcUaByteString password_;
		OpcUaString encryptionAlgorithm_;
	};

}

#endif