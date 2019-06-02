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

#ifndef __OpcUaClient_CommandWriteH_h__
#define __OpcUaClient_CommandWriteH_h__

#include <boost/shared_ptr.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaDataValue.h"
#include "OpcUaClient/ClientCommand/CommandBase.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	class DLLEXPORTCommandWriteH
	: public CommandBase
	{
	  public:
		typedef boost::shared_ptr<CommandWriteH> SPtr;

		typedef enum {
			T_CommandLine,
			T_CSVFile
		} InputType;

		CommandWriteH(void);
		virtual ~CommandWriteH(void);

		//- CommandWriteH interface ---------------------------------------------
		virtual CommandBase::SPtr createCommand(void);
		virtual bool validateCommand(void);
		virtual bool addParameter(const std::string& parameterName, const std::string& parameterValue);
		virtual std::string help(void);
		//- CommandWriteH interface ---------------------------------------------

		OpcUaNodeId& nodeId(void);
		OpcUaDataValue::Vec& dataValueVec(void);

		std::string& csvFileName(void);
		InputType inputType(void);
		OpcUaBuildInType valueType(void);

	  private:
		OpcUaNodeId nodeId_;
		OpcUaDataValue::Vec dataValueVec_;
		OpcUaDataValue::SPtr actDataValue_;

		std::string csvFileName_;
		OpcUaBuildInType valueType_;
		InputType inputType_;
	};

}

#endif
