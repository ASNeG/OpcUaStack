#include <iostream>

#include "unittest.h"
#include "OpcUaStackCore/Certificate/CSR.h"
#include "OpcUaStackCore/Certificate/RSAKey.h"
#include "OpcUaStackCore/Certificate/UserExtensionOpenSSL.h"
#include "OpcUaStackCore/Certificate/UserExtensionObject.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(CSR_)

BOOST_AUTO_TEST_CASE(CSR_)
{
	std::cout << "CSR_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(CSR_encode_decode)
{
	RSAKey key(2048);
	CSR csr0, csr1;
	Identity subject0, subject1;
	CertificateInfo info0, info1;
	PrivateKey privateKey0;
	PublicKey publicKey0, publicKey1;

	subject0.organization("ASNeG");
	subject0.organizationUnit("OPC UA Service Department");
	subject0.commonName("MyServiceApplication");
	subject0.locality("Neukirchen");
	subject0.state("Hessen");
	subject0.country("DE");
	subject0.domainComponent("asneg.de");

	info0.uri("urn:localhost:ASNeG:MyServiceApplication");
	info0.ipAddresses().push_back("127.0.0.1");
	info0.dnsNames().push_back("ASNeG.de");
	info0.eMail("info@ASNeG.de");

	// Create CSR request
	privateKey0 = key.privateKey();
	publicKey0 = key.publicKey();
	BOOST_REQUIRE(csr0.createCSR(subject0, info0, publicKey0, privateKey0) == true);

	// Encode CSR request
	MemoryBuffer derBuf;
	BOOST_REQUIRE(csr0.toDERBuf(derBuf) == true);

	// Decode CSR request
	BOOST_REQUIRE(csr1.fromDERBuf(derBuf) == true);

	// check subject
	BOOST_REQUIRE(csr1.getSubject(subject1) == true);
	BOOST_REQUIRE(subject1.organization() == std::string("ASNeG"));
	BOOST_REQUIRE(subject1.organizationUnit() == std::string("OPC UA Service Department"));
	BOOST_REQUIRE(subject1.commonName() == std::string("MyServiceApplication"));
	BOOST_REQUIRE(subject1.locality() == std::string("Neukirchen"));
	BOOST_REQUIRE(subject1.state() == std::string("Hessen"));
	BOOST_REQUIRE(subject1.country() == std::string("DE"));
	BOOST_REQUIRE(subject1.domainComponent() == std::string("asneg.de"));

	// Check info
	BOOST_REQUIRE(csr1.getInfo(info1) == true);
	BOOST_REQUIRE(info1.uri() == std::string("urn:localhost:ASNeG:MyServiceApplication"));
	BOOST_REQUIRE(info1.ipAddresses()[0] == std::string("127.0.0.1"));
	BOOST_REQUIRE(info1.dnsNames()[0] == std::string("ASNeG.de"));
	BOOST_REQUIRE(info1.eMail() == std::string("info@ASNeG.de"));

	// Check certificate
	BOOST_REQUIRE(csr1.getPublicKey(publicKey1) == true);

	char dataBuf0[10000];
	uint32_t dataLen0 = 10000;
	publicKey0.toDER(dataBuf0, dataLen0);
	OpcUaByteString derBuf0((const OpcUaByte*)dataBuf0, dataLen0);
	//std::cout << "..." << derBuf0.toHexString() << std::endl;

	char dataBuf1[10000];
	uint32_t dataLen1 = 10000;
	publicKey1.toDER(dataBuf1, dataLen1);
	OpcUaByteString derBuf1((const OpcUaByte*)dataBuf1, dataLen1);
	//std::cout << "..." << derBuf1.toHexString() << std::endl;

	BOOST_REQUIRE(derBuf0.toHexString() == derBuf1.toHexString());
}

BOOST_AUTO_TEST_CASE(CSR_encode_decode_user_extension)
{
	std::string value;
	RSAKey key(2048);
	CSR csr0, csr1;
	Identity subject0, subject1;
	CertificateInfo info0, info1;
	PrivateKey privateKey0;
	PublicKey publicKey0, publicKey1;

	// Register user extension types
	UserExtensionObject ueo;
	ueo.registerUserExtension(1, "1.3.6.1.4.1.444.1", "P1", "PARA1");
	ueo.registerUserExtension(2, "1.3.6.1.4.1.444.2", "P2", "PARA2");

	subject0.organization("ASNeG");
	subject0.organizationUnit("OPC UA Service Department");
	subject0.commonName("MyServiceApplication");
	subject0.locality("Neukirchen");
	subject0.state("Hessen");
	subject0.country("DE");
	subject0.domainComponent("asneg.de");

	info0.uri("urn:localhost:ASNeG:MyServiceApplication");
	info0.ipAddresses().push_back("127.0.0.1");
	info0.dnsNames().push_back("ASNeG.de");
	info0.eMail("info@ASNeG.de");

	// Create user extension
	UserExtension::SPtr ue_in0 = boost::make_shared<UserExtensionOpenSSL>();
	ue_in0->nid(1);
	ue_in0->setEntry("N1", "V1");
	ue_in0->setEntry("N2", "V2");
	UserExtension::SPtr ue_in1 = boost::make_shared<UserExtensionOpenSSL>();
	ue_in1->nid(2);
	ue_in1->setEntry("N3", "V3");
	ue_in1->setEntry("N4", "V4");
	UserExtension::Vec ue_vec = {ue_in0, ue_in1};

	// Create CSR request
	privateKey0 = key.privateKey();
	publicKey0 = key.publicKey();
	BOOST_REQUIRE(csr0.createCSR(subject0, info0, publicKey0, privateKey0, &ue_vec) == true);

	// Encode CSR request
	MemoryBuffer derBuf;
	BOOST_REQUIRE(csr0.toDERBuf(derBuf) == true);

	// Decode CSR request
	BOOST_REQUIRE(csr1.fromDERBuf(derBuf) == true);

	// check subject
	BOOST_REQUIRE(csr1.getSubject(subject1) == true);
	BOOST_REQUIRE(subject1.organization() == std::string("ASNeG"));
	BOOST_REQUIRE(subject1.organizationUnit() == std::string("OPC UA Service Department"));
	BOOST_REQUIRE(subject1.commonName() == std::string("MyServiceApplication"));
	BOOST_REQUIRE(subject1.locality() == std::string("Neukirchen"));
	BOOST_REQUIRE(subject1.state() == std::string("Hessen"));
	BOOST_REQUIRE(subject1.country() == std::string("DE"));
	BOOST_REQUIRE(subject1.domainComponent() == std::string("asneg.de"));

	// Check info
	BOOST_REQUIRE(csr1.getInfo(info1) == true);
	BOOST_REQUIRE(info1.uri() == std::string("urn:localhost:ASNeG:MyServiceApplication"));
	BOOST_REQUIRE(info1.ipAddresses()[0] == std::string("127.0.0.1"));
	BOOST_REQUIRE(info1.dnsNames()[0] == std::string("ASNeG.de"));
	BOOST_REQUIRE(info1.eMail() == std::string("info@ASNeG.de"));

	// Check certificate
	BOOST_REQUIRE(csr1.getPublicKey(publicKey1) == true);

	char dataBuf0[10000];
	uint32_t dataLen0 = 10000;
	publicKey0.toDER(dataBuf0, dataLen0);
	OpcUaByteString derBuf0((const OpcUaByte*)dataBuf0, dataLen0);
	//std::cout << "..." << derBuf0.toHexString() << std::endl;

	char dataBuf1[10000];
	uint32_t dataLen1 = 10000;
	publicKey1.toDER(dataBuf1, dataLen1);
	OpcUaByteString derBuf1((const OpcUaByte*)dataBuf1, dataLen1);
	//std::cout << "..." << derBuf1.toHexString() << std::endl;

	BOOST_REQUIRE(derBuf0.toHexString() == derBuf1.toHexString());

	// Check user extension (NID=1)
	UserExtension::SPtr ue_out0 = boost::make_shared<UserExtensionOpenSSL>();
	ue_out0->nid(1);
	BOOST_REQUIRE(csr1.getUserExtension(ue_out0) == true);
	BOOST_REQUIRE(ue_out0->getEntry("N1", value) == true);
	BOOST_REQUIRE(value == "V1");
	BOOST_REQUIRE(ue_out0->getEntry("N2", value) == true);
	BOOST_REQUIRE(value == "V2");

	// Check user extension (NID=2)
	UserExtension::SPtr ue_out1 = boost::make_shared<UserExtensionOpenSSL>();
	ue_out1->nid(2);
	BOOST_REQUIRE(csr1.getUserExtension(ue_out1) == true);
	BOOST_REQUIRE(ue_out1->getEntry("N3", value) == true);
	BOOST_REQUIRE(value == "V3");
	BOOST_REQUIRE(ue_out1->getEntry("N4", value) == true);
	BOOST_REQUIRE(value == "V4");
}

BOOST_AUTO_TEST_CASE(CSR_verify_signature)
{
	RSAKey key(2048);
	CSR csr0, csr1;
	Identity subject0, subject1;
	CertificateInfo info0, info1;
	PrivateKey privateKey0;
	PublicKey publicKey0, publicKey1;

	subject0.organization("ASNeG");
	subject0.organizationUnit("OPC UA Service Department");
	subject0.commonName("MyServiceApplication");
	subject0.locality("Neukirchen");
	subject0.state("Hessen");
	subject0.country("DE");
	subject0.domainComponent("asneg.de");

	info0.uri("urn:localhost:ASNeG:MyServiceApplication");
	info0.ipAddresses().push_back("127.0.0.1");
	info0.dnsNames().push_back("ASNeG.de");
	info0.eMail("info@ASNeG.de");

	// Create CSR request
	privateKey0 = key.privateKey();
	publicKey0 = key.publicKey();
	BOOST_REQUIRE(csr0.createCSR(subject0, info0, publicKey0, privateKey0) == true);

	// Encode CSR request
	MemoryBuffer derBuf;
	BOOST_REQUIRE(csr0.toDERBuf(derBuf) == true);

	// Decode CSR request
	BOOST_REQUIRE(csr1.fromDERBuf(derBuf) == true);

	// check subject
	BOOST_REQUIRE(csr1.getSubject(subject1) == true);
	BOOST_REQUIRE(subject1.organization() == std::string("ASNeG"));
	BOOST_REQUIRE(subject1.organizationUnit() == std::string("OPC UA Service Department"));
	BOOST_REQUIRE(subject1.commonName() == std::string("MyServiceApplication"));
	BOOST_REQUIRE(subject1.locality() == std::string("Neukirchen"));
	BOOST_REQUIRE(subject1.state() == std::string("Hessen"));
	BOOST_REQUIRE(subject1.country() == std::string("DE"));
	BOOST_REQUIRE(subject1.domainComponent() == std::string("asneg.de"));

	// Check info
	BOOST_REQUIRE(csr1.getInfo(info1) == true);
	BOOST_REQUIRE(info1.uri() == std::string("urn:localhost:ASNeG:MyServiceApplication"));
	BOOST_REQUIRE(info1.ipAddresses()[0] == std::string("127.0.0.1"));
	BOOST_REQUIRE(info1.dnsNames()[0] == std::string("ASNeG.de"));
	BOOST_REQUIRE(info1.eMail() == std::string("info@ASNeG.de"));

	// Check certificate
	BOOST_REQUIRE(csr1.getPublicKey(publicKey1) == true);

	char dataBuf0[10000];
	uint32_t dataLen0 = 10000;
	publicKey0.toDER(dataBuf0, dataLen0);
	OpcUaByteString derBuf0((const OpcUaByte*)dataBuf0, dataLen0);
	//std::cout << "..." << derBuf0.toHexString() << std::endl;

	char dataBuf1[10000];
	uint32_t dataLen1 = 10000;
	publicKey1.toDER(dataBuf1, dataLen1);
	OpcUaByteString derBuf1((const OpcUaByte*)dataBuf1, dataLen1);
	//std::cout << "..." << derBuf1.toHexString() << std::endl;

	BOOST_REQUIRE(derBuf0.toHexString() == derBuf1.toHexString());

	// Verify signature
	BOOST_REQUIRE(csr1.validateSignature(publicKey0) == true);
}

BOOST_AUTO_TEST_SUITE_END()
