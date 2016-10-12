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

#ifndef __OpcUaStackCore_ReferenceDescription_h__
#define __OpcUaStackCore_ReferenceDescription_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"
#include "OpcUaStackCore/ServiceSet/NodeClass.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ReferenceDescription
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<ReferenceDescription> SPtr;
		typedef std::vector<ReferenceDescription::SPtr> Vec;

		ReferenceDescription(void);
		virtual ~ReferenceDescription(void);

		void referenceTypeId(const OpcUaNodeId::SPtr referenceTypeId);
		OpcUaNodeId::SPtr referenceTypeId(void) const;
		void isForward(const OpcUaBoolean& isForward);
		OpcUaBoolean isForward(void);
		void expandedNodeId(const OpcUaExpandedNodeId::SPtr nodeId);
		OpcUaExpandedNodeId::SPtr expandedNodeId(void) const;
		void browseName(const OpcUaQualifiedName& browseName);
		OpcUaQualifiedName& browseName(void);
		void displayName(const OpcUaLocalizedText& displayName);
		OpcUaLocalizedText& displayName(void);
		void nodeClass(const NodeClassType nodeClass);
		NodeClassType nodeClass(void);
		void typeDefinition(const OpcUaExpandedNodeId::SPtr typeDefinition);
		OpcUaExpandedNodeId::SPtr typeDefinition(void) const;
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaNodeId::SPtr referenceTypeIdSPtr_;
		OpcUaBoolean isForward_;
		OpcUaExpandedNodeId::SPtr nodeIdSPtr_;
		OpcUaQualifiedName browseName_;
		OpcUaLocalizedText displayName_;
		NodeClassType nodeClass_;
		OpcUaExpandedNodeId::SPtr typeDefinitionSPtr_;
	};

	class ReferenceDescriptionArray
	: public OpcUaArray<ReferenceDescription::SPtr, SPtrTypeCoder<ReferenceDescription> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<ReferenceDescriptionArray> SPtr;
	};

}

#endif
