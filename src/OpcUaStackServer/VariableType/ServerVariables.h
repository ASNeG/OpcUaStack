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

#ifndef __OpcUaStackServer_ServerVariables_h__
#define __OpcUaStackServer_ServerVariables_h__

#include <boost/shared_ptr.hpp>
#include <map>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT ServerVariable
	{
	  public:
		typedef boost::shared_ptr<ServerVariable> SPtr;
		typedef std::map<std::string, ServerVariable*> Map;

		ServerVariable(void);
		~ServerVariable(void);

		void baseNode(const BaseNodeClass::WPtr& baseNode);
		BaseNodeClass::WPtr& baseNode(void);
		bool setDataValue(const OpcUaDataValue& dataValue);
		bool getDataValue(OpcUaDataValue& dataValue);

	  private:
		BaseNodeClass::WPtr baseNode_;
	};


	class DLLEXPORT ServerVariables
	{
	  public:
		typedef boost::shared_ptr<ServerVariables> SPtr;

		ServerVariables(void);
		~ServerVariables(void);

		bool registerServerVariable(ServerVariable* serverVariable);

	  private:
		ServerVariable::Map serverVariableMap_;
	};


}

#endif
