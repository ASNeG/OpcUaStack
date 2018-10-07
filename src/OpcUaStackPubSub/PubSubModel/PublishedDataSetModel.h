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

#ifndef __OpcUaStackPubSub_PublishedDataSetModel_h__
#define __OpcUaStackPubSub_PublishedDataSetModel_h__

#include <boost/shared_ptr.hpp>

#include <map>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

#include "OpcUaStackPubSub/PubSubModel/KeyValuePair.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	/**
	 * This class represents the published data set parameters.
	 */
	class DLLEXPORT PublishedDataSetModel
	{
	  public:
		typedef boost::shared_ptr<PublishedDataSetModel> SPtr;
		typedef std::map<OpcUaNodeId, PublishedDataSetModel::SPtr> Map;

		/**
		 * constructor
		 */
		PublishedDataSetModel(void);

		/**
		 * destructor
		 */
		virtual ~PublishedDataSetModel(void);

		/**
		 * setter method for variable name
		 *
		 * @param[in] name					name of the published data set
		 */
		void name(const OpcUaString& name);

		/**
		 * getter method for variable name
		 *
		 * @return name of the published data set
		 */
		OpcUaString& name(void);

	  private:
		OpcUaString name_;					//!< name of published data set

	};

}

#endif
