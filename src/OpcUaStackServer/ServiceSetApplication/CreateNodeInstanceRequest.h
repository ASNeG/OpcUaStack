/*
   Copyright 2017-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_CreateNodeInstanceRequest_h__
#define __OpcUaStackServer_CreateNodeInstanceRequest_h__

#include "OpcUaStackCore/StandardDataTypes/NodeClass.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaLocalizedText.h"

namespace OpcUaStackServer
{

	class DLLEXPORT CreateNodeInstanceRequest
	: public OpcUaStackCore::Object
	{
	  public:
		using SPtr =  boost::shared_ptr<CreateNodeInstanceRequest>;

		CreateNodeInstanceRequest(void);
		virtual ~CreateNodeInstanceRequest(void);

		std::string& name(void);
		OpcUaStackCore::NodeClass::Enum& nodeClassType(void);
		OpcUaStackCore::OpcUaNodeId& parentNodeId(void);
		OpcUaStackCore::OpcUaNodeId& nodeId(void);
		OpcUaStackCore::OpcUaLocalizedText& displayName(void);
		OpcUaStackCore::OpcUaQualifiedName& browseName(void);
		OpcUaStackCore::OpcUaNodeId& referenceNodeId(void);
		OpcUaStackCore::OpcUaNodeId& typeNodeId(void);

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		std::string name_;
		OpcUaStackCore::NodeClass::Enum nodeClassType_;
		OpcUaStackCore::OpcUaNodeId parentNodeId_;
		OpcUaStackCore::OpcUaNodeId nodeId_;
		OpcUaStackCore::OpcUaLocalizedText displayName_;
		OpcUaStackCore::OpcUaQualifiedName browseName_;
		OpcUaStackCore::OpcUaNodeId referenceNodeId_;
		OpcUaStackCore::OpcUaNodeId typeNodeId_;			// optional
	};

}

#endif
