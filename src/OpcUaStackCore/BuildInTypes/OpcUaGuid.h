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

#ifndef __OpcUaStackCore_OpcUaGuid_h__
#define __OpcUaStackCore_OpcUaGuid_h__

#include <boost/property_tree/ptree.hpp>
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

#include <stdint.h>

namespace OpcUaStackCore 
{

	class DLLEXPORT OpcUaGuid
	: public Object
	{
	  public:
		typedef boost::shared_ptr<OpcUaGuid> SPtr;

	    OpcUaGuid(void);
	    OpcUaGuid(const std::string& string);
		~OpcUaGuid(void);

		void data1(OpcUaUInt32 value);
		OpcUaUInt32 data1(void) const;
		void data2(OpcUaUInt16 value);
		OpcUaUInt16 data2(void) const;
		void data3(OpcUaUInt16 value);
		OpcUaUInt16 data3(void) const;
		void data4(OpcUaByte value[8]);
		OpcUaByte* data4(void) const;

		bool value(const std::string& string);
		std::string value(void);
		OpcUaGuid& operator=(const std::string& string); 
		operator std::string const (void); 

		void copyTo(OpcUaGuid& opcUaGuid);
		bool operator<(const OpcUaGuid& opcUaGuid) const;

		bool operator!=(const OpcUaGuid& opcUaGuid) const;
		bool operator==(const OpcUaGuid& opcUaGuid) const;

		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const OpcUaGuid& value) {
			value.out(os);
			return os;
		}

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool jsonEncode(boost::property_tree::ptree& pt, const std::string& element);
		bool jsonEncode(boost::property_tree::ptree& pt);
		bool jsonDecode(const boost::property_tree::ptree& pt, const std::string& element);
		bool jsonDecode(const boost::property_tree::ptree& pt);

	  private:
		OpcUaGuid(const OpcUaGuid& value);

		OpcUaUInt32 data1_;
		OpcUaUInt16 data2_;
		OpcUaUInt16 data3_;
		OpcUaByte data4_[8];
	};

	class OpcUaGuidArray
	: public OpcUaArray<OpcUaGuid::SPtr, SPtrTypeCoder<OpcUaGuid> >
	{
	  public:
		typedef boost::shared_ptr<OpcUaGuidArray> SPtr;
	};

}

#endif
