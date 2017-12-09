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

#ifndef __OpcUaStackPubSub_NetworkMessageHeader_h__
#define __OpcUaStackPubSub_NetworkMessageHeader_h__

#include <boost/shared_ptr.hpp>
#include <iostream>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaVariant.h"
#include "OpcUaStackPubSub/DataSetMessage/DataSetPayloadHeader.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{
	enum PublisherIdType
	{
		PublisherIdType_Byte = 0,
		PublisherIdType_UInt16 = 1,
		PublisherIdType_UInt32 = 2,
		PublisherIdType_UInt64 = 3,
		PublisherIdType_Guid = 4,
		PublisherIdType_String = 5,
	};

	enum NetworkMessageType
	{
		NetworkMessageType_DataSetMessage = 0,
		NetworkMessageType_Chunk = 1,
		NetworkMessageType_DiscoveryRequest = 2,
		NetworkMessageType_DiscoveryResponse = 3,
		NetworkMessageType_MimeType = 4,
	};

	class DLLEXPORT NetworkMessageHeader
	{
	  public:
		typedef boost::shared_ptr<NetworkMessageHeader> SPtr;

		NetworkMessageHeader(void);
		~NetworkMessageHeader(void);

		void UADPVersion(OpcUaByte UADPVersion);
		OpcUaByte UADPVersion() const;

		void publisherIdEnabled(bool publisherIdEnabled);
		bool publisherIdEnabled() const;

		void dataSetArrayEnabled(bool dataSetArrayEnabled);
		bool dataSetArrayEnabled() const;

		void dataSetWriterIdEnabled(bool dataSetWriterIdEnabled);
		bool dataSetWriterIdEnabled() const;

		void extendedFlags1Enabled(bool extendedFlags1Enabled);
		bool extendedFlags1Enabled() const;

		void publisherIdType(PublisherIdType type);
		PublisherIdType publisherIdType() const;

		void dataSetClassIdEnabled(bool dataSetClassIdEnabled);
		bool dataSetClassIdEnabled() const;

		void securityEnabled(bool securityEnabled);
		bool securityEnabled() const;

		void timestampEnabled(bool timestampEnabled);
		bool timestampEnabled() const;

		void picoSecondsEnabled(bool picosecondsEnabled);
		bool picoSecondsEnabled() const;

		void extendedFlags2Enabled(bool extendedFlags2Enabled);
		bool extendedFlags2Enabled() const;

		void networkMessageType(NetworkMessageType type);
		NetworkMessageType networkMessageType() const;

		void promotedFieldsEnabled(bool promotedFieldsEnabled);
		bool promotedFieldsEnabled() const;

		void dataSetClassId(OpcUaGuid::SPtr dataSetClassId);
		OpcUaGuid::SPtr dataSetClassId() const;

		void publisherId(OpcUaVariant::SPtr publisherId);
		OpcUaVariant::SPtr publisherId() const;

		void dataSetPayloadHeader(DataSetPayloadHeader::SPtr header);
		DataSetPayloadHeader::SPtr dataSetPayloadHeader() const;

		void timestamp(OpcUaDateTime timestamp);
		OpcUaDateTime timestamp() const;

		void picoSeconds(OpcUaInt16 picoSeconds);
		OpcUaInt16 picoSeconds() const;

		void promotedFields(OpcUaVariantArray::SPtr promotedFields);
		OpcUaVariantArray::SPtr promotedFields() const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		bool operator==(const NetworkMessageHeader& other) const;

	  private:
		OpcUaByte UADPVersion_;
		bool publisherIdEnabled_;
		bool dataSetArrayEnabled_;
		bool dataSetWriterIdEnabled_;
		bool extendedFlags1Enabled_;
		PublisherIdType publisherIdType_;
		bool dataSetClassIdEnabled_;
		bool securityEnabled_;
		bool timestampEnabled_;
		bool picoSecondsEnabled_;
		bool extendedFlags2Enabled_;
		NetworkMessageType networkMessageType_;
		bool promotedFieldsEnabled_;

		OpcUaVariant::SPtr publisherId_;
		OpcUaGuid::SPtr dataSetClassId_;
		DataSetPayloadHeader::SPtr dataSetPayloadHeader_;
		OpcUaDateTime timestamp_;
		OpcUaInt16 picoSeconds_;

		OpcUaVariantArray::SPtr promotedFields_;
	};

}

#endif
