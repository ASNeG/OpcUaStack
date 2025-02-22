#include "unittest.h"

#include <boost/filesystem.hpp>

#include "OpcUaStackCore/PKI/PKIStoreFile.h"


using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(PKIStoreFile_)

BOOST_AUTO_TEST_CASE(PKIStoreFile_)
{
	std::cout << "PKIStoreFile_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(PKIStoreFile_open_close_rootDir)
{
	boost::filesystem::remove_all(boost::filesystem::path("./pki"));

	// Set configuration
	auto config = boost::make_shared<PKIStoreFileConfiguration>();
	config->rootPath_ = "./pki";

	// Open PKI Store
	PKIStoreFile pkiStore;
	BOOST_REQUIRE(pkiStore.open(config) == true);
	BOOST_REQUIRE(boost::filesystem::is_directory(boost::filesystem::path("./pki")) == true);

	// Close PKI Store
	BOOST_REQUIRE(pkiStore.close() == true);

	boost::filesystem::remove_all(boost::filesystem::path("./pki"));
}

BOOST_AUTO_TEST_CASE(PKIStoreFile_open_close_rootDir_deep)
{
	boost::filesystem::remove_all(boost::filesystem::path("./pki/pki"));

	// Set configuration
	auto config = boost::make_shared<PKIStoreFileConfiguration>();
	config->rootPath_ = "./pki/pki";

	// Open PKI Store - Two directories must be created
	PKIStoreFile pkiStore;
	BOOST_REQUIRE(pkiStore.open(config) == true);
	BOOST_REQUIRE(boost::filesystem::is_directory(boost::filesystem::path("./pki/pki")) == true);

	// Close PKI Store
	BOOST_REQUIRE(pkiStore.close() == true);

	boost::filesystem::remove_all(boost::filesystem::path("./pki/pki"));
}

BOOST_AUTO_TEST_CASE(PKIStoreFile_write_exist_read_remove_1)
{
	boost::filesystem::remove_all(boost::filesystem::path("./pki"));

	// Open PKI Store -
	PKIStoreFile pkiStore;
	BOOST_REQUIRE(pkiStore.open(boost::make_shared<PKIStoreFileConfiguration>()) == true);

	// Write data to PKI store
	BOOST_REQUIRE(pkiStore.write(PKIStoreDataType::TrustedCert, "MyCert", OpcUaByteString("0123456789")) == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "MyCert") == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "87acec17cd9dcd20a716cc2cf67417b71c8a7016") == true);

	// Read data from PKI store
	OpcUaByteString data1, data2;
	BOOST_REQUIRE(pkiStore.read(PKIStoreDataType::TrustedCert, "87acec17cd9dcd20a716cc2cf67417b71c8a7016", data1) == true);
	BOOST_REQUIRE(data1.toString() == std::string("0123456789"));
	BOOST_REQUIRE(pkiStore.read(PKIStoreDataType::TrustedCert, "MyCert", data2) == true);
	BOOST_REQUIRE(data2.toString() == std::string("0123456789"));

	// Remove data from PKI store
	BOOST_REQUIRE(pkiStore.remove(PKIStoreDataType::TrustedCert, "MyCert") == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "MyCert") == false);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "87acec17cd9dcd20a716cc2cf67417b71c8a7016") == false);

	// Close PKI Store
	BOOST_REQUIRE(pkiStore.close() == true);

	boost::filesystem::remove_all(boost::filesystem::path("./pki"));
}

BOOST_AUTO_TEST_CASE(PKIStoreFile_write_exist_read_remove_2)
{
	boost::filesystem::remove_all(boost::filesystem::path("./pki"));

	// Open PKI Store -
	PKIStoreFile pkiStore;
	BOOST_REQUIRE(pkiStore.open(boost::make_shared<PKIStoreFileConfiguration>()) == true);

	// Write data to PKI store
	BOOST_REQUIRE(pkiStore.write(PKIStoreDataType::TrustedCert, "MyCert", OpcUaByteString("0123456789")) == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "MyCert") == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "87acec17cd9dcd20a716cc2cf67417b71c8a7016") == true);

	// Read data from PKI store
	OpcUaByteString data1, data2;
	BOOST_REQUIRE(pkiStore.read(PKIStoreDataType::TrustedCert, "87acec17cd9dcd20a716cc2cf67417b71c8a7016", data1) == true);
	BOOST_REQUIRE(data1.toString() == std::string("0123456789"));
	BOOST_REQUIRE(pkiStore.read(PKIStoreDataType::TrustedCert, "MyCert", data2) == true);
	BOOST_REQUIRE(data2.toString() == std::string("0123456789"));

	// Remove data from PKI store
	BOOST_REQUIRE(pkiStore.remove(PKIStoreDataType::TrustedCert, "87acec17cd9dcd20a716cc2cf67417b71c8a7016") == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "MyCert") == false);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "87acec17cd9dcd20a716cc2cf67417b71c8a7016") == false);

	// Close PKI Store
	BOOST_REQUIRE(pkiStore.close() == true);

	boost::filesystem::remove_all(boost::filesystem::path("./pki"));
}

