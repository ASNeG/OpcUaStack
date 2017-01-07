/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_ComplexDataType_h__
#define __OpcUaStackCore_ComplexDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaType.h"

#include <vector>
#include <map>

namespace OpcUaStackCore
{

	class DLLEXPORT ComplexDataTypeItem
	{
	  public:
		typedef boost::shared_ptr<ComplexDataTypeItem> SPtr;
		typedef std::vector<ComplexDataTypeItem> Vec;

		ComplexDataTypeItem(void);
		ComplexDataTypeItem(const std::string& itemName, OpcUaBuildInType itemType);
		virtual ~ComplexDataTypeItem(void);

		void itemName(const std::string& itemName);
		std::string& itemName(void);
		void itemType(OpcUaBuildInType itemType);
		OpcUaBuildInType itemType(void);

	  private:
		std::string itemName_;
		OpcUaBuildInType itemType_;
	};


	class DLLEXPORT ComplexDataType
	{
	  public:
		typedef std::map<std::string, uint32_t> NameIndexMap;
		typedef boost::shared_ptr<ComplexDataType> SPtr;

		ComplexDataType(void);
		ComplexDataType(ComplexDataTypeItem::Vec& complexDataTypeItemVec);
		virtual ~ComplexDataType(void);

		void complexDataTypeItemVec(ComplexDataTypeItem::Vec& complexDataTypeItemVec);
		void addComplexDataTypeItem(ComplexDataTypeItem& complexDataTypeItem);
		ComplexDataTypeItem::Vec& complexDataTypeItemVec(void);

		void binaryTypeId(OpcUaNodeId& binaryTypeId);
		OpcUaNodeId& binaryTypeId(void);
		void xmlTypeId(OpcUaNodeId& xmlTypeId);
		OpcUaNodeId& xmlTypeId(void);

		int32_t name2Index(const std::string& name);
		std::string index2Name(uint32_t index);
		uint32_t size(void);

	  private:
		NameIndexMap nameIndexMap_;
		OpcUaNodeId binaryTypeId_;
		OpcUaNodeId xmlTypeId_;
		ComplexDataTypeItem::Vec complexDataTypeItemVec_;
	};

}

#endif
