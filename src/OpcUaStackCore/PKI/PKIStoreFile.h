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

#ifndef __OpcUaStackCore_PKIStoreFile_h__
#define __OpcUaStackCore_PKIStoreFile_h__

#include <string>
#include <tuple>
#include <functional>

#include <boost/shared_ptr.hpp>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/MemoryBuffer.h"
#include "OpcUaStackCore/PKI/PKIStore.h"

namespace OpcUaStackCore
{

	class DLLEXPORT PKIStoreFileConfiguration
	: public PKIStoreConfiguration
	{
	  public:
		using SPtr = boost::shared_ptr<PKIStoreFileConfiguration>;
		using DirEntry = std::tuple<PKIStoreDataType, std::string, bool>;
		using DirEntryVec = std::vector<DirEntry>;

		PKIStoreFileConfiguration(void);
		virtual ~PKIStoreFileConfiguration(void);

	    std::string rootPath_ = "pki";
	    DirEntryVec dirEntryVec_ = {
	    	{PKIStoreDataType::OwnKeyApplType, "OwnKeyApplType", false},
			{PKIStoreDataType::OwnKeyRsaMinType, "OwnKeyRsaMinType", false},
			{PKIStoreDataType::OwnKeyRsaSha256Type, "OwnKeyRsaSha256Type", false},
			{PKIStoreDataType::OwnKeyHttpsType, "OwnKeyHttpsType", false},
			{PKIStoreDataType::OwnKeyUserCredentialType, "OwnKeyUserCredentialType", false},
			{PKIStoreDataType::OwnCertApplType, "OwnCertApplType", false},
			{PKIStoreDataType::OwnCertRsaMinType, "OwnCertRsaMinType", false},
			{PKIStoreDataType::OwnCertRsaSha256Type, "OwnCertRsaSha256Type", false},
			{PKIStoreDataType::OwnCertHttpsType, "OwnCertHttpsType", false},
			{PKIStoreDataType::OwnCertUserCredentialType, "OwnCertUserCredentialType", false},
			{PKIStoreDataType::TrustedCert, "TrustedCert", true},
			{PKIStoreDataType::TrustedCrlsCert, "TrustedCrlsCert", true},
			{PKIStoreDataType::IssuerCert, "IssuerCert", true},
			{PKIStoreDataType::IssuerCrlsCert, "IssuerCrlsCert", true},
			{PKIStoreDataType::RejectedCert, "RejectedCert", true},
			{PKIStoreDataType::UserCredentialKey, "UserCredentialKey", true},
			{PKIStoreDataType::UserCredentialCert, "UserCredentialCert", true}
	    };
	};

	class DLLEXPORT PKIStoreFile
	: public PKIStore
	{
	  public:
		using SPtr = boost::shared_ptr<PKIStoreFile>;
		using DirEntryMap = std::map<PKIStoreDataType, PKIStoreFileConfiguration::DirEntry>;

		PKIStoreFile(void);
		virtual ~PKIStoreFile(void);

		// PKIStore interface functions
		bool open(PKIStoreConfiguration::SPtr config) override;
		bool close(void) override;
		bool cleanup(void) override;

		// Functions to access data in key store
		bool exist(
			PKIStoreDataType type,
			const std::string& name
		) override;
		bool write(
			PKIStoreDataType type,
			const std::string& name,
			const OpcUaByteString& data
		) override;
		bool read(
			PKIStoreDataType type,
			const std::string& name,
			OpcUaByteString& data
		) override;
		bool readAll(
			PKIStoreDataType type,
			std::vector<OpcUaByteString>& dataVec
		) override;
		bool remove(
			PKIStoreDataType type,
			const std::string& name
		) override;
		bool removeAll(
			PKIStoreDataType type
		) override;

	  private:
		PKIStoreFileConfiguration::SPtr config_ = NULL;
		DirEntryMap dirEntryMap_ = {};

		bool createThumbPrint(const OpcUaByteString& buffer, std::string& thumbPrint);
	};

}

#endif
