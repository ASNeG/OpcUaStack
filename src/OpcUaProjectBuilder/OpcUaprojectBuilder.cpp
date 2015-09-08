/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#include <iostream>
#include "OpcUaProjectBuilderConfig.h"
#include "OpcUaProjectBuilder/OpcUaProjectBuilder.h"

namespace OpcUaProjectBuilder
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaProjectBuilder
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaProjectBuilder::OpcUaProjectBuilder(void)
	{
	}

	OpcUaProjectBuilder::~OpcUaProjectBuilder(void)
	{
	}

	uint32_t
	OpcUaProjectBuilder::start(int argc, char** argv)
	{
		// check command line arguments
		if (argc != 3 && argc != 4) {
			usage();
			return 1;
		}
		projectName_ = argv[1];
		projectDescription_ = argv[2];
		if (argc == 3) verbose_ = false;
		else verbose_ = true;

		if (!createProject()) {
			if (verbose_) std::cout << "failed" << std::endl;
			return 1;
		}
		if (verbose_) std::cout << "success" << std::endl;
		return 0;
	}

	void
	OpcUaProjectBuilder::usage(void)
	{
		std::cout <<
			"OpcUaProjectBuilder <Project-Name> <Project-Description> [verbose]\n"
			"\n"
			"<Project-Name>\n"
			"  name of the new project\n"
			"<Project-Description>\n"
			"  short description of the new project\n"
			"\n";
	}

	bool
	OpcUaProjectBuilder::createProject(void)
	{
		if (!createProjectInfo()) return false;
		if (!createProjectDirectory()) return false;
		if (!browseProjectDirectory(templateDirectory_, projectDirectory_)) return false;
		return true;
	}

	bool
	OpcUaProjectBuilder::createProjectInfo(void)
	{
		// set template directory
		templateDirectory_ /= INSTALL_DIR;
		templateDirectory_ /= "/usr/share/OpcUaStack/ProjectTemplate";

		// set project directory
		projectDirectory_ /= boost::filesystem::current_path();
		projectDirectory_ /= projectName_;

		if (verbose_) {
			std::cout
				<< "TemplateDirectory: " << templateDirectory_ << std::endl
				<< "ProjectDirectory: " << projectDirectory_ << std::endl
				<< std::endl;
		}

		return true;
	}

	bool
	OpcUaProjectBuilder::createProjectDirectory(void)
	{
		if (boost::filesystem::exists(projectDirectory_)) {
			if (verbose_) {
				std::cout << "cannot create project directory, because project directory " << projectDirectory_ << " already exist" << std::endl;
				return false;
			}
		}

		if (!boost::filesystem::create_directory(projectDirectory_)) {
			if (verbose_)  {
				std::cout << "create project directory " << projectDirectory_ << "failed" << std::endl;
				return false;
			}
		}

		return true;
	}

	bool
	OpcUaProjectBuilder::createProjectDirectory(boost::filesystem::path& projectDirectory)
	{
		return true;
	}

	bool
	OpcUaProjectBuilder::createProjectFile(boost::filesystem::path& filename, const std::string& content)
	{
		return true;
	}

	bool
	OpcUaProjectBuilder::readProjectFile(boost::filesystem::path& filename, std::string& content)
	{
		return false;
	}

	bool
	OpcUaProjectBuilder::browseProjectDirectory(boost::filesystem::path& templateDirectory, boost::filesystem::path& projectDirectory)
	{
		boost::filesystem::directory_iterator itEnd;
		for (boost::filesystem::directory_iterator it(templateDirectory); it != itEnd; it++) {
			boost::filesystem::path newTemplateDirectory = templateDirectory;
			boost::filesystem::path newProjectDirectory = projectDirectory;

			boost::filesystem::path file = *it;
			templateDirectory /= file;
			projectDirectory /= file;

			if (boost::filesystem::is_directory(templateDirectory)) {
				if (!browseProjectDirectory(newTemplateDirectory, newProjectDirectory)) return false;
			}
			else {
				std::cout << *it << std::endl;
			}
		}
		return true;
	}

}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//
// main application
//
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
int main(int argc, char** argv)
{
	OpcUaProjectBuilder::OpcUaProjectBuilder projectBuilder;
	return projectBuilder.start(argc, argv);
}


