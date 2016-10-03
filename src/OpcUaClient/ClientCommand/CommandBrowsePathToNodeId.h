/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaClient_CommandBrowsePathToNodeId_h__
#define __OpcUaClient_CommandBrowsePathToNodeId_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaQualifiedName.h"
#include "OpcUaClient/ClientCommand/CommandBase.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	class CommandBrowsePathToNodeId
	: public CommandBase
	{
	  public:
		typedef boost::shared_ptr<CommandBrowsePathToNodeId> SPtr;

		CommandBrowsePathToNodeId(void);
		virtual ~CommandBrowsePathToNodeId(void);

		//- CommandBrowsePathToNodeId interface ---------------------------------------------
		virtual CommandBase::SPtr createCommand(void);
		virtual bool validateCommand(void);
		virtual bool addParameter(const std::string& parameterName, const std::string& parameterValue);
		virtual std::string help(void);
		//- CommandBrowsePathToNodeId interface ---------------------------------------------

		OpcUaNodeId::SPtr& nodeId(void);
		std::vector<OpcUaQualifiedName>& browseNameVec(void);

	  private:
		OpcUaNodeId::SPtr nodeId_;
		std::vector<OpcUaQualifiedName> browseNameVec_;
	};

}

#endif
