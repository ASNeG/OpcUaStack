/*
   Copyright 2019-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_CreateObjectRequest_h__
#define __OpcUaStackServer_CreateObjectRequest_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaLocalizedText.h"

namespace OpcUaStackServer
{

	class DLLEXPORT CreateObjectRequest
	: public OpcUaStackCore::Object
	{
	  public:
		typedef boost::shared_ptr<CreateObjectRequest> SPtr;

		CreateObjectRequest(void);
		virtual ~CreateObjectRequest(void);

		void namespaceName(const std::string& namespaceName);
		std::string& namespaceName(void);
		void displayName(const OpcUaStackCore::OpcUaLocalizedText& displayName);
		OpcUaStackCore::OpcUaLocalizedText& displayName(void);
		void parentNodeId(const OpcUaStackCore::OpcUaNodeId& parentNodeId);
		OpcUaStackCore::OpcUaNodeId& parentNodeId(void);
		void referenceTypeNodeId(const OpcUaStackCore::OpcUaNodeId& referenceTypeNodeId);
		OpcUaStackCore::OpcUaNodeId& referenceTypeNodeId(void);
        void objectInstance(Object::SPtr& objectInstance);
        Object::SPtr& objectInstance(void);

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		std::string namespaceName_;
		OpcUaStackCore::OpcUaLocalizedText displayName_;
		OpcUaStackCore::OpcUaNodeId parentNodeId_;
		OpcUaStackCore::OpcUaNodeId referenceTypeNodeId_;
		Object::SPtr objectInstance_;
	};

}

#endif