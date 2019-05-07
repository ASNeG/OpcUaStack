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
#include "Log.h"
#include "JsonFormatter.h"


namespace OpcUaStackCore
{


    JsonFormatter::JsonFormatter()
    {

    }

    JsonFormatter::~JsonFormatter(void)
    {

    }

    bool
    JsonFormatter::jsonEncode(boost::property_tree::ptree &pt, const std::string &element) const
    {
        boost::property_tree::ptree elementTree;
        if (!jsonEncode(elementTree)) {
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

        return jsonDecode(*tmpTree);
    }

    bool
    JsonFormatter::jsonEncode(boost::property_tree::ptree &pt) const
    {
        Log(Error, std::string(typeid(this).name()) + " doesn't implement JsonFormatter::jsonEncode method");
        return false;
    }

    bool
    JsonFormatter::jsonDecode(const boost::property_tree::ptree &pt)
    {
        Log(Error, std::string(typeid(this).name()) + " doesn't implement JsonFormatter::jsonDecode method");
        return false;
    }
}

