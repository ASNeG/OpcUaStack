/*
   Copyright 2022 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_PKIStore_h__
#define __OpcUaStackCore_PKIStore_h__

#include <boost/shared_ptr.hpp>

#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	enum class DLLEXPORT PKIStoreCertKind
	{
		OwnKey,   // ApplType, RsaMinType, RsaSha256Type, HttpsType, UserCredentialType
		OwnCert,
		TrustedCert,
		TrustedCrlsCert,
		IssuerCert,
		IssuerCrlsCert,
		RejectedCert,
		UserCredentialKey,
		UserCredentialCert
	};

	class DLLEXPORT PKIStoreConfiguration
	{
 	  public:
	    typedef boost::shared_ptr<PKIStoreConfiguration> SPtr;

	    PKIStoreConfiguration(void);
	    virtual ~PKIStoreConfiguration(void);
	};


	class DLLEXPORT PKIStore
	{
	  public:
		typedef boost::shared_ptr<PKIStore> SPtr;

		PKIStore(void);
		virtual ~PKIStore(void);

		// Functions to open and close PKI Store
		virtual bool open(PKIStoreConfiguration::SPtr config) = 0;
		virtual bool close(void) = 0;
		virtual bool cleanup(void) = 0;

		// Functions to access certificates and keys
#if 0
		virtual bool write(PKIStoreCertKind kind, const std::string& name, ...) = 0;
#endif
	};

}

#endif