BOOST_AUTO_TEST_CASE(PKIStoreFile_read_all)
{
	boost::filesystem::remove_all(boost::filesystem::path("./pki"));

	// Open PKI Store -
	PKIStoreFile pkiStore;
	BOOST_REQUIRE(pkiStore.open(boost::make_shared<PKIStoreFileConfiguration>()) == true);

	// Write data to PKI store
	BOOST_REQUIRE(pkiStore.write(PKIStoreDataType::TrustedCert, "MyCert0", OpcUaByteString("0123456789")) == true);
	BOOST_REQUIRE(pkiStore.write(PKIStoreDataType::TrustedCert, "MyCert1", OpcUaByteString("9876543210")) == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "MyCert0") == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "87acec17cd9dcd20a716cc2cf67417b71c8a7016") == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "MyCert1") == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "9cd656169600157ec17231dcf0613c94932efcdc") == true);

	// Read data vector from PKI store
	std::vector<OpcUaByteString> dataVec;
	BOOST_REQUIRE(pkiStore.readAll(PKIStoreDataType::TrustedCert, dataVec) == true);
	BOOST_REQUIRE(dataVec.size() ==  2);
	if (dataVec[0] == OpcUaByteString("0123456789")) {
		BOOST_REQUIRE(dataVec[0] == OpcUaByteString("0123456789"));
		BOOST_REQUIRE(dataVec[1] == OpcUaByteString("9876543210"));
	}
	else {
		BOOST_REQUIRE(dataVec[0] == OpcUaByteString("9876543210"));
		BOOST_REQUIRE(dataVec[1] == OpcUaByteString("0123456789"));
	}

	// Remove all data from PKI store
	BOOST_REQUIRE(pkiStore.removeAll(PKIStoreDataType::TrustedCert) == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "MyCert0") == false);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "87acec17cd9dcd20a716cc2cf67417b71c8a7016") == false);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "MyCert1") == false);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "9cd656169600157ec17231dcf0613c94932efcdc") == false);

	// Close PKI Store
	BOOST_REQUIRE(pkiStore.close() == true);

	boost::filesystem::remove_all(boost::filesystem::path("./pki"));
}

BOOST_AUTO_TEST_CASE(PKIStoreFile_cleanup)
{
	boost::filesystem::remove_all(boost::filesystem::path("./pki"));

	// Open PKI Store -
	PKIStoreFile pkiStore;
	BOOST_REQUIRE(pkiStore.open(boost::make_shared<PKIStoreFileConfiguration>()) == true);

	// Write data to PKI store
	BOOST_REQUIRE(pkiStore.write(PKIStoreDataType::TrustedCert, "MyCert0", OpcUaByteString("0123456789")) == true);
	BOOST_REQUIRE(pkiStore.write(PKIStoreDataType::TrustedCert, "MyCert1", OpcUaByteString("9876543210")) == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "MyCert0") == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "87acec17cd9dcd20a716cc2cf67417b71c8a7016") == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "MyCert1") == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "9cd656169600157ec17231dcf0613c94932efcdc") == true);

	// Read data vector from PKI store
	std::vector<OpcUaByteString> dataVec;
	BOOST_REQUIRE(pkiStore.readAll(PKIStoreDataType::TrustedCert, dataVec) == true);
	BOOST_REQUIRE(dataVec.size() ==  2);
	if (dataVec[0] == OpcUaByteString("0123456789")) {
		BOOST_REQUIRE(dataVec[0] == OpcUaByteString("0123456789"));
		BOOST_REQUIRE(dataVec[1] == OpcUaByteString("9876543210"));
	}
	else {
		BOOST_REQUIRE(dataVec[0] == OpcUaByteString("9876543210"));
		BOOST_REQUIRE(dataVec[1] == OpcUaByteString("0123456789"));
	}

	// Remove all data from PKI store
	BOOST_REQUIRE(pkiStore.cleanup() == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "MyCert0") == false);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "87acec17cd9dcd20a716cc2cf67417b71c8a7016") == false);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "MyCert1") == false);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "9cd656169600157ec17231dcf0613c94932efcdc") == false);

	// Close PKI Store
	BOOST_REQUIRE(pkiStore.close() == true);

	boost::filesystem::remove_all(boost::filesystem::path("./pki"));
}

