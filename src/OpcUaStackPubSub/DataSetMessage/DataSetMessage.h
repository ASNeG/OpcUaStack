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

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackPubSub_DataSetMessage_h__
#define __OpcUaStackPubSub_DataSetMessage_h__

#include <boost/shared_ptr.hpp>
#include <iostream>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"
#include "OpcUaStackPubSub/DataSetMessage/DataSetMessageType.h"
#include "OpcUaStackPubSub/DataSetMessage/DataSetMessageHeader.h"

namespace OpcUaStackPubSub
{

	class DLLEXPORT DataSetMessage
	: public OpcUaStackCore::JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<DataSetMessage> SPtr;

		DataSetMessage(void);
		virtual ~DataSetMessage(void);

		void messageType(DataSetMessageType messageType);
		DataSetMessageType messageType(void);
		DataSetMessageHeader& dataSetMessageHeader(void);
		void dataSetMessageHeader(DataSetMessageHeader::SPtr& dataSetMessageHeader);
		void sequenceNumber(uint16_t sequenceNumber);
		uint16_t sequenceNumber(void);

		virtual void setFieldEncoding(void) {};
		virtual bool opcUaBinaryEncode(std::ostream& os) const { return false; }
		virtual bool opcUaBinaryDecode(std::istream& is) { return false; }

		void copyTo(DataSetMessage& dataSetMessage);
		bool operator==(const DataSetMessage& other) const;
		bool operator!=(const DataSetMessage& other) const;

		void out(std::ostream& os) const;

		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, OpcUaStackCore::Xmlns& xmlns) { return true; }
		bool xmlEncode(boost::property_tree::ptree& pt, OpcUaStackCore::Xmlns& xmlns) { return true; }
		bool xmlDecode(boost::property_tree::ptree& pt, OpcUaStackCore::Xmlns& xmlns) { return true; }

      protected:
        bool jsonEncodeImpl(boost::property_tree::ptree &pt) const { return false; };
        bool jsonDecodeImpl(const boost::property_tree::ptree &pt) { return false; };

	  private:
		DataSetMessageHeader::SPtr dataSetMessageHeader_;
	};

	class DLLEXPORT DataSetMessageArray
	: public OpcUaStackCore::OpcUaArray<DataSetMessage::SPtr, OpcUaStackCore::SPtrTypeCoder<DataSetMessage> >
	, public OpcUaStackCore::Object
	{
	  public:
		typedef boost::shared_ptr<DataSetMessageArray> SPtr;
	};

}

#endif
