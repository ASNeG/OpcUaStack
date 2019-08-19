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

#ifndef __OpcUaStackServer_ServiceSetBase_h__
#define __OpcUaStackServer_ServiceSetBase_h__

#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackCore/ServiceSetApplication/ForwardGlobalSync.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"
#include "OpcUaStackServer/InformationModel/NamespaceArray.h"
#include "OpcUaStackServer/InformationModel/ServerArray.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ServiceSetBase
	: public OpcUaStackCore::Component
	{
	  public:
		ServiceSetBase(void);
		virtual ~ServiceSetBase(void);

		void informationModel(InformationModel::SPtr informationModel);
		InformationModel::SPtr informationModel(void);
		NamespaceArray::SPtr namespaceArray(void);
		ServerArray::SPtr serverArray(void);
		void forwardGlobalSync(OpcUaStackCore::ForwardGlobalSync::SPtr forwardGlobalSync);
		OpcUaStackCore::ForwardGlobalSync::SPtr forwardGlobalSync(void);

		virtual bool init(void) { return true; }
		virtual bool shutdown(void) { return true; }

	  protected:
		InformationModel::SPtr informationModel_;
		NamespaceArray::SPtr namespaceArray_;
		ServerArray::SPtr serverArray_; 
		OpcUaStackCore::ForwardGlobalSync::SPtr forwardGlobalSync_;
	};

}

#endif
