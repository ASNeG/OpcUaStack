/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Aleksey Timin (atimin@gmail.com)
 */

#include <typeinfo>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"


namespace OpcUaStackCore
{


    JsonFormatter::JsonFormatter()
    {

    }

    JsonFormatter::~JsonFormatter()
    {

    }

    bool
    JsonFormatter::jsonEncode(boost::property_tree::ptree &pt, const std::string &element) const
    {
        boost::property_tree::ptree elementTree;
        if (!jsonEncodeImpl(elementTree)) {
            Log(Error, std::string(typeid(this).name()) + " json encoder error")
                    .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }

    bool
    JsonFormatter::jsonDecode(const boost::property_tree::ptree &pt, const std::string &element)
    {
        boost::optional<const boost::property_tree::ptree&> tmpTree;

        tmpTree = pt.get_child_optional(element);
        if (!tmpTree) {
            Log(Error, std::string(typeid(this).name()) + " json decoder error")
                    .parameter("Element", element);
            return false;
        }

        return jsonDecodeImpl(*tmpTree);
    }

    bool
    JsonFormatter::jsonEncode(boost::property_tree::ptree &pt) const
    {
        return jsonEncodeImpl(pt);
    }

    bool
    JsonFormatter::jsonDecode(const boost::property_tree::ptree &pt)
    {
        return jsonDecodeImpl(pt);
    }

    bool
    JsonFormatter::jsonObjectSPtrEncode(
    	boost::property_tree::ptree &pt,
		JsonFormatter::SPtr valuePtr,
		const std::string &element,
		bool optional
	) const
    {
    	// check if array element is null
    	if (valuePtr.get() == nullptr) {
    		if (optional) {
    			return true; // the element can be omitted
    		}
    		else {
    			 Log(Error, std::string(typeid(this).name()) + " json encode error, because mandatory object is null")
    			    .parameter("Element", element);
    			return false;
    		}
    	}

        return jsonObjectEncode(pt, *valuePtr.get(), element, optional);
    }


    bool
    JsonFormatter::jsonObjectSPtrEncode(
    	boost::property_tree::ptree &pt,
		JsonFormatter::SPtr valuePtr,
		const std::string &element
	) const
    {
        return jsonObjectSPtrEncode(pt, valuePtr, element, false);
    }

    bool
    JsonFormatter::jsonObjectSPtrDecode(
		const boost::property_tree::ptree &pt,
		JsonFormatter::SPtr valuePtr,
		const std::string &element,
		bool optional
	)
    {
    	if (valuePtr.get() == nullptr) {
    		Log(Error, std::string(typeid(this).name()) + " json decoder error, because variable is null")
    		    .parameter("Element", element);
    		return false;
    	}

        return jsonObjectDecode(pt, *valuePtr.get(), element);
    }

    bool
    JsonFormatter::jsonObjectSPtrDecode(
    	const boost::property_tree::ptree &pt,
		JsonFormatter::SPtr valuePtr,
		const std::string &element
	)
    {
        return jsonObjectSPtrDecode(pt, valuePtr, element, false);
    }

    bool
    JsonFormatter::jsonObjectEncode(
    	boost::property_tree::ptree &pt,
		const JsonFormatter &valuePtr,
        const std::string &element,
		bool optional
	) const
    {
    	// check if array element is null
    	if (valuePtr.isNull()) {
    		if (optional) {
    			return true; // the element can be omitted
    		}
    		else {
    			 Log(Error, std::string(typeid(this).name()) + " json encode error, because mandatory object is null")
    			    .parameter("Element", element);
    			return false;
    		}
    	}

        return valuePtr.jsonEncode(pt, element);
    }

    bool
    JsonFormatter::jsonObjectEncode(
    	boost::property_tree::ptree &pt,
		const JsonFormatter &valuePtr,
        const std::string &element
	) const
    {
        return jsonObjectEncode(pt, valuePtr, element, false);
    }

    bool
    JsonFormatter::jsonObjectDecode(
    	const boost::property_tree::ptree &pt,
		JsonFormatter &valuePtr,
        const std::string &element,
		bool optional
	)
    {
    	auto ptElement = pt.get_child_optional(element);
    	if (!ptElement) {
    		if (!optional) {
    			Log(Error, std::string(typeid(this).name()) + " json decoder error, because mandatory object is missing")
			    	.parameter("Element", element);
    			return false;
    		}
    		else {
    			valuePtr.setNull();
    			return true;
    		}
    	}

        return valuePtr.jsonDecode(pt, element);
    }

    bool
    JsonFormatter::jsonObjectDecode(
    	const boost::property_tree::ptree &pt,
		JsonFormatter &valuePtr,
        const std::string &element
	)
    {
        return jsonObjectDecode(pt, valuePtr, element, false);
    }

    bool
	JsonFormatter::jsonArraySPtrEncode(
		boost::property_tree::ptree &pt,
		JsonFormatter::SPtr valuePtr,
		const std::string &element,
		bool optional
	) const
    {
    	// check if array element is null
    	if (valuePtr.get() == nullptr) {
    		if (optional) {
    			return true; // the element can be ommitted
    		}
    		else {
    			 Log(Error, std::string(typeid(this).name()) + " json encode error, because mandatory array is null")
    			    .parameter("Element", element);
    			return false;
    		}
    	}

    	// encode array element
    	return jsonArrayEncode(pt, *valuePtr.get(), element, optional);
    }

    bool
	JsonFormatter::jsonArraySPtrEncode(
		boost::property_tree::ptree &pt,
		JsonFormatter::SPtr valuePtr,
		const std::string &element
	) const
    {
    	return jsonArraySPtrEncode(pt, valuePtr, element, false);
    }

    bool
	JsonFormatter::jsonArraySPtrDecode(
		const boost::property_tree::ptree &pt,
		JsonFormatter::SPtr valuePtr,
		const std::string &element,
		bool optional
	)
    {
    	return jsonArrayDecode(pt, *valuePtr.get(), element, optional);
    }

    bool
	JsonFormatter::jsonArraySPtrDecode(
		const boost::property_tree::ptree &pt,
		JsonFormatter::SPtr valuePtr,
		const std::string &element
	)
    {
    	return jsonArraySPtrDecode(pt, valuePtr, element, false);
    }

    bool
	JsonFormatter::jsonArrayEncode(
		boost::property_tree::ptree &pt,
		const JsonFormatter& valuePtr,
		const std::string &element,
		bool optional
	) const
    {
    	// check if array element is null
    	if (valuePtr.isNull()) {
    		if (optional) {
    			return true; // the element can be omitted
    		}
    		else {
    			 Log(Error, std::string(typeid(this).name()) + " json encode error, because mandatory array is null")
    			    .parameter("Element", element);
    			return false;
    		}
    	}

    	// encode array element
    	return jsonArrayEncode(pt, valuePtr, element);
    }

    bool
	JsonFormatter::jsonArrayEncode(
		boost::property_tree::ptree &pt,
		const JsonFormatter& valuePtr,
		const std::string &element
	) const
    {
    	return valuePtr.jsonEncode(pt, element);
    }

    bool
	JsonFormatter::jsonArrayDecode(
		const boost::property_tree::ptree &pt,
		JsonFormatter& valuePtr,
		const std::string &element,
		bool optional
	)
    {
    	auto ptElement = pt.get_child_optional(element);
    	if (!ptElement) {
    		if (!optional) {
    			Log(Error, std::string(typeid(this).name()) + " json decoder error, because mandatory array is missing")
			    	.parameter("Element", element);
    			return false;
    		}
    		else {
    			valuePtr.setNull();
    			return true;
    		}
    	}

    	// decode array element
    	return jsonArrayDecode(pt, valuePtr, element);
    }

    bool
	JsonFormatter::jsonArrayDecode(
		const boost::property_tree::ptree &pt,
		JsonFormatter& valuePtr,
		const std::string &element
	)
    {
    	return valuePtr.jsonDecode(pt, element);
    }

}

