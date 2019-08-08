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

#ifndef __OpcUaStackCore_ConfigJson_h__
#define __OpcUaStackCore_ConfigJson_h__

#include <boost/property_tree/ptree.hpp>
#include <string>
#include <set>
#include <vector>
#include "OpcUaStackCore/Base/ConfigIf.h"

namespace OpcUaStackCore
{

	/**
	 * This class is used to read and write an json based file. The structure
	 * of the json document is stored internally in a boost property tree.
	 *
	 * Optionally, a configuration class can be created.
	 */
	class DLLEXPORT ConfigJson
	{
	  public:
		/**
		 * constructor
		 */
		ConfigJson(void);

		/**
		 * destructor
		 */
		~ConfigJson(void);

		/**
		 * clear all data variables in class
		 */
		void clear(void);

		/*
		 * This method returns the property tree with the structure of the json
		 * document. Before that, the read function must be executed.
		 *
		 * @return property tree with the structure of the json document
		 */
		boost::property_tree::ptree& ptree(void);

		/**
		 * This method is used to set the property tree. Executing the write function
		 * transfers the property tree to an json document.
		 *
		 * @param[in] ptree 			property tree with the structure of the json document
		 */
		void ptree(boost::property_tree::ptree& ptree);

		/**
		 * This function transfers the property tree to an json document and saves
		 * this json document in a file. If an error occurs during the execution of
		 * the function, an error text can be determined with the errorMessage
		 * function.
		 *
		 * @param[in] configFileName	name of the file
		 *
		 * @return true if successful
		 */
		bool write(const std::string& configFileName);

		/**
		 * This function transfers the property tree to an json document and saves
		 * this json document in a output stream. If an error occurs during the
		 * execution of the function, an error text can be determined with the
		 * errorMessage function.
		 *
		 * @param[in] os				output stream
		 *
		 * @return true if successful
		 */
		bool write(std::ostream& os);

		/**
		 * This function reads a json document from a file and transfers the json document
		 * in a property tree. The property tree can be requested with the function ptree.
		 * If an error occurs during the execution of the function, an error text can be
		 * determined with the errorMessage function.
		 *
		 * @param[in] configFileName	name of the file
		 *
		 * @return true if successful
		 */
		bool read(const std::string& configFileName);

		/**
		 * This function reads a json document from a input stream and transfers the json document
		 * in a property tree. The property tree can be requested with the function ptree. If an
		 * error occurs during the execution of the function, an error text can be determined
		 * with the errorMessage function.
		 *
		 * @param[in] is				input stream
		 *
		 * @return true if successful
		 */
		bool read(std::istream& is);

		/**
		 * This function reads a json document from a input stream and transfers the json document
		 * in a property tree. The property tree can be requested with the function ptree. If an
		 * error occurs during the execution of the function, an error text can be determined
		 * with the errorMessage function.
		 *
		 * @param[in] is				input stream
		 *
		 * @return true if successful
		 */
		bool parse(std::istream& is);

		/**
		 * This function reads a json document from a input stream and transfers the json document
		 * in a property tree. The property tree can be requested with the function ptree. If an
		 * error occurs during the execution of the function, an error text can be determined
		 * with the errorMessage function.
		 *
		 * @param[in] configFileName	name of the file
		 * @param[in] writeConfig		if true, then the property tree is stored in a configuration
		 * 								object. The configuration object (class Config) is a static
		 * 								instance.
		 *
		 * @return true if successful
		 */
		bool parse(const std::string& configFileName, bool writeToConfig = false);

		/**
		 * This function reads a json document from a input stream and transfers the json document
		 * in a property tree. The property tree can be requested with the function ptree. If an
		 * error occurs during the execution of the function, an error text can be determined
		 * with the errorMessage function.
		 *
		 * @param[in] configFileName	name of the file
		 * @param[in] configIf			if not null, then the property tree is passed to a configuration
		 * 								interface.
		 *
		 * @return true if successful
		 */
		bool parse(const std::string& configFileName, ConfigIf* configIf);

		/**
		 * This functions returns an error message.
		 *
		 * @return error message
		 */
		std::string errorMessage(void);

		/**
		 * This function is used to store the property tree in a configuration object. The configuration
		 * object (class Config) is a static instance.
		 *
		 */
		void writeToConfig(void);

		/**
		 * This function is used to pass the property tree to a configuration interface.
		 *
		 * @param[in] configIf			if not null, then the property tree is passed to a configuration
		 * 								interface.
		 */
		void writeToConfig(ConfigIf* configIf);

		/**
		 * This function searches for elements with a given name and returns the property
		 * trees in a vector.
		 *
		 * @param[in] elementName		name of the element
		 * @param[out] ptrees			property trees
		 */
		void find(const std::string& elementName, std::vector<boost::property_tree::ptree>& ptrees);

		/**
		 * This function is used to create a set of all element names in the given property tree.
		 *
		 * @param[in] ptree				property tree
		 * @param[out] elementNameSet	set of all element names in the property tree
		 */
		static void createElementNameSet(boost::property_tree::ptree& ptree, std::set<std::string>& elementNameSet);

	  private:
		void find(
			const std::string& elementName,
			boost::property_tree::ptree& ptree,
			std::vector<boost::property_tree::ptree>& ptrees
		);

		std::string configFileName_;			//!< name of the configuration file
		boost::property_tree::ptree ptree_;		//! property tree
		std::string errorMessage_;				//! actual error message
	};

}

#endif
