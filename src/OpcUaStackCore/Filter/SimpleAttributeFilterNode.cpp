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

#include "OpcUaStackCore/Filter/SimpleAttributeFilterNode.h"

namespace OpcUaStackCore
{
    SimpleAttributeFilterNode::SimpleAttributeFilterNode(void)
    : FilterNode()
    , typeId_()
    , browsePath_()
    , attributeId_(0)
    , numericRange_("")
    , simpleAttributeIf_(nullptr)
    , status_(OpcUaStatusCode::Success)
    , operandStatuses_(0)
    {
    }

    SimpleAttributeFilterNode::SimpleAttributeFilterNode(
            const OpcUaNodeId& typeId,
            OpcUaQualifiedNameArray& browsePath,
            OpcUaUInt32 attributeId,
            const OpcUaString& numericRange)
    : FilterNode()
    , typeId_(typeId)
    , browsePath_(0)
    , attributeId_(attributeId)
    , numericRange_(numericRange)
    , simpleAttributeIf_(nullptr)
    , operandStatuses_(0)
    {
        for (int i = 0; i < browsePath.size(); ++i) {
            OpcUaQualifiedName::SPtr el;

            browsePath.get(i, el);
            browsePath_.push_back(el);
        }

        //FIXME: Check arguments
        status_ = OpcUaStatusCode::Success;
    }

    SimpleAttributeFilterNode::~SimpleAttributeFilterNode()
    {

    }

    OpcUaStatusCode& SimpleAttributeFilterNode::status()
    {
        return status_;
    }

    std::vector<OpcUaStatusCode>& SimpleAttributeFilterNode::operandStatuses()
    {
        return operandStatuses_;
    }


    void
	SimpleAttributeFilterNode::simpleAttributeIf(SimpleAttributeIf* simpleAttributeIf)
    {
    	simpleAttributeIf_ = simpleAttributeIf;
    }

    bool
	SimpleAttributeFilterNode::evaluate(OpcUaVariant& value)
    {
    	if (simpleAttributeIf_ == nullptr) {
    		return false;
    	}

    	return simpleAttributeIf_->getAttribute(
    		typeId_,
			browsePath_,
			attributeId_,
			numericRange_,
			value
    	);

    }
}

