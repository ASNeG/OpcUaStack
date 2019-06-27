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

#ifndef __OpcUaStackCore_ComplexDataValue_h__
#define __OpcUaStackCore_ComplexDataValue_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaVariant.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ComplexDataTypes/ComplexDataType.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ComplexDataValue
	: public Object
	, public ExtensionObjectBase
	{
	  public:
		typedef boost::shared_ptr<ComplexDataValue> SPtr;

		ComplexDataValue(void);
		ComplexDataValue(ComplexDataType::SPtr& complexDataType);
		virtual ~ComplexDataValue(void);

		//- ExtensionObjectBase -----------------------------------------------
		virtual ExtensionObjectBase::SPtr factory(void);
		virtual OpcUaNodeId binaryTypeId(void);
		virtual OpcUaNodeId xmlTypeId(void);
		virtual void opcUaBinaryEncode(std::ostream& os) const;
		virtual void opcUaBinaryDecode(std::istream& is);
		virtual bool encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const;
		virtual bool decode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
		virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
		virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
		virtual void out(std::ostream& os);
		//- ExtensionObjectBase -----------------------------------------------

		void copyTo(ComplexDataValue& complexDataValue);
		bool operator==(const ComplexDataValue& complexDataValue) const;
		void complexDataType(ComplexDataType::SPtr& complexDataType);
		int32_t size(void);
		int32_t name2Index(const std::string& name);
		std::string index2Name(uint32_t index);
		OpcUaVariant::SPtr& getValue(const std::string& itemName);
		OpcUaVariant::SPtr& getValue(uint32_t itemIndex);

	  private:
		void clearVariantValueVec(void);
	    void createVariantValueVec(void);

		ComplexDataType::SPtr complexDataType_;
		OpcUaVariant::SPtr tmp_;
		OpcUaVariant::Vec variantVec_;
	};

}

#endif
