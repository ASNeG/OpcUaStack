/*
   Copyright 2017-2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_Xmlns_h__
#define __OpcUaStackCore_Xmlns_h__

#include <iostream>
#include <map>
#include <boost/property_tree/ptree.hpp>
#include "OpcUaStackCore/Base/os.h"
#include <vector>

namespace OpcUaStackCore
{

	class DLLEXPORT Xmlns
	{
	  public:
		typedef std::map<std::string, std::string> NamespaceMap;

		/**
		 * Encoder
		 */
		Xmlns(void);

		/**
		 * Decoder
		 */
		~Xmlns(void);

		/**
		 * This function removes all namespace entries
		 */
		void clear(void);

		/**
		 * This function is used to add a new xml namespace to the namespace map. If the
		 * namespace already exist then the old namespace will be delete.
		 *
		 * @param[in] prefix			prefix of the namespace
		 * @param[in] uri				uri of the namespace
		 *
		 * @return true, if successfuly
		 */
		bool addNamespace(const std::string& prefix, const std::string& uri);

		/**
		 * This function used to parse an add all xml namespaces wich are content of a
		 * nodeset xml element
		 *
		 * @param[in] nodeSetElement	xml node set element
		 *
		 * @return true, if successfuly
		 */
		bool addNamespaceFromNodeSetElement(boost::property_tree::ptree& nodeSetElement);

		/**
		 * checks if the uri exists in the namespace map
		 *
		 * @param[in] uri				uri of the namespace
		 *
		 * @return true, if the uri already exist
		 */
		bool exist(const std::string& uri);

		/**
		 * This function returns a prefix for a given uri
		 *
		 * @param[in] uri				uri of the namesapce
		 *
		 * @return prefix of the namespace or a empty string
		 */
		std::string getPrefix(const std::string& uri);

		/**
		 * This function returns a list of all puris
		 *
		 * @return prefix of the namespace or a empty string
		 */
		void getUris(std::vector<std::string>& uris);

		/**
		 * This function is used to add the prefix to the element name
		 *
		 * @parameter[in] element		name of the element
		 * @parameter[in] uri			uri of the element
		 *
		 * @return data type name with prefix
		 */
		std::string addPrefix(const std::string& element, const std::string& uri = "");

		/**
		 * This function returns the data type part of an element name
		 *
		 * @parameter[in] element		name of the element
		 * @parameter[in] uri			uri of the element
		 *
		 * @return data type name
		 */
		std::string cutPrefix(const std::string& element, const std::string& uri = "");

		/**
		 * equal operator
		 *
		 * @parameter[in] value			xmlns element
		 *
		 * @return class reference
		 */
		Xmlns& operator=(const Xmlns& value);

		/**
		 * This function is used to log all prefix and uri pairs.
		 *
		 * @parameter[in] message		log message
		 */
		void log(const std::string& message = "");

		/**
		 * This function is usd to enable or disable the logging of the class
		 *
		 * @parameter[in] logEnable		enable or disable the log of the class
		 */
		void logEnable(bool logEnable);

	  private:
		bool logEnable_;
		NamespaceMap namespaceMap_;
	};

}

#endif
