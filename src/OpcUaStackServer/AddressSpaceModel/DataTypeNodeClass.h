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

#ifndef __OpcUaStackServer_DataTypeNodeClass_h__
#define __OpcUaStackServer_DataTypeNodeClass_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT DataTypeNodeClass
	: public BaseNodeClass
	{
	  public:
		typedef boost::shared_ptr<DataTypeNodeClass> SPtr;

		DataTypeNodeClass(void);
		~DataTypeNodeClass(void);

		IsAbstractAttribute& isAbstract(void);

		Attribute* isAbstractAttribute(void);

		void copyTo(DataTypeNodeClass::SPtr dataTypeNodeClass);
		void copyTo(DataTypeNodeClass& dataTypeNodeClass);
		BaseNodeClass::SPtr clone(void);

		void dataTypeDefinition(Object::SPtr dataTypeDefinition);
		Object::SPtr& dataTypeDefinition(void);

	  private:
		// attributes mandatory
		IsAbstractAttribute isAbstract_;

		// additional properties
		Object::SPtr dataTypeDefinition_;

		// standard properties - all optional
		OpcUaString nodeVersion_;
	};

}

#endif
