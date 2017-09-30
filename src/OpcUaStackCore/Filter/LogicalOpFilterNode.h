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

   Autor: Aleksey Timin (timin-ayu@nefteavtomatika.ru)
 */

#ifndef __OpcUaStackCore_LogicalOpFilterNode_h__
#define __OpcUaStackCore_LogicalOpFilterNode_h__

#include "OpcUaStackCore/Filter/FilterNode.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaOperator.h"

namespace OpcUaStackCore
{
    class DLLEXPORT LogicalOpFilterNode
	: public FilterNode
    {
      public:

        typedef boost::shared_ptr<LogicalOpFilterNode> SPtr;

        LogicalOpFilterNode(OpcUaOperator op, const std::vector<FilterNode::SPtr>& args);
        virtual ~LogicalOpFilterNode(void);

        virtual bool evaluate(OpcUaVariant& value) override;

        virtual OpcUaStatusCode& status() override;
        virtual std::vector<OpcUaStatusCode>& operandStatuses() override;

      private:
        OpcUaOperator operator_;

        FilterNode::SPtr arg1_;
        FilterNode::SPtr arg2_;

        OpcUaStatusCode status_;
        std::vector<OpcUaStatusCode> operandStatuses_;

        enum LogicalValue {
        	True = 0,
			False,
			Null
        };

        static LogicalValue andTable[3][3];
        static LogicalValue orTable[3][3];

        LogicalValue toLogicalValue(FilterNode::SPtr arg);
    };

}
#endif
