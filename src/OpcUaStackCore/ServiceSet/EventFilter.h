/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_EventFilter_h__
#define __OpcUaStackCore_EventFilter_h__

#include <boost/shared_ptr.hpp>
#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/SimpleAttributeOperand.h"
#include "OpcUaStackCore/ServiceSet/ContentFilter.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT EventFilter
	: public  Object
	, public ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<EventFilter> SPtr;

		EventFilter(void);
		virtual ~EventFilter(void);

		void selectClauses(const SimpleAttributeOperandArray::SPtr selectClauses);
		SimpleAttributeOperandArray::SPtr selectClauses(void) const;
		void whereClause(const ContentFilter& whereClause);
		ContentFilter& whereClause(void);
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::SPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		SimpleAttributeOperandArray::SPtr selectClausesArraySPtr_;
		ContentFilter whereClause_;
	};

}

#endif
