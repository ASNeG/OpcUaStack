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

#ifndef __OpcUaStackCore_DataTypeField_h__
#define __OpcUaStackCore_DataTypeField_h__

#include <boost/property_tree/ptree.hpp>
#include <vector>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{

	typedef enum {
		None,
		Structure,
		Enumeration
	} DataSubType;


	class DLLEXPORT DataTypeFieldIf
	{
	  public:
		DataTypeFieldIf(void) {}
		virtual ~DataTypeFieldIf(void) {}

		virtual bool decode(boost::property_tree::ptree& ptree, Object::SPtr& dataTypeDefinition) = 0;
		virtual bool encode(boost::property_tree::ptree& ptree, Object::SPtr& dataTypeDefinition) = 0;
	};


	class DLLEXPORT DataTypeField
	{
	  public:
		typedef boost::shared_ptr<DataTypeField> SPtr;
		typedef std::vector<DataTypeField::SPtr> Vec;

		DataTypeField(void);
		~DataTypeField(void);

		void dataTypeFieldIf(DataTypeFieldIf* dataTypeFieldIf);
		DataSubType& dataSubType(void);
		void dataSubType(DataSubType& dataSubType);
		OpcUaString& name(void);
		void name(OpcUaString& name);
		OpcUaNodeId& dataType(void);
		void dataType(OpcUaNodeId& dataType);
		OpcUaInt32 valueRank(void);
		void valueRank(OpcUaInt32 valueRank);
		OpcUaLocalizedText& description(void);
		void description(OpcUaLocalizedText& description);
		Object::SPtr& dataTypeDefinition(void);
		void dataTypeDefinition(Object::SPtr& dataTypeDefinition);
		OpcUaInt32 value(void);
		void value(OpcUaInt32 value);
		OpcUaBoolean isOptional(void);
		void isOptional(OpcUaBoolean isOptional);

		bool decode(boost::property_tree::ptree& ptree);
		bool encode(boost::property_tree::ptree& ptree);

	  private:
		bool decodeEnum(boost::property_tree::ptree& ptree);
		bool decodeStruct(boost::property_tree::ptree& ptree);
		bool encodeEnum(boost::property_tree::ptree& ptree);
		bool encodeStruct(boost::property_tree::ptree& ptree);

		DataTypeFieldIf* dataTypeFieldIf_;
		DataSubType dataSubType_;

		OpcUaString name_;
		OpcUaNodeId dataType_;
		OpcUaInt32 valueRank_;
		OpcUaLocalizedText description_;
		Object::SPtr dataTypeDefinition_;
		OpcUaInt32 value_;
		OpcUaBoolean isOptional_;
	};


}

#endif
