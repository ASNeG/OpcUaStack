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

#ifndef __OpcUaStackCore_TestEnvironment_h__
#define __OpcUaStackCore_TestEnvironment_h__

#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	/**
	 * Provides parameters for the test environment that are read in via environment variables
	 *
	 * The following environment variables are evaluated
	 *
	 * - TEST_TRUST_ALL_CERTS (Values: undefined, defined)
	 *   If a foreign certificate  is received, a trust is automatically carries out for the
	 *   received certificate,
	 *
	 * - TEST_USE_ASNEG_CA (Values: undefined, defined)
	 *
	 * - TEST_CREATE_SELF_SIGNED_WITH_ASNEG_CA (Value: undefined, defined)
	 *
	 *
	 */
	class DLLEXPORT TestEnvironment
	{
	  public:
		TestEnvironment(void);
		~TestEnvironment(void);
	};

}

#endif
