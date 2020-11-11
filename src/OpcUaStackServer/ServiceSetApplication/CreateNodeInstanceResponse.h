/*
   Copyright 2017-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_CreateNodeInstanceResponse_h__
#define __OpcUaStackServer_CreateNodeInstanceResponse_h__

#include "OpcUaStackCore/Base/Object.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

namespace OpcUaStackServer
{

	class DLLEXPORT CreateNodeInstanceResponse
	: public OpcUaStackCore::Object
	{
	  public:
		using SPtr = boost::shared_ptr<CreateNodeInstanceResponse>;

		CreateNodeInstanceResponse(void);
		virtual ~CreateNodeInstanceResponse(void);

		void baseNodeClass(OpcUaStackServer::BaseNodeClass::WPtr& baseNodeClass);
		OpcUaStackServer::BaseNodeClass::WPtr& baseNodeClass(void);

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaStackServer::BaseNodeClass::WPtr baseNodeClass_;// base class reference of the created node
	};

}

#endif
