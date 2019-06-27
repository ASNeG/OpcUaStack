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

#include "OpcUaStackServer/AddressSpaceModel/DataTypeNodeClass.h"

namespace OpcUaStackServer
{

	DataTypeNodeClass::DataTypeNodeClass(void)
	: BaseNodeClass(NodeClassType_DataType)
	, isAbstract_()
	, dataTypeDefinition_()
	{
	}

	DataTypeNodeClass::~DataTypeNodeClass(void)
	{
	}

	IsAbstractAttribute& 
	DataTypeNodeClass::isAbstract(void)
	{
		return isAbstract_;
	}

	Attribute* 
	DataTypeNodeClass::isAbstractAttribute(void)
	{
		return &isAbstract_;
	}

	void
	DataTypeNodeClass::copyTo(DataTypeNodeClass::SPtr dataTypeNodeClass)
	{
		copyTo(*dataTypeNodeClass);
	}

	void
	DataTypeNodeClass::copyTo(DataTypeNodeClass& dataTypeNodeClass)
	{
		BaseNodeClass::copyTo(dataTypeNodeClass);
		isAbstractAttribute()->copyTo(dataTypeNodeClass.isAbstractAttribute());
	}

	BaseNodeClass::SPtr
	DataTypeNodeClass::clone(void)
	{
		DataTypeNodeClass::SPtr dataTypeNodeClass = constructSPtr<DataTypeNodeClass>();
		copyTo(dataTypeNodeClass);
		return dataTypeNodeClass;
	}

	void
	DataTypeNodeClass::dataTypeDefinition(Object::SPtr dataTypeDefinition)
	{
		dataTypeDefinition_ = dataTypeDefinition;
	}

	Object::SPtr&
	DataTypeNodeClass::dataTypeDefinition(void)
	{
		return dataTypeDefinition_;
	}

}
