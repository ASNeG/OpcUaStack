/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/ServiceSetApplication/NamespaceInfoResponse.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa NamespaceInfoResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	NamespaceInfoResponse::NamespaceInfoResponse(void)
	: Object()
	, index2NamespaceMap_()
	, namespace2IndexMap_()
	{
	}

	NamespaceInfoResponse::~NamespaceInfoResponse(void)
	{
	}

	NamespaceInfoResponse::Index2NamespaceMap&
	NamespaceInfoResponse::index2NamespaceMap(void)
	{
		return index2NamespaceMap_;
	}

	NamespaceInfoResponse::Namespace2IndexMap&
	NamespaceInfoResponse::namespace2IndexMap(void)
	{
		return namespace2IndexMap_;
	}

	bool
	NamespaceInfoResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		return false;
	}

	bool
	NamespaceInfoResponse::opcUaBinaryDecode(std::istream& is)
	{
		return false;
	}
}



