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

#ifndef __OpcUaStackPubSub_DataSetWriterModel_h__
#define __OpcUaStackPubSub_DataSetWriterModel_h__

#include <boost/shared_ptr.hpp>

#include <map>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

#include "OpcUaStackPubSub/PubSubModel/PubSubState.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	/**
	 * todo
	 */
	class DLLEXPORT DataSetWriterModel
	: public PubSubState
	{
	  public:
		typedef boost::shared_ptr<DataSetWriterModel> SPtr;
		typedef std::map<OpcUaNodeId, DataSetWriterModel::SPtr> Map;

		/**
		 * constructor
		 */
		DataSetWriterModel(void);

		/**
		 * destructor
		 */
		virtual ~DataSetWriterModel(void);
	};

}

#endif
