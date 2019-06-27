/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/AddressSpaceModel/ObjectNodeClass.h"

namespace OpcUaStackServer
{

	ObjectNodeClass::ObjectNodeClass(void)
	: BaseNodeClass(NodeClassType_Object)
	, eventNotifier_()
	, nodeVersion_()
	{
	}

	ObjectNodeClass::~ObjectNodeClass(void)
	{
	}

	EventNotifierAttribute& 
	ObjectNodeClass::eventNotifier(void)
	{
		return eventNotifier_;
	}

	Attribute* 
	ObjectNodeClass::eventNotifierAttribute(void)
	{
		return &eventNotifier_;
	}

	void
	ObjectNodeClass::copyTo(ObjectNodeClass::SPtr objectNodeClass)
	{
		copyTo(*objectNodeClass);
	}

	void
	ObjectNodeClass::copyTo(ObjectNodeClass& objectNodeClass)
	{
		BaseNodeClass::copyTo(objectNodeClass);
		eventNotifierAttribute()->copyTo(objectNodeClass.eventNotifierAttribute());
	}

	BaseNodeClass::SPtr
	ObjectNodeClass::clone(void)
	{
		ObjectNodeClass::SPtr objectNodeClass = constructSPtr<ObjectNodeClass>();
		copyTo(objectNodeClass);
		return objectNodeClass;
	}

}
