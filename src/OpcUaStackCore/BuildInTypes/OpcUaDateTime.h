/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_OpcUaDateTime_h__
#define __OpcUaStackCore_OpcUaDateTime_h__

#include "boost/property_tree/ptree.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaDateTime
	: public JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<OpcUaDateTime> SPtr;

		OpcUaDateTime(void);
		OpcUaDateTime(const OpcUaDateTime& value);
		OpcUaDateTime(const boost::posix_time::ptime& ptime);
		OpcUaDateTime(const std::string& dateTimeString);
		~OpcUaDateTime(void);

		void dateTime(const boost::posix_time::ptime& dateTime);
		OpcUaUInt64 rawDateTime(void) const;
		boost::posix_time::ptime dateTime(void) const;
		bool exist(void) const;

		OpcUaDateTime& operator=(const OpcUaUInt64& dateTime); 
		bool operator!=(const OpcUaDateTime& dateTime) const;
		bool operator==(const OpcUaDateTime& dateTime) const;
		operator OpcUaUInt64 const (void); 
		bool fromISOString(const std::string& dateTimeString);
		std::string toISOString(void) const;
		bool fromISO8601(const std::string& dateTimeString);
		std::string toISO8601(void) const;

		void copyTo(OpcUaDateTime& opcUaDataTime);

		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const OpcUaDateTime& value) {
			value.out(os);
			return os;
		}
		bool isNull(void) const override;

        bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);

      protected:
        bool jsonEncodeImpl(boost::property_tree::ptree &pt) const override;
        bool jsonDecodeImpl(const boost::property_tree::ptree &pt) override;

	  private:
		static boost::posix_time::ptime nullTime_;
		OpcUaUInt64 dateTime_;
	};

	class DLLEXPORT OpcUaDateTimeArray
	: public OpcUaArray<OpcUaDateTime>
	{
	  public:
		typedef boost::shared_ptr<OpcUaDateTimeArray> SPtr;
	};
	
};

#endif
