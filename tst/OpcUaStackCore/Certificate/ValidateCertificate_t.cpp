#include "unittest.h"
#include "OpcUaStackCore/Certificate/ValidateCertificate.h"
#include "OpcUaStackCore/Certificate/CertificateManager.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ValidateCertificate_)

BOOST_AUTO_TEST_CASE(ValidateCertificate_)
{
	std::cout << "ValidateCertificate_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ValidateCertificate_Build_Test_Certs)
{
	CertificateInfo info;
	CertificateManager cm;

	//
	// create self signed certificate
	//
	RSAKey key(2048);
	BOOST_REQUIRE(key.isError() == false);

	Identity identity;
	identity.organization("ASNeG");
	identity.organizationUnit("OPC UA Service Department");
	identity.commonName("ASNeG-Self-Signed");
	identity.locality("Neukirchen");
	identity.state("Hessen");
	identity.country("DE");
	identity.domainComponent("devel");

	info.dnsNames().clear();
	info.eMail().clear();
	info.uri("urn:devel:ASNeG:ASNeG-Server");
	info.ipAddresses().push_back("127.0.0.1");
	info.dnsNames().push_back("devel");
	info.eMail("info@ASNeG.de");
	info.validTime(
		boost::posix_time::microsec_clock::local_time() +
		boost::posix_time::seconds(3600*24*365*5)
	);
	info.serialNumber(time(0));
	info.validFrom(boost::posix_time::microsec_clock::local_time());

	Certificate certificate(info, identity, key, false, SignatureAlgorithm_Sha256);
	BOOST_REQUIRE(certificate.isError() == false);

	cm.ownCertificateFile("ASNeG-Self-Signed.der");
	BOOST_REQUIRE(cm.writeOwnCertificate(certificate) == true);

	PrivateKey privateKey = key.privateKey();
	cm.ownPrivateKeyFile("ASNeG-Self-Signed.pem");
	BOOST_REQUIRE(cm.writeOwnPrivateKey(privateKey) == true);

	//
	// create root CA certificate
	//
	RSAKey keyCA(2048);
	BOOST_REQUIRE(keyCA.isError() == false);

	identity.organization("ASNeG");
	identity.organizationUnit("OPC UA Service Department");
	identity.commonName("ASNeG-CA");
	identity.locality("Neukirchen");
	identity.state("Hessen");
	identity.country("DE");
	identity.domainComponent("devel");

	info.dnsNames().clear();
	info.eMail().clear();
	info.uri("urn:devel:ASNeG:ASNeG-CA");
	info.ipAddresses().push_back("127.0.0.1");
	info.dnsNames().push_back("devel");
	info.eMail("info@ASNeG.de");
	info.validTime(
		boost::posix_time::microsec_clock::local_time() +
		boost::posix_time::seconds(3600*24*365*5)
	);
	info.serialNumber(time(0));
	info.validFrom(boost::posix_time::microsec_clock::local_time());

	Certificate certificateCA(info, identity, keyCA, true, SignatureAlgorithm_Sha256);
	BOOST_REQUIRE(certificateCA.isError() == false);

	cm.ownCertificateFile("ASNeG-CA.der");
	BOOST_REQUIRE(cm.writeOwnCertificate(certificateCA) == true);

	PrivateKey privateKeyCA = keyCA.privateKey();
	cm.ownPrivateKeyFile("ASNeG-CA.pem");
	BOOST_REQUIRE(cm.writeOwnPrivateKey(privateKeyCA) == true);

	//
	// create department certificate
	//
	RSAKey keyDEP(2048);
	BOOST_REQUIRE(keyDEP.isError() == false);

	identity.organization("ASNeG");
	identity.organizationUnit("OPC UA Service Department");
	identity.commonName("ASNeG-DEP");
	identity.locality("Neukirchen");
	identity.state("Hessen");
	identity.country("DE");
	identity.domainComponent("devel");

	info.dnsNames().clear();
	info.eMail().clear();
	info.uri("urn:devel:ASNeG:ASNeG-DEP");
	info.ipAddresses().push_back("127.0.0.1");
	info.dnsNames().push_back("devel");
	info.eMail("info@ASNeG.de");
	info.validTime(
		boost::posix_time::microsec_clock::local_time() +
		boost::posix_time::seconds(3600*24*365*5)
	);
	info.serialNumber(time(0));
	info.validFrom(boost::posix_time::microsec_clock::local_time());

	PublicKey publicKeyDEP = keyDEP.publicKey();
	Certificate certificateDEP(
		info, identity, publicKeyDEP,
		certificateCA, privateKeyCA,
		true, SignatureAlgorithm_Sha256);
	BOOST_REQUIRE(certificateDEP.isError() == false);

	cm.ownCertificateFile("ASNeG-DEP.der");
	BOOST_REQUIRE(cm.writeOwnCertificate(certificateDEP) == true);

	PrivateKey privateKeyDEP = keyDEP.privateKey();
	cm.ownPrivateKeyFile("ASNeG-DEP.pem");
	BOOST_REQUIRE(cm.writeOwnPrivateKey(privateKeyDEP) == true);

	//
	// create server certificate
	//
	RSAKey keySRV(2048);
	BOOST_REQUIRE(keySRV.isError() == false);

	identity.organization("ASNeG");
	identity.organizationUnit("OPC UA Service Department");
	identity.commonName("ASNeG-SRV");
	identity.locality("Neukirchen");
	identity.state("Hessen");
	identity.country("DE");
	identity.domainComponent("devel");

	info.dnsNames().clear();
	info.eMail().clear();
	info.uri("urn:devel:ASNeG:ASNeG-SRV");
	info.ipAddresses().push_back("127.0.0.1");
	info.dnsNames().push_back("devel");
	info.eMail("info@ASNeG.de");
	info.validTime(
		boost::posix_time::microsec_clock::local_time() +
		boost::posix_time::seconds(3600*24*365*5)
	);
	info.serialNumber(time(0));
	info.validFrom(boost::posix_time::microsec_clock::local_time());

	PublicKey publicKeySRV = keySRV.publicKey();
	Certificate certificateSRV(
		info, identity, publicKeySRV,
		certificateDEP, privateKeyDEP,
		false, SignatureAlgorithm_Sha256);
	BOOST_REQUIRE(certificateSRV.isError() == false);

	cm.ownCertificateFile("ASNeG-SRV.der");
	BOOST_REQUIRE(cm.writeOwnCertificate(certificateSRV) == true);

	PrivateKey privateKeySRV = keySRV.privateKey();
	cm.ownPrivateKeyFile("ASNeG-SRV.pem");
	BOOST_REQUIRE(cm.writeOwnPrivateKey(privateKeySRV) == true);
}

BOOST_AUTO_TEST_SUITE_END()
