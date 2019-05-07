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

#ifndef __OpcUaStackCore_JsonFormatter_h__
#define __OpcUaStackCore_JsonFormatter_h__

#include "os.h"
#include <string>
#include <boost/property_tree/ptree.hpp>

#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"

namespace OpcUaStackCore
{

	class DLLEXPORT JsonFormatter
    {
    public:
        JsonFormatter();
		virtual ~JsonFormatter(void);

        bool jsonEncode(boost::property_tree::ptree& pt, const std::string& element) const;
        virtual bool jsonEncode(boost::property_tree::ptree& pt) const;
        bool jsonDecode(const boost::property_tree::ptree& pt, const std::string& element);
        virtual bool jsonDecode(const boost::property_tree::ptree& pt);

	protected:
        template <typename  T>
        bool jsonNumberEncode(boost::property_tree::ptree &pt, T value, const std::string &element) const {
            if (!JsonNumber::jsonEncode(pt, value, element)) {
                Log(Error, std::string(typeid(this).name()) + " json encoder error")
                        .parameter("Element", element);
                return false;
            }

            return true;
        }

        template <typename  T>
        bool jsonNumberDecode(const boost::property_tree::ptree &pt, T& value, const std::string &element)  {
            if (!JsonNumber::jsonDecode(pt, value, element)) {
                Log(Error, std::string(typeid(this).name()) + " json decoder error")
                        .parameter("Element", element);
                return false;
            }

            return true;
        }
    };


}

#endif
