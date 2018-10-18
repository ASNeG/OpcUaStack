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

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_NodeInfo_h__
#define __OpcUaStackCore_NodeInfo_h__

#include <boost/shared_ptr.hpp>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include <OpcUaStackServer/Generator/NumberNamespaceMap.h>
#include "OpcUaStackServer/InformationModel/InformationModel.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

/**
 * This function manages node information
 */
class DLLEXPORT NodeInfo
{
  public:
	typedef boost::shared_ptr<NodeInfo> SPtr;

	/**
	 * constructor
	 */
	NodeInfo(void);

	/**
	 * destructor
	 */
	~NodeInfo(void);

	/**
	 * This function sets a new namespace entry
	 *
	 * @param[in] namespaceEntry			Set a new namespace entry. The string must have
	 * 										the following format:
	 * 										<NamespaceIndex>:<NamespaceName>
	 *
	 * @return true if successful
	 */
	bool setNamespaceEntry(const std::string& namespaceEntry);

	/**
	 * Getter function
	 *
	 * @return data type node identifier
	 */
	OpcUaNodeId dataTypeNodeId(void);

	/**
	 * Getter function
	 *
	 * @return opc ua information model
	 */
	InformationModel::SPtr& informationModel(void);

	/**
	 * Getter function
	 *
	 * @return pointer to node
	 */
	BaseNodeClass::SPtr& baseNode(void);

	/**
	 * Getter function
	 *
	 * @return namespace name
	 */
	std::string& namespaceName(void);

	/**
	 * Getter function
	 *
	 * @return class name
	 */
	std::string& className(void);

	/**
	 * This function inits the node info class
	 *
	 * @parameter[in] dataTypeNodeId			opc ua data type node identifier
	 * @parameter[in] informationModel			opc ua information model
	 */
	bool init(const OpcUaNodeId& dataTypeNodeId, InformationModel::SPtr& informationModel);

  private:
	NumberNamespaceMap numberNamespaceMap_;		//!< number to namespace map
	OpcUaNodeId dataTypeNodeId_;				//!< data type node identifier
	InformationModel::SPtr informationModel_;	//!< opc ua information model

	BaseNodeClass::SPtr baseNode_;				//!< pointer to node
	std::string namespaceName_;					//!< namespace name
	std::string className_;						//!< name of class
};

}

#endif