BOOST_AUTO_TEST_CASE(PKIStoreFile_remove_all)
{
	boost::filesystem::remove_all(boost::filesystem::path("./pki"));

	// Open PKI Store -
	PKIStoreFile pkiStore;
	BOOST_REQUIRE(pkiStore.open(boost::make_shared<PKIStoreFileConfiguration>()) == true);

	// Write data to PKI store
	BOOST_REQUIRE(pkiStore.write(PKIStoreDataType::TrustedCert, "MyCert0", OpcUaByteString("0123456789")) == true);
	BOOST_REQUIRE(pkiStore.write(PKIStoreDataType::TrustedCert, "MyCert1", OpcUaByteString("9876543210")) == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "MyCert0") == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "87acec17cd9dcd20a716cc2cf67417b71c8a7016") == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "MyCert1") == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "9cd656169600157ec17231dcf0613c94932efcdc") == true);

	// Read data vector from PKI store
	std::vector<OpcUaByteString> dataVec;
	BOOST_REQUIRE(pkiStore.readAll(PKIStoreDataType::TrustedCert, dataVec) == true);
	BOOST_REQUIRE(dataVec.size() ==  2);
	if (dataVec[0] == OpcUaByteString("0123456789")) {
		BOOST_REQUIRE(dataVec[0] == OpcUaByteString("0123456789"));
		BOOST_REQUIRE(dataVec[1] == OpcUaByteString("9876543210"));
	}
	else {
		BOOST_REQUIRE(dataVec[0] == OpcUaByteString("9876543210"));
		BOOST_REQUIRE(dataVec[1] == OpcUaByteString("0123456789"));
	}

	// Remove data from PKI store
	BOOST_REQUIRE(pkiStore.remove(PKIStoreDataType::TrustedCert, "87acec17cd9dcd20a716cc2cf67417b71c8a7016") == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "MyCert0") == false);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "87acec17cd9dcd20a716cc2cf67417b71c8a7016") == false);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "MyCert1") == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "9cd656169600157ec17231dcf0613c94932efcdc") == true);

	BOOST_REQUIRE(pkiStore.remove(PKIStoreDataType::TrustedCert, "9cd656169600157ec17231dcf0613c94932efcdc") == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "MyCert0") == false);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "87acec17cd9dcd20a716cc2cf67417b71c8a7016") == false);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "MyCert1") == false);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "9cd656169600157ec17231dcf0613c94932efcdc") == false);

	// Close PKI Store
	BOOST_REQUIRE(pkiStore.close() == true);

	boost::filesystem::remove_all(boost::filesystem::path("./pki"));
}

BOOST_AUTO_TEST_CASE(PKIStoreFile_empty)
{
	boost::filesystem::remove_all(boost::filesystem::path("./pki"));

	// Open PKI Store -
	PKIStoreFile pkiStore;
	BOOST_REQUIRE(pkiStore.open(boost::make_shared<PKIStoreFileConfiguration>()) == true);

	// Check empty
	BOOST_REQUIRE(pkiStore.empty(PKIStoreDataType::TrustedCert) == true);

	// Write data to PKI store
	BOOST_REQUIRE(pkiStore.write(PKIStoreDataType::TrustedCert, "MyCert", OpcUaByteString("0123456789")) == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "MyCert") == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "87acec17cd9dcd20a716cc2cf67417b71c8a7016") == true);

	// Check empty
	BOOST_REQUIRE(pkiStore.empty(PKIStoreDataType::TrustedCert) == false);

	// Remove data from PKI store
	BOOST_REQUIRE(pkiStore.remove(PKIStoreDataType::TrustedCert, "MyCert") == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "MyCert") == false);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "87acec17cd9dcd20a716cc2cf67417b71c8a7016") == false);

	// Check empty
	BOOST_REQUIRE(pkiStore.empty(PKIStoreDataType::TrustedCert) == true);

	// Close PKI Store
	BOOST_REQUIRE(pkiStore.close() == true);

	boost::filesystem::remove_all(boost::filesystem::path("./pki"));
}

