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

#ifndef __OpcUaStackCore_StructureDefinitionExpand_h__
#define __OpcUaStackCore_StructureDefinitionExpand_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/DataTypeDefinition.h"
#include "OpcUaStackCore/StandardDataTypes/StructureField.h"

namespace OpcUaStackCore
{

	class DLLEXPORT StructureDefinitionExpand
	: public DataTypeDefinition
	{
	  public:
		typedef boost::shared_ptr<StructureDefinitionExpand> SPtr;

		StructureDefinitionExpand(void);
		virtual ~StructureDefinitionExpand(void);

		void name(const std::string& name);
		std::string& name(void);
		void symbolicName(const std::string& symbolicName);
		std::string& symbolicName(void);
		void defaultEncodingId(OpcUaNodeId& defaultEncodingId);
		OpcUaNodeId& defaultEncodingId(void);
		void baseDataType(OpcUaNodeId& baseDataType);
		OpcUaNodeId& baseDataType(void);
		void structureType(uint32_t structureType);
		uint32_t structureType(void);
		void fields(StructureFieldArray::SPtr& fields);
		StructureFieldArray::SPtr& fields(void);

		void copyTo(StructureDefinitionExpand& structureTypeDefinition);
		bool operator==(const StructureDefinitionExpand& structureTypeDefinition) const;
		friend std::ostream& operator<<(std::ostream& os, const StructureDefinitionExpand& value) {
			const_cast<StructureDefinitionExpand*>(&value)->out(os);
			return os;
		}

		//- ExtensionObjectBase -----------------------------------------------
		virtual ExtensionObjectBase::SPtr factory(void) override;
		virtual OpcUaNodeId binaryTypeId(void) override;
		virtual OpcUaNodeId xmlTypeId(void) override;
		virtual void opcUaBinaryEncode(std::ostream& os) const override;
		virtual void opcUaBinaryDecode(std::istream& is) override;
		virtual bool encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const;
		virtual bool decode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) override;
		virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns) override;
		virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) override { return true; }
		virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns) override;
		virtual void copyTo(ExtensionObjectBase& extensionObjectBase) override;
		virtual bool equal(ExtensionObjectBase& extensionObjectBase) const override;
		virtual void out(std::ostream& os) override;
		//- ExtensionObjectBase -----------------------------------------------

	  private:
		std::string name_;
		std::string symbolicName_;
		OpcUaNodeId defaultEncodingId_;
		OpcUaNodeId baseDataType_;
		uint32_t structureType_;
		StructureFieldArray::SPtr fields_;

	};

}

#endif
