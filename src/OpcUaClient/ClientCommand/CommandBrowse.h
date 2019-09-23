/*
   Copyright 2016-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaClient_CommandBrowse_h__
#define __OpcUaClient_CommandBrowse_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaClient/ClientCommand/CommandBase.h"
#include "OpcUaStackClient/ServiceSet/ViewServiceBrowse.h"

namespace OpcUaClient
{

	class DLLEXPORT CommandBrowse
	: public CommandBase
	{
	  public:
		typedef boost::shared_ptr<CommandBrowse> SPtr;

		CommandBrowse(void);
		virtual ~CommandBrowse(void);

		//- CommandBrowse interface ---------------------------------------------
		virtual CommandBase::SPtr createCommand(void);
		virtual bool validateCommand(void);
		virtual bool addParameter(const std::string& parameterName, const std::string& parameterValue);
		virtual std::string help(void);
		//- CommandBrowse interface ---------------------------------------------

		OpcUaStackCore::OpcUaNodeId::Vec& nodeIdVec(void);
		OpcUaStackCore::BrowseDirectionEnum direction(void);
		bool recursive(void);

	  private:
		OpcUaStackCore::OpcUaNodeId::Vec nodeIdVec_;
		OpcUaStackCore::BrowseDirectionEnum direction_;
		bool recursive_;
	};

}

#endif
