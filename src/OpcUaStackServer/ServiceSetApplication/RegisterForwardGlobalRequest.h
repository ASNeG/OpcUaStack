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

#ifndef __OpcUaStackServer_RegisterForwardGlobalRequest_h__
#define __OpcUaStackServer_RegisterForwardGlobalRequest_h__

#include "OpcUaStackCore/ServiceSetApplication/ForwardGlobalSync.h"

namespace OpcUaStackServer
{

	class DLLEXPORT RegisterForwardGlobalRequest
	: public OpcUaStackCore::Object
	{
	  public:
		typedef boost::shared_ptr<RegisterForwardGlobalRequest> SPtr;

		RegisterForwardGlobalRequest(void);
		virtual ~RegisterForwardGlobalRequest(void);

		void forwardGlobalSync(OpcUaStackCore::ForwardGlobalSync::SPtr forwardGlobalSync);
		OpcUaStackCore::ForwardGlobalSync::SPtr forwardGlobalSync(void);

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaStackCore::ForwardGlobalSync::SPtr forwardGlobalSync_;
	};

}

#endif
