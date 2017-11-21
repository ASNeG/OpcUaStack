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

#ifndef __OpcUaStackPubSub_NetworkMessageCreator_h__
#define __OpcUaStackPubSub_NetworkMessageCreator_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackPubSub/DataSet/DataSetWriterIf.h"
#include "OpcUaStackPubSub/Network/NetworkSenderIf.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{
	class DLLEXPORT NetworkMessageCreator
	{
	  public:
		typedef std::list<DataSetWriterIf::SPtr> WriterCollection;

		NetworkMessageCreator(void);
		virtual ~NetworkMessageCreator(void);

		void ioThread(IOThread::SPtr& ioThread);
		void publishInterval(uint32_t publishInterval);

		bool startup(void);
		bool shutdown(void);

		bool deregisterDataSetWriterIf(uint32_t writerId);
		bool registerDataSetWriterIf(const DataSetWriterIf::SPtr& writerIf);

		void networkSenderIf(const NetworkSenderIf::SPtr& senderIf);
		NetworkSenderIf::SPtr networkSenderIf();

	  protected:
		virtual bool publish();

	  private:
		IOThread::SPtr ioThread_;
		uint32_t publishInterval_;
		SlotTimerElement::SPtr slotTimerElement_;

		WriterCollection dataSetWriters_;
		NetworkSenderIf::SPtr networkSender_;
	};
}

#endif
