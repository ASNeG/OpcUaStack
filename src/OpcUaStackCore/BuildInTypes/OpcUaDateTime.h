/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_OpcUaDateTime_h__
#define __OpcUaStackCore_OpcUaDateTime_h__

#include "boost/property_tree/ptree.hpp"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/Base/os.h"
#include "boost/date_time/posix_time/posix_time.hpp"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaDateTime
	{
	  public:
		typedef boost::shared_ptr<OpcUaDateTime> SPtr;

		OpcUaDateTime(void);
		OpcUaDateTime(const boost::posix_time::ptime& ptime);
		~OpcUaDateTime(void);

		void dateTime(const boost::posix_time::ptime& dateTime);
		boost::posix_time::ptime dateTime(void) const;
		bool exist(void) const;

		OpcUaDateTime& operator=(const OpcUaUInt64& dateTime); 
		bool operator==(const OpcUaDateTime& dateTime) const;
		operator OpcUaUInt64 const (void); 
		bool fromISOString(const std::string& dateTimeString);
		std::string toISOString(void);

		void copyTo(OpcUaDateTime& opcUaDataTime);

		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const OpcUaDateTime& value) {
			value.out(os);
			return os;
		}

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		bool encode(boost::property_tree::ptree& pt) const;
		bool decode(boost::property_tree::ptree& pt);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);

	  private:
		static boost::posix_time::ptime nullTime_;
		OpcUaUInt64 dateTime_;
	};

	class OpcUaDateTimeArray
	: public OpcUaArray<OpcUaDateTime>
	{
	  public:
		typedef boost::shared_ptr<OpcUaDateTimeArray> SPtr;
	};
	
};

#endif
