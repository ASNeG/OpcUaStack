/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_NodeTypeDescription_h__
#define __OpcUaStackCore_NodeTypeDescription_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExpandedNodeId.h"
#include "OpcUaStackCore/ServiceSet/QueryDataDescription.h"

namespace OpcUaStackCore
{

	class DLLEXPORT NodeTypeDescription
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<NodeTypeDescription> SPtr;

		NodeTypeDescription(void);
		virtual ~NodeTypeDescription(void);

		void typeDefinitionNode(const OpcUaExpandedNodeId::SPtr typeDefinitionNode);
		OpcUaExpandedNodeId::SPtr typeDefinitionNode(void) const;
		void includeSubtypes(const OpcUaBoolean& includeSubtypes);
		OpcUaBoolean includeSubtypes(void);
		void dataToReturn(const QueryDataDescriptionArray::SPtr dataToReturn);
		QueryDataDescriptionArray::SPtr dataToReturn(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaExpandedNodeId::SPtr typeDefinitionNodeSPtr_;
		OpcUaBoolean includeSubtypes_;
		QueryDataDescriptionArray::SPtr dataToReturnArraySPtr_;
	};

	class DLLEXPORT NodeTypeDescriptionArray
	: public OpcUaArray<NodeTypeDescription::SPtr, SPtrTypeCoder<NodeTypeDescription> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<NodeTypeDescriptionArray> SPtr;
	};

}

#endif
