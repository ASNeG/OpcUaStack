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

#ifndef __OpcUaStackCore_OpcUaString_h__
#define __OpcUaStackCore_OpcUaString_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include <string>
#include <stdint.h>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"
#include <boost/property_tree/ptree.hpp>

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaString
	: public Object
	{
	  public:
		typedef boost::shared_ptr<OpcUaString> SPtr;

	    OpcUaString(void);
	    OpcUaString(const std::string& value);
		~OpcUaString(void);

		std::string value(void) const;
		std::string toStdString(void) const;
		void value(const std::string& value);
		uint32_t size(void) const;
		void reset(void);
		bool exist(void) const;

		OpcUaString& operator=(const std::string& string); 
		operator std::string const (void); 

		void copyTo(OpcUaString& opcUaString);
		bool operator<(const OpcUaString& opcUaString) const;
		bool operator!=(const OpcUaString& opcUaString) const;
		bool operator==(const OpcUaString& opcUaString) const;

		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const OpcUaString& value) {
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
		bool exist_;
		std::string value_; 
	};

	class OpcUaStringArray
	: public OpcUaArray<OpcUaString::SPtr, SPtrTypeCoder<OpcUaString> >
	{
	  public:
		typedef boost::shared_ptr<OpcUaStringArray> SPtr;
	};

}

#endif
