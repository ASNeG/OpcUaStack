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
    		if (!converter.conversion(argValue, OpcUaBuildInType_OpcUaString, tmpVariant)) {
    			return false;
    		}

    		OpcUaString string;
    		tmpVariant->getValue(string);

    		arg2_->evaluate(*argValue);
    		if (!converter.conversion(argValue, OpcUaBuildInType_OpcUaString, tmpVariant)) {
    			return false;
    		}

    		OpcUaString pattern;
    		tmpVariant->getValue(pattern);


    		bool matches = true;
    		std::string stdString = string.toStdString();
    		std::string stdPattern = pattern.toStdString();
    		int i = 0;
    		int j = 0;
    		while(i < stdString.size() && j < stdPattern.size() && matches) {
    			switch (stdPattern[j]) {
    			case '%':
    			{
    				if ((j + 1) == stdPattern.size()) {
    					j++; // the last char of the pattern is %. Finish cycle.
    					break;
    				} else {
    					// Check next character after %
    					if (stdPattern[j+1] == stdString[i]) {
    						j += 2;
    					}
    					if ((++i) == stdString.size()) {
    						matches = false;
    					}
    				}

    				break;
    			}
    			default:
    			{
    				if (stdPattern[j] != stdString[i]) {
    					matches = false;
    				} else {
    					i++;
    					j++;
    				}
    			}
    			}
    		}


    		value.setValue(matches);

    		return true;
    	}

		return false;
    }


}
