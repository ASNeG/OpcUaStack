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

#ifndef __OpcUaStackServer_ReferenceTypeNodeClass_h__
#define __OpcUaStackServer_ReferenceTypeNodeClass_h__

#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ReferenceTypeNodeClass
	: public BaseNodeClass
	{
	  public:
		typedef boost::shared_ptr<ReferenceTypeNodeClass> SPtr;

		ReferenceTypeNodeClass(void);
		~ReferenceTypeNodeClass(void);

		IsAbstractAttribute& isAbstract(void);
		SymmetricAttribute& symmetric(void);
		InverseNameAttribute& inverseName(void);

		Attribute* isAbstractAttribute(void);
		Attribute* symmetricAttribute(void);
		Attribute* inverseNameAttribute(void);

		void copyTo(ReferenceTypeNodeClass::SPtr referenceTypeNodeClass);
		void copyTo(ReferenceTypeNodeClass& referenceTypeNodeClass);
		BaseNodeClass::SPtr clone(void);

	  private:
		// attributes mandatory
		IsAbstractAttribute isAbstract_;
		SymmetricAttribute symmetric_;
	
		// attributes optional
		InverseNameAttribute inverseName_;

		// standard properties
		OpcUaStackCore::OpcUaString nodeVersion_;  // optional
	};

}

#endif
