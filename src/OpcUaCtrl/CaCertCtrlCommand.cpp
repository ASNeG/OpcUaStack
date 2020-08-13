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

#include <iostream>
#include <fstream>
#include "OpcUaStackCore/Certificate/Certificate.h"
#include "OpcUaCtrl/CaCertCtrlCommand.h"

using namespace OpcUaStackCore;

namespace OpcUaCtrl
{


	CaCertCtrlCommand::CaCertCtrlCommand(void)
	: CtrlCommand()
	{
	}

	CaCertCtrlCommand::~CaCertCtrlCommand(void)
	{
	}

	uint32_t
	CaCertCtrlCommand::start(const std::vector<std::string>& commandLine)
	{
		// check command parameter
		if (commandLine[2] == "show") {
			return show(commandLine);
		}
		else if (commandLine[2] == "add") {
			return add(commandLine);
		}
		else if (commandLine[2] == "del") {
			return del(commandLine);
		}
		else if (commandLine[2] == "trust") {
			return trust(commandLine);
		}
		else if (commandLine[2] == "untrust") {
			return untrust(commandLine);
		}
		else {
			usageMessage(std::string("command ") + commandLine[2] + " unknown");
			return 1;
		}
	}

	void
	CaCertCtrlCommand::usage(void)
	{
		std::cout << "    Commands:" << std::endl;
		std::cout << "    show <Application-Name>:" << std::endl;
		std::cout << "        shows all ca certificates" << std::endl;
		std::cout << "    add <Application-Name> <Ca-Cert-File>:" << std::endl;
		std::cout << "        add a new ca certificate" << std::endl;
		std::cout << "    del <Application-Name> <Cert-Id>:" << std::endl;
		std::cout << "        delete a ca certificate" << std::endl;
		std::cout << "        use *all* as certId to delete all ca certs" << std::endl;
		std::cout << "    trust <Application-Name> <Cert-Id>:" << std::endl;
		std::cout << "        activate a ca certificate" << std::endl;
		std::cout << "    untrust <Application-Name> <CertId>:" << std::endl;
		std::cout << "        deactivate a ca certificate" << std::endl;
	}

	void
	CaCertCtrlCommand::usageMessage(const std::string& message)
	{
		std::cout << "usage: " << name_ << " ca_cert <Command> [<Parameter>, ...]" << std::endl;
		std::cout << std::endl;
		std::cout << "ERROR: " << message << std::endl;
		usage();
	}

	uint32_t
	CaCertCtrlCommand::show(const std::vector<std::string>& commandLine)
	{
		// Should be provided information about all existing applications
		if (commandLine.size() == 3) {
			Application application(applBlackList_, installPathList_, installPkiList_);

			for (auto applicationInfo : application) {
				std::vector<std::string> tmpCommandLine(commandLine);
				tmpCommandLine.push_back(applicationInfo.second->applName_);
				auto result = show(tmpCommandLine);
				if (result != 0) return result;
			}

			return 0;
		}

		// check command line parameter
		if (commandLine.size() < 4) {
			usageMessage("parameter invalid");
			return 1;
		}
		std::string applicationName = commandLine[3];

		// get application info
		Application application(applBlackList_, installPathList_, installPkiList_);
		auto it = application.find(applicationName);
		if (it == application.end()) {
			Log(Error, "application name not exist")
				.parameter("ApplicationName", applicationName);
			return 1;
		}
		auto applicationInfo = it->second;

		std::stringstream ss;

		// read all files from ca trust directory
		boost::filesystem::path caDirectoryTrust(applicationInfo->caDirectoryTrust_);
		for ( auto filenameIt : boost::filesystem::directory_iterator(caDirectoryTrust) ) {
			// show only ca certificates
			if (!isCaRootCertificate(filenameIt.path().string())) {
				continue;
			}

			// show certificate info
			showCertificateInfo(ss, filenameIt.path().string(), "Trusted");
		}

		// read all files from ca revocation directory
		boost::filesystem::path caDirectoryRevocation(applicationInfo->caDirectoryRevocation_);
		for ( auto filenameIt : boost::filesystem::directory_iterator(caDirectoryRevocation) ) {
			// show only ca certificates
			if (!isCaRootCertificate(filenameIt.path().string())) {
				continue;
			}

			// show certificate info
			showCertificateInfo(ss, filenameIt.path().string(), "Untrusted");
		}

		if (!ss.str().empty()) {
			std::cout << applicationName << ":" << std::endl;
			std::cout << ss.str();
		}

		return 0;
	}

