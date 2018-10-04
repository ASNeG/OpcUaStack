/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackPubSub_PubSubConnectionModel_h__
#define __OpcUaStackPubSub_PubSubConnectionModel_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

#include "OpcUaStackPubSub/PubSubModel/PubSubState.h"
#include "OpcUaStackPubSub/PubSubModel/PubSubWriterGroupModel.h"
#include "OpcUaStackPubSub/PubSubModel/PubSubReaderGroupModel.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	/**
	 * This class is used to represent the configuration parameters for PubSubConnections.
	 */
	class DLLEXPORT PubSubConnectionModel
	: public PubSubState
	{
	  public:
		typedef boost::shared_ptr<PubSubConnectionModel> SPtr;

		/**
		 * constructor
		 */
		PubSubConnectionModel(void);

		/**
		 * destructor
		 */
		virtual ~PubSubConnectionModel(void);

		/**
		 * This method is used to add a new writer group to a connection
		 *
		 * @param[in] configuration			Configuration parameters for the writer group.
		 * @param[out] groupId				The NodeId of the new writer group
		 * @return opc ua status code
		 */
		OpcUaStatusCode addWriterGroup(
			PubSubWriterGroupModel::SPtr& configuration,
			OpcUaNodeId& groupId
		);

		/**
		 * This method is used to add a new reader group to a connection
		 *
		 * @param[in] configuration			Configuration parameters for the reader group.
		 * @param[out] groupId				The NodeId of the new reader group.
		 * @return opc ua status code
		 */
		OpcUaStatusCode addReaderGroup(
			PubSubReaderGroupModel::SPtr& configuration,
			OpcUaNodeId& groupId
		);

		/**
		 * This method is used to remove an existing writer group or reader group
		 *
		 * @param[out] groupId				The NodeId of the writer group or reader group to delete.
		 * @return opc ua status code
		 */
		OpcUaStatusCode removeGroup(
			OpcUaNodeId& groupId
		);

	  private:

	};

}

#endif
