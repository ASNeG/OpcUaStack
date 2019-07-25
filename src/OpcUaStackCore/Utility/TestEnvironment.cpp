
/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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

#include <cstdlib>
#include "OpcUaStackCore/Utility/TestEnvironment.h"

namespace OpcUaStackCore
{

	TestEnvironment::TestEnvironment(void)
	{
	}

	TestEnvironment::~TestEnvironment(void)
	{
	}

	bool
	TestEnvironment::testTrustAllCerts(void)
	{
		return getBoolEnv("TEST_TRUST_ALL_CERTS");
	}

	bool
	TestEnvironment::testUseASNeGCA(void)
	{
		return getBoolEnv("TEST_USE_ASNEG_CA");
	}

	bool
	TestEnvironment::testSelgSignedWithASNeGCA(void)
	{
		return getBoolEnv("TEST_CREATE_SELF_SIGNED_WITH_ASNEG_CA");
	}

	bool
	TestEnvironment::getBoolEnv(const std::string& name)
	{
		char* var = std::getenv(name.c_str());
		if (var != nullptr) {
			return true;
		}
		return false;
	}

}
