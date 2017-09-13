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

#include "BuildConfig.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/EventType/EventTypeGenerator.h"

namespace OpcUaStackServer
{

	EventTypeGenerator::EventTypeGenerator(void)
	: sourceContent_("")
	, headerContent_("")
	, eventTypeNodeId_()
	, eventTypeName_("")
	, informationModel_(nullptr)
	, eventTypeNode_()
	{
	}

	EventTypeGenerator::~EventTypeGenerator(void)
	{
	}

	bool
	EventTypeGenerator::generate(void)
	{
		// check information model
		if (informationModel_ == nullptr) {
			Log(Error, "information model is empty");
			return false;
		}

		// find event node
		eventTypeNode_ = informationModel_->find(eventTypeNodeId_);
		if (!eventTypeNode_) {
			Log(Error, "event type do not not exist in information model")
				.parameter("EventType", eventTypeNodeId_);
			return false;
		}

		// get event name
		OpcUaQualifiedName browseName;
		if (!eventTypeNode_->getBrowseName(browseName)) {
			Log(Error, "event name not found in node")
				.parameter("EventType", eventTypeNodeId_);
			return false;
		}
		eventTypeName_ = browseName.name().toStdString();

		// generate source file and header file
		return generateSource() && generateHeader();
	}

	void
	EventTypeGenerator::informationModel(InformationModel& informationModel)
	{
		informationModel_ = &informationModel;
	}

	void
	EventTypeGenerator::eventType(OpcUaNodeId& eventType)
	{
		eventTypeNodeId_ = eventType;
	}

	std::string&
	EventTypeGenerator::sourceContent(void)
	{
		return sourceContent_;
	}

	std::string&
	EventTypeGenerator::headerContent(void)
	{
		return headerContent_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// header functions
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	EventTypeGenerator::generateHeader(void)
	{
		return generateHeaderComments();
	}

	bool
	EventTypeGenerator::generateHeaderComments(void)
	{
		std::stringstream ss;

		ss << "/*" << std::endl;
		ss << "    EventTypeClass: " << eventTypeName_ << std::endl;
		ss << std::endl;
		ss << "    Generated Source Code - please do not change this source code" << std::endl;
		ss << std::endl;
		ss << "    EventTypeCodeGenerator Version:"  << std::endl;
		ss << "        OpcUaStackCore - " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH << std::endl;
		ss << std::endl;
		ss << "    Autor: Kai Huebl (kai@huebl-sgh.de)" << std::endl;
		ss << "*/" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// source functions
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	EventTypeGenerator::generateSource(void)
	{
		return generateSourceComments();
	}

	bool
	EventTypeGenerator::generateSourceComments(void)
	{
		std::stringstream ss;

		ss << "/*" << std::endl;
		ss << "    EventTypeClass: " << eventTypeName_ << std::endl;
		ss << std::endl;
		ss << "    Generated Source Code - please do not change this source code" << std::endl;
		ss << std::endl;
		ss << "    EventTypeCodeGenerator Version:" << std::endl;
		ss << "        OpcUaStackCore - " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH  << std::endl;
		ss << std::endl;
		ss << "    Autor: Kai Huebl (kai@huebl-sgh.de)" << std::endl;
		ss << "*/" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

}
