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

#ifndef __OpcUaStackServer_VariableTypeNodeClass_h__
#define __OpcUaStackServer_VariableTypeNodeClass_h__

#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

namespace OpcUaStackServer
{

	class DLLEXPORT VariableTypeNodeClass
	: public BaseNodeClass
	{
	  public:
		typedef boost::shared_ptr<VariableTypeNodeClass> SPtr;

		VariableTypeNodeClass(void);
		~VariableTypeNodeClass(void);

		DataTypeAttribute& dataType(void);
		ValueRankAttribute& valueRank(void);
		IsAbstractAttribute& isAbstract(void);
		ValueAttribute& value(void);
		ArrayDimensionsAttribute& arrayDimensions(void);

		Attribute* dataTypeAttribute(void);
		Attribute* valueRankAttribute(void);
		Attribute* isAbstractAttribute(void);
		Attribute* valueAttribute(void);
		Attribute* arrayDimensionsAttribute(void);

		void copyTo(VariableTypeNodeClass::SPtr variableTypeNodeClass);
		void copyTo(VariableTypeNodeClass& variableTypeNodeClass);
		BaseNodeClass::SPtr clone(void);

	  private:
		// attributes mandatory
		DataTypeAttribute dataType_;
		ValueRankAttribute valueRank_;
		IsAbstractAttribute isAbstract_;

		// attributes optional
		ValueAttribute value_;
		ArrayDimensionsAttribute arrayDimensions_;

		// standard properties - all optional
		OpcUaStackCore::OpcUaString nodeVersion_;
	};

}

#endif
