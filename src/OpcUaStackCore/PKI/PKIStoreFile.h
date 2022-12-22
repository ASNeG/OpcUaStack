/*
   Copyright 2022 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_PKIStoreFile_h__
#define __OpcUaStackCore_PKIStoreFile_h__

#include <string>

#include <boost/shared_ptr.hpp>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/MemoryBuffer.h"
#include "OpcUaStackCore/PKI/PKIStore.h"

namespace OpcUaStackCore
{

	class DLLEXPORT PKIStoreFileConfiguration
	: public PKIStoreConfiguration
	{
	  public:
		using SPtr = boost::shared_ptr<PKIStoreFileConfiguration>;

		PKIStoreFileConfiguration(void);
		virtual ~PKIStoreFileConfiguration(void);

	    std::string rootPath_ = "pki";
	};


	class DLLEXPORT PKIStoreFile
	: public PKIStore
	{
	  public:
		using SPtr = boost::shared_ptr<PKIStoreFile>;

		PKIStoreFile(void);
		virtual ~PKIStoreFile(void);

		// PKIStore interface functions
		bool open(PKIStoreConfiguration::SPtr config) override;
		bool close(void) override;
		bool cleanup(void) override;

	  private:
		PKIStoreFileConfiguration::SPtr config_ = NULL;
	};

}

#endif
