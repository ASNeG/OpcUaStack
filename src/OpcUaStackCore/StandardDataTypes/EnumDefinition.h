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

#ifndef __OpcUaStackCore_EnumDefinition_h__
#define __OpcUaStackCore_EnumDefinition_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/DataTypeDefinition.h"
#include "OpcUaStackCore/StandardDataTypes/EnumField.h"

namespace OpcUaStackCore
{

	class DLLEXPORT EnumDefinition
	: public DataTypeDefinition
	{
	  public:
		typedef boost::shared_ptr<EnumDefinition> SPtr;

		EnumDefinition(void);
		virtual ~EnumDefinition(void);

		void enumFields(EnumFieldArray::SPtr& enumFields);
		EnumFieldArray::SPtr& enumFields(void);

		void copyTo(EnumDefinition& enumTypeDefinition);
		bool operator==(const EnumDefinition& enumTypeDefinition) const;

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
		EnumFieldArray::SPtr enumFields_;

	};

}

#endif
