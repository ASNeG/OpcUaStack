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

BOOST_AUTO_TEST_CASE(PkiCertificate_create)
{
	boost::posix_time::ptime validTimeNotBefore(boost::posix_time::time_from_string("2016-03-15 15:00:00"));
	boost::posix_time::ptime validTimeNotAfter(boost::posix_time::time_from_string("2021-03-15 15:00:00"));

	std::string hostname = boost::asio::ip::host_name();

	PkiIdentity identity;
	identity.commonName()		= "ASNeG-Demo@" + hostname;
	identity.organization()		= "ASNeG";
	identity.organizationUnit()	= "Unit";
	identity.locality()			= "LocationName";
	identity.state()			= "State";
	identity.country()			= "DE";
	identity.domainComponent()	= hostname;

	PkiCertificateInfo info;
	info.URI()					= "urn:" + hostname + ":ASNeG::ASNeG-Demo";
	info.dnsNames().push_back(hostname);
	info.validTimeNotBefore(validTimeNotBefore);
	info.validTimeNotAfter(validTimeNotBefore);

	PkiRsaKey rsaKey;
	BOOST_REQUIRE(rsaKey.createKey(1024) == true);

	PkiPrivateKey issuerPrivateKey;
	BOOST_REQUIRE(rsaKey.getPrivateKey(issuerPrivateKey) == true);

	PkiPublicKey subjectPublicKey;
	BOOST_REQUIRE(rsaKey.getPublicKey(subjectPublicKey) == true);

	PkiCertificate certificate;
	BOOST_REQUIRE(certificate.createNewCertificate(info, identity, subjectPublicKey, identity, issuerPrivateKey) == true);
}

