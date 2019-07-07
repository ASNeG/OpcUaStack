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

#ifndef __OpcUaCertificateGenerator_OpcUaCertificateGenerator_h__
#define __OpcUaCertificateGenerator_OpcUaCertificateGenerator_h__

#include <stdint.h>
#include <string>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaCertificateGenerator
{

	class DLLEXPORT OpcUaCertificateGenerator
	{
	  public:
		OpcUaCertificateGenerator(void);
		~OpcUaCertificateGenerator(void);

		uint32_t start(int argc, char** argv);

	  private:
		uint32_t createCertificate(void);

		std::string command_ = "";
		std::string descFile_ = "";
		bool selfSigned_ = true;
		bool ca_ = false;
	};

}

#endif
