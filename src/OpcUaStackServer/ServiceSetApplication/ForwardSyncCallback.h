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

#ifndef __OpcUaStackServer_ForwardSyncCallback_h__
#define __OpcUaStackServer_ForwardSyncCallback_h__

#include "OpcUaStackCore/Base/BaseClass.h"

namespace OpcUaStackServer
{

    template<typename CallbackFunction>
	  class DLLEXPORT ForwardSyncCallback
	  {
	    public:
    	  using SPtr = boost::shared_ptr<ForwardSyncCallback>;

		  ForwardSyncCallback(void)
		  {
		  }

		  ~ForwardSyncCallback(void)
		  {
		  }

		  void updateFrom(ForwardSyncCallback& forwardInfo)
		  {
				// set or unset callback
				if (forwardInfo.usedCallback()) {
					if (forwardInfo.isCallback()) {
						setCallback(forwardInfo.callback());
						applicationContext_ = forwardInfo.applicationContext();
					}
					else {
						unsetCallback();
						applicationContext_.reset();
					}
				}
		  }

		  void setCallback(CallbackFunction callback)
		  {
				callback_ = callback;
				callbackFlag_ = true;
				usedCallbackFlag_ = true;
		  }

		  void unsetCallback(void)
		  {
			  callbackFlag_ = false;
			  usedCallbackFlag_ = true;
		  }

		  bool isCallback(void)
		  {
			  return callbackFlag_;
		  }

		  bool usedCallback(void)
		  {
			  return usedCallbackFlag_;
		  }

		  CallbackFunction callback(void)
		  {
			  return callback_;
		  }

		  void applicationContext(OpcUaStackCore::BaseClass::SPtr& applicationContext)
		  {
			  applicationContext_ = applicationContext;
		  }

		  OpcUaStackCore::BaseClass::SPtr& applicationContext(void)
		  {
			  return applicationContext_;
		  }

	    private:
		  bool callbackFlag_ = false;
		  bool usedCallbackFlag_ = false;
		  CallbackFunction callback_ = nullptr;
		  OpcUaStackCore::BaseClass::SPtr applicationContext_ = nullptr;
	  };

}

#endif
