/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/AddressSpaceModel/ObjectTypeNodeClass.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	ObjectTypeNodeClass::ObjectTypeNodeClass(void)
	: BaseNodeClass(NodeClass::EnumObjectType)
	, isAbstract_()
	{
	}

	ObjectTypeNodeClass::~ObjectTypeNodeClass(void)
	{
	}

	IsAbstractAttribute& 
	ObjectTypeNodeClass::isAbstract(void)
	{
		return isAbstract_;
	}

	Attribute* 
	ObjectTypeNodeClass::isAbstractAttribute(void)
	{
		return &isAbstract_;
	}

	void
	ObjectTypeNodeClass::copyTo(ObjectTypeNodeClass::SPtr objectTypeNodeClass)
	{
		copyTo(*objectTypeNodeClass);
	}

	void
	ObjectTypeNodeClass::copyTo(ObjectTypeNodeClass& objectTypeNodeClass)
	{
		BaseNodeClass::copyTo(objectTypeNodeClass);
		isAbstractAttribute()->copyTo(objectTypeNodeClass.isAbstractAttribute());
	}

	BaseNodeClass::SPtr
	ObjectTypeNodeClass::clone(void)
	{
		ObjectTypeNodeClass::SPtr objectTypeNodeClass = boost::make_shared<ObjectTypeNodeClass>();
		copyTo(objectTypeNodeClass);
		return objectTypeNodeClass;
	}

}
