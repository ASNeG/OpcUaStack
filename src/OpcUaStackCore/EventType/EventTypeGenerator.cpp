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

#include "OpcUaStackCore/EventType/EventTypeGenerator.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	EventTypeGenerator::EventTypeGenerator(void)
	: sourceContent_("")
	, headerContent_("")
	{
	}

	EventTypeGenerator::~EventTypeGenerator(void)
	{
	}

	bool
	EventTypeGenerator::generate(void)
	{
		return false;
	}

	void
	EventTypeGenerator::eventType(OpcUaNodeId& eventType)
	{
		eventType_ = eventType;
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
		return false;
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
		return false;
	}

}
