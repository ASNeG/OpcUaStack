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


#include "OpcUaStackCore/Filter/EqualsFilterNode.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaTypeConversion.h"


namespace OpcUaStackCore
{
    EqualsFilterNode::EqualsFilterNode(const std::vector<FilterNode::SPtr>& args)
    {
        value_ = OpcUaVariant();
        value_.set<OpcUaBoolean>(false);

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

    EqualsFilterNode::~EqualsFilterNode()
    {

    }

    OpcUaStatusCode&
	EqualsFilterNode::status()
    {
    	return status_;
    }

    std::vector<OpcUaStatusCode>&
	EqualsFilterNode::operandStatuses()
    {
    	return operandStatuses_;
    }

    bool
	EqualsFilterNode::evaluate(OpcUaVariant& value)
    {
    	if (status_ == OpcUaStatusCode::Success) {
    		OpcUaVariant::SPtr v1 = constructSPtr<OpcUaVariant>();
            if (!arg1_->evaluate(*v1)) {
            	return false;
            }

            OpcUaVariant::SPtr v2 = constructSPtr<OpcUaVariant>();
            if (!arg2_->evaluate(*v2)) {
            	return false;
            }

    		OpcUaTypeConversion converter;
    		// Convert variable with greater precedence rank
    		if (converter.precedenceRank(v1->variantType()) < converter.precedenceRank(v2->variantType())) {
    			v1.swap(v2);
    		}
    	    char conveType = converter.conversionType(v1->variantType(), v2->variantType());

    	    switch (conveType)
    	    {
    	    case '-':
    	    {
    	    	value_.set<OpcUaBoolean>(*v1 == *v2);
    	    	break;
    	    }
    	    case 'I':
    	    {
    	    	converter.conversion(v1, v2->variantType(), v1);
    	    	value_.set<OpcUaBoolean>(*v1 == *v2);
    	    	break;
    	    }
    	    }


			value_.copyTo(value);
			return true;
		}

		return false;
    }
}
