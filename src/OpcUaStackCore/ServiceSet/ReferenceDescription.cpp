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
	: ObjectPool<ReferenceDescription>()
	, referenceTypeIdSPtr_(OpcUaNodeId::construct())
	, isForward_()
	, nodeIdSPtr_(OpcUaExpandedNodeId::construct())
	, browseName_()
	, displayName_()
	, nodeClass_()
	, typeDefinitionSPtr_(OpcUaExpandedNodeId::construct())
	{
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
	ReferenceDescription::nodeId(const OpcUaExpandedNodeId::SPtr nodeId)
	{
		nodeIdSPtr_ = nodeId;
	}
	
	OpcUaExpandedNodeId::SPtr 
	ReferenceDescription::nodeId(void) const
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
	ReferenceDescription::nodeClass(const NodeClass nodeClass)
	{
		nodeClass_ = nodeClass;
	}
	
	NodeClass 
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
	ReferenceDescription::opcUaBinaryEncode(std::ostream& os) const
	{
		referenceTypeIdSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, isForward_);
		nodeIdSPtr_->opcUaBinaryEncode(os);
		browseName_.opcUaBinaryEncode(os);
		displayName_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)nodeClass_);
		typeDefinitionSPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	ReferenceDescription::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		referenceTypeIdSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, isForward_);
		nodeIdSPtr_->opcUaBinaryDecode(is);
		browseName_.opcUaBinaryDecode(is);
		displayName_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		nodeClass_ = (NodeClass)tmp;
		typeDefinitionSPtr_->opcUaBinaryDecode(is);
	}

}