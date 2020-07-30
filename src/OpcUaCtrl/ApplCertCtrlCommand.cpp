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
#include "OpcUaCtrl/ApplCertCtrlCommand.h"

using namespace OpcUaStackCore;

namespace OpcUaCtrl
{


	ApplCertCtrlCommand::ApplCertCtrlCommand(void)
	: CtrlCommand()
	{
	}

	ApplCertCtrlCommand::~ApplCertCtrlCommand(void)
	{
	}

	uint32_t
	ApplCertCtrlCommand::start(const std::vector<std::string>& commandLine)
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
		else if (commandLine[2] == "get") {
			return get(commandLine);
		}
		else {
			usageMessage(std::string("command ") + commandLine[2] + " unknown");
			return 1;
		}
	}

	void
	ApplCertCtrlCommand::usage(void)
	{
		std::cout << "    Commands:" << std::endl;
		std::cout << "    show <Application-Name>:" << std::endl;
		std::cout << "        shows application certificate" << std::endl;
		std::cout << "    get <Application-Name> <Appl-Cert-File> <Private-Key-File>:" << std::endl;
		std::cout << "        export existing application certificate and private key" << std::endl;
		std::cout << "    add <Application-Name> <Appl-Cert-File> <Private-Key-File>:" << std::endl;
		std::cout << "        add a new application certificate and private key" << std::endl;
		std::cout << "    del <Application-Name>:" << std::endl;
		std::cout << "        delete application certificate and private key" << std::endl;
	}

	void
	ApplCertCtrlCommand::usageMessage(const std::string& message)
	{
		std::cout << "usage: " << name_ << " appl_cert <Command> [<Parameter>, ...]" << std::endl;
		std::cout << std::endl;
		std::cout << "ERROR: " << message << std::endl;
		usage();
	}

	uint32_t
	ApplCertCtrlCommand::show(const std::vector<std::string>& commandLine)
	{
		// Should be provided information about all existing applications
		if (commandLine.size() == 3) {
			Application application(applBlackList_, installPathList_);

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
		Application application(applBlackList_, installPathList_);
		auto it = application.find(applicationName);
		if (it == application.end()) {
			Log(Error, "application name not exist")
				.parameter("ApplicationName", applicationName);
			return 1;
		}
		auto applicationInfo = it->second;

		std::stringstream ss;

		// show application certificate info
		boost::filesystem::path applCertFile(applicationInfo->applicationCertFile_);
		if (boost::filesystem::exists(applCertFile)) {
			showCertificateInfo(ss, applCertFile.string(), "Trusted");
		}

		if (!ss.str().empty()) {
			std::cout << applicationName << ":" << std::endl;
			std::cout << ss.str();
		}

		return 0;
	}

	bool
	ApplCertCtrlCommand::showCertificateInfo(
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

		// check whether it is a ca certificate
		if (!certificate.isApplCertificate()) {
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
	ApplCertCtrlCommand::get(const std::vector<std::string>& commandLine)
	{
		// check command line parameter
		if (commandLine.size() < 6) {
			usageMessage("parameter invalid");
			return 1;
		}
		std::string applicationName = commandLine[3];
		std::string certificateFile = commandLine[4];
		std::string privateKeyFile = commandLine[5];

		// get application info
		Application application(applBlackList_, installPathList_);
		auto it = application.find(applicationName);
		if (it == application.end()) {
			Log(Error, "application name unknown")
				.parameter("ApplicationName", applicationName);
			return 1;
		}
		auto applicationInfo = it->second;

		// check if certificate file exist
		if (!boost::filesystem::exists(boost::filesystem::path(applicationInfo->applicationCertFile_))) {
			Log(Error, "application certificate file do not exist");
			return 1;
		}

		// check if private key file exist
		if (!boost::filesystem::exists(boost::filesystem::path(applicationInfo->privateKeyFile_))) {
			Log(Error, "private key file do not exist");
			return 1;
		}

		// read certificate file
		Certificate certificate;
		if (!certificate.fromDERFile(applicationInfo->applicationCertFile_)) {
			certificate.log(Error, "read certificate in der format error");
			return 1;
		}

		// read private key file
		PrivateKey privateKey;
		if (!privateKey.fromPEMFile(applicationInfo->privateKeyFile_, nullptr, nullptr, nullptr)) {
			certificate.log(Error, "read private key in pem format error");
			return 1;
		}

		// save application certificate
		if (!certificate.toDERFile(certificateFile)) {
			certificate.log(Error, "write application certificate in der format error");
			Log(Error, "application certificate file error")
				.parameter("ApplCertificateFile", certificateFile);
			return 1;
		}

		// save private key
		if (!privateKey.toPEMFile(privateKeyFile, nullptr)) {
			certificate.log(Error, "write private key in pem format error");
			Log(Error, "private key file error")
				.parameter("PrivateKeyFile", privateKeyFile);
			return 1;
		}

		return true;
	}

	uint32_t
	ApplCertCtrlCommand::add(const std::vector<std::string>& commandLine)
	{
		// check command line parameter
		if (commandLine.size() < 6) {
			usageMessage("parameter invalid");
			return 1;
		}
		std::string applicationName = commandLine[3];
		std::string certificateFile = commandLine[4];
		std::string privateKeyFile = commandLine[5];

		// get application info
		Application application(applBlackList_, installPathList_);
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

		// check whether it is a application certificate
		if (!certificate.isApplCertificate()) {
			certificate.log(Error, "application certificate error");
			return 1;
		}

		// read private key file
		PrivateKey privateKey;
		if (!privateKey.fromPEMFile(privateKeyFile, nullptr, nullptr, nullptr)) {
			certificate.log(Error, "read private key in pem format error");
			return 1;
		}

		// check if application certificate already exist
		if (boost::filesystem::exists(boost::filesystem::path(applicationInfo->applicationCertFile_))) {
			certificate.log(Error, "application certificate file already exist");
			return 1;
		}

		// check if private key file already exist
		if (boost::filesystem::exists(boost::filesystem::path(applicationInfo->privateKeyFile_))) {
			certificate.log(Error, "private key file already exist");
			return 1;
		}

		// save application certificate
		if (!certificate.toDERFile(applicationInfo->applicationCertFile_)) {
			certificate.log(Error, "write application certificate in der format error");
			Log(Error, "application certificate file error")
				.parameter("ApplCertificateFile", applicationInfo->applicationCertFile_);
			return 1;
		}

		// save private key
		if (!privateKey.toPEMFile(applicationInfo->privateKeyFile_, nullptr)) {
			certificate.log(Error, "write private key in pem format error");
			Log(Error, "private key file error")
				.parameter("PrivateKeyFile", applicationInfo->privateKeyFile_);
			return 1;
		}

		return 0;
	}

	uint32_t
	ApplCertCtrlCommand::del(const std::vector<std::string>& commandLine)
	{
		// check command line parameter
		if (commandLine.size() < 4) {
			usageMessage("parameter invalid");
			return 1;
		}
		std::string applicationName = commandLine[3];

		// get application info
		Application application(applBlackList_, installPathList_);
		auto it = application.find(applicationName);
		if (it == application.end()) {
			Log(Error, "application name unknown")
				.parameter("ApplicationName", applicationName);
			return 1;
		}
		auto applicationInfo = it->second;

		// remove application certificate
		boost::filesystem::path applicationCertFile(applicationInfo->applicationCertFile_);
		boost::filesystem::remove(applicationCertFile);

		// remove private key
		boost::filesystem::path privateKeyFile(applicationInfo->privateKeyFile_);
		boost::filesystem::remove(privateKeyFile);

		return 0;
	}

}



