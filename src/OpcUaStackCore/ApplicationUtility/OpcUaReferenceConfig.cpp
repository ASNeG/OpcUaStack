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


#include <boost/algorithm/string.hpp>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/ApplicationUtility/OpcUaReferenceConfig.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaCallReferenceConfig
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaCallReferenceConfig::OpcUaCallReferenceConfig(void)
	: Object()
	, configFileName_("")
	, elementPrefix_("")
	, objectNodeId_("")
	{
	}

	OpcUaCallReferenceConfig::~OpcUaCallReferenceConfig(void)
	{
	}

	void
	OpcUaCallReferenceConfig::configFileName(const std::string& configFileName)
	{
		configFileName_ = configFileName;
	}

	void
	OpcUaCallReferenceConfig::elementPrefix(const std::string& elementPrefix)
	{
		elementPrefix_ = elementPrefix;
	}

	OpcUaNodeId&
	OpcUaCallReferenceConfig::objectNodeId(void)
	{
		return objectNodeId_;
	}

	bool
	OpcUaCallReferenceConfig::decode(Config& config)
	{
		// get ObjectNodeId attribute
		std::string objectNodeId;
		if (!config.getConfigParameter("<xmlattr>.ObjectNodeId", objectNodeId)) {
			Log(Error, "attribute missing in config file")
				.parameter("Element", elementPrefix_)
				.parameter("Attribute", "ObjectNodeId")
				.parameter("ConfigFileName", configFileName_);
			return false;
		}
		if (!objectNodeId_.fromString(objectNodeId)) {
			Log(Error, "attribute invalid in config file")
				.parameter("Element", elementPrefix_)
				.parameter("Attribute", "ObjectNodeId")
				.parameter("ConfigFileName", configFileName_);
			return false;
		}

		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaMonReferenceConfig
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaMonReferenceConfig::OpcUaMonReferenceConfig(void)
	: Object()
	, configFileName_("")
	, elementPrefix_("")
	, handle_("")
	{
	}

	OpcUaMonReferenceConfig::~OpcUaMonReferenceConfig(void)
	{
	}

	void
	OpcUaMonReferenceConfig::configFileName(const std::string& configFileName)
	{
		configFileName_ = configFileName;
	}

	void
	OpcUaMonReferenceConfig::elementPrefix(const std::string& elementPrefix)
	{
		elementPrefix_ = elementPrefix;
	}

	std::string&
	OpcUaMonReferenceConfig::handle(void)
	{
		return handle_;
	}

	bool
	OpcUaMonReferenceConfig::decode(Config& config)
	{
		// get Handle attribute
		if (!config.getConfigParameter("<xmlattr>.Handle", handle_)) {
			Log(Error, "attribute missing in config file")
				.parameter("Element", elementPrefix_)
				.parameter("Attribute", "Handle")
				.parameter("ConfigFileName", configFileName_);
			return false;
		}

		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaReferenceConfig
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaReferenceConfig::OpcUaReferenceConfig(void)
	: configFileName_("")
	, elementPrefix_("")
	, nodeId_()
	, service_(None)
	, extension_()
	{
	}

	OpcUaReferenceConfig::~OpcUaReferenceConfig(void)
	{
	}

	void
	OpcUaReferenceConfig::configFileName(const std::string& configFileName)
	{
		configFileName_ = configFileName;
	}

	void
	OpcUaReferenceConfig::elementPrefix(const std::string& elementPrefix)
	{
		elementPrefix_ = elementPrefix;
	}

	OpcUaNodeId&
	OpcUaReferenceConfig::nodeId(void)
	{
		return nodeId_;
	}

	OpcUaReferenceConfig::Service
	OpcUaReferenceConfig::service(void)
	{
		return service_;
	}

	Object::SPtr&
	OpcUaReferenceConfig::extension(void)
	{
		return extension_;
	}

	bool
	OpcUaReferenceConfig::decode(Config& config)
	{
		// get Service attribute
		std::string service;
		if (!config.getConfigParameter("<xmlattr>.Service", service)) {
			Log(Error, "attribute missing in config file")
				.parameter("Element", elementPrefix_)
				.parameter("Attribute", "Service")
				.parameter("ConfigFileName", configFileName_);
			return false;
		}
		boost::to_upper(service);
		if (service == "READ") service_ = Read;
		else if (service == "WRITE") service_ = Write;
		else if (service == "HREAD") service_ = HRead;
		else if (service == "HWRITE") service_ = HWrite;
		else if (service == "MON") service_ = Mon;
		else if (service == "CALL") service_ = Call;
		else {
			Log(Error, "attribute error in config file")
				.parameter("Element", elementPrefix_)
				.parameter("Attribute", "Service")
				.parameter("Value", service)
				.parameter("ConfigFileName", configFileName_);
			return false;
		}

		// get NodeId attribute
		std::string nodeIdStr;
		if (!config.getConfigParameter("<xmlattr>.NodeId", nodeIdStr)) {
			Log(Error, "attribute missing in config file")
				.parameter("Element", elementPrefix_)
				.parameter("Attribute", "NodeId")
				.parameter("ConfigFileName", configFileName_);
			return false;
		}
		if (!nodeId_.fromString(nodeIdStr)) {
			Log(Error, "attribute error in config file")
				.parameter("Element", elementPrefix_)
				.parameter("Attribute", "NodeId")
				.parameter("Value", service)
				.parameter("ConfigFileName", configFileName_);
			return false;
		}

		// add monitored item extension
		if (service_ == Mon) {
			OpcUaMonReferenceConfig::SPtr mon = boost::make_shared<OpcUaMonReferenceConfig>();
			mon->configFileName(configFileName_);
			mon->elementPrefix(elementPrefix_);
			extension_ = mon;
			return mon->decode(config);
		}

		// add call item extension
		if (service_ == Call) {
			OpcUaCallReferenceConfig::SPtr call = boost::make_shared<OpcUaCallReferenceConfig>();
			call->configFileName(configFileName_);
			call->elementPrefix(elementPrefix_);
			extension_ = call;
			return call->decode(config);
		}

		return true;
	}

}
