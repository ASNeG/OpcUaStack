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

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaStackPubSub_DataSetReaderIf_h__
#define __OpcUaStackPubSub_DataSetReaderIf_h__

#include <set>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaVariant.h"
#include "OpcUaStackPubSub/DataSetMessage/DataSetMessage.h"

namespace OpcUaStackPubSub
{

	class DLLEXPORT DataSetReaderIf
	{
	  public:
		typedef boost::shared_ptr<DataSetReaderIf> SPtr;
		typedef std::set<DataSetReaderIf::SPtr> Set;

		DataSetReaderIf(void);
		virtual ~DataSetReaderIf(void);

		void writerId(uint32_t readerId);
		uint32_t writerId(void) const;

		void publisherId(OpcUaVariant::SPtr publisherId);
		OpcUaVariant::SPtr publisherId() const;

		void messageReceiveTimeout(uint32_t messageReceiveTimeout);
		uint32_t messageReceiveTimeout() const;

		virtual bool receiveDataSetMessage(const DataSetMessage::SPtr& dataSetMessage) = 0;
		virtual bool checkTimeout(uint32_t timeoutInterval) = 0;

	  private:
		uint32_t writerId_;
		OpcUaVariant::SPtr publisherId_;
		uint32_t messageReceiveTimeout_;
	};

}

#endif
