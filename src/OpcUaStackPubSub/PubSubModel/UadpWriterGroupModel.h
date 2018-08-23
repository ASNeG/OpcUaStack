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

#ifndef __OpcUaStackBroker_UadpWriterGroupModel_h__
#define __OpcUaStackBroker_UadpWriterGroupModel_h__

#include <boost/shared_ptr.hpp>
#include <map>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackPubSub/PubSubModel/PubSubWriterGroupModel.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	class DLLEXPORT UadpWriterGroupModel
	: public PubSubWriterGroupModel
	{
	  public:
		typedef boost::shared_ptr<UadpWriterGroupModel> SPtr;
		typedef std::map<OpcUaNodeId, UadpWriterGroupModel::SPtr> Map;

		UadpWriterGroupModel(void);
		virtual ~UadpWriterGroupModel(void);

		virtual void startup(void);
		virtual void shutdown(void);

		void maxNetworkMessageSize(OpcUaInt16 maxNetworkMessageSize);
		OpcUaInt16 maxNetworkMessageSize(void);
		void publishingOffset(Duration publishingOffset);
		Duration publishingOffset(void);
		void samplingOffset(Duration samplingOffset);
		Duration samplingOffset(void);

	  private:
		OpcUaUInt16 maxNetworkMessageSize_;
		Duration publishingOffset_;
		Duration samplingOffset_;
	};

}

#endif

