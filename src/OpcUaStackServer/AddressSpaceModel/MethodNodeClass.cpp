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

#include "OpcUaStackServer/AddressSpaceModel/MethodNodeClass.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	MethodNodeClass::MethodNodeClass(void)
	: BaseNodeClass(NodeClass::EnumMethod)
	, executable_()
	, userExecutable_()
	{
	}

	MethodNodeClass::MethodNodeClass(OpcUaNodeId& nodeId, MethodNodeClass& methodNodeClass)
	: BaseNodeClass(NodeClass::EnumMethod, nodeId, &methodNodeClass)
	, executable_()
	, userExecutable_()
	{

		OpcUaBoolean executable;
		if (methodNodeClass.getExecutable(executable)) setExecutable(executable);

		OpcUaBoolean userExecutable;
		if (methodNodeClass.getUserExecutable(userExecutable)) setUserExecutable(userExecutable);
	}

	MethodNodeClass::~MethodNodeClass(void)
	{
	}

	ExecutableAttribute& 
	MethodNodeClass::executable(void)
	{
		return executable_;
	}
	
	UserExecutableAttribute& 
	MethodNodeClass::userExecutable(void)
	{
		return userExecutable_;
	}

	Attribute* 
	MethodNodeClass::executableAttribute(void)
	{
		return & executable_;
	}
		
	Attribute* 
	MethodNodeClass::userExecutableAttribute(void)
	{
		return &userExecutable_;
	}

	void
	MethodNodeClass::copyTo(MethodNodeClass::SPtr methodNodeClass)
	{
		copyTo(*methodNodeClass);
	}

	void
	MethodNodeClass::copyTo(MethodNodeClass& methodNodeClass)
	{
		BaseNodeClass::copyTo(methodNodeClass);
		executableAttribute()->copyTo(methodNodeClass.executableAttribute());
		userExecutableAttribute()->copyTo(methodNodeClass.userExecutableAttribute());
	}

	BaseNodeClass::SPtr
	MethodNodeClass::clone(void)
	{
		MethodNodeClass::SPtr methodNodeClass = boost::make_shared<MethodNodeClass>();
		copyTo(methodNodeClass);
		return methodNodeClass;
	}

}
