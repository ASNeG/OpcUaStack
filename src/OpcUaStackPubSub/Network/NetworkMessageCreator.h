/*
   Copyright 2017-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackPubSub_NetworkMessageCreator_h__
#define __OpcUaStackPubSub_NetworkMessageCreator_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackPubSub/DataSet/DataSetWriterIf.h"
#include "OpcUaStackPubSub/Network/NetworkSenderIf.h"

namespace OpcUaStackPubSub
{
	class DLLEXPORT NetworkMessageCreator
	{
	  public:

		NetworkMessageCreator(void);
		virtual ~NetworkMessageCreator(void);

		void ioThread(OpcUaStackCore::IOThread::SPtr& ioThread);

		void publishInterval(OpcUaStackCore::OpcUaUInt32 publishInterval);
		OpcUaStackCore::OpcUaUInt32 publishInterval() const;

		void keepAliveTime(OpcUaStackCore::OpcUaUInt32 keepAliveTime);
		OpcUaStackCore::OpcUaUInt32 keepAliveTime() const;

		bool startup(void);
		bool shutdown(void);

		bool deregisterDataSetWriterIf(uint32_t writerId);
		bool registerDataSetWriterIf(const DataSetWriterIf::SPtr& writerIf);
		DataSetWriterIf::Map dataSetWriterIfMap() const;


		void networkSenderIf(const NetworkSenderIf::SPtr& senderIf);
		NetworkSenderIf::SPtr networkSenderIf();

		void publisherIdEnabled(bool publisherIdEnabled);
		bool publisherIdEnabled() const;

		void dataSetWriterIdEnabled(bool dataSetWriterIdEnabled);
		bool dataSetWriterIdEnabled() const;

		void dataSetArrayEnabled(bool dataSetArrayEnabled);
		bool dataSetArrayEnabled() const;

		void timestampEnabled(bool timestampEnabled);
		bool timestampEnabled() const;

		void picosecondsEnabled(bool picosecondsEnabled);
		bool picosecondsEnabled() const;

		void dataSetClassIdEnabled(bool dataSetClassIdEnabled);
		bool dataSetClassIdEnabled() const;

		void promotedFieldsEnabled(bool promotedFieldsEabled);
		bool promotedFieldsEnabled() const;

		void publisherId(OpcUaStackCore::OpcUaVariant::SPtr publisherId);
		OpcUaStackCore::OpcUaVariant::SPtr publisherId() const;
	  protected:
		virtual bool publish();

	  private:
		OpcUaStackCore::IOThread::SPtr ioThread_;
		OpcUaStackCore::OpcUaUInt32 publishInterval_;
		OpcUaStackCore::OpcUaUInt32 keepAliveTime_;
		OpcUaStackCore::SlotTimerElement::SPtr slotTimerElement_;



		// Content Flags
		bool publisherIdEnabled_;
		bool dataSetWriterIdEnabled_;
		bool dataSetArrayEnabled_;
		bool timestampEnabled_;
		bool picosecondsEnabled_;
		bool dataSetClassIdEnabled_;
		bool promotedFieldsEnabled_;

		OpcUaStackCore::OpcUaVariant::SPtr publisherId_;
		DataSetWriterIf::Map dataSetWriterIfMap_;
		NetworkSenderIf::SPtr networkSender_;
	};
}

#endif
