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

#include "OpcUaStackCore/ServiceSet/ReferenceDescription.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ReferenceDescription
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ReferenceDescription::ReferenceDescription(void)
	: Object()
	, referenceTypeIdSPtr_()
	, isForward_()
	, nodeIdSPtr_(boost::make_shared<OpcUaExpandedNodeId>())
	, browseName_()
	, displayName_()
	, nodeClass_()
	, typeDefinitionSPtr_(boost::make_shared<OpcUaExpandedNodeId>())
	{
		referenceTypeIdSPtr_ = boost::make_shared<OpcUaNodeId>();
	}

	ReferenceDescription::~ReferenceDescription(void)
	{
	}

	void 
	ReferenceDescription::referenceTypeId(const OpcUaNodeId::SPtr referenceTypeId)
	{
		referenceTypeIdSPtr_ = referenceTypeId;
	}
	
	OpcUaNodeId::SPtr 
	ReferenceDescription::referenceTypeId(void) const
	{
		return referenceTypeIdSPtr_;
	}
	
	void 
	ReferenceDescription::isForward(const OpcUaBoolean& isForward)
	{
		isForward_ = isForward;
	}
	
	OpcUaBoolean 
	ReferenceDescription::isForward(void)
	{
		return isForward_;
	}
	
	void 
	ReferenceDescription::expandedNodeId(const OpcUaExpandedNodeId::SPtr nodeId)
	{
		nodeIdSPtr_ = nodeId;
	}
	
	OpcUaExpandedNodeId::SPtr 
	ReferenceDescription::expandedNodeId(void) const
	{
		return nodeIdSPtr_;
	}

	void 
	ReferenceDescription::browseName(const OpcUaQualifiedName& browseName)
	{
		browseName_ = browseName;
	}
	
	OpcUaQualifiedName& 
	ReferenceDescription::browseName(void)
	{
		return browseName_;
	}
	
	void 
	ReferenceDescription::displayName(const OpcUaLocalizedText& displayName)
	{
		displayName_ = displayName;
	}
	
	OpcUaLocalizedText& 
	ReferenceDescription::displayName(void)
	{
		return displayName_;
	}

	void 
	ReferenceDescription::nodeClass(const NodeClass::Enum nodeClass)
	{
		nodeClass_ = nodeClass;
	}
	
	NodeClass::Enum
	ReferenceDescription::nodeClass(void)
	{
		return nodeClass_;
	}
	
	void 
	ReferenceDescription::typeDefinition(const OpcUaExpandedNodeId::SPtr typeDefinition)
	{
		typeDefinitionSPtr_ = typeDefinition;
	}
	
	OpcUaExpandedNodeId::SPtr 
	ReferenceDescription::typeDefinition(void) const
	{
		return typeDefinitionSPtr_;
	}

	void
	ReferenceDescription::copyTo(ReferenceDescription& referenceDescription)
	{
		referenceTypeIdSPtr_->copyTo(*referenceDescription.referenceTypeId().get());
		referenceDescription.isForward(isForward_);
		nodeIdSPtr_->copyTo(*referenceDescription.expandedNodeId().get());
		browseName_.copyTo(referenceDescription.browseName());
		displayName_.copyTo(referenceDescription.displayName());
		referenceDescription.nodeClass(nodeClass_);
		typeDefinitionSPtr_->copyTo(*referenceDescription.typeDefinition().get());
	}

	bool
	ReferenceDescription::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= referenceTypeIdSPtr_->opcUaBinaryEncode(os);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, isForward_);
		rc &= nodeIdSPtr_->opcUaBinaryEncode(os);
		rc &= browseName_.opcUaBinaryEncode(os);
		rc &= displayName_.opcUaBinaryEncode(os);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)nodeClass_);
		rc &= typeDefinitionSPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	ReferenceDescription::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		OpcUaUInt32 tmp;
		rc &= referenceTypeIdSPtr_->opcUaBinaryDecode(is);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, isForward_);
		rc &= nodeIdSPtr_->opcUaBinaryDecode(is);
		rc &= browseName_.opcUaBinaryDecode(is);
		rc &= displayName_.opcUaBinaryDecode(is);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, tmp);
		nodeClass_ = (NodeClass::Enum)tmp;
		rc &= typeDefinitionSPtr_->opcUaBinaryDecode(is);

		return rc;
	}

	bool
	ReferenceDescription::jsonEncodeImpl(boost::property_tree::ptree &pt) const
	{
		bool rc = jsonObjectSPtrEncode(pt, referenceTypeIdSPtr_, "ReferenceTypeId");
		rc &= jsonNumberEncode(pt, isForward_, "IsForward");
		rc &= jsonObjectSPtrEncode(pt, nodeIdSPtr_, "NodeId");
		rc &= jsonObjectEncode(pt, browseName_, "BrowseName", true);
		rc &= jsonObjectEncode(pt, displayName_, "DisplayName");
		rc &= jsonNumberEncode(pt, (OpcUaUInt32)nodeClass_, "NodeClass", true, OpcUaUInt32(0));
		rc &= jsonObjectSPtrEncode(pt, typeDefinitionSPtr_, "TypeDefinition", true);

		return rc;
	}

	bool
	ReferenceDescription::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	{
		bool rc = jsonObjectSPtrDecode(pt, referenceTypeIdSPtr_, "ReferenceTypeId");
		rc &= jsonNumberDecode(pt, isForward_, "IsForward");
		rc &= jsonObjectSPtrDecode(pt, nodeIdSPtr_, "NodeId");
		rc &= jsonObjectDecode(pt, browseName_, "BrowseName", true);
		rc &= jsonObjectDecode(pt, displayName_, "DisplayName");

		OpcUaUInt32  tmp;
		rc &= jsonNumberDecode(pt, tmp, "NodeClass", true, OpcUaUInt32(0));
		nodeClass_ = (NodeClass::Enum)tmp;

		rc &= jsonObjectSPtrDecode(pt, typeDefinitionSPtr_, "TypeDefinition", true);

		return rc;
	}

}
