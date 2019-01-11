/*
   Copyright 2017-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_ForwardCallback_h__
#define __OpcUaStackCore_ForwardCallback_h__

#include "OpcUaStackCore/Base/BaseClass.h"
#include "OpcUaStackCore/Base/Callback.h"


namespace OpcUaStackCore
{

	class DLLEXPORT ForwardCallback
	{
	  public:
		typedef boost::shared_ptr<ForwardCallback> SPtr;

		ForwardCallback(void);
		~ForwardCallback(void);

		void updateFrom(ForwardCallback& forwardInfo);
		void setCallback(Callback& callback);
		template<typename T>
		  void setCallback(T handler) {
			  Callback callback;
			  callback.reset(handler);
			  setCallback(callback);
		  }
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

}

#endif
