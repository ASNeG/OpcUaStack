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

   DirEntry:
   <0>: Pki store data type
   <1>: Name of the sub directory
   <2>: True: A second file is created as a symlink to the first file
        False: A second file is not used
   <3>: True: The first filename is the thumbprint of the file content. The second
              filename (symlink) is the passed name.
        False:The first filename is the passed name. The second filename (symlink)
              is the thumbprint of the file content.

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

#define pkiStoreDataType(entry) std::get<0>(entry)
#define subdirectory(entry) std::get<1>(entry)
#define	symlinkUsed(entry) std::get<2>(entry)
#define firstFileThumbprintUsed(entry) std::get<3>(entry)

namespace OpcUaStackCore
{

	class DLLEXPORT PKIStoreFileConfiguration
	: public PKIStoreConfiguration
	{
	  public:
		using SPtr = boost::shared_ptr<PKIStoreFileConfiguration>;
		using DirEntry = std::tuple<PKIStoreDataType, std::string, bool, bool>; // Description see above
		using DirEntryVec = std::vector<DirEntry>;

		PKIStoreFileConfiguration(void);
		virtual ~PKIStoreFileConfiguration(void);

	    std::string rootPath_ = "pki";
	    DirEntryVec dirEntryVec_ = {
	    	{PKIStoreDataType::OwnKeyApplType, "OwnKeyApplType", false, true},
			{PKIStoreDataType::OwnKeyRsaMinType, "OwnKeyRsaMinType", false, true},
			{PKIStoreDataType::OwnKeyRsaSha256Type, "OwnKeyRsaSha256Type", false, true},
			{PKIStoreDataType::OwnKeyHttpsType, "OwnKeyHttpsType", false, true},
			{PKIStoreDataType::OwnKeyUserCredentialType, "OwnKeyUserCredentialType", false, true},
			{PKIStoreDataType::OwnCertApplType, "OwnCertApplType", false, true},
			{PKIStoreDataType::OwnCertRsaMinType, "OwnCertRsaMinType", false, true},
			{PKIStoreDataType::OwnCertRsaSha256Type, "OwnCertRsaSha256Type", false, true},
			{PKIStoreDataType::OwnCertHttpsType, "OwnCertHttpsType", false, true},
			{PKIStoreDataType::OwnCertUserCredentialType, "OwnCertUserCredentialType", false, true},
			{PKIStoreDataType::TrustedCert, "TrustedCert", true, true},
			{PKIStoreDataType::TrustedCrlsCert, "TrustedCrlsCert", true, true},
			{PKIStoreDataType::IssuerCert, "IssuerCert", true, true},
			{PKIStoreDataType::IssuerCrlsCert, "IssuerCrlsCert", true, true},
			{PKIStoreDataType::RejectedCert, "RejectedCert", true, true},
			{PKIStoreDataType::UserCredentialKey, "UserCredentialKey", true, true},
			{PKIStoreDataType::UserCredentialCert, "UserCredentialCert", true, true}
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
		bool empty(
			PKIStoreDataType type
		) override;
		bool exist(
			PKIStoreDataType type,
			const std::string& name
		) override;
		bool write(
			PKIStoreDataType type,
			const std::string& name,
			const OpcUaByteString& data
		) override;
		bool writeFile(
			PKIStoreDataType type,
			const std::string& name,
			const std::string& filename
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
