#include "unittest.h"
#include <boost/asio/ip/host_name.hpp>
#include "OpcUaStackCore/Certificate/PkiCertificate.h"
#include "OpcUaStackCore/Certificate/PkiRsaKey.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(PkiCertificate_t)

BOOST_AUTO_TEST_CASE(PkiCertificate_)
{
	std::cout << "PkiCertificate_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(PkiCertificate_create_self_signed)
{
	bool success;
	PkiCertificate certificate;
	PkiCertificateInfo pkiCertificateInfo;
	PkiIdentity subjectPkiIdentity;
	PkiPublicKey subjectPkiPublicKey;
	PkiIdentity issuerPkiIdentity;
	PkiPrivateKey issuerPkiPrivateKey;


	// check version
	pkiCertificateInfo.version(2); // V3

	// check serial number
	pkiCertificateInfo.serialNumber(1);

	// create private and public key
	PkiRsaKey rsaKey;
	BOOST_REQUIRE(rsaKey.createKey(1024) == true);
	BOOST_REQUIRE(rsaKey.getPrivateKey(issuerPkiPrivateKey) == true);
	BOOST_REQUIRE(rsaKey.getPublicKey(subjectPkiPublicKey) == true);

#if 0
	// check signature algorithm
	std::string signatureAlgorithm;
	BOOST_REQUIRE(certificate.getSignatureAlgorithm(signatureAlgorithm) == true);
	BOOST_REQUIRE(signatureAlgorithm == "sha1WithRSAEncryption");
#endif

	// issuer
	issuerPkiIdentity.commonName("ASNeG-Demo-Server");
	issuerPkiIdentity.organization("ASNeG");
	issuerPkiIdentity.organizationUnit("OPC UA Infrastructure");
	issuerPkiIdentity.locality("Neukirchen");
	issuerPkiIdentity.state("Hesse");
	issuerPkiIdentity.country("de");
	issuerPkiIdentity.domainComponent("ASNeG.de");

	// subject
	subjectPkiIdentity.commonName("ASNeG-Demo-Server");
	subjectPkiIdentity.organization("ASNeG");
	subjectPkiIdentity.organizationUnit("OPC UA Infrastructure");
	subjectPkiIdentity.locality("Neukirchen");
	subjectPkiIdentity.state("Hesse");
	subjectPkiIdentity.country("de");
	subjectPkiIdentity.domainComponent("ASNeG.de");

	// times
	pkiCertificateInfo.validTimeNotBefore(boost::posix_time::time_from_string("2016-01-01 00:00:00"));
	pkiCertificateInfo.validTimeNotAfter(boost::posix_time::time_from_string("2021-01-01 00:00:00"));

#if 0
	// check public key type
	BOOST_REQUIRE(subjectPkiPublicKey.keyType() == PkiPublicKey::KT_RSA);

	// check public key algorithm
	std::string publicKeyAlgorithm;
	BOOST_REQUIRE(subjectPkiPublicKey.getPublicKeyAlgorithm(publicKeyAlgorithm) == true);
	BOOST_REQUIRE(publicKeyAlgorithm == "rsaEncryption");

	// check public key length
	BOOST_REQUIRE(pkiRsaKey.keyLength() == 2048);

	// check public key
	std::string publicKey;
	BOOST_REQUIRE(pkiRsaKey.toHexStringPublicKey(publicKey) == true);
#endif

	// extensions
	BOOST_REQUIRE(certificate.setExtension("Netscape Comment", "OpenSSL Generated Certificate") == true);
	BOOST_REQUIRE(certificate.setExtension("X509v3 Subject Key Identifier", "06:7D:C3:F7:D1:95:AC:3B:E0:60:51:C8:57:21:E7:54:FC:26:2C:45") == true);
	BOOST_REQUIRE(certificate.setExtension("X509v3 Authority Key Identifier", "keyid:06:7D:C3:F7:D1:95:AC:3B:E0:60:51:C8:57:21:E7:54:FC:26:2C:45\n") == true);
	BOOST_REQUIRE(certificate.setExtension("X509v3 Subject Alternative Name", "URI:urn:BakerHughes:AggregationServer:N39541, DNS:siemens-ipc") == true);
	BOOST_REQUIRE(certificate.setExtension("X509v3 Basic Constraints", "CA:FALSE") == true);
	BOOST_REQUIRE(certificate.setExtension("X509v3 Key Usage", "Digital Signature, Non Repudiation, Key Encipherment, Data Encipherment, Certificate Sign") == true);
	BOOST_REQUIRE(certificate.setExtension("X509v3 Extended Key Usage", "TLS Web Server Authentication, TLS Web Client Authentication") == true);

#if 0
	// get signature
	std::string signature;
	BOOST_REQUIRE(certificate.getSignature(signature) == true);
#endif

	// create certificate
	success = certificate.createNewCertificate(
		pkiCertificateInfo,
		subjectPkiIdentity,
		subjectPkiPublicKey,
		issuerPkiIdentity,
		issuerPkiPrivateKey
	);
	BOOST_REQUIRE(success == true);
}

BOOST_AUTO_TEST_CASE(PkiCertificate_write_read_key)
{
	PkiRsaKey rsaKey;

	std::string hostname = boost::asio::ip::host_name();

	{ // read certificate from file
		PkiCertificate certificate;
		std::stringstream ss;

		PkiCertificateInfo pkiCertificateInfo;
		PkiIdentity subjectPkiIdentity;
		PkiPublicKey subjectPkiPublicKey;
		PkiIdentity issuerPkiIdentity;
		PkiPrivateKey issuerPrivateKey;
		PkiRsaKey pkiRsaKey;

		BOOST_REQUIRE(certificate.fromDERFile("../tst/data/ASNeG-Demo-Server.der") == true);
		BOOST_REQUIRE(
			certificate.getCertificate(
				pkiCertificateInfo,
				subjectPkiIdentity,
				subjectPkiPublicKey,
				issuerPkiIdentity,
				issuerPrivateKey
			) == true
		);
		BOOST_REQUIRE(pkiRsaKey.setPublicKey(subjectPkiPublicKey) == true);

		// check version
		BOOST_REQUIRE(pkiCertificateInfo.version() == 2); // V3

		// check serial number
		BOOST_REQUIRE(pkiCertificateInfo.serialNumber() == 1);

		// check signature algorithm
		std::string signatureAlgorithm;
		BOOST_REQUIRE(certificate.getSignatureAlgorithm(signatureAlgorithm) == true);
		BOOST_REQUIRE(signatureAlgorithm == "sha1WithRSAEncryption");

		// check issuer
		BOOST_REQUIRE(issuerPkiIdentity.commonName()	== "AggregationServer");
		BOOST_REQUIRE(issuerPkiIdentity.organization() == "Baker Hughes");
		BOOST_REQUIRE(issuerPkiIdentity.organizationUnit() == "Drilling Systems Automation");
		BOOST_REQUIRE(issuerPkiIdentity.locality() == "Celle");
		BOOST_REQUIRE(issuerPkiIdentity.state() == "Lower Saxony");
		BOOST_REQUIRE(issuerPkiIdentity.country() == "DE");
		BOOST_REQUIRE(issuerPkiIdentity.domainComponent() == "siemens-ipc");

		// check subject
		BOOST_REQUIRE(subjectPkiIdentity.commonName()	== "AggregationServer");
		BOOST_REQUIRE(subjectPkiIdentity.organization() == "Baker Hughes");
		BOOST_REQUIRE(subjectPkiIdentity.organizationUnit() == "Drilling Systems Automation");
		BOOST_REQUIRE(subjectPkiIdentity.locality() == "Celle");
		BOOST_REQUIRE(subjectPkiIdentity.state() == "Lower Saxony");
		BOOST_REQUIRE(subjectPkiIdentity.country() == "DE");
		BOOST_REQUIRE(subjectPkiIdentity.domainComponent() == "siemens-ipc");

		// check times
		ss.str("");
		ss << pkiCertificateInfo.validTimeNotBefore();
		BOOST_REQUIRE(ss.str() == std::string("2016-Feb-25 14:33:47"));
		ss.str("");
		ss << pkiCertificateInfo.validTimeNotAfter();
		BOOST_REQUIRE(ss.str() == std::string("2019-Feb-24 15:33:47"));

		// check public key type
		BOOST_REQUIRE(subjectPkiPublicKey.keyType() == PkiPublicKey::KT_RSA);

		// check public key algorithm
		std::string publicKeyAlgorithm;
		BOOST_REQUIRE(subjectPkiPublicKey.getPublicKeyAlgorithm(publicKeyAlgorithm) == true);
		BOOST_REQUIRE(publicKeyAlgorithm == "rsaEncryption");

		// check public key length
		BOOST_REQUIRE(pkiRsaKey.keyLength() == 2048);

		// check public key
		std::string publicKey;
		BOOST_REQUIRE(pkiRsaKey.toHexStringPublicKey(publicKey) == true);

		// get extensions
		BOOST_REQUIRE(certificate.existExtension("Netscape Comment") == true);
		BOOST_REQUIRE(certificate.existExtension("X509v3 Subject Key Identifier") == true);
		BOOST_REQUIRE(certificate.existExtension("X509v3 Authority Key Identifier") == true);
		BOOST_REQUIRE(certificate.existExtension("X509v3 Subject Alternative Name") == true);
		BOOST_REQUIRE(certificate.existExtension("X509v3 Basic Constraints") == true);
		BOOST_REQUIRE(certificate.existExtension("X509v3 Key Usage") == true);
		BOOST_REQUIRE(certificate.existExtension("X509v3 Extended Key Usage") == true);

		std::string ext;
		ext = certificate.getExtension("Netscape Comment");
		BOOST_REQUIRE(ext == "OpenSSL Generated Certificate");
		ext = certificate.getExtension("X509v3 Subject Key Identifier");
		BOOST_REQUIRE(ext == "06:7D:C3:F7:D1:95:AC:3B:E0:60:51:C8:57:21:E7:54:FC:26:2C:45");
		ext = certificate.getExtension("X509v3 Authority Key Identifier");
		BOOST_REQUIRE(ext == "keyid:06:7D:C3:F7:D1:95:AC:3B:E0:60:51:C8:57:21:E7:54:FC:26:2C:45\n");
		ext = certificate.getExtension("X509v3 Subject Alternative Name");
		BOOST_REQUIRE(ext == "URI:urn:BakerHughes:AggregationServer:N39541, DNS:siemens-ipc");
		ext = certificate.getExtension("X509v3 Basic Constraints");
		BOOST_REQUIRE(ext == "CA:FALSE");
		ext = certificate.getExtension("X509v3 Key Usage");
		BOOST_REQUIRE(ext == "Digital Signature, Non Repudiation, Key Encipherment, Data Encipherment, Certificate Sign");
		ext = certificate.getExtension("X509v3 Extended Key Usage");
		BOOST_REQUIRE(ext == "TLS Web Server Authentication, TLS Web Client Authentication");

		// get signature
		std::string signature;
		BOOST_REQUIRE(certificate.getSignature(signature) == true);
	}
}

BOOST_AUTO_TEST_SUITE_END()


