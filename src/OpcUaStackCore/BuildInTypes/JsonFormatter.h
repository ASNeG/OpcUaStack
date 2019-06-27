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

#include <string>
#include <boost/property_tree/ptree.hpp>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"

namespace OpcUaStackCore
{

	class DLLEXPORT JsonFormatter
    {
    public:
        using SPtr = boost::shared_ptr<JsonFormatter>;

        JsonFormatter();
		virtual ~JsonFormatter();

        /**
         * Function to encode the structure data to a json tree format.
         *
         * @param[out] pt					tree for json output
         * @param[in] element				element name of the subtree
         *
         * @return true if successful
         */
        bool jsonEncode(boost::property_tree::ptree& pt, const std::string& element) const;

        /**
         * Function to encode the structure data to a json tree format.
         *
         * @param[out] pt					tree for json output
         *
         * @return true if successful
         */
        bool jsonEncode(boost::property_tree::ptree& pt) const;

        /**
         * Function to decode the json tree format to the structure data.
         *
         * @param[in] pt					tree for json output
         * @param[in] element				element name of the subtree
         *
         * @return true if successful
         */
        bool jsonDecode(const boost::property_tree::ptree& pt, const std::string& element);

        /**
         * Function to decode the json tree format to the structure data.
         *
         * @param[in] pt					tree for json output
         *
         * @return true if successful
         */
        bool jsonDecode(const boost::property_tree::ptree& pt);

        virtual bool isArray(void) const { return false; }
        virtual bool isNull(void) const { return false; }
        virtual void setNull(void) { return; }
        virtual size_t arrayLength(void) const { return 0; }

      protected:
        virtual bool jsonEncodeImpl(boost::property_tree::ptree& pt) const = 0;
        virtual bool jsonDecodeImpl(const boost::property_tree::ptree& pt) = 0;

        template <typename  T>
        bool jsonNumberEncode(
        	boost::property_tree::ptree &pt,
			T value,
			const std::string &element,
			bool optional,
			T defaultValue
		) const
        {
            if (!optional || value != defaultValue) {
                if (!JsonNumber::jsonEncode(pt, value, element)) {
                    Log(Error, std::string(typeid(this).name()) + " json encoder error")
                            .parameter("Element", element);

                    return false;
                }
            }

            return true;
        }

        template <typename  T>
        bool jsonNumberEncode(boost::property_tree::ptree &pt, T value, const std::string &element) const
        {
            return jsonNumberEncode(pt, value, element, false, T());
        }

        template <typename  T>
        bool jsonNumberEncode(boost::property_tree::ptree &pt, T value) const
        {
            return JsonNumber::jsonEncode(pt, value);
        }

        template <typename  T>
        bool jsonNumberDecode(const boost::property_tree::ptree &pt, T& value, const std::string &element, bool optional, T defaultValue)
        {
        	auto ptElement = pt.get_child_optional(element);
        	if (!ptElement) {
         		if (!optional) {
            			Log(Error, std::string(typeid(this).name()) + " json decoder error, because mandatory number is missing")
        			    	.parameter("Element", element);
            			return false;
            		}
            		else {
            			value = defaultValue;
            			return true;
            		}
        	}

            if (!JsonNumber::jsonDecode(pt, value, element)) {
       			Log(Error, std::string(typeid(this).name()) + " json decoder error, because variable format error")
    			    	.parameter("Element", element);
        			return false;
            	return false;
            }
            return true;
        }

        template <typename  T>
        bool jsonNumberDecode(const boost::property_tree::ptree &pt, T& value, const std::string &element)
        {
            return jsonNumberDecode(pt, value, element, false, T());
        }

        template <typename  T>
        bool jsonNumberDecode(const boost::property_tree::ptree &pt, T& value)
        {
            return JsonNumber::jsonDecode(pt, value);
        }

        bool jsonObjectSPtrEncode(boost::property_tree::ptree &pt, JsonFormatter::SPtr valuePtr, const std::string &element, bool optional) const;
        bool jsonObjectSPtrEncode(boost::property_tree::ptree &pt, JsonFormatter::SPtr valuePtr, const std::string &element) const;
        bool jsonObjectSPtrDecode(const boost::property_tree::ptree &pt, JsonFormatter::SPtr valuePtr, const std::string &element, bool optional);
        bool jsonObjectSPtrDecode(const boost::property_tree::ptree &pt, JsonFormatter::SPtr valuePtr, const std::string &element);

        bool jsonObjectEncode(boost::property_tree::ptree &pt, const JsonFormatter& valuePtr, const std::string &element, bool optional) const;
        bool jsonObjectEncode(boost::property_tree::ptree &pt, const JsonFormatter& valuePtr, const std::string &element) const;
        bool jsonObjectDecode(const boost::property_tree::ptree &pt, JsonFormatter& valuePtr, const std::string &element, bool optional);
        bool jsonObjectDecode(const boost::property_tree::ptree &pt, JsonFormatter& valuePtr, const std::string &element);


        bool jsonArraySPtrEncode(boost::property_tree::ptree &pt, JsonFormatter::SPtr valuePtr, const std::string &element, bool optional) const;
        bool jsonArraySPtrEncode(boost::property_tree::ptree &pt, JsonFormatter::SPtr valuePtr, const std::string &element) const;
        bool jsonArraySPtrDecode(const boost::property_tree::ptree &pt, JsonFormatter::SPtr valuePtr, const std::string &element, bool optional);
        bool jsonArraySPtrDecode(const boost::property_tree::ptree &pt, JsonFormatter::SPtr valuePtr, const std::string &element);

        bool jsonArrayEncode(boost::property_tree::ptree &pt, const JsonFormatter& valuePtr, const std::string &element, bool optional) const;
        bool jsonArrayEncode(boost::property_tree::ptree &pt, const JsonFormatter& valuePtr, const std::string &element) const;
        bool jsonArrayDecode(const boost::property_tree::ptree &pt, JsonFormatter& valuePtr, const std::string &element, bool optional);
        bool jsonArrayDecode(const boost::property_tree::ptree &pt, JsonFormatter& valuePtr, const std::string &element);
    };

}

#endif
