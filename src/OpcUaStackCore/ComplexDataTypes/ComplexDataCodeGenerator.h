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
	    void namespaceName(const std::string& namespaceName);

	    bool generate(ComplexDataType& complexDataType);
	    std::string& content(void);

	  private:
	    bool readClassTemplateFile(void);
	    bool substNamespaceName(void);
	    bool substClassName(const std::string& className);
	    bool substValues(void);

	    std::string content_;
		std::string classTemplateFileHeader_;
		std::string classTemplateFileSource_;
		std::string namespaceName_;
		std::string values_;

	};

}

#endif
