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


#include "OpcUaStackCore/Filter/NotFilterNode.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaTypeConversion.h"

namespace OpcUaStackCore
{
	NotFilterNode::NotFilterNode(const std::vector<FilterNode::SPtr>& args)
    {
        status_ = OpcUaStatusCode::Success;
        operandStatuses_ = std::vector<OpcUaStatusCode>();

        if (args.size() == 1) {
        	arg_ = args[0];
        }
        else {
        	status_ = OpcUaStatusCode::BadFilterOperandCountMismatch;
        }
    }

	NotFilterNode::~NotFilterNode()
    {

    }

    OpcUaStatusCode&
	NotFilterNode::status()
    {
    	return status_;
    }

    std::vector<OpcUaStatusCode>&
	NotFilterNode::operandStatuses()
    {
    	return operandStatuses_;
    }

    bool
	NotFilterNode::evaluate(OpcUaVariant& value)
    {
    	if (status_ == OpcUaStatusCode::Success) {
    		OpcUaTypeConversion converter;

    		OpcUaVariant::SPtr argValue = constructSPtr<OpcUaVariant>();
    		if (!arg_->evaluate(*argValue))
    			return false;

    		OpcUaVariant::SPtr tmp = constructSPtr<OpcUaVariant>();
    		if (!converter.conversion(argValue, OpcUaBuildInType_OpcUaBoolean, tmp))
    			return false;


    		value.set(!tmp->get<OpcUaBoolean>());
    		return true;
    	}

		return false;
    }
}
