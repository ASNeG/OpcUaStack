/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaProjectBuilder_OpcUaProjectBuilder_h__
#define __OpcUaProjectBuilder_OpcUaProjectBuilder_h__

#include <boost/filesystem.hpp>
#include <set>
#include <stdint.h>

namespace OpcUaProjectBuilder
{

	/**
	 * The class implements the building an user application template
	 *
	 * It takes the project name, the project description and the port as command line arguments and
	 * substitute them to the user application template
	 */
	class DLLEXPORT OpcUaProjectBuilder
	{
	  public:
		OpcUaProjectBuilder(void);
		~OpcUaProjectBuilder(void);

		/**
		 * entry point
		 * @param[in] number of command line arguments
		 * @param[in] command line arguments
		 * @return 0 if no errors happen else 1
		 */
		uint32_t start(int argc, char** argv);

	  private:
		void usage(void);
		bool createProject(void);
		bool createProjectInfo(void);
		bool createProjectDirectory(void);
		bool createProjectDirectory(boost::filesystem::path& projectDirectory);
		bool createProjectFile(boost::filesystem::path& filename, const std::string& content);
		bool readProjectFile(boost::filesystem::path& filename, std::string& content);
		bool browseProjectDirectory(boost::filesystem::path& templateDirectory, boost::filesystem::path& projectDirectory);
		std::string substituteString(const std::string& string);
        bool isFileToSubstitute(const boost::filesystem::path& file) const;

		// command line parameter
		std::string projectName_;
		std::string projectDescription_;
		std::string projectPort_;
		bool verbose_;

		boost::filesystem::path templateDirectory_;
		boost::filesystem::path projectDirectory_;

        const std::set<std::string> noSubstitueExtensions_;
	};

}

#endif
