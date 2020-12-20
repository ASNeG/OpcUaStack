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

#ifndef __OpcUaStackCore_ForwardMethodSync_h__
#define __OpcUaStackCore_ForwardMethodSync_h__

#include <OpcUaStackCore/ServiceSetApplication/ForwardSyncCallback.h>
#include "OpcUaStackCore/Application/ApplicationCallback.h"
#include "OpcUaStackCore/Application/ApplicationMethodContext.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ForwardMethodSync
	: public OpcUaStackCore::Object
	{
	  public:
		using SPtr = boost::shared_ptr<ForwardMethodSync>;

		ForwardMethodSync(void);
		virtual ~ForwardMethodSync(void);

		OpcUaStackCore::ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::Method>& methodService(void);

		void updateFrom(ForwardMethodSync& forwardInfoSync);

	  private:
		OpcUaStackCore::ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::Method> methodService_;
	};

}

#endif
