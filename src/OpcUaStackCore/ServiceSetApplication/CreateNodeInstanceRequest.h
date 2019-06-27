/*
   Copyright 2017-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_CreateNodeInstanceRequest_h__
#define __OpcUaStackCore_CreateNodeInstanceRequest_h__

#include "OpcUaStackCore/StandardDataTypes/NodeClass.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaLocalizedText.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CreateNodeInstanceRequest
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<CreateNodeInstanceRequest> SPtr;

		CreateNodeInstanceRequest(void);
		virtual ~CreateNodeInstanceRequest(void);

		std::string& name(void);
		NodeClass::Enum& nodeClassType(void);
		OpcUaNodeId& parentNodeId(void);
		OpcUaNodeId& nodeId(void);
		OpcUaLocalizedText& displayName(void);
		OpcUaQualifiedName& browseName(void);
		OpcUaNodeId& referenceNodeId(void);
		OpcUaNodeId& typeNodeId(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		std::string name_;
		NodeClass::Enum nodeClassType_;
		OpcUaNodeId parentNodeId_;
		OpcUaNodeId nodeId_;
		OpcUaLocalizedText displayName_;
		OpcUaQualifiedName browseName_;
		OpcUaNodeId referenceNodeId_;
		OpcUaNodeId typeNodeId_;			// optional
	};

}

#endif
