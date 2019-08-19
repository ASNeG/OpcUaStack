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

#ifndef __OpcUaStackServer_ObjectTypeNodeClass_h__
#define __OpcUaStackServer_ObjectTypeNodeClass_h__

#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ObjectTypeNodeClass
	: public BaseNodeClass
	{
	  public:
		typedef boost::shared_ptr<ObjectTypeNodeClass> SPtr;

		ObjectTypeNodeClass(void);
		~ObjectTypeNodeClass(void);

		IsAbstractAttribute& isAbstract(void);

		Attribute* isAbstractAttribute(void);

		void copyTo(ObjectTypeNodeClass::SPtr objectTypeNodeClass);
		void copyTo(ObjectTypeNodeClass& objectTypeNodeClass);
		BaseNodeClass::SPtr clone(void);

	  private:
		// attributes mandatory
		  IsAbstractAttribute isAbstract_;

		// standard properties
		OpcUaStackCore::OpcUaString::SPtr nodeVersion_;  // optional
		// FIXME: Image icon_;	// optional
	};

}

#endif
