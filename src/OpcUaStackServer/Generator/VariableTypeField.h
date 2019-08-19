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

#include <vector>
#include <map>

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"

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
	void dataTypeNamespaceName(const std::string& dataTypeNamespaceName);
	std::string& dataTypeNamespaceName(void);
	void dataTypeNodeId(const OpcUaStackCore::OpcUaNodeId& dataTypeNodeId);
	OpcUaStackCore::OpcUaNodeId& dataTypeNodeId(void);
	void dataTypeName(const std::string& dataTypeName);
	std::string& dataTypeName(void);
	void dataTypeDescription(const std::string& dataTypeDescription);
	std::string& dataTypeDescription(void);
	void isArray(bool isArray);
	bool isArray(void);

  private:
	std::string name_;
	std::string variableName_;
	std::string functionName_;
	std::string dataTypeNamespaceName_;
	OpcUaStackCore::OpcUaNodeId dataTypeNodeId_;
	std::string dataTypeName_;
	std::string dataTypeDescription_;
	bool isArray_;

};

}

#endif
