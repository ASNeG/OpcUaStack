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

#ifndef __OpcUaStackCore_AddSessionRequest_h__
#define __OpcUaStackCore_AddSessionRequest_h__

#include <boost/shared_ptr.hpp>
#include <stdint.h>
#include <iostream>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT AddSessionRequest
	{
	  public:
		using SPtr = boost::shared_ptr<AddSessionRequest>;

		AddSessionRequest(void);
		virtual ~AddSessionRequest(void);

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
	};

}

#endif