	bool
	CaCertCtrlCommand::showCertificateInfo(
		std::stringstream& ss,
		const std::string& filename,
		const std::string& status
	)
	{
		// read certificate from file
		Certificate certificate;
		if (!certificate.fromDERFile(filename)) {
			certificate.log(Error, "read certificate in der format error");
			return false;
		}

		// get subject information
		Identity subject;
		if (!certificate.getSubject(subject)) {
			certificate.log(Error, "read certificate subject error");
			return false;
		}

		// get
		CertificateInfo certificateInfo;
		if (!certificate.getInfo(certificateInfo)) {
			certificate.log(Error, "read certificate info error");
			return false;
		}

		// output status
		ss << "    "
			<< certificate.thumbPrint().toHexString()
			<< "/"
			<< status
			<< "/"
			<< certificateInfo.validFrom()
			<< "/"
			<< certificateInfo.validTime()
			<< "/"
			<< subject.commonName()
			<< std::endl;
		return true;
	}

	uint32_t
	CaCertCtrlCommand::add(const std::vector<std::string>& commandLine)
	{
		// check command line parameter
		if (commandLine.size() < 5) {
			usageMessage("parameter invalid");
			return 1;
		}
		std::string applicationName = commandLine[3];
		std::string certificateFile = commandLine[4];

		// get application info
		Application application(applBlackList_, installPathList_, installPkiList_);
		auto it = application.find(applicationName);
		if (it == application.end()) {
			Log(Error, "application name unknown")
				.parameter("ApplicationName", applicationName);
			return 1;
		}
		auto applicationInfo = it->second;

		// read certificate file
		Certificate certificate;
		if (!certificate.fromDERFile(certificateFile)) {
			certificate.log(Error, "read certificate in der format error");
			return 1;
		}

		// check whether it is a ca certificate
		if (!certificate.isCaRoot()) {
			certificate.log(Error, "root ca certificate error");
			return 1;
		}

		// generate path and name for trusted and revocation ca certificate
		auto targetTrustCertificateFile = applicationInfo->caDirectoryTrust_ +
			std::string("/") +
			certificate.thumbPrint().toHexString() +
			std::string(".der");
		auto targetRelocationCertificateFile = applicationInfo->caDirectoryRevocation_ +
			std::string("/") +
			certificate.thumbPrint().toHexString() +
			std::string(".der");

		// check if certificate file already exist in revocation path
		if (boost::filesystem::exists(boost::filesystem::path(targetRelocationCertificateFile))) {
			Log(Error, "ca certificate file already exist - status is untrusted");
			return 1;
		}

		// check if certificate file already exist in trusted path
		if (boost::filesystem::exists(boost::filesystem::path(targetTrustCertificateFile))) {
			Log(Error, "ca certificate file already exist - status is trusted");
			return 1;
		}

		// save certificate in ca trusted folder
		if (!certificate.toDERFile(targetTrustCertificateFile)) {
			certificate.log(Error, "write certificate in der format error");
			Log(Error, "certificate file error")
				.parameter("CertificateFile", targetTrustCertificateFile);
			return 1;
		}

		return 0;
	}

