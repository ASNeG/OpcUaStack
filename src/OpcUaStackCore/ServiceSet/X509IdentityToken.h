/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_X509IdentityToken_h__
#define __OpcUaStackCore_X509IdentityToken_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT X509IdentityToken
	: public Object
	, public ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<X509IdentityToken> SPtr;

		X509IdentityToken(void);
		~X509IdentityToken(void);

		void policyId(const std::string& policyId);
		std::string policyId(void) const;
		void certificateData(const OpcUaByte* buf, OpcUaInt32 bufLen);
		void certificateData(OpcUaByte** buf, OpcUaInt32* bufLen) const;
		OpcUaByteString& certificateData(void);

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::SPtr factory(void);
		virtual void opcUaBinaryEncode(std::ostream& os) const;
		virtual void opcUaBinaryDecode(std::istream& is);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		OpcUaString policyId_;
		OpcUaByteString certificateData_;
	};

}

#endif
