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

#ifndef __OpcUaStackServer_ForwardNodeAsync_h__
#define __OpcUaStackServer_ForwardNodeAsync_h__

#include "OpcUaStackCore/ServiceSetApplication/ForwardAsyncCallback.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ForwardNodeAsync
	: public OpcUaStackCore::Object
	{
	  public:
		using SPtr = boost::shared_ptr<ForwardNodeAsync>;

		ForwardNodeAsync(void);
		virtual ~ForwardNodeAsync(void);

		OpcUaStackCore::ForwardAsyncCallback& readService(void);
		OpcUaStackCore::ForwardAsyncCallback& writeService(void);
		OpcUaStackCore::ForwardAsyncCallback& methodService(void);

		void updateFrom(ForwardNodeAsync& forwardInfoAsync);

	  private:
		// attribute service
		OpcUaStackCore::ForwardAsyncCallback readService_;
		OpcUaStackCore::ForwardAsyncCallback writeService_;

		// method service
		OpcUaStackCore::ForwardAsyncCallback methodService_;
	};

}

#endif
