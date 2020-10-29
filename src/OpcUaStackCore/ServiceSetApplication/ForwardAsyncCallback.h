/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_ForwardAsyncCallback_h__
#define __OpcUaStackCore_ForwardAsyncCallback_h__

#include "OpcUaStackCore/Base/BaseClass.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ForwardAsyncCallback
	{
	  public:
		using SPtr = boost::shared_ptr<ForwardAsyncCallback>;

		ForwardAsyncCallback(void);
		~ForwardAsyncCallback(void);

		void updateFrom(ForwardAsyncCallback& forwardInfo);
		bool isUsed(void);
		void activate(BaseClass::SPtr& applicationContext);
		void deactivate(void);
		bool isActive(void);
		BaseClass::SPtr& applicationContext(void);

	  private:
		bool used_ = false;			// indicates whether the variable is used
		bool active_ = false;		// active/deactivate
		BaseClass::SPtr applicationContext_ = nullptr;
	};

}

#endif
