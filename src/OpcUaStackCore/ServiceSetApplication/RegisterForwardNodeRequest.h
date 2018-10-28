/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_RegisterForwardNodeRequest_h__
#define __OpcUaStackCore_RegisterForwardNodeRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSetApplication/ForwardNodeSync.h"

namespace OpcUaStackCore
{

	class DLLEXPORT RegisterForwardNodeRequest
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<RegisterForwardNodeRequest> SPtr;

		RegisterForwardNodeRequest(void);
		virtual ~RegisterForwardNodeRequest(void);

		void nodesToRegister(const OpcUaNodeIdArray::SPtr nodesToRegister);
		OpcUaNodeIdArray::SPtr nodesToRegister(void) const;
		void forwardNodeSync(ForwardNodeSync::SPtr forwardInfo);
		ForwardNodeSync::SPtr forwardNodeSync(void);
		void applicationContextArray(BaseClassArray::SPtr& applicationContextArray);
		BaseClassArray::SPtr& applicationContextArray(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ForwardNodeSync::SPtr forwardNodeSync_;
		OpcUaNodeIdArray::SPtr nodesToRegisterArraySPtr_;
		BaseClassArray::SPtr applicationContextArray_;
	};

}

#endif
