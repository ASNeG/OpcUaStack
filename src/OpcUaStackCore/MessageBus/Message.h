/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_Message_h__
#define __OpcUaStackCore_Message_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT Message
	{
	  public:
		typedef boost::shared_ptr<Message> SPtr;

		typedef enum {
			Unknown,
			ServiceTransaction,
			ForwardTransaction,
			CutomerTransaction1,
			CutomerTransaction2,
			CutomerTransaction3,
			CutomerTransaction4,
			CutomerTransaction5,
		} Type_t;

		Message(Type_t type)
		: type_(type)
		{
		}

		virtual ~Message(void)
		{
		}

		uint32_t sequence_ = 0;
		Type_t type_ = Unknown;

	  private:
		Message(void) {}
	};

}

#endif
