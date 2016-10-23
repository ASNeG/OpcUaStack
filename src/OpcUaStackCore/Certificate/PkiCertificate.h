/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_PkiCertificate_h__
#define __OpcUaStackCore_PkiCertificate_h__

#include <openssl/x509.h>
#include <openssl/asn1.h>
#include <list>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Certificate/PkiIdentity.h"
#include "OpcUaStackCore/Certificate/PkiCertificateInfo.h"
#include "OpcUaStackCore/Certificate/PkiPublicKey.h"
#include "OpcUaStackCore/Certificate/PkiPrivateKey.h"

namespace OpcUaStackCore
{

	class DLLEXPORT PkiExtensionEntry
	{
	  public:
		typedef std::vector<PkiExtensionEntry> Vec;

		PkiExtensionEntry(void);
		PkiExtensionEntry(const std::string& key, const std::string& value);
		~PkiExtensionEntry(void);

		void key(const std::string& key);
		std::string& key(void);
		void value(const std::string& value);
		std::string& value(void);

	  private:
		std::string key_;
		std::string value_;
	};

	class DLLEXPORT PkiCertificate
	: public PkiError
	{
	  public:
		static bool loadCryptoStrings_;
		static std::list<std::string> cryptoStringErrorList_;
		static PkiExtensionEntry::Vec pkiEntensionEntryVec_;
		static bool init_;

		PkiCertificate(void);
		~PkiCertificate(void);

		bool createNewCertificate(
			PkiCertificateInfo& pkiCertificateInfo,
			PkiIdentity& subjectPkiIdentity,
			PkiPublicKey& subjectPkiPublicKey,
			PkiIdentity& issuerPkiIdentity,
			PkiPrivateKey& issuerPrivateKey
		);
		bool getCertificate(
			PkiCertificateInfo& pkiCertificateInfo,
			PkiIdentity& subjectPkiIdentity,
			PkiPublicKey& subjectPkiPublicKey,
			PkiIdentity& issuerPkiIdentity,
			PkiPrivateKey& issuerPrivateKey
		);
		bool toDERFile(const std::string& derFileName);
		bool fromDERFile(const std::string& derFileName);
		void signatureAlgorithm() const;

	  private:
		bool getX509Name(X509_NAME* name, uint32_t nameId, std::string& value);
		bool ASN1TimeToPosixTime(ASN1_TIME* asn1Time, boost::posix_time::ptime& ptime);
		bool PosixTimeToASN1Time(boost::posix_time::ptime& ptime, ASN1_TIME* asn1Time);

		X509 *x509Cert_;

		time_t startTime_;
	};

}

#endif
