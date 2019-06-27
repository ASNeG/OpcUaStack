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

#include <OpcUaStackServer/Generator/ObjectTypeGenerator.h>
#include "BuildConfig.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"

namespace OpcUaStackServer
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ObjectTypeGenerator
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ObjectTypeGenerator::ObjectTypeGenerator(void)
	{
	}

	ObjectTypeGenerator::~ObjectTypeGenerator(void)
	{
	}

	bool
	ObjectTypeGenerator::generate(void)
	{
		return true;
	}

	void
	ObjectTypeGenerator::informationModel(InformationModel::SPtr& informationModel)
	{
		informationModel_ = informationModel;
	}

	void
	ObjectTypeGenerator::objectType(OpcUaNodeId& objectTypeNodeId)
	{
		objectTypeNodeId_ = objectTypeNodeId;
	}

	std::string&
	ObjectTypeGenerator::sourceContent(void)
	{
		return sourceContent_;
	}

	std::string&
	ObjectTypeGenerator::headerContent(void)
	{
		return headerContent_;
	}

}
