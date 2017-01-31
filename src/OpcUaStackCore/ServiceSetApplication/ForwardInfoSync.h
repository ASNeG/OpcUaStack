/*
   Copyright 2015-2016 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_ForwardInfoSync_h__
#define __OpcUaStackCore_ForwardInfoSync_h__

#include "OpcUaStackCore/Base/BaseClass.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/Callback.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ForwardInfo
	{
	  public:
		typedef boost::shared_ptr<ForwardInfo> SPtr;

		ForwardInfo(void);
		~ForwardInfo(void);

		void updateFrom(ForwardInfo& forwardInfo);
		void setCallback(Callback& callback);
		void unsetCallback(void);
		bool isCallback(void);
		bool usedCallback(void);
		Callback& callback(void);

		void applicationContext(BaseClass::SPtr& applicationContext);
		BaseClass::SPtr& applicationContext(void);

	  private:
		bool callbackFlag_;
		bool usedCallbackFlag_;
		Callback callback_;
		BaseClass::SPtr applicationContext_;
	};


	class DLLEXPORT ForwardInfoSync
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<ForwardInfoSync> SPtr;

		ForwardInfoSync(void);
		virtual ~ForwardInfoSync(void);

		ForwardInfo& readService(void);
		ForwardInfo& readHService(void);
		ForwardInfo& writeService(void);
		ForwardInfo& writeHService(void);
		ForwardInfo& methodService(void);
		ForwardInfo& monitoredItemStartService(void);
		ForwardInfo& monitoredItemStopService(void);

		void updateFrom(ForwardInfoSync& forwardInfoSync);

	  private:
		// attribute service
		ForwardInfo readService_;
		ForwardInfo readHService_;
		ForwardInfo writeService_;
		ForwardInfo writeHService_;
		ForwardInfo monitoredItemStartService_;
		ForwardInfo monitoredItemStopService_;

		// method service
		ForwardInfo methodService_;
	};

}

#endif