	uint32_t
	CaCertCtrlCommand::del(const std::vector<std::string>& commandLine)
	{
		// check command line parameter
		if (commandLine.size() < 5) {
			usageMessage("parameter invalid");
			return 1;
		}
		std::string applicationName = commandLine[3];
		std::string certificateId = commandLine[4];

		// get application info
		Application application(applBlackList_, installPathList_, installPkiList_);
		auto it = application.find(applicationName);
		if (it == application.end()) {
			Log(Error, "application name unknown")
				.parameter("ApplicationName", applicationName);
			return 1;
		}
		auto applicationInfo = it->second;

		// check whether all certificates should be deleted
		if (certificateId == "all") {

			// find and delete all ca certificates in trusted directory
			for (auto& entry : boost::filesystem::directory_iterator(applicationInfo->caDirectoryTrust_)) {
				// remove only ca root certificates
				if (!isCaRootCertificate(entry.path().string())) {
					continue;
				}

				// delete ca root certificate
				std::vector<std::string> cmdLine = commandLine;
				cmdLine[4] = entry.path().stem().string();
				auto rc = del(cmdLine);
				if (rc != 0) {
					return rc;
				}
			}

			// find and delete all ca certificates in revocation list directory
			for (auto& entry : boost::filesystem::directory_iterator(applicationInfo->caDirectoryRevocation_)) {
				// remove only ca root certificates
				if (!isCaRootCertificate(entry.path().string())) {
					continue;
				}

				// delete ca root certificate
				std::vector<std::string> cmdLine = commandLine;
				cmdLine[4] = entry.path().stem().string();
				auto rc = del(cmdLine);
				if (rc != 0) {
					return rc;
				}
			}

			return 0;
		}

		// generate path and name for trusted and revocation ca certificate file
		boost::filesystem::path targetTrustCertificateFile(
			applicationInfo->caDirectoryTrust_ +
			std::string("/") +
			certificateId +
			std::string(".der")
		);
		boost::filesystem::path targetRelocationCertificateFile(
			applicationInfo->caDirectoryRevocation_ +
			std::string("/") +
			certificateId +
			std::string(".der")
		);

		// check if certificate exist
		if (
			!boost::filesystem::exists(targetTrustCertificateFile) &&
			!boost::filesystem::exists(targetRelocationCertificateFile)
		) {
			Log(Error, "certificate identifier unknown")
				.parameter("ApplicationName", applicationName)
				.parameter("CertId", certificateId);
			return 1;
		}

		// remove certificate
		if (boost::filesystem::exists(targetTrustCertificateFile)) {
			// remove only ca root certificates
			if (!isCaRootCertificate(targetTrustCertificateFile.string())) {
				Log(Error, "certificate is not a ca root certificate")
					.parameter("ApplicationName", applicationName)
					.parameter("CertId", certificateId);
				return 1;
			}

			if (!boost::filesystem::remove(targetTrustCertificateFile)) {
				Log(Error, "remove certificate error")
					.parameter("ApplicationName", applicationName)
					.parameter("CertId", certificateId);
			}
		}
		if (boost::filesystem::exists(targetRelocationCertificateFile)) {
			// remove only ca root certificates
			if (!isCaRootCertificate(targetRelocationCertificateFile.string())) {
				Log(Error, "certificate is not a ca root certificate")
					.parameter("ApplicationName", applicationName)
					.parameter("CertId", certificateId);
				return 1;
			}

			if (!boost::filesystem::remove(targetRelocationCertificateFile)) {
				Log(Error, "remove certificate error")
					.parameter("ApplicationName", applicationName)
					.parameter("CertId", certificateId);
			}
		}

		return 0;
	}

