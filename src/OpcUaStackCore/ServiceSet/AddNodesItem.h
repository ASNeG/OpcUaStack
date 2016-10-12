/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_AddNodesItem_h__
#define __OpcUaStackCore_AddNodesItem_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/NodeClass.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"


namespace OpcUaStackCore
{

	class DLLEXPORT AddNodesItem
	: public Object
	{
	  public:
		typedef boost::shared_ptr<AddNodesItem> SPtr;

	    AddNodesItem(void);
		~AddNodesItem(void);

		void parentNodeId(const OpcUaExpandedNodeId::SPtr parentNodeIdSPtr);
		OpcUaExpandedNodeId::SPtr parentNodeId(void) const;
		void referenceTypeId(const OpcUaNodeId::SPtr referenceTypeIdSPtr);
		OpcUaNodeId::SPtr referenceTypeId(void) const;
		void requestedNewNodeId(const OpcUaExpandedNodeId::SPtr requestedNewNodeIdSPtr);
		OpcUaExpandedNodeId::SPtr requestedNewNodeId(void) const;
		void browseName(const OpcUaQualifiedName::SPtr browseNameSPtr);
		OpcUaQualifiedName::SPtr browseName(void) const;
		void nodeClass(const NodeClass::SPtr nodeClassSPtr);
		NodeClass::SPtr nodeClass(void) const;
		ExtensibleParameter& nodeAttributes(void);
		void typeDefinition(const OpcUaExpandedNodeId::SPtr typeDefinitionSPtr);
		OpcUaExpandedNodeId::SPtr typeDefinition(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaExpandedNodeId::SPtr parentNodeId_;
		OpcUaNodeId::SPtr referenceTypeId_;
		OpcUaExpandedNodeId::SPtr requestedNewNodeId_;
		OpcUaQualifiedName::SPtr browseName_;
		NodeClass::SPtr nodeClass_;
		ExtensibleParameter nodeAttributes_;
		OpcUaExpandedNodeId::SPtr typeDefinition_;
	};

	class AddNodesItemArray
	: public OpcUaArray<AddNodesItem::SPtr, SPtrTypeCoder<AddNodesItem> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<AddNodesItemArray> SPtr;
	};
}

#endif