BOOST_AUTO_TEST_CASE(PkiCertificate_write_key)
{
	boost::posix_time::ptime validTimeNotBefore(boost::posix_time::time_from_string("2016-03-15 15:00:00"));
	boost::posix_time::ptime validTimeNotAfter(boost::posix_time::time_from_string("2021-03-15 15:00:00"));

	std::string hostname = boost::asio::ip::host_name();

	PkiIdentity identity;
	identity.commonName()		= "ASNeG-Demo@" + hostname;
	identity.organization()		= "ASNeG";
	identity.organizationUnit()	= "Unit";
	identity.locality()			= "LocationName";
	identity.state()			= "State";
	identity.country()			= "DE";
	identity.domainComponent()	= hostname;

	PkiCertificateInfo info;
	info.URI()					= "urn:" + hostname + ":ASNeG::ASNeG-Demo";
	info.dnsNames().push_back(hostname);
	info.validTimeNotBefore(validTimeNotBefore);
	info.validTimeNotAfter(validTimeNotAfter);

	PkiRsaKey rsaKey;
	BOOST_REQUIRE(rsaKey.createKey(1024) == true);

	PkiPrivateKey issuerPrivateKey;
	BOOST_REQUIRE(rsaKey.getPrivateKey(issuerPrivateKey) == true);

	PkiPublicKey subjectPublicKey;
	BOOST_REQUIRE(rsaKey.getPublicKey(subjectPublicKey) == true);

	PkiCertificate certificate;
	BOOST_REQUIRE(
		certificate.createNewCertificate(
			info, identity, subjectPublicKey, identity, issuerPrivateKey
		) == true);

	//
	// store certificate
	//
	BOOST_REQUIRE(certificate.toDERFile("../tst/data/ASNeG-Test.der") == true);

	//
	// store private key
	//
	BOOST_REQUIRE(rsaKey.writePEMFile("../tst/data/ASNeG-Test.PEM", "") == true);
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


#if 0
BOOST_AUTO_TEST_CASE(PkiCertificate_write_read_key)
{
	PkiRsaKey rsaKey1, rsaKey2;
	boost::posix_time::ptime validTimeNotBefore(boost::posix_time::time_from_string("2016-03-15 15:00:00"));
	boost::posix_time::ptime validTimeNotAfter(boost::posix_time::time_from_string("2021-03-15 15:00:00"));

	std::string hostname = boost::asio::ip::host_name();

	{ // write certificate to file

		PkiIdentity identity;
		identity.commonName()		= "ASNeG-Demo@" + hostname;
		identity.organization()		= "ASNeG";
		identity.organizationUnit()	= "Unit";
		identity.locality()			= "LocationName";
		identity.state()			= "State";
		identity.country()			= "DE";
		identity.domainComponent()	= hostname;

		PkiCertificateInfo info;
		info.URI()					= "urn:" + hostname + ":ASNeG::ASNeG-Demo";
		info.dnsNames().push_back(hostname);
		info.validTimeNotBefore(validTimeNotBefore);
		info.validTimeNotAfter(validTimeNotAfter);

		BOOST_REQUIRE(rsaKey1.createKey(1024) == true);

		PkiPrivateKey issuerPrivateKey;
		BOOST_REQUIRE(rsaKey1.getPrivateKey(issuerPrivateKey) == true);

		PkiPublicKey subjectPublicKey;
		BOOST_REQUIRE(rsaKey1.getPublicKey(subjectPublicKey) == true);

		PkiCertificate certificate;
		BOOST_REQUIRE(
			certificate.createNewCertificate(
				info, identity, subjectPublicKey, identity, issuerPrivateKey
			) == true
		);

		//
		// store certificate
		//
		BOOST_REQUIRE(certificate.toDERFile("../tst/data/ASNeG-Test.der") == true);

		//
		// store private key
		//
		BOOST_REQUIRE(rsaKey1.writePEMFile("../tst/data/ASNeG-Test.PEM", "") == true);
	}

	{ // read certificate from file
		PkiCertificate certificate;

		PkiCertificateInfo pkiCertificateInfo;
		PkiIdentity subjectPkiIdentity;
		PkiPublicKey subjectPkiPublicKey;
		PkiIdentity issuerPkiIdentity;
		PkiPrivateKey issuerPrivateKey;

		certificate.fromDERFile("../tst/data/ASNeG-Test.der");

		BOOST_REQUIRE(certificate.fromDERFile("../tst/data/ASNeG-Test.der") == true);
		BOOST_REQUIRE(
			certificate.getCertificate(
				pkiCertificateInfo,
				subjectPkiIdentity,
				subjectPkiPublicKey,
				issuerPkiIdentity,
				issuerPrivateKey
			) == true
		);

		BOOST_REQUIRE(subjectPkiIdentity.commonName()	== "ASNeG-Demo@" + hostname);
		BOOST_REQUIRE(subjectPkiIdentity.organization() == "ASNeG");
		BOOST_REQUIRE(subjectPkiIdentity.organizationUnit() == "Unit");
		BOOST_REQUIRE(subjectPkiIdentity.locality() == "LocationName");
		BOOST_REQUIRE(subjectPkiIdentity.state() == "State");
		BOOST_REQUIRE(subjectPkiIdentity.country() == "DE");
		BOOST_REQUIRE(subjectPkiIdentity.domainComponent() == hostname);

		BOOST_REQUIRE(issuerPkiIdentity.commonName()	== "ASNeG-Demo@" + hostname);
		BOOST_REQUIRE(issuerPkiIdentity.organization() == "ASNeG");
		BOOST_REQUIRE(issuerPkiIdentity.organizationUnit() == "Unit");
		BOOST_REQUIRE(issuerPkiIdentity.locality() == "LocationName");
		BOOST_REQUIRE(issuerPkiIdentity.state() == "State");
		BOOST_REQUIRE(issuerPkiIdentity.country() == "DE");
		BOOST_REQUIRE(issuerPkiIdentity.domainComponent() == hostname);

		// inaccuracy available
		//BOOST_REQUIRE(pkiCertificateInfo.validTimeNotBefore() == validTimeNotBefore);
		//BOOST_REQUIRE(pkiCertificateInfo.validTimeNotAfter() == validTimeNotAfter);

	}
}
#endif

BOOST_AUTO_TEST_SUITE_END()


