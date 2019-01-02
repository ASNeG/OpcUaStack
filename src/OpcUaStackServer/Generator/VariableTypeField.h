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

#ifndef __OpcUaStackCore_VariableTypeField_h__
#define __OpcUaStackCore_VariableTypeField_h__

#include <boost/shared_ptr.hpp>

#include <vector>
#include <map>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

/**
 * This function manages variable type field information
 */
class DLLEXPORT VariableTypeField
{
  public:
	typedef boost::shared_ptr<VariableTypeField> SPtr;
	typedef std::vector<VariableTypeField::SPtr> Vec;
	typedef std::map<std::string, VariableTypeField::SPtr> Map;

	/**
	 * constructor
	 */
	VariableTypeField(void);

	/**
	 * destructor
	 */
	~VariableTypeField(void);

	void name(const std::string& name);
	std::string& name(void);
	void variableName(const std::string& variableName);
	std::string& variableName(void);
	void functionName(const std::string& functionName);
	std::string& functionName(void);
	void typeNamespaceName(const std::string& namespaceName);
	std::string& typeNamespaceName(void);
	void typeNodeId(const OpcUaNodeId& typeNodeId);
	OpcUaNodeId& typeNodeId(void);

  private:
	std::string name_;
	std::string variableName_;
	std::string functionName_;
	std::string typeNamespaceName_;
	OpcUaNodeId typeNodeId_;

};

}

#endif
