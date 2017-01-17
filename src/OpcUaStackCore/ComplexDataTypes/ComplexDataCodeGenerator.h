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

#ifndef __OpcUaStackCore_ComplexDataCodeGenerator_h__
#define __OpcUaStackCore_ComplexDataCodeGenerator_h__

#include <boost/shared_ptr.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/regex.hpp>
#include <iostream>
#include <sstream>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/ComplexDataTypes/ComplexDataType.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ComplexDataCodeGenerator

	{
	  public:
		typedef boost::shared_ptr<ComplexDataCodeGenerator> SPtr;

		ComplexDataCodeGenerator(void);
		virtual ~ComplexDataCodeGenerator(void);

	    void classTemplateFileHeader(const std::string& classTemplateFileHeader);
	    void classTemplateFileSource(const std::string& classTemplateFileSource);

	    bool generate(ComplexDataType& complexDataType);
	    bool generate(ComplexDataType& complexDataType, ComplexDataType& complexDataTypeSuperType);
	    std::string& contentHeader(void);
	    std::string& contentSource(void);

	  private:
	    bool generateHeader(ComplexDataType& complexDataType);
	    bool generateSource(ComplexDataType& complexDataType);
	    bool readClassTemplateFileHeader(void);
	    bool readClassTemplateFileSource(void);
	    bool substSuperType(std::string& content);
	    bool substProjectNamespace(std::string& content);
	    bool substClassName(std::string& content, const std::string& className);
	    bool substProjectFolder(std::string& content);
	    bool substValues(std::string& content);
	    bool substValuesInit(std::string& content);
	    bool substValuesEncode(std::string& content);
	    bool substValuesDecode(std::string& content);
	    bool substValuesOut(std::string& content);
	    bool substValuesCopyTo(std::string& content);
	    bool substValuesEqual(std::string& content);
	    bool substTypeIds(std::string& content);

	    std::string contentHeader_;
	    std::string contentSource_;
		std::string classTemplateFileHeader_;
		std::string classTemplateFileSource_;
		std::string superType_;
		std::string projectNamespace_;
		std::string projectFolder_;
		std::string projectNamespaceSuperType_;
		std::string projectFolderSuperType_;
		std::string values_;
		std::string valuesInit_;
		std::string valuesEncode_;
		std::string valuesDecode_;
		std::string valuesOut_;
		std::string valuesCopyTo_;
		std::string valuesEqual_;
		std::string binaryTypeId_;
		std::string xmlTypeId_;

	};

}

#endif
