/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_BaseClass_h__
#define __OpcUaStackCore_BaseClass_h__

#include "OpcUaStackCore/Base/Object.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

#include <vector>

namespace OpcUaStackCore
{

	class DLLEXPORT BaseClass
	: public OpcUaStackCore::Object
	{
	  public:
		using SPtr = boost::shared_ptr<BaseClass>;
		using Vec = std::vector<SPtr>;

		BaseClass(void)
		: OpcUaStackCore::Object()
		{}
		virtual ~BaseClass(void)
		{}

		void copyTo(BaseClass& baseClass) {}
		void out(std::ostream& os) {}
		bool opcUaBinaryEncode(std::ostream& os) const { return false; }
		bool opcUaBinaryDecode(std::istream& is) { return false; }
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return false; }
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return false; }
		bool jsonEncode(boost::property_tree::ptree& pt, const std::string& element) { return false; }
		bool jsonEncode(boost::property_tree::ptree& pt) { return false; }
		bool jsonDecode(const boost::property_tree::ptree& pt, const std::string& element) { return false; }
		bool jsonDecode(const boost::property_tree::ptree& pt) { return false; }
	};

	class DLLEXPORT BaseClassArray
	: public OpcUaArray<BaseClass::SPtr, SPtrTypeCoder<BaseClass> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<BaseClassArray> SPtr;
	};



}

#endif
