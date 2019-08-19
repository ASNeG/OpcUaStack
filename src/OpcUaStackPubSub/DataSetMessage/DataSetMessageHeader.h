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

#ifndef __OpcUaStackPubSub_DataSetMessageHeader_h__
#define __OpcUaStackPubSub_DataSetMessageHeader_h__

#include <boost/shared_ptr.hpp>
#include <iostream>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackPubSub/DataSetMessage/DataSetMessageType.h"
#include "OpcUaStackPubSub/DataSetMessage/FieldEncoding.h"

namespace OpcUaStackPubSub
{

	class DLLEXPORT DataSetMessageHeader
	: public OpcUaStackCore::JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<DataSetMessageHeader> SPtr;

		DataSetMessageHeader(void);
		~DataSetMessageHeader(void);

		void disableAll(void);
		void fieldEncoding(FieldEncoding fieldEncoding);
		FieldEncoding fieldEncoding(void);
		void dataSetMessageSequenceNumberEnabled(bool enabled);
		bool dataSetMessageSequenceNumberEnabled(void);
		void timestampEnabled(bool enabled);
		bool timestampEnabled(void);
		void statusEnabled(bool enabled);
		bool statusEnabled(void);
		bool configurationVersionMajorVersionEnabled(void);
		void configurationVersionMajorVersionEnabled(bool enabled);
		bool configurationVersionMinorVersionEnabled(void);
		void configurationVersionMinorVersionEnabled(bool enabled);
		void dataSetFlag2Enabled(bool dataSetFlag2Enabled);
		bool dataSetFlag2Enabled(void);
		void messageType(DataSetMessageType messageType);
		DataSetMessageType messageType(void);
		void picoSecondsEnabled(bool enabled);
		bool picoSecondsEnabled(void);
		void dataMessageSequenceNumber(OpcUaStackCore::OpcUaUInt16 dataMessageSequenceNumber);
		OpcUaStackCore::OpcUaUInt16 dataMessageSequenceNumber(void);
		void timestamp(OpcUaStackCore::OpcUaDateTime timestamp);
		OpcUaStackCore::OpcUaDateTime timestamp(void);
		void picoSeconds(OpcUaStackCore::OpcUaUInt16 picoSeconds);
		OpcUaStackCore::OpcUaUInt16 picoSeconds(void);
		void statusCode(OpcUaStackCore::OpcUaUInt16 statusCode);
		OpcUaStackCore::OpcUaUInt16 statusCode(void);
		void configurationVersionMajorVersion(OpcUaStackCore::OpcUaUInt32 configurationVersionMajorVersion);
		OpcUaStackCore::OpcUaUInt32 configurationVersionMajorVersion(void);
		void configurationVersionMinorVersion(OpcUaStackCore::OpcUaUInt32 configurationVersionMinorVersion);
		OpcUaStackCore::OpcUaUInt32 configurationVersionMinorVersion(void);

		void copyTo(DataSetMessageHeader& dataSetMessageHeader);
		bool operator==(const DataSetMessageHeader& other) const;
		void out(std::ostream& os) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, OpcUaStackCore::Xmlns& xmlns) { return false; }
		bool xmlEncode(boost::property_tree::ptree& pt, OpcUaStackCore::Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, OpcUaStackCore::Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, OpcUaStackCore::Xmlns& xmlns) { return false; }

	  protected:
	    bool jsonEncodeImpl(boost::property_tree::ptree &pt) const { return false; };
	    bool jsonDecodeImpl(const boost::property_tree::ptree &pt) { return false; };

	  private:
		FieldEncoding fieldEncoding_;
		bool dataSetMessageSequenceNumberEnabled_;
		bool timestampEnabled_;
		bool statusEnabled_;
		bool configurationVersionMajorVersionEnabled_;
		bool configurationVersionMinorVersionEnabled_;
		bool dataSetFlag2Enabled_;
		DataSetMessageType messageType_;
		bool picoSecondsEnabled_;

		OpcUaStackCore::OpcUaUInt16 dataMessageSequenceNumber_;
		OpcUaStackCore::OpcUaDateTime timestamp_;
		OpcUaStackCore::OpcUaUInt16 picoSeconds_;
		OpcUaStackCore::OpcUaUInt16 statusCode_;
		OpcUaStackCore::OpcUaUInt32 configurationVersionMajorVersion_;
		OpcUaStackCore::OpcUaUInt32 configurationVersionMinorVersion_;

	};

	class DLLEXPORT DataSetMessageHeaderArray
	: public OpcUaStackCore::OpcUaArray<DataSetMessageHeader::SPtr, OpcUaStackCore::SPtrTypeCoder<DataSetMessageHeader> >
	, public OpcUaStackCore::Object
	{
	  public:
		typedef boost::shared_ptr<DataSetMessageHeaderArray> SPtr;
	};

}

#endif
