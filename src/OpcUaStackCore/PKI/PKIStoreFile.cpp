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

#include <boost/filesystem.hpp>

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/PKI/PKIStoreFile.h"

namespace OpcUaStackCore
{
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// PKIStoreFileConfiguration
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	PKIStoreFileConfiguration::PKIStoreFileConfiguration(void)
	: PKIStoreConfiguration()
	{
	}

	PKIStoreFileConfiguration::~PKIStoreFileConfiguration(void)
	{
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// PKIStoreFile
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	PKIStoreFile::PKIStoreFile(void)
	: PKIStore()
	{
	}
		
	PKIStoreFile::~PKIStoreFile(void)
	{
	}

	bool
	PKIStoreFile::open(PKIStoreConfiguration::SPtr config)
	{
		config_ = boost::static_pointer_cast<PKIStoreFileConfiguration>(config);

		Log(Info, "PKIFileStore open")
		    .parameter("RootDirectory", config_->rootPath_);

		// Check pki root directory
		if (!boost::filesystem::exists(boost::filesystem::path(config_->rootPath_))) {
			if (!boost::filesystem::create_directory(boost::filesystem::path(config_->rootPath_))) {
				Log(Error, "create root directory error")
					.parameter("RootDirectory", config_->rootPath_);
				return false;
			}
		}

		return true;
	}

	bool
	PKIStoreFile::close(void)
	{
		Log(Info, "PKIFileStore close");
		return true;
	}

	bool
	PKIStoreFile::cleanup(void)
	{
		// FIXME: TODO
		return true;
	}

}
