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

#ifndef __OpcUaStackCore_NodeElement_h__
#define __OpcUaStackCore_NodeElement_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/os.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

class DLLEXPORT NodeElement
{
  public:
	typedef boost::shared_ptr<NodeElement> SPtr;
	typedef std::vector<NodeElement::SPtr> Vec;

	NodeElement(void);
	~NodeElement(void);

	void log(void);
	void prefix(const std::string& prefix);
	std::string prefix(void);
	void nodeId(const OpcUaNodeId& nodeId);
	OpcUaNodeId& nodeId(void);
	void browseName(const OpcUaQualifiedName& browseName);
	OpcUaQualifiedName& browseName(void);
	void fullName(const std::string& fullName);
	std::string& fullName(void);
	void globalVariableName(const std::string& globalVariableName);
	std::string& globalVariableName(void);
	void localVariableName(const std::string& localVariableName);
	std::string& localVariableName(void);
	void functionName(const std::string& functionName);
	std::string& functionName(void);
	void dataTypeName(const std::string& dataTypeName);
	std::string& dataTypeName(void);

  private:
	std::string prefix_;
	OpcUaNodeId nodeId_;
	OpcUaQualifiedName browseName_;
	std::string fullName_;
	std::string globalVariableName_;
	std::string localVariableName_;
	std::string functionName_;
	std::string dataTypeName_;
};

}

#endif
