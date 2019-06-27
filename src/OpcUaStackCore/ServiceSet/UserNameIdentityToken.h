/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaStackCore_UserNameIdentityToken_h__
#define __OpcUaStackCore_UserNameIdentityToken_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT UserNameIdentityToken
	: public Object
	, public ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<UserNameIdentityToken> SPtr;

		UserNameIdentityToken(void);
		~UserNameIdentityToken(void);

		void policyId(const std::string& policyId);
		std::string policyId(void) const;
		void userName(const std::string& userName);
		std::string userName(void) const;
		void password(const OpcUaByte* buf, OpcUaInt32 bufLen);
		void password(OpcUaByte** buf, OpcUaInt32* bufLen) const;
		std::string password() const;
		uint32_t passwordLen(void);
		void encryptionAlgorithm(const std::string& encryptionAlgorithm);
		std::string encryptionAlgorithm(void) const;

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::SPtr factory(void);
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
