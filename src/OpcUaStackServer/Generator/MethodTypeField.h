/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_MethodTypeField_h__
#define __OpcUaStackCore_MethodTypeField_h__

#include <boost/shared_ptr.hpp>

#include <vector>
#include <map>

#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackServer
{

/**
 * This function manages method type field information
 */
class DLLEXPORT MethodTypeField
{
  public:
	typedef boost::shared_ptr<MethodTypeField> SPtr;
	typedef std::vector<MethodTypeField::SPtr> Vec;
	typedef std::map<std::string, MethodTypeField::SPtr> Map;

	/**
	 * constructor
	 */
	MethodTypeField(void);

	/**
	 * destructor
	 */
	~MethodTypeField(void);

	void name(const std::string& name);
	std::string& name(void);
	void variableName(const std::string& variableName);
	std::string& variableName(void);
	void functionName(const std::string& functionName);
	std::string& functionName(void);

  private:
	std::string name_;
	std::string variableName_;
	std::string functionName_;
};

}

#endif
