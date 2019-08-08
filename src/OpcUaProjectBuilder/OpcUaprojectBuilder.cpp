/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/filesystem/fstream.hpp>
#include <boost/regex.hpp>
#include <iostream>
#include <sstream>
#include "OpcUaStackCore/Utility/Environment.h"
#include "OpcUaProjectBuilderConfig.h"
#include "OpcUaProjectBuilder/OpcUaProjectBuilder.h"

using namespace OpcUaStackCore;

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
	: noSubstitueExtensions_({ ".ico" })
	{
	}

	OpcUaProjectBuilder::~OpcUaProjectBuilder(void)
	{
	}

	uint32_t
	OpcUaProjectBuilder::start(int argc, char** argv)
	{
		// check command line arguments
		if (argc != 4 && argc != 5) {
			usage();
			return 1;
		}
		projectName_ = argv[1];
		projectDescription_ = argv[2];
		projectPort_ = argv[3];
		if (argc == 4) verbose_ = false;
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
			"OpcUaProjectBuilder <Project-Name> <Project-Description> <Project-Port> [verbose]\n"
			"\n"
			"<Project-Name>\n"
			"  name of the new project\n"
			"<Project-Description>\n"
			"  short description of the new project\n"
			"<Project-Port>\n"
			"  project port of the opc ua server\n"
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
		boost::filesystem::path application =  Environment::getApplicationPathAbsolute();
		boost::filesystem::path applicationPath = application.parent_path();
		boost::filesystem::path installPath = applicationPath / "../../";

		// set template directory
		templateDirectory_ /= installPath;
		templateDirectory_ /= "/usr/share/OpcUaStack" + std::string(VERSION_MAJOR) + "/ProjectTemplate";

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
		if (verbose_) {
			std::cout << "create project directory: " << projectDirectory << std::endl;
		}

		if (boost::filesystem::create_directory(projectDirectory)) return true;

		if (verbose_)  {
			std::cout << "create project directory " << projectDirectory << "failed" << std::endl;
		}

		return false;
	}

	bool
	OpcUaProjectBuilder::createProjectFile(boost::filesystem::path& filename, const std::string& content)
	{
		if (verbose_) {
			std::cout << "create template file: " << filename << std::endl;
		}

		boost::filesystem::ofstream out;
		out.open(filename.string(), std::ios::out);

		if (!out) {
			if (verbose_)  {
				std::cout << "writing file " << filename << "failed" << std::endl;
			}
			return false;
		}

		out << content;

		out.close();

		return true;
	}

	bool
	OpcUaProjectBuilder::readProjectFile(boost::filesystem::path& filename, std::string& content)
	{
		if (verbose_) {
			std::cout << "read template file: " << filename << std::endl;
		}

		boost::filesystem::ifstream in;
		in.open(filename.string(), std::ios::in);

		if (!in) {
			if (verbose_)  {
				std::cout << "reading file " << filename << "failed" << std::endl;
			}
			return false;
		}

		std::stringstream ss;
		ss << in.rdbuf();
		content = ss.str();

		in.close();
		return true;
	}

	std::string
	OpcUaProjectBuilder::substituteString(const std::string& string)
	{
		std::string result;
		boost::regex regProjectName("ProjectName");
		boost::regex regProjectDescription("ProjectDescription");
		boost::regex regProjectPort("ProjectPort");
		boost::regex regDockerTag("DockerTag");
		boost::regex regVersionMajor("VersionMajor");
		boost::regex regVersionMinor("VersionMinor");
		boost::regex regVersionPatch("VersionPatch");

		result = boost::regex_replace(string, regProjectName, projectName_);
		result = boost::regex_replace(result, regProjectDescription, projectDescription_);
		result = boost::regex_replace(result, regProjectPort, projectPort_);
		result = boost::regex_replace(result, regDockerTag, DOCKER_TAG);
		result = boost::regex_replace(result, regVersionMajor, VERSION_MAJOR);
		result = boost::regex_replace(result, regVersionMinor, VERSION_MINOR);
		result = boost::regex_replace(result, regVersionPatch, VERSION_PATCH);

		return result;
	}

	bool
	OpcUaProjectBuilder::browseProjectDirectory(boost::filesystem::path& templatePath, boost::filesystem::path& projectPath)
	{
		boost::filesystem::directory_iterator itEnd;
		for (boost::filesystem::directory_iterator it(templatePath); it != itEnd; it++) {

			boost::filesystem::path file = *it;

			std::string leaf = file.leaf().string();
			leaf = substituteString(leaf);

			templatePath /= file.leaf();
			projectPath /= leaf;

			if (boost::filesystem::is_directory(templatePath)) {
				// create directory
				if (!createProjectDirectory(projectPath)) return false;

				// create sub tree
				if (!browseProjectDirectory(templatePath, projectPath)) return false;
			}
			else {

				// read and substituate file content
                if (isFileToSubstitute(templatePath)) {
                    std::string content;

                    // read project file
                    if (!readProjectFile(templatePath, content)) return false;

                    content = substituteString(content);
                    // create project file
                    if (!createProjectFile(projectPath, content)) return false;
                }
                else {
                    boost::filesystem::copy_file(templatePath, projectPath, boost::filesystem::copy_option::overwrite_if_exists);
                }					
			}

			templatePath.remove_leaf();
			projectPath.remove_leaf();
		}
		return true;
	}

    bool 
    OpcUaProjectBuilder::isFileToSubstitute(const boost::filesystem::path& file) const
    {        
        return noSubstitueExtensions_.find(boost::filesystem::extension(file)) == noSubstitueExtensions_.end();
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



