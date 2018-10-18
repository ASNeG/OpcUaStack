/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "BuildConfig.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/Generator/DataTypeGenerator.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"

namespace OpcUaStackServer
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// DataTypeGenerator
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	DataTypeGenerator::DataTypeGenerator(void)
	: informationModel_()
	, sourceContent_("")
	, headerContent_("")

	, nodeInfo_()
	{
	}

	DataTypeGenerator::~DataTypeGenerator(void)
	{
	}

	bool
	DataTypeGenerator::generate(const OpcUaNodeId& dataType)
	{
		// check parameter
		if (informationModel_.get() == nullptr) {
			Log(Error, "invalid parameter - information model is null");
			return false;
		}

		// create node infos
		if (!nodeInfo_.init(dataType, informationModel_)) {
			return false;
		}
		nodeInfo_.log();

		// generate header and source content
		return
			generateHeader() &&
			generateSource();
	}

	void
	DataTypeGenerator::informationModel(InformationModel::SPtr& informationModel)
	{
		informationModel_ = informationModel;
	}

	bool
	DataTypeGenerator::setNamespaceEntry(const std::string& namespaceEntry)
	{
		return nodeInfo_.setNamespaceEntry(namespaceEntry);
	}

	std::string&
	DataTypeGenerator::sourceContent(void)
	{
		return sourceContent_;
	}

	std::string&
	DataTypeGenerator::headerContent(void)
	{
		return headerContent_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// header
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	DataTypeGenerator::generateHeader(void)
	{
		return
			generateHeaderComments() &&
			generateHeaderBegin() &&
				generateHeaderClassBegin("    ") &&
			//		generateHeaderClassValueGetter("        ") &&
			//	    generateHeaderClassExtensionInterface("        ") &&
			//	    generateHeaderClassPublic("        ") &&
			//	    generateHeaderClassPrivate("    ") &&
			//	    generateHeaderClassValueDefinition("        ") &&
				generateHeaderClassEnd("    ") &&
		    generateHeaderEnd();
	}

	bool
	DataTypeGenerator::generateHeaderComments(void)
	{
		std::stringstream ss;

		ss << "/*" << std::endl;
		ss << "    DataTypeClass: " << nodeInfo_.className() << std::endl;
		ss << std::endl;
		ss << "    Generated Source Code - please do not change this source code" << std::endl;
		ss << std::endl;
		ss << "    DataTypeCodeGenerator Version:"  << std::endl;
		ss << "        OpcUaStackCore - " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH << std::endl;
		ss << std::endl;
		ss << "    Autor: Kai Huebl (kai@huebl-sgh.de)" << std::endl;
		ss << "*/" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	bool
	DataTypeGenerator::generateHeaderBegin(void)
	{
		std::stringstream ss;

		//
		// added defines
		//
		ss << std::endl;
		ss << "#ifndef __" << nodeInfo_.namespaceName() << "_" << nodeInfo_.className() << "_h__" << std::endl;
		ss << "#define __" << nodeInfo_.namespaceName() << "_" << nodeInfo_.className() << std::endl;

		//
		// added includes
		//
		ss << std::endl;
		ss << "#include <boost/shared_ptr.hpp>" << std::endl;
		ss << "#include \"OpcUaStackCore/Base/os.h\"" << std::endl;
		ss << "#include \"OpcUaStackCore/Base/ObjectPool.h\"" << std::endl;
		ss << "#include \"OpcUaStackCore/BuildInTypes/BuildInTypes.h\"" << std::endl;

		//
		// added parent includes
		//
		if (!nodeInfo_.parentIsStructureType()) {
			ss << "#include \"" << nodeInfo_.parentNamespaceName() << "/" << nodeInfo_.parentDirectory()<< "/" << nodeInfo_.parentClassName() << ".h\"" << std::endl;
		}

		//
		// added namespace
		//
		ss << std::endl;
		ss << "namespace " << nodeInfo_.namespaceName() << std::endl;
		ss << "{" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	bool
	DataTypeGenerator::generateHeaderEnd(void)
	{
		std::stringstream ss;

		//
		// added namespace
		//
		ss << std::endl;
		ss << "}" << std::endl;

		//
		// added defines
		//
		ss << std::endl;
		ss << "#endif" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	bool
	DataTypeGenerator::generateHeaderClassBegin(const std::string& prefix)
	{
		std::stringstream ss;

		//
		// added class
		//
		ss << prefix << std::endl;
		ss << prefix << "class " << nodeInfo_.className() << std::endl;

		//
		// added base classes
		//
		if (!nodeInfo_.parentIsStructureType()) {
			ss << prefix << ": " << nodeInfo_.parentClassName() << std::endl;
		}
		else {
			ss << prefix << ": public Object" << std::endl;
			ss << prefix << ", public ExtensionObjectBase" << std::endl;
		}


		ss << prefix << "{" << std::endl;
		ss << prefix << "  public:" << std::endl;
		ss << prefix << "    typedef boost::shared_ptr<" << nodeInfo_.className()  << "> SPtr;" << std::endl;
		ss << prefix << std::endl;
		ss << prefix << "    " << nodeInfo_.className() << "(void);" << std::endl;
		ss << prefix << "    virtual ~" << nodeInfo_.className() << "(void);" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	bool
	DataTypeGenerator::generateHeaderClassEnd(const std::string& prefix)
	{
		std::stringstream ss;

		//
		// added class
		//
		ss << prefix << std::endl;
		ss << prefix << "};" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// source
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	DataTypeGenerator::generateSource(void)
	{
		// FIXME: todo
		return true;
	}

}
