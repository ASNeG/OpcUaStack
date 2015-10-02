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
	info.validTime(3600*24*365*5);

	PkiRsaKey rsaKey;
	BOOST_REQUIRE(rsaKey.createKey(1024) == true);

	PkiPrivateKey issuerPrivateKey;
	BOOST_REQUIRE(rsaKey.getPrivateKey(issuerPrivateKey) == true);

	PkiPublicKey subjectPublicKey;
	BOOST_REQUIRE(rsaKey.getPublicKey(subjectPublicKey) == true);

	PkiCertificate certificate;
	BOOST_REQUIRE(certificate.createNewCertificate(info, identity, subjectPublicKey, identity, issuerPrivateKey) == true);
}

BOOST_AUTO_TEST_CASE(PkiCertificate_store_key)
{
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
	info.validTime(3600*24*365*5);

	PkiRsaKey rsaKey;
	BOOST_REQUIRE(rsaKey.createKey(1024) == true);

	PkiPrivateKey issuerPrivateKey;
	BOOST_REQUIRE(rsaKey.getPrivateKey(issuerPrivateKey) == true);

	PkiPublicKey subjectPublicKey;
	BOOST_REQUIRE(rsaKey.getPublicKey(subjectPublicKey) == true);

	PkiCertificate certificate;
	BOOST_REQUIRE(certificate.createNewCertificate(info, identity, subjectPublicKey, identity, issuerPrivateKey) == true);

	//
	// store public key
	//
	BOOST_REQUIRE(certificate.toDERFile("../tst/data/certs/ASNeG-Test.der") == true);

	//
	// store private key
	//
	BOOST_REQUIRE(rsaKey.writePEMFile("../tst/data/private/ASNeG-Test.PEM", "") == true);
}

BOOST_AUTO_TEST_SUITE_END()


