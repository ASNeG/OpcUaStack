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

#ifndef __OpcUaStackServer_NodeReferenceApplication_h__
#define __OpcUaStackServer_NodeReferenceApplication_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/ServiceSetApplication/NodeReference.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT NodeReferenceApplication
	: public NodeReference
	{
	  public:
		typedef boost::shared_ptr<NodeReferenceApplication> SPtr;

		NodeReferenceApplication(void);
		virtual ~NodeReferenceApplication(void);

		void baseNodeClass(BaseNodeClass::WPtr baseNodeClass);
		BaseNodeClass::WPtr baseNodeClass(void);

	  private:
		BaseNodeClass::WPtr baseNodeClass_;
	};

}
#endif
