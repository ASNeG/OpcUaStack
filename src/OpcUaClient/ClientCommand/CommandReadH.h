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

#ifndef __OpcUaClient_CommandReadH_h__
#define __OpcUaClient_CommandReadH_h__

#include <boost/shared_ptr.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/ServiceSet/TimestampsToReturn.h"
#include "OpcUaClient/ClientCommand/CommandBase.h"

namespace OpcUaClient
{

	class DLLEXPORT CommandReadH
	: public CommandBase
	{
	  public:
		typedef boost::shared_ptr<CommandReadH> SPtr;

		typedef enum {
			T_Stdout,
			T_CSVFile
		} OutputType;

		CommandReadH(void);
		virtual ~CommandReadH(void);

		//- CommandReadH interface ---------------------------------------------
		virtual CommandBase::SPtr createCommand(void);
		virtual bool validateCommand(void);
		virtual bool addParameter(const std::string& parameterName, const std::string& parameterValue);
		virtual std::string help(void);
		//- CommandReadH interface ---------------------------------------------

		OpcUaStackCore::OpcUaNodeId::Vec& nodeIdVec(void);
		boost::posix_time::ptime& startTime(void);
		boost::posix_time::ptime& endTime(void);
		OpcUaStackCore::TimestampsToReturn timestampsToReturn(void);
		uint32_t maxNumResultValuesPerNode(void);
		uint32_t maxNumRequests(void);
		void maxNumRequestsDec(void);

		std::string& csvFileName(void);
		OutputType outputType(void);
		void outputType(OutputType outputType);

	  private:
		OpcUaStackCore::OpcUaNodeId::Vec nodeIdVec_;
		boost::posix_time::ptime startTime_;
		boost::posix_time::ptime endTime_;
		OpcUaStackCore::TimestampsToReturn timestampsToReturn_;
		uint32_t maxNumResultValuesPerNode_;
		int32_t maxNumRequests_;

		std::string csvFileName_;
		OutputType outputType_;
	};

}

#endif
