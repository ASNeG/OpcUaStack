/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/program_options.hpp>
#include "OpcUaStackCore/Utility/Environment.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackServer/NodeSet/NodeSetXmlParser.h"
#include "OpcUaStackServer/InformationModel/InformationModelNodeSet.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"
#include "OpcUaGenerator/OpcUaVariableTypeGenerator.h"
#include "BuildConfig.h"

namespace OpcUaVariableTypeGenerator
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaVariableTypeGenerator
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaVariableTypeGenerator::OpcUaVariableTypeGenerator(void)
	: variableTypeNodeId_(0)
	, informationModel_()
	, fileName_("")
	, variableTypeName_("")
	, projectNamespace_("")
	, parentProjectNamespace_("")
	, buildSubTypes_(false)
	, variableTypeNameVec_()
	, ignoreVariableTypeNameVec_()
	{
	}

	OpcUaVariableTypeGenerator::~OpcUaVariableTypeGenerator(void)
	{
		// FIXME: todo
	}

	uint32_t
	OpcUaVariableTypeGenerator::start(int argc, char** argv)
	{
		boost::program_options::options_description desc("Allowed options");
		desc.add_options()
		    (
		    	"help",
				"produce help message"
		    )
			(
				"version",
				"print version string"
			)
		    (
		    	"nodeset",
				boost::program_options::value<std::string>(),
				"set nodeset file name (mandatory)"
			)
			(
				"variabletype",
				boost::program_options::value<std::string>(),
				"set variable type name (mandatory)"
			)
			(
				"projectNamespace",
				boost::program_options::value<std::string>()->default_value("OpcUaStackServer"),
			    "set project namespace"
			)
			(
				"parentProjectNamespace",
				boost::program_options::value<std::string>()->default_value("OpcUaStackServer"),
			    "set parent project namespace"
			)
			(
				"buildSubTypes",
				boost::program_options::value<bool>()->default_value(false),
			    "build all subtypes"
			)
			(
				"ignoreVariableTypeName",
				boost::program_options::value< std::vector<std::string> >(),
			    "ignore variable type name"
			)
		;

		boost::program_options::variables_map vm;
		boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
		boost::program_options::notify(vm);

		if (vm.count("help")) {
		    std::cout << desc << std::endl;
		    return 1;
		}

		if (vm.count("version")) {
		    std::cout << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH <<  std::endl;
		    return 1;
		}

		if (vm.count("nodeset") == 0) {
		    std::cout << desc << std::endl;
		    return 1;
		}

		if (vm.count("variabletype") == 0) {
		    std::cout << desc << std::endl;
		    return 1;
		}

		// vm["input-file"].as< vector<string> >()

		fileName_ = vm["nodeset"].as<std::string>();
		variableTypeName_ = vm["variabletype"].as<std::string>();
		projectNamespace_ = vm["projectNamespace"].as<std::string>();
		parentProjectNamespace_ = vm["parentProjectNamespace"].as<std::string>();
		buildSubTypes_ = vm["buildSubTypes"].as<bool>();
		if (vm.count("ignoreEventTypeName") != 0) {
			ignoreVariableTypeNameVec_ = vm["ignoreVariableTypeName"].as< std::vector<std::string> >();
		}

#if 0
		if (buildSubTypes_) {
			return buildAllSubTypes();
		}
#endif

		// ignore BaseEventType
		if (variableTypeName_ == "BaseVariableType") {
			return 1;
		}

		// load inforomation model
		int32_t rc = loadInformationModel();
		if (rc < 0) {
			return rc;
		}

#if 0
		return generateVariableTypeSource();
#endif
		//FIXME: todo
		return 1;
	}

	int32_t
	OpcUaVariableTypeGenerator::loadInformationModel(void)
	{
		// read opc ua nodeset
		ConfigXml configXml;
	    if (!configXml.parse(fileName_)) {
	    	std::cout << configXml.errorMessage() << std::endl;
	    	return -1;
	    }

	    // parse node set file
	    NodeSetXmlParser nodeSetXmlParser;
	    if (!nodeSetXmlParser.decode(configXml.ptree())) {
	    	std::cout << "node set parser error" << std::endl;
	    	return -2;
	    }

	    // init information model
		informationModel_ = constructSPtr<InformationModel>();
		if (!InformationModelNodeSet::initial(informationModel_, nodeSetXmlParser)) {
			std::cout << "init information model error" << std::endl;
			return -3;
		}
		informationModel_->checkForwardReferences();

		return 0;
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
	OpcUaVariableTypeGenerator::OpcUaVariableTypeGenerator projectBuilder;
	return projectBuilder.start(argc, argv);
}


