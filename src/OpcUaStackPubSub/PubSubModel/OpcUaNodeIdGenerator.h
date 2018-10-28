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

#ifndef __OpcUaStackPubSub_OpcUaNodeIdGenerator_h__
#define __OpcUaStackPubSub_OpcUaNodeIdGenerator_h__

#include <boost/shared_ptr.hpp>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"


using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	/**
	 * This class is used to generate an unique node identifier
	 */
	class DLLEXPORT OpcUaNodeIdGenerator
	{
	  public:
		typedef boost::shared_ptr<OpcUaNodeIdGenerator> SPtr;

		/**
		 * constructor
		 */
		OpcUaNodeIdGenerator(void);

		/**
		 * destructor
		 */
		~OpcUaNodeIdGenerator(void);

		/**
		 * This method is used to create an instance of class OpcUaNodeIdGenerator
		 *
		 * @return instance off class OpcUaNodeIdGenerator
		 */
		static OpcUaNodeIdGenerator* instance(void);

		/**
		 * This method is used to create a new node identifier
		 *
		 * @parameter[out] nodeId New generated node identifier
		 */
		void createNodeNodeId(
			OpcUaNodeId& nodeId
		);

	  private:
		static OpcUaNodeIdGenerator* instance_;		//!< single instance of class OpcUaNodeIdGenerator
		OpcUaNodeId nodeId_;						//!< actual node identifier
	};

}

#endif
