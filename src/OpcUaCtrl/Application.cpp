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
#include "OpcUaCtrl/Application.h"

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
	    std::set<std::string>& applBlackList,
		std::vector<std::string>& installPathList
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

				// add new entry to application info map
				auto applicationInfo = boost::make_shared<ApplicationInfo>();
				applicationInfo->applName_ = applName.path().filename().string();
				applicationInfo->installPath_ = installPath;
				applicationInfoMap_.insert(std::make_pair(applicationInfo->applName_, applicationInfo));
			}
		}
	}

	Application::~Application(void)
	{
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

}



