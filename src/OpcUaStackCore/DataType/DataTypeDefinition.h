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

#ifndef __OpcUaStackCore_DataTypeDefinition_h__
#define __OpcUaStackCore_DataTypeDefinition_h__

#include <boost/property_tree/ptree.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/DataType/DataTypeField.h"

namespace OpcUaStackCore
{

	class DLLEXPORT DataTypeDefinition
	: public Object
	, public DataTypeFieldIf
	{
	  public:
		typedef boost::shared_ptr<DataTypeDefinition> SPtr;

		DataTypeDefinition(void);
		~DataTypeDefinition(void);

		DataSubType dataSubType(void);
		void dataSubType(DataSubType dataSubType);
		bool nested(void);
		void nested(bool nested);
		OpcUaQualifiedName& name(void);
		void name(OpcUaQualifiedName& name);
		OpcUaQualifiedName& baseType(void);
		void baseType(OpcUaQualifiedName& baseType);
		OpcUaBoolean isUnion(void);
		void isUnion(OpcUaBoolean isUnion);
		DataTypeField::Vec& dataFields(void);
		void dataField(DataTypeField::SPtr& dataField);

		static DataTypeDefinition::SPtr definition(DataTypeField::SPtr& dataField);

		bool decode(boost::property_tree::ptree& ptree);
		bool encode(boost::property_tree::ptree& ptree);

		//- DataTypeFieldIf ---------------------------------------------------
		virtual bool decode(boost::property_tree::ptree& ptree, Object::SPtr& dataTypeDefinition);
		virtual bool encode(boost::property_tree::ptree& ptree, Object::SPtr& dataTypeDefinition);
		//- DataTypeFieldIf ---------------------------------------------------

	  private:
		bool decode(boost::property_tree::ptree& ptree, bool withDefinitionTag);

		DataSubType dataSubType_;
		bool nested_;

		OpcUaQualifiedName name_; 		// only for nested dataTypeDefinitions
		OpcUaQualifiedName baseType_;	// only for nested dataTypeDefinitions
		OpcUaBoolean isUnion_;			// default: false
		DataTypeField::Vec dataFields_;
	};


}

#endif
