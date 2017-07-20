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

#ifndef __OpcUaStackCore_OpcUaQulifiedName_h__
#define __OpcUaStackCore_OpcUaQulifiedName_h__

#include <boost/property_tree/ptree.hpp>
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaQualifiedName
	: public Object
	{
	  public:
		typedef boost::shared_ptr<OpcUaQualifiedName> SPtr;

		OpcUaQualifiedName(void);
		OpcUaQualifiedName(const std::string& name, OpcUaInt16 namespaceIndex = 0);
		~OpcUaQualifiedName(void);

		void set(const std::string& name, OpcUaInt16 namespaceIndex = 0);
		void get(std::string& name, OpcUaUInt16& namespaceIndex);
		void namespaceIndex(const OpcUaUInt16& namespaceIndex);
		OpcUaUInt16 namespaceIndex(void);
		void name(const std::string& name);
		void name(const OpcUaString& name);
		OpcUaString& name(void);
		bool fromString(const std::string& qualifiedNameString);
		std::string toString(void);

		OpcUaQualifiedName& operator=(const std::string& name);
		OpcUaQualifiedName& operator=(const OpcUaUInt16& namespaceIndex);
		operator std::string const (void); 
		operator OpcUaUInt16 const (void); 

		void copyTo(OpcUaQualifiedName& qualifiedName);
		bool operator!=(const OpcUaQualifiedName& opcUaQualifiedName) const;
		bool operator==(const OpcUaQualifiedName& opcUaQualifiedName) const;

		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const OpcUaQualifiedName& value) {
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
		OpcUaUInt16 namespaceIndex_;
		OpcUaString name_;
	};

	class OpcUaQualifiedNameArray
	: public OpcUaArray<OpcUaQualifiedName::SPtr, SPtrTypeCoder<OpcUaQualifiedName> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<OpcUaQualifiedNameArray> SPtr;
	};
};

#endif
