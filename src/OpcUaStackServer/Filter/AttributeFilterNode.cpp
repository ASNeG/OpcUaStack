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

#include "OpcUaStackServer/Filter/AttributeFilterNode.h"

namespace OpcUaStackServer
{
    AttributeFilterNode::AttributeFilterNode(void)
    : FilterNode()
    , attributeIf_(nullptr)
    , typeId_()
    , alias_("")
    , relativePath_()
    , attributeId_(0)
    , numericRange_("")
    {
    }

    AttributeFilterNode::~AttributeFilterNode()
    {

    }

    void
	AttributeFilterNode::attributeIf(AttributeIf* attributeIf)
    {
    	attributeIf_ = attributeIf;
    }

    OpcUaVariant
	AttributeFilterNode::evaluate()
    {
    	OpcUaVariant value;
        return value;
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
			relativePath_,
			attributeId_,
			numericRange_,
			value
    	);
    }
}

