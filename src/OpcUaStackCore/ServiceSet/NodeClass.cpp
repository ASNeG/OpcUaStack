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

#include "OpcUaStackCore/ServiceSet/NodeClass.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// MethodAttributes
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	NodeClass::NodeClass(void)
		: nodeClassType_(NodeClassType_Unspecified)
	{
	}

	NodeClass::~NodeClass(void)
	{
	}

	 NodeClassType
     NodeClass::nodeClassType(void) const
	 {
		 return nodeClassType_;
	 }

	void
	NodeClass::nodeClassType(
		const NodeClassType nodeClassType)
	{
		nodeClassType_ = nodeClassType;		
	}
		
	void 
	NodeClass::opcUaBinaryEncode(
		std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)nodeClassType_);
	}
	
	void 
	NodeClass::opcUaBinaryDecode(
		std::istream& is)
	{
		OpcUaUInt32 nodeClassType;
		OpcUaNumber::opcUaBinaryDecode(is, nodeClassType);
		nodeClassType_ = (NodeClassType)nodeClassType;
	}

}
