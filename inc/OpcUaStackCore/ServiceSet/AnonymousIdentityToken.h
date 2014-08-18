#ifndef __OpcUaStackCore_AnonymousIdentityToken_h__
#define __OpcUaStackCore_AnonymousIdentityToken_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT AnonymousIdentityToken : public  ObjectPool<AnonymousIdentityToken>, public ExtensibleParameterBase
	{
	  public:
		AnonymousIdentityToken(void);
		~AnonymousIdentityToken(void);

		void policyId(const std::string& policyId);
		std::string policyId(void) const;

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::BSPtr factory(void);
		virtual void opcUaBinaryEncode(std::ostream& os) const;
		virtual void opcUaBinaryDecode(std::istream& is);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		OpcUaString policyId_;
	};

}

#endif