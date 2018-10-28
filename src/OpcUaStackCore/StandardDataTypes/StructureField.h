/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_StructureField_h__
#define __OpcUaStackCore_StructureField_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/EnumValueType.h"

namespace OpcUaStackCore
{

	class DLLEXPORT StructureField
	: public ExtensionObjectBase
	{
	  public:
		typedef boost::shared_ptr<StructureField> SPtr;
		typedef std::vector<StructureField::SPtr> Vec;

		StructureField(void);
		virtual ~StructureField(void);

		void name(OpcUaString& name);
		OpcUaString& name(void);
		void description(OpcUaLocalizedText& description);
		OpcUaLocalizedText& description(void);
		void dataType(OpcUaNodeId& dataType);
		OpcUaNodeId& dataType(void);
		void valueRank(int32_t valueRank);
		int32_t valueRank(void);
		void arrayDimensions(OpcUaUInt32Array::SPtr& arrayDimensions);
		OpcUaUInt32Array::SPtr& arrayDimensions(void);
		void maxStringLength(uint32_t maxStringLength);
		uint32_t maxStringLength(void);
		void isOptional(OpcUaBoolean isOptional);
		OpcUaBoolean isOptional(void);

		void copyTo(StructureField& structureField);
		bool operator==(const StructureField& structureField) const;
		friend std::ostream& operator<<(std::ostream& os, const StructureField& value) {
			const_cast<StructureField*>(&value)->out(os);
			return os;
		}

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

	  private:
		OpcUaString name_;
		OpcUaLocalizedText description_;
		OpcUaNodeId dataType_;
		int32_t valueRank_;
		OpcUaUInt32Array::SPtr arrayDimensions_;
		uint32_t maxStringLength_;
		OpcUaBoolean isOptional_;
	};


	class StructureFieldArray
	: public OpcUaArray<StructureField::SPtr, SPtrTypeCoder<StructureField> >
	{
	  public:
		typedef boost::shared_ptr<StructureFieldArray> SPtr;
	};

}

#endif
