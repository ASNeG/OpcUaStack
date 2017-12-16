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

#ifndef __OpcUaStackPubSub_NetworkMessageProcessor_h__
#define __OpcUaStackPubSub_NetworkMessageProcessor_h__

#include "OpcUaStackPubSub/DataSet/DataSetReaderIf.h"
#include "OpcUaStackPubSub/Network/NetworkReceiverIf.h"
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackPubSub
{

	class DLLEXPORT NetworkMessageProcessor
	: public NetworkReceiverIf
	{
	  public:
		static const uint32_t TimeoutHandleInterval;

		NetworkMessageProcessor(void);
		~NetworkMessageProcessor(void);

		bool startup(void);
		bool shutdown(void);

		bool deregisterDataSetReaderIf(const DataSetReaderIf::SPtr& reader);
		virtual bool registerDataSetReaderIf(const DataSetReaderIf::SPtr& reader);
		virtual bool receive(const NetworkMessage& message);

	  protected:
		virtual bool timeoutHandle();

	  private:
		struct DataSetReaderKey
		{
			DataSetReaderKey();
			DataSetReaderKey(const DataSetReaderIf& readerIf);

			bool operator< (const DataSetReaderKey& other) const;

			uint16_t writerId_;
			OpcUaVariant publisherId_;

		};

		typedef std::map<DataSetReaderKey, DataSetReaderIf::Set> DataSetReaderIfTree;

		DataSetReaderIfTree dataSetReaderIfTree_;

		IOThread::SPtr ioThread_;
		SlotTimerElement::SPtr slotTimerElement_;
	};

}

#endif

