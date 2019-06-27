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

#ifndef __OpcUaStackServer_VariableNodeClass_h__
#define __OpcUaStackServer_VariableNodeClass_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

namespace OpcUaStackServer
{

	class DLLEXPORT VariableNodeClass
	: public BaseNodeClass
	{
	  public:
		typedef boost::shared_ptr<VariableNodeClass> SPtr;

		VariableNodeClass(void);
		~VariableNodeClass(void);

		ValueAttribute& value(void);
		DataTypeAttribute& dataType(void);
		ValueRankAttribute& valueRank(void);
		AccessLevelAttribute& accessLevel(void);
		UserAccessLevelAttribute& userAccessLevel(void);
		HistorizingAttribute& historizing(void);
		ArrayDimensionsAttribute& arrayDimensions(void);
		MinimumSamplingIntervalAttribute& minimumSamplingInterval(void);

		Attribute* valueAttribute(void);
		Attribute* dataTypeAttribute(void);
		Attribute* valueRankAttribute(void);
		Attribute* accessLevelAttribute(void);
		Attribute* userAccessLevelAttribute(void);
		Attribute* historizingAttribute(void);
		Attribute* arrayDimensionsAttribute(void);
		Attribute* minimumSamplingIntervalAttribute(void);

		void copyTo(VariableNodeClass::SPtr variableNodeClass);
		void copyTo(VariableNodeClass& variableNodeClass);
		BaseNodeClass::SPtr clone(void);

	  private:
		// attributes mandatory
		ValueAttribute value_;
		DataTypeAttribute dataType_;
		ValueRankAttribute valueRank_;
		AccessLevelAttribute accessLevel_;
		UserAccessLevelAttribute userAccessLevel_;
		HistorizingAttribute historizing_;

		// attributes optional
		ArrayDimensionsAttribute arrayDimensions_;
		MinimumSamplingIntervalAttribute minimumSamplingInterval_;

		// standard properties - all optional
		OpcUaString nodeVersion_;  
		//TimeZoneDataType localTime_;
		OpcUaString dataTypeVersion_;
		OpcUaByteString dictionaryFragment_;
		OpcUaBoolean allowNulls_;

	};

}

#endif
