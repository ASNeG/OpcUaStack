/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_Session_h__
#define __OpcUaStackServer_Session_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelServer.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT ChannelSessionHandle
	{
	  public:

		typedef boost::shared_ptr<ChannelSessionHandle> SPtr;

		typedef enum
		{
			SCSS_Ready,
			SCSS_Invalid
		} SecureChannelServerState;

		ChannelSessionHandle(void);
		~ChannelSessionHandle(void);

	  private:
		SecureChannelServerState secureChannelServerState_;
		SecureChannelServer* secureChannelServer_;
	};

}

#endif
