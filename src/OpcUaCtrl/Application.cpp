/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#include <boost/make_shared.hpp>
#include <boost/filesystem.hpp>
#include <iostream>
#include <stdint.h>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaCtrl/Application.h"

using namespace OpcUaStackCore;

namespace OpcUaCtrl
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ApplicationInfo
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ApplicationInfo::ApplicationInfo(void)
	{
	}

	ApplicationInfo::~ApplicationInfo(void)
	{
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// Application
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	Application::Application(
	    const std::set<std::string>& applBlackList,
		const std::vector<std::string>& installPathList,
		const std::vector<std::string>& installPkiList
	)
	{
		// add install path list
		addInstallPath(applBlackList, installPathList);

		// add pki path list
		addPkiPath(applBlackList, installPkiList);
	}

	Application::~Application(void)
	{
	}

	ApplicationInfo::Map&
	Application::map(void)
	{
		return applicationInfoMap_;
	}

	const Application::iterator
	Application::begin(void)
	{
		return applicationInfoMap_.begin();
	}

	const Application::iterator
	Application::end(void)
	{
		return applicationInfoMap_.end();
	}

	const Application::iterator
	Application::find(const std::string& applName)
	{
		return applicationInfoMap_.find(applName);
	}

	void
	Application::addInstallPath(
	    const std::set<std::string>& applBlackList,
		const std::vector<std::string>& installPathList
	)
	{
		// We search for applications in all installation locations
		for ( auto installPath : installPathList ) {
			boost::filesystem::path applPath(installPath + std::string("/etc/OpcUaStack"));

			for ( auto applName : boost::filesystem::directory_iterator(applPath)) {
				// appl name must be a direcory
				if (!boost::filesystem::is_directory(applName.path())) {
					continue;
				}

				// ignore applications from black list
				if (applBlackList.find(applName.path().filename().string()) != applBlackList.end()) {
					continue;
				}

				// the configuration file OpcUaServer.xml must be exist
				boost::filesystem::path serverConfigFileName(
					installPath +
					std::string("/etc/OpcUaStack/") +
					applName.path().filename().string() +
					"/OpcUaServer.xml"
				);
				if (!boost::filesystem::exists(serverConfigFileName)) {
					continue;
				}

				// read server configuration file
				auto config = Config::instance();
				config->alias(
					"@CONF_DIR@", installPath +
					std::string("/etc/OpcUaStack/") +
					applName.path().filename().string()
				);
				ConfigXml configXml;
				if (!configXml.parse(serverConfigFileName.string(), true)) {
					continue;
				}

				// obtain ca/issuer/cert directory
				std::string caDirectoryTrust = config->getValue(
					"OpcUaServer.ApplicationCertificate.Folder.CertificateTrustListLocation", ""
				);
				std::string caDirectoryRevocation = config->getValue(
					"OpcUaServer.ApplicationCertificate.Folder.CertificateRevocationListLocation", ""
				);

				std::string issuerDirectoryTrust = config->getValue(
					"OpcUaServer.ApplicationCertificate.Folder.IssuersCertificatesLocation", ""
				);
				std::string issuerDirectoryRevocation = config->getValue(
					"OpcUaServer.ApplicationCertificate.Folder.IssuersRevocationListLocation", ""
				);

				std::string certDirectoryTrust = config->getValue(
					"OpcUaServer.ApplicationCertificate.Folder.CertificateTrustListLocation", ""
				);
				std::string certDirectoryRevocation = config->getValue(
					"OpcUaServer.ApplicationCertificate.Folder.CertificateRejectListLocation", ""
				);

				std::string applicationCertFile = config->getValue(
					"OpcUaServer.ApplicationCertificate.Files.ApplicationCertificateFile", ""
				);
				std::string privateKeyFile = config->getValue(
					"OpcUaServer.ApplicationCertificate.Files.PrivateKeyFile", ""
				);

				// add new entry to application info map
				auto applicationInfo = boost::make_shared<ApplicationInfo>();
				applicationInfo->applName_ = applName.path().filename().string();
				applicationInfo->installPath_ = installPath;
				applicationInfo->serverConfigFile_ = serverConfigFileName.string();
				applicationInfo->caDirectoryTrust_ = caDirectoryTrust;
				applicationInfo->caDirectoryRevocation_ = caDirectoryRevocation;
				applicationInfo->issuerDirectoryTrust_ = issuerDirectoryTrust;
				applicationInfo->issuerDirectoryRevocation_ = issuerDirectoryRevocation;
				applicationInfo->certDirectoryTrust_ = certDirectoryTrust;
				applicationInfo->certDirectoryRevocation_ = certDirectoryRevocation;
				applicationInfo->applicationCertFile_ = applicationCertFile;
				applicationInfo->privateKeyFile_ = privateKeyFile;

				applicationInfoMap_.insert(std::make_pair(applicationInfo->applName_, applicationInfo));
			}
		}
	}

	void
	Application::addPkiPath(
		const std::set<std::string>& applBlackList,
	    const std::vector<std::string>& installPkiList
	)
	{
		uint32_t idx;

		// check number of elements in install pki list
		if ((installPkiList.size() % 2) != 0 || installPkiList.size() < 2) {
			return;
		}

		// handle entries from install pki list
		for (idx = 0; idx < installPkiList.size(); idx++) {
			std::string applicationName = installPkiList[idx];
			std::string installPkiDir = installPkiList[idx+1];

			// check install pki directory - The install pki directory must be exist
			if (!boost::filesystem::exists(boost::filesystem::path(installPkiDir))) {
				Log(Warning, "install pki directory do not exist")
					.parameter("InstallPkiDirectory", installPkiDir)
					.parameter("ApplicationName", applicationName);
				continue;
			}

			// add new entry to application info map
			auto applicationInfo = boost::make_shared<ApplicationInfo>();
			applicationInfo->applName_ = applicationName;
			applicationInfo->installPath_ = "";
			applicationInfo->serverConfigFile_ = "";

			// set own certificate file. If the certificate file directory do not
			// exist create it.
			boost::filesystem::path ownCertFilePath(installPkiDir + "/own/certs/");
			if (!boost::filesystem::exists(ownCertFilePath)) {
				if (!boost::filesystem::create_directories(ownCertFilePath)) {
					Log(Warning, "create own cert directory error")
						.parameter("OwnCertDirectory", ownCertFilePath.string())
						.parameter("ApplicationName", applicationName);
					continue;
				}
			}
			applicationInfo->applicationCertFile_ = installPkiDir + "/own/certs/" + applicationName + ".der";

			// set own private key file. If the certificate key directory do not
			// exist create it.
			boost::filesystem::path privateKeyPath(installPkiDir + "/own/private/");
			if (!boost::filesystem::exists(privateKeyPath)) {
				if (!boost::filesystem::create_directories(privateKeyPath)) {
					Log(Warning, "create own private key directory error")
						.parameter("OwnCertDirectory", privateKeyPath.string())
						.parameter("ApplicationName", applicationName);
					continue;
				}
			}
			applicationInfo->privateKeyFile_ = installPkiDir + "/own/private/" + applicationName + ".pem";

			// set ca trust directory. If the ca trust directory do not exist
			// create it.
			boost::filesystem::path caTrustPath(installPkiDir + "/trusted/certs");
			if (!boost::filesystem::exists(caTrustPath)) {
				if (!boost::filesystem::create_directories(caTrustPath)) {
					Log(Warning, "create ca trust directory error")
						.parameter("CaTrustDirectory", caTrustPath.string())
						.parameter("ApplicationName", applicationName);
					continue;
				}
			}
			applicationInfo->caDirectoryTrust_ = caTrustPath.string();

			// set ca revocation directory. If the ca revocation directory do
			// not exist create it.
			boost::filesystem::path caRevocationPath(installPkiDir + "/trusted/crl");
			if (!boost::filesystem::exists(caRevocationPath)) {
				if (!boost::filesystem::create_directories(caRevocationPath)) {
					Log(Warning, "create ca revocation directory error")
						.parameter("CaRevocationDirectory", caRevocationPath.string())
						.parameter("ApplicationName", applicationName);
					continue;
				}
			}
			applicationInfo->caDirectoryRevocation_ = caRevocationPath.string();

			// set issuer trust directory. If the issuer trust directory do
			// not exist create it.
			boost::filesystem::path issuerTrustPath(installPkiDir + "/issuers/certs");
			if (!boost::filesystem::exists(issuerTrustPath)) {
				if (!boost::filesystem::create_directories(issuerTrustPath)) {
					Log(Warning, "create issuer trust directory error")
						.parameter("IssuerTrustDirectory", issuerTrustPath.string())
						.parameter("ApplicationName", applicationName);
					continue;
				}
			}
			applicationInfo->issuerDirectoryTrust_ =  issuerTrustPath.string();

			// set issuer revocation directory. If the issuer revocation directory do
			// not exist create it.
			boost::filesystem::path issuerRevocationPath(installPkiDir + "/issuers/crl");
			if (!boost::filesystem::exists(issuerRevocationPath)) {
				if (!boost::filesystem::create_directories(issuerRevocationPath)) {
					Log(Warning, "create issuer revocation directory error")
						.parameter("IssuerRevocationDirectory", issuerRevocationPath.string())
						.parameter("ApplicationName", applicationName);
					continue;
				}
			}
			applicationInfo->issuerDirectoryRevocation_ =  issuerRevocationPath.string();

			// set cert trust directory. If the cert trust directory do
			// not exist create it.
			boost::filesystem::path certTrustPath(installPkiDir + "trusted/certs");
			if (!boost::filesystem::exists(certTrustPath)) {
				if (!boost::filesystem::create_directories(certTrustPath)) {
					Log(Warning, "create cert trust directory error")
						.parameter("CertTrustDirectory", certTrustPath.string())
						.parameter("ApplicationName", applicationName);
					continue;
				}
			}
			applicationInfo->certDirectoryTrust_ =  certTrustPath.string();

			// set cert revocation directory. If the cert revocation directory do
			// not exist create it.
			boost::filesystem::path certRevocationPath(installPkiDir + "reject/certs");
			if (!boost::filesystem::exists(certRevocationPath)) {
				if (!boost::filesystem::create_directories(certRevocationPath)) {
					Log(Warning, "create cert revocation directory error")
						.parameter("CertTrustDirectory", certRevocationPath.string())
						.parameter("ApplicationName", applicationName);
					continue;
				}
			}
			applicationInfo->certDirectoryRevocation_ =  certRevocationPath.string();

			applicationInfoMap_.insert(std::make_pair(applicationInfo->applName_, applicationInfo));

			idx++;
		}
	}

}



