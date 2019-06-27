/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaStackCore_ExtensionObjectBase_h__
#define __OpcUaStackCore_ExtensionObjectBase_h__

#include <boost/property_tree/ptree.hpp>

#include <map>

#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"

namespace OpcUaStackCore
{

	/**
	 * This class is the base class for all structure classes
	 */
    class DLLEXPORT ExtensionObjectBase
    : public JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<ExtensionObjectBase> SPtr;
		typedef std::map<OpcUaNodeId, ExtensionObjectBase::SPtr> Map;

		/**
		 * Constructor
		 */
		ExtensionObjectBase(void);

		/**
		 * Destructor
		 */
		virtual ~ExtensionObjectBase(void);

		/**
		 * Creates a structure class and resturns a pointer to this class.
		 *
		 * @return pointer to the structure class
		 */
		virtual SPtr factory(void) = 0;

		/**
		 * Function to encode the structure data to the binary format.
		 *
		 * @param[out] os					output stream for binary output
		 */
		virtual void opcUaBinaryEncode(std::ostream& os) const = 0;

		/**
		 * Function to decode the binary format to the structure data
		 *
		 * @param[in] is					input stream for binary input
		 */
		virtual void opcUaBinaryDecode(std::istream& is) = 0;

		/**
		 * Function to encode the structure data to a xml tree format.
		 *
		 * @param[out] pt					tree for xml output
		 * @param[in] element				element name of the subtree
		 * @param[in] xmlns					xml namespaces
		 *
		 * @return true if successful
		 */
		virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return true; }

		/**
		 * Function to encode the structure data to a xml tree format.
		 *
		 * @param[out] pt					tree for xml output
		 * @param[in] xmlns					xml namespaces
		 *
		 * @return true if successful
		 */
		virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return true; }

		/**
		 * Function to decode the xml tree format to the structure data.
		 *
		 * @param[in] pt					tree for xml output
		 * @param[in] element				element name of the subtree
		 * @param[in] xmlns					xml namespaces
		 *
		 * @return true if successful
		 */
		virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return true; }

		/**
		 * Function to decode the xml tree format to the structure data.
		 *
		 * @param[in] pt					tree for xml output
		 * @param[in] xmlns					xml namespaces
		 *
		 * @return true if successful
		 */
		virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return true; }


		/**
		 * Function to create a copy of the extension object
		 *
		 * @param[out] extensionObjectBase	target extension object
		 *
		 */
		virtual void copyTo(ExtensionObjectBase& extensionObjectBase) = 0;

		/**
		 * Function to compare two extension objects
		 *
		 * @param[in] extensionObjectBase	extension object
		 *
		 * @return true, if both extension objects are equal
		 */
		virtual bool equal(ExtensionObjectBase& extensionObjectBase) const = 0;

		/**
		 * Function to show the parameters of the extension object
		 *
		 * @param[out] os					output stream
		 */
		virtual void out(std::ostream& os) = 0;

		/**
		 * Function to result the namespace name of the extension object
		 *
		 * @return namespace name of the extension object
		 */
		virtual std::string namespaceName(void) { return "UnknownNamespace"; }

		/**
		 * Function to result the type name of the extension object
		 *
		 * @return type name of the extension object
		 */
		virtual std::string typeName(void) { return "UnknownType"; }

		/**
		 * Function to result the type node identifier of the extension object
		 *
		 * @return type node identifier of the extension object
		 */
		virtual OpcUaNodeId typeId(void) { return OpcUaNodeId(0, 0); }

		/**
		 * Function to result the binary encoding node identifier of the extension object
		 *
		 * @return binary encoding node identifier of the extension object
		 */
		virtual OpcUaNodeId binaryTypeId(void) { return OpcUaNodeId(0, 0); }

		/**
		 * Function to result the xml encoding node identifier of the extension object
		 *
		 * @return xml encoding node identifier of the extension object
		 */
		virtual OpcUaNodeId xmlTypeId(void) { return OpcUaNodeId(0, 0); }

		/**
		 * Function to result the json encoding node identifier of the extension object
		 *
		 * @return json encoding node identifier of the extension object
		 */
		virtual OpcUaNodeId jsonTypeId(void) { return OpcUaNodeId(0, 0); }

		/**
		 * Function to compare two extension objects
		 *
		 * @param[in] extensionObjectBase	extension object
		 *
		 * @return true, if both extension objects are equal
		 */
        bool operator==(const ExtensionObjectBase& extensionObjectBase) const;

		/**
		 * Function to compare two extension objects
		 *
		 * @param[in] extensionObjectBase	extension object
		 *
		 * @return true, if both extension objects are not equal
		 */
        bool operator!=(const ExtensionObjectBase& extensionObjectBase) const;

		/**
		 * Function to create a copy of the extension object
		 *
		 * @param[in] extensionObjectBase	target extension object
		 *
		 * @return copy of the extension object
		 */
        ExtensionObjectBase& operator=(const ExtensionObjectBase& extensionObjectBase);

	};

}

#endif
