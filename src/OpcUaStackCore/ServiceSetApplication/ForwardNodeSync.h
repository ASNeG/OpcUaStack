/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_ForwardNodeSync_h__
#define __OpcUaStackCore_ForwardNodeSync_h__

#include "OpcUaStackCore/Base/BaseClass.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/Callback.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSetApplication/ForwardCallback.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ForwardNodeSync
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<ForwardNodeSync> SPtr;

		ForwardNodeSync(void);
		virtual ~ForwardNodeSync(void);

		ForwardCallback& readService(void);
		ForwardCallback& readHService(void);
		ForwardCallback& readHEService(void);
		ForwardCallback& writeService(void);
		ForwardCallback& writeHService(void);
		ForwardCallback& methodService(void);
		ForwardCallback& monitoredItemStartService(void);
		ForwardCallback& monitoredItemStopService(void);

		void updateFrom(ForwardNodeSync& forwardInfoSync);

	  private:
		// attribute service
		ForwardCallback readService_;
		ForwardCallback readHService_;
		ForwardCallback readHEService_;
		ForwardCallback writeService_;
		ForwardCallback writeHService_;
		ForwardCallback monitoredItemStartService_;
		ForwardCallback monitoredItemStopService_;

		// method service
		ForwardCallback methodService_;
	};

}

#endif
