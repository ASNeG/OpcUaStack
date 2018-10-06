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

#ifndef __OpcUaStackPubSub_PubSubGroupModel_h__
#define __OpcUaStackPubSub_PubSubGroupModel_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

#include "OpcUaStackPubSub/PubSubModel/PubSubState.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	/**
	 * This class is used to represent the configuration parameters for WriterGroups.
	 */
	class DLLEXPORT PubSubGroupModel
	: public PubSubState
	{
	  public:
		typedef boost::shared_ptr<PubSubGroupModel> SPtr;
		typedef std::map<OpcUaNodeId, PubSubGroupModel::SPtr> Map;

		/**
		 * constructor
		 */
		PubSubGroupModel(void);

		/**
		 * destructor
		 */
		virtual ~PubSubGroupModel(void);

		/**
		 * setter method for variable name
		 *
		 * @param[in] name					name of the writer group
		 */
		void name(const OpcUaString& name);

		/**
		 * getter method for variable name
		 *
		 * @return writer group name
		 */
		OpcUaString& name(void);


	  private:
		OpcUaString name_;					//!< name of writer group
	};

}

#endif
