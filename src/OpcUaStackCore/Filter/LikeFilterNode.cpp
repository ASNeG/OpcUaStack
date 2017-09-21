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


    		value.setValue(matches(string, pattern));

    		return true;
    	}

		return false;
    }

    bool
	LikeFilterNode::matches(const OpcUaString& string, const OpcUaString& pattern)
    {
		bool result = true;

		std::string string_ = string.toStdString();
		std::string pattern_ = pattern.toStdString();

		int i = 0;
		int j = 0;
		while (i < string_.size() && j < pattern_.size() && result) {
			switch (pattern_[j]) {
			case '%': {
				if ((j + 1) == pattern_.size()) {
					i = string_.size(); // the last char of the pattern is %. Finish cycle.
					break;
				} else {
					// Check next character after %
					if (pattern_[j + 1] == string_[i]) {
						j += 2;
					}
					if ((++i) >= string_.size()) {
						result = false;
					}
				}
				break;
			}
			case '_': {
				i++;
				j++;
				break;
			}
			case '\\': {
				// Check if \ is the last character of the pattern
				if ((j + 1) >= pattern_.size()) {
					result = pattern_[j] == string_[i];
					break;
				}
				result = pattern_[++j] == string_[i];
				i++;
				j++;
				break;
			}
			case '[': {
				bool inversed = false;
				if (pattern_[j + 1] == '^') {
					inversed = true;
					j++;
				}
				std::list<char> charList;
				bool stop = false;
				while (j < pattern_.size() && !stop) {
					switch (pattern_[++j]) {
					case ']':
						j++;
						stop = true;
						break;
					case '-': {
						char currentChar = pattern_[j - 1];
						j++;
						while (pattern_[j] >= currentChar) {
							charList.push_back(currentChar++);
						}
						break;
					}
					case '\\': {
						charList.push_back(pattern_[++j]);
						break;
					}
					default:
						charList.push_back(pattern_[j]);
						break;
					}
				}
				std::list<char>::iterator it = std::find(charList.begin(),
						charList.end(), string_[i++]);
				result = (it != charList.end()) ^ inversed;
				break;
			}
			default: {
				result = pattern_[j++] == string_[i++];
			}
			}
		}

		if (i < string_.size()) {
			result = false;
		}

		return result;
	}


}
