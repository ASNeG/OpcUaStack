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

#include "OpcUaStackCore/Filter/AttributeFilterNode.h"

namespace OpcUaStackCore
{
    AttributeFilterNode::AttributeFilterNode(void)
    : FilterNode()
    , attributeIf_(nullptr)
    , typeId_()
    , alias_("")
    , browsePath_()
    , attributeId_(0)
    , numericRange_("")
    , status_(OpcUaStatusCode::Success)
    , operandStatuses_(0)
    {
    }

    AttributeFilterNode::AttributeFilterNode(const OpcUaNodeId& typeId,
            const OpcUaString& alias,
            const RelativePath& browsePath,
            OpcUaUInt32 attributeId,
            const OpcUaString& numericRange)
    : FilterNode()
    , attributeIf_(nullptr)
    , typeId_(typeId)
    , alias_(alias)
    , attributeId_(attributeId)
    , numericRange_(numericRange)
    , operandStatuses_(0)
    {
        browsePath_ = boost::make_shared<RelativePath>(browsePath);

        //FIXME: Check arguments
        status_ = OpcUaStatusCode::Success;
    }

    AttributeFilterNode::~AttributeFilterNode()
    {

    }

    void
	AttributeFilterNode::attributeIf(AttributeIf* attributeIf)
    {
    	attributeIf_ = attributeIf;
    }

    OpcUaStatusCode& AttributeFilterNode::status()
    {
        return status_;
    }

    std::vector<OpcUaStatusCode>& AttributeFilterNode::operandStatuses()
    {
        return operandStatuses_;
    }


    bool
	AttributeFilterNode::evaluate(OpcUaVariant& value)
    {
    	if (attributeIf_ == nullptr) {
    		return false;
    	}

    	return attributeIf_->getAttribute(
    		typeId_,
			alias_,
			browsePath_,
			attributeId_,
			numericRange_,
			value
    	);
    }
}

