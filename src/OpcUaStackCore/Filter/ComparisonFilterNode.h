/*
   Copyright 2017-2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Aleksey Timin (timin-ayu@nefteavtomatika.ru), Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_ComparisonFilterNode_h__
#define __OpcUaStackCore_ComparisonFilterNode_h__

#include "OpcUaStackCore/Filter/FilterNode.h"
#include "OpcUaStackCore/StandardDataTypes/FilterOperator.h"

namespace OpcUaStackCore
{
    class DLLEXPORT ComparisonFilterNode
	: public FilterNode
    {
      public:

        typedef boost::shared_ptr<ComparisonFilterNode> SPtr;

        ComparisonFilterNode(FilterOperator::Enum op, const std::vector<FilterNode::SPtr>& args);
        virtual ~ComparisonFilterNode(void);

        virtual bool evaluate(OpcUaVariant& value) override;

        virtual OpcUaStatusCode& status() override;
        virtual std::vector<OpcUaStatusCode>& operandStatuses() override;

      private:
        FilterOperator::Enum operator_;

        FilterNode::SPtr arg1_;
        FilterNode::SPtr arg2_;

        OpcUaStatusCode status_;
        std::vector<OpcUaStatusCode> operandStatuses_;

        bool compare(OpcUaVariant& lhs, OpcUaVariant& rhs, OpcUaVariant& result);
    };

}
#endif
