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

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaStackCore_ReferenceDescription_h__
#define __OpcUaStackCore_ReferenceDescription_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/NodeClass.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ReferenceDescription
	: public Object
	, public JsonFormatter
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
		void nodeClass(const NodeClass::Enum nodeClass);
		NodeClass::Enum nodeClass(void);
		void typeDefinition(const OpcUaExpandedNodeId::SPtr typeDefinition);
		OpcUaExpandedNodeId::SPtr typeDefinition(void) const;
		
		void copyTo(ReferenceDescription& referenceDescription);
		void out(std::ostream& os) const {};

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return false; }
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return false; }

	protected:
		bool jsonEncodeImpl(boost::property_tree::ptree &pt) const override;
		bool jsonDecodeImpl(const boost::property_tree::ptree &pt) override;

	private:
		OpcUaNodeId::SPtr referenceTypeIdSPtr_;
		OpcUaBoolean isForward_;
		OpcUaExpandedNodeId::SPtr nodeIdSPtr_;
		OpcUaQualifiedName browseName_;
		OpcUaLocalizedText displayName_;
		NodeClass::Enum nodeClass_;
		OpcUaExpandedNodeId::SPtr typeDefinitionSPtr_;
	};

	class DLLEXPORT ReferenceDescriptionArray
	: public OpcUaArray<ReferenceDescription::SPtr, SPtrTypeCoder<ReferenceDescription> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<ReferenceDescriptionArray> SPtr;
	};

}

#endif
