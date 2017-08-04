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

#include "OpcUaStackServer/ServiceSet/EqualsFilterNode.h"

namespace OpcUaStackServer
{
    EqualsFilterNode::EqualsFilterNode(const std::vector<FilterNode::SPtr>& args)
    {
        arg1_ = args[0];
        arg2_ = args[1];
    }

    EqualsFilterNode::~EqualsFilterNode()
    {

    }

    OpcUaVariant EqualsFilterNode::evaluate()
    {
        //FIXME: Need conversions;
        OpcUaVariant result;

        OpcUaVariant v1 = arg1_->evaluate();
        OpcUaVariant v2 = arg2_->evaluate();

        result.set<OpcUaBoolean>(v1 == v2);

        return result;
    }
}
