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

#ifndef __OpcUaStackServer_ObjectNodeClass_h__
#define __OpcUaStackServer_ObjectNodeClass_h__

#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ObjectTypeNodeClass.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ObjectNodeClass
	: public BaseNodeClass
	{
	  public:
		typedef boost::shared_ptr<ObjectNodeClass> SPtr;

		ObjectNodeClass(void);
		ObjectNodeClass(OpcUaStackCore::OpcUaNodeId& nodeId, ObjectNodeClass& objectNodeClass);
		ObjectNodeClass(OpcUaStackCore::OpcUaNodeId& nodeId, ObjectTypeNodeClass& objectTypeNodeClass);
		~ObjectNodeClass(void);

		EventNotifierAttribute& eventNotifier(void);

		Attribute* eventNotifierAttribute(void);

		void copyTo(ObjectNodeClass::SPtr objectNodeClass);
		void copyTo(ObjectNodeClass& objectNodeClass);
		BaseNodeClass::SPtr clone(void);

	  private:
		// attributes mandatory
		EventNotifierAttribute eventNotifier_;
	};

}

#endif
