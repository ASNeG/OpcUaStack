/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_NumberNamespaceMap_h__
#define __OpcUaStackCore_NumberNamespaceMap_h__

#include <boost/shared_ptr.hpp>

#include <string>
#include <map>

#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackServer
{

	/**
	 * This class is used to map a namespace index to a namespace name. The
	 * following entries are fixed.
	 *
	 * 0 -> OpcUaStackCore
	 */
	class DLLEXPORT NumberNamespaceMap
	{
	  public:
		typedef boost::shared_ptr<NumberNamespaceMap> SPtr;
		typedef std::map<uint16_t, std::string> NumberStringMap;

		/**
		 * constructor
		 */
		NumberNamespaceMap(void);
		NumberNamespaceMap(const std::string& namespaceName);

		/**
		 * destructor
		 */
		~NumberNamespaceMap(void);

		/**
		 * This function adds a new namespace entry to the map.
		 *
		 * @parameter[in] namespaceEntry		Namespace entry. The string must have
		 * 										the following format:
		 * 										<NamespaceIndex>:<NamespaceName>
		 *
		 * @return true if successful
		 */
		bool addNamespace(const std::string& namespaceEntry);

		/**
		 * This function results a namespace name for a given namespace index
		 *
		 * @param[in] namespaceIndex			namespace index
		 *
		 * @return results a namesapce name. if the namespace do not exist, the function
		 *         results the following string: namespace_<namespaceIndex>
		 *
		 */
		std::string getNamespaceName(uint16_t namespaceIndex);

		/**
		 * This function checks if the given namespace index exist.
		 *
		 * @param[in] namespaceIndex			namespace index
		 *
		 * @return true if the namespace index exists
		 */
		bool exist(uint16_t namespaceIndex);

	  private:
		NumberStringMap numberStringMap_;		//!< map namespace index to namespace name
	};


}

#endif
