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

#ifndef __OpcUaStackPubSub_PubSubWriterGroupModel_h__
#define __OpcUaStackPubSub_PubSubWriterGroupModel_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

#include "OpcUaStackPubSub/PubSubModel/PubSubGroupModel.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	/**
	 * This class is used to represent the configuration parameters for WriterGroups.
	 */
	class DLLEXPORT PubSubWriterGroupModel
	: public PubSubGroupModel
	{
	  public:
		typedef boost::shared_ptr<PubSubWriterGroupModel> SPtr;
		typedef std::map<OpcUaNodeId, PubSubWriterGroupModel::SPtr> Map;

		/**
		 * constructor
		 */
		PubSubWriterGroupModel(void);

		/**
		 * destructor
		 */
		virtual ~PubSubWriterGroupModel(void);

		/**
		 * setter method for variable writerGroupId
		 *
		 * @param[in] writerGroupId				unique writer group id
		 */
		void writerGroupId(uint16_t writerGroupId);

		/**
		 * getter method for variable writerGroupId
		 *
		 * @return writer group id
		 */
		uint16_t writerGroupId(void);


	  private:
		uint16_t writerGroupId_;			//!< unique identifier for writer group

	};

}

#endif
