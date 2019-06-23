/*
   Copyright 2017-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_OpcUaReferenceConfig_h__
#define __OpcUaStackCore_OpcUaReferenceConfig_h__

#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaCallReferenceConfig
	: public Object
	{
	  public:
		typedef boost::shared_ptr<OpcUaCallReferenceConfig> SPtr;

		OpcUaCallReferenceConfig(void);
		~OpcUaCallReferenceConfig(void);

		void configFileName(const std::string& configFileName);
		void elementPrefix(const std::string& elementPrefix);
		OpcUaNodeId& objectNodeId(void);

		bool decode(Config& config);

	  private:
		std::string configFileName_;
		std::string elementPrefix_;
		OpcUaNodeId objectNodeId_;
	};


	class DLLEXPORT OpcUaMonReferenceConfig
	: public Object
	{
	  public:
		typedef boost::shared_ptr<OpcUaMonReferenceConfig> SPtr;

		OpcUaMonReferenceConfig(void);
		~OpcUaMonReferenceConfig(void);

		void configFileName(const std::string& configFileName);
		void elementPrefix(const std::string& elementPrefix);
		std::string& handle(void);

		bool decode(Config& config);

	  private:
		std::string configFileName_;
		std::string elementPrefix_;
		std::string handle_;
	};


	class DLLEXPORT OpcUaReferenceConfig
	{
	  public:
		typedef boost::shared_ptr<OpcUaReferenceConfig> SPtr;
		typedef std::vector<OpcUaReferenceConfig::SPtr> Vec;
		typedef enum
		{
			None,
			Read,
			Write,
			Mon,
			HRead,
			HWrite,
			Call
		} Service;

		OpcUaReferenceConfig(void);
		~OpcUaReferenceConfig(void);

		void configFileName(const std::string& configFileName);
		void elementPrefix(const std::string& elementPrefix);
		OpcUaNodeId& nodeId(void);
		Service service(void);
		Object::SPtr& extension(void);

		bool decode(Config& config);

	  private:
		std::string configFileName_;
		std::string elementPrefix_;
		OpcUaNodeId nodeId_;
		Service service_;

		Object::SPtr extension_;
	};

}

#endif
