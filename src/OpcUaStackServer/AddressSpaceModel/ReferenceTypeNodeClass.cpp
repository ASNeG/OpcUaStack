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

#include "OpcUaStackServer/AddressSpaceModel/ReferenceTypeNodeClass.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	ReferenceTypeNodeClass::ReferenceTypeNodeClass(void)
	: BaseNodeClass(NodeClass::EnumReferenceType)
	, isAbstract_()
	, symmetric_()
	, inverseName_()
	{
	}

	ReferenceTypeNodeClass::~ReferenceTypeNodeClass(void)
	{
	}

	IsAbstractAttribute& 
	ReferenceTypeNodeClass::isAbstract(void)
	{
		return isAbstract_;
	}

	SymmetricAttribute& 
	ReferenceTypeNodeClass::symmetric(void)
	{
		return symmetric_;
	}

	InverseNameAttribute& 
	ReferenceTypeNodeClass::inverseName(void)
	{
		return inverseName_;
	}

	Attribute* 
	ReferenceTypeNodeClass::isAbstractAttribute(void)
	{
		return &isAbstract_;
	}

	Attribute* 
	ReferenceTypeNodeClass::symmetricAttribute(void)
	{
		return &symmetric_;
	}

	Attribute* 
	ReferenceTypeNodeClass::inverseNameAttribute(void)
	{
		return &inverseName_;
	}

	void
	ReferenceTypeNodeClass::copyTo(ReferenceTypeNodeClass::SPtr referenceTypeNodeClass)
	{
		copyTo(*referenceTypeNodeClass);
	}

	void
	ReferenceTypeNodeClass::copyTo(ReferenceTypeNodeClass& referenceTypeNodeClass)
	{
		BaseNodeClass::copyTo(referenceTypeNodeClass);
		isAbstractAttribute()->copyTo(referenceTypeNodeClass.isAbstractAttribute());
		symmetricAttribute()->copyTo(referenceTypeNodeClass.symmetricAttribute());
		inverseNameAttribute()->copyTo(referenceTypeNodeClass.inverseNameAttribute());
	}

	BaseNodeClass::SPtr
	ReferenceTypeNodeClass::clone(void)
	{
		ReferenceTypeNodeClass::SPtr referenceTypeNodeClass = boost::make_shared<ReferenceTypeNodeClass>();
		copyTo(referenceTypeNodeClass);
		return referenceTypeNodeClass;
	}

}
