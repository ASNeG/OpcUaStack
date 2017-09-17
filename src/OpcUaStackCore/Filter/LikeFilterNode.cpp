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


#include <OpcUaStackCore/Filter/LikeFilterNode.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaTypeConversion.h"


namespace OpcUaStackCore
{

    LikeFilterNode::LikeFilterNode(const std::vector<FilterNode::SPtr>& args)
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

    LikeFilterNode::~LikeFilterNode()
    {

    }

    OpcUaStatusCode&
	LikeFilterNode::status()
    {
    	return status_;
    }

    std::vector<OpcUaStatusCode>&
	LikeFilterNode::operandStatuses()
    {
    	return operandStatuses_;
    }

    bool
	LikeFilterNode::evaluate(OpcUaVariant& value)
    {
    	if (status_ == OpcUaStatusCode::Success) {
    		OpcUaTypeConversion converter;

    		OpcUaVariant::SPtr tmpVariant = constructSPtr<OpcUaVariant>();
    		OpcUaVariant::SPtr argValue = constructSPtr<OpcUaVariant>();

    		arg1_->evaluate(*argValue);
    		converter.conversion(argValue, OpcUaBuildInType_OpcUaString, tmpVariant);

    		OpcUaString string;
    		tmpVariant->getValue(string);

    		arg2_->evaluate(*argValue);
    		converter.conversion(argValue, OpcUaBuildInType_OpcUaString, tmpVariant);

    		OpcUaString patern;
    		tmpVariant->getValue(patern);

    		value.setValue(patern == string);

    		return true;
    	}

		return false;
    }


}
