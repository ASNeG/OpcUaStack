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

#ifndef __OpcUaStackCore_ComplexDataTypeParser_h__
#define __OpcUaStackCore_ComplexDataTypeParser_h__

#include <boost/shared_ptr.hpp>
#include <set>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/ComplexDataTypes/ComplexDataType.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ComplexDataTypeParser
	{
	  public:
		typedef std::set<std::string> SuperTypeProcessing;

		ComplexDataTypeParser(void);
		~ComplexDataTypeParser(void);

		bool parse(const std::string& fileName);
		ComplexDataType::Map& complexDataTypeMap(void);
		ComplexDataType::SPtr complexDataType(const std::string& typeName);
		void mergeSuperType(bool mergeSuperType);

	  private:
		bool parseComplexDataType(Config& config, ComplexDataType::SPtr& complexDataType);
		bool parseComplexDataTypeVariable(Config& config, ComplexDataTypeItem::SPtr& complexDataTypeItem);
		bool postProcessing(void);
		bool postProcessingSuperType(ComplexDataType::SPtr& complexDataType);

		std::string typeName_;
		std::string fileName_;
		ComplexDataType::Map complexDataTypeMap_;

		bool mergeSuperType_;
		SuperTypeProcessing superTypeProcessing_;
	};

}

#endif