	uint32_t
	CaCertCtrlCommand::trust(const std::vector<std::string>& commandLine)
	{
		// check command line parameter
		if (commandLine.size() < 5) {
			usageMessage("parameter invalid");
			return 1;
		}
		std::string applicationName = commandLine[3];
		std::string certificateId = commandLine[4];

		// get application info
		Application application(applBlackList_, installPathList_, installPkiList_);
		auto it = application.find(applicationName);
		if (it == application.end()) {
			Log(Error, "application name unknown")
				.parameter("ApplicationName", applicationName);
			return 1;
		}
		auto applicationInfo = it->second;

		// generate path and name for trusted and revocation ca certificate file
		boost::filesystem::path targetTrustCertificateFile(
			applicationInfo->caDirectoryTrust_ +
			std::string("/") +
			certificateId +
			std::string(".der")
		);
		boost::filesystem::path targetRelocationCertificateFile(
			applicationInfo->caDirectoryRevocation_ +
			std::string("/") +
			certificateId +
			std::string(".der")
		);

		// check if ca certificate already trusted
		if (boost::filesystem::exists(targetTrustCertificateFile)) {
			return 0;
		}

		// check if ca certificate exist in relocation folder
		if (!boost::filesystem::exists(targetRelocationCertificateFile)) {
			Log(Error, "certificate identifier unknown")
				.parameter("ApplicationName", applicationName)
				.parameter("CertId", certificateId);
		}

		// certificate must be a ca root certificate
		if (!isCaRootCertificate(targetRelocationCertificateFile.string())) {
			Log(Error, "certificate is not a ca root certificate")
				.parameter("ApplicationName", applicationName)
				.parameter("CertId", certificateId);
			return 1;
		}

		// trust ca certificate
		boost::system::error_code ec;
		boost::filesystem::rename(targetRelocationCertificateFile, targetTrustCertificateFile, ec);
		if (ec != boost::system::errc::success) {
			Log(Error, "certificate trust error")
				.parameter("ApplicationName", applicationName)
				.parameter("CertId", certificateId);
		}

		return 0;
	}


	uint32_t
	CaCertCtrlCommand::untrust(const std::vector<std::string>& commandLine)
	{
		// check command line parameter
		if (commandLine.size() < 5) {
			usageMessage("parameter invalid");
			return 1;
		}
		std::string applicationName = commandLine[3];
		std::string certificateId = commandLine[4];

		// get application info
		Application application(applBlackList_, installPathList_, installPkiList_);
		auto it = application.find(applicationName);
		if (it == application.end()) {
			Log(Error, "application name unknown")
				.parameter("ApplicationName", applicationName);
			return 1;
		}
		auto applicationInfo = it->second;

		// generate path and name for trusted and revocation ca certificate file
		boost::filesystem::path targetTrustCertificateFile(
			applicationInfo->caDirectoryTrust_ +
			std::string("/") +
			certificateId +
			std::string(".der")
		);
		boost::filesystem::path targetRelocationCertificateFile(
			applicationInfo->caDirectoryRevocation_ +
			std::string("/") +
			certificateId +
			std::string(".der")
		);

		// check if ca certificate already untrusted
		if (boost::filesystem::exists(targetRelocationCertificateFile)) {
			return 0;
		}

		// check if ca certificate exist in trusted folder
		if (!boost::filesystem::exists(targetTrustCertificateFile)) {
			Log(Error, "certificate identifier unknown")
				.parameter("ApplicationName", applicationName)
				.parameter("CertId", certificateId);
		}

		// certificate must be a ca root certificate
		if (!isCaRootCertificate(targetTrustCertificateFile.string())) {
			Log(Error, "certificate is not a ca root certificate")
				.parameter("ApplicationName", applicationName)
				.parameter("CertId", certificateId);
			return 1;
		}

		// untrust ca certificate
		boost::system::error_code ec;
		boost::filesystem::rename(targetTrustCertificateFile, targetRelocationCertificateFile, ec);
		if (ec != boost::system::errc::success) {
			Log(Error, "certificate trust error")
				.parameter("ApplicationName", applicationName)
				.parameter("CertId", certificateId);
		}

		return 0;
	}

	bool
	CaCertCtrlCommand::isCaRootCertificate(const std::string& certFileName)
	{
		// read certificate from file
		Certificate certificate;
		if (!certificate.fromDERFile(certFileName)) {
			certificate.log(Error, "read certificate in der format error");
			return false;
		}

		// check whether it is a root ca certificate
		if (!certificate.isCaRoot()) {
			return false;
		}

		return true;
	}

}



