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


#include <OpcUaStackCore/Filter/CastFilterNode.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaTypeConversion.h"


namespace OpcUaStackCore
{

    CastFilterNode::CastFilterNode(const std::vector<FilterNode::SPtr>& args)
    {
		status_ = OpcUaStatusCode::Success;
		operandStatuses_ = std::vector<OpcUaStatusCode>();

		if (args.size() == 2) {
			arg1_ = args[0];
			arg2_ = args[1];
		}
		else {
			status_ = OpcUaStatusCode::BadFilterOperandCountMismatch;
		}
    }

    CastFilterNode::~CastFilterNode()
    {

    }

    OpcUaStatusCode&
	CastFilterNode::status()
    {
    	return status_;
    }

    std::vector<OpcUaStatusCode>&
	CastFilterNode::operandStatuses()
    {
    	return operandStatuses_;
    }

    bool
	CastFilterNode::evaluate(OpcUaVariant& value)
    {
    	if (status_ == OpcUaStatusCode::Success) {

    		OpcUaVariant operand;
    		if (!arg1_->evaluate(operand)) {
    			return false;
    		}

    		OpcUaVariant typeId;
			if (!arg2_->evaluate(typeId)) {
				return false;
			}

			OpcUaUInt32 intId;
			OpcUaUInt16 namespaceIdx;
			typeId.getSPtr<OpcUaNodeId>()->get(intId, namespaceIdx);

    		OpcUaTypeConversion converter;
    		if (!converter.conversion(operand, (OpcUaBuildInType)intId, value)) {
    			value.clear();
    		}

			return true;
		}

		return false;
	}
}