BOOST_AUTO_TEST_CASE(PKIStoreFile_getNames1)
{
	boost::filesystem::remove_all(boost::filesystem::path("./pki"));

	// Open PKI Store -
	PKIStoreFile pkiStore;
	BOOST_REQUIRE(pkiStore.open(boost::make_shared<PKIStoreFileConfiguration>()) == true);

	// Write data to PKI store
	BOOST_REQUIRE(pkiStore.write(PKIStoreDataType::TrustedCert, "MyCert0", OpcUaByteString("0123456789")) == true);
	BOOST_REQUIRE(pkiStore.write(PKIStoreDataType::TrustedCert, "MyCert1", OpcUaByteString("9876543210")) == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "MyCert0") == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "87acec17cd9dcd20a716cc2cf67417b71c8a7016") == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "MyCert1") == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "9cd656169600157ec17231dcf0613c94932efcdc") == true);

	// Get names
	std::vector<std::string> nameVec;

	nameVec.clear();
	BOOST_REQUIRE(pkiStore.getNameList(PKIStoreDataType::TrustedCert, nameVec, PKIStoreNameType::ThumbPrint) == true);
	BOOST_REQUIRE(nameVec.size() == 2);
	if (nameVec[0] == "87acec17cd9dcd20a716cc2cf67417b71c8a7016") {
		BOOST_REQUIRE(nameVec[0] == "87acec17cd9dcd20a716cc2cf67417b71c8a7016");
		BOOST_REQUIRE(nameVec[1] == "9cd656169600157ec17231dcf0613c94932efcdc");
	}
	else {
		BOOST_REQUIRE(nameVec[1] == "87acec17cd9dcd20a716cc2cf67417b71c8a7016");
		BOOST_REQUIRE(nameVec[0] == "9cd656169600157ec17231dcf0613c94932efcdc");
	}

	nameVec.clear();
	BOOST_REQUIRE(pkiStore.getNameList(PKIStoreDataType::TrustedCert, nameVec, PKIStoreNameType::RealName) == true);
	BOOST_REQUIRE(nameVec.size() == 2);
	if (nameVec[0] == "MyCert0") {
		BOOST_REQUIRE(nameVec[0] == "MyCert0");
		BOOST_REQUIRE(nameVec[1] == "MyCert1");
	}
	else {
		BOOST_REQUIRE(nameVec[1] == "MyCert0");
		BOOST_REQUIRE(nameVec[0] == "MyCert1");
	}

	// Close PKI Store
	BOOST_REQUIRE(pkiStore.close() == true);

	boost::filesystem::remove_all(boost::filesystem::path("./pki"));
}

BOOST_AUTO_TEST_CASE(PKIStoreFile_getNames2)
{
	boost::filesystem::remove_all(boost::filesystem::path("./pki"));

	// Open PKI Store -
	auto storeCfg = boost::make_shared<PKIStoreFileConfiguration>();
	storeCfg->dirEntryVec_ = {{PKIStoreDataType::TrustedCert, "TrustedCert", true, false}};

	PKIStoreFile pkiStore;
	BOOST_REQUIRE(pkiStore.open(storeCfg) == true);

	// Write data to PKI store
	BOOST_REQUIRE(pkiStore.write(PKIStoreDataType::TrustedCert, "MyCert0", OpcUaByteString("0123456789")) == true);
	BOOST_REQUIRE(pkiStore.write(PKIStoreDataType::TrustedCert, "MyCert1", OpcUaByteString("9876543210")) == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "MyCert0") == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "87acec17cd9dcd20a716cc2cf67417b71c8a7016") == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "MyCert1") == true);
	BOOST_REQUIRE(pkiStore.exist(PKIStoreDataType::TrustedCert, "9cd656169600157ec17231dcf0613c94932efcdc") == true);

	// Get names
	std::vector<std::string> nameVec;

	nameVec.clear();
	BOOST_REQUIRE(pkiStore.getNameList(PKIStoreDataType::TrustedCert, nameVec, PKIStoreNameType::ThumbPrint) == true);
	BOOST_REQUIRE(nameVec.size() == 2);
	if (nameVec[0] == "87acec17cd9dcd20a716cc2cf67417b71c8a7016") {
		BOOST_REQUIRE(nameVec[0] == "87acec17cd9dcd20a716cc2cf67417b71c8a7016");
		BOOST_REQUIRE(nameVec[1] == "9cd656169600157ec17231dcf0613c94932efcdc");
	}
	else {
		BOOST_REQUIRE(nameVec[1] == "87acec17cd9dcd20a716cc2cf67417b71c8a7016");
		BOOST_REQUIRE(nameVec[0] == "9cd656169600157ec17231dcf0613c94932efcdc");
	}

	nameVec.clear();
	BOOST_REQUIRE(pkiStore.getNameList(PKIStoreDataType::TrustedCert, nameVec, PKIStoreNameType::RealName) == true);
	BOOST_REQUIRE(nameVec.size() == 2);
	if (nameVec[0] == "MyCert0") {
		BOOST_REQUIRE(nameVec[0] == "MyCert0");
		BOOST_REQUIRE(nameVec[1] == "MyCert1");
	}
	else {
		BOOST_REQUIRE(nameVec[1] == "MyCert0");
		BOOST_REQUIRE(nameVec[0] == "MyCert1");
	}


	// Close PKI Store
	BOOST_REQUIRE(pkiStore.close() == true);

	boost::filesystem::remove_all(boost::filesystem::path("./pki"));
}

BOOST_AUTO_TEST_SUITE_END()
