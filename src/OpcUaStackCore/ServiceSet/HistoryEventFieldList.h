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

#ifndef __OpcUaStackCore_HistoryEventFieldList_h__
#define __OpcUaStackCore_HistoryEventFieldList_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/EventField.h"

namespace OpcUaStackCore
{

	class DLLEXPORT HistoryEventFieldList
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<HistoryEventFieldList> SPtr;

		HistoryEventFieldList(void);
		virtual ~HistoryEventFieldList(void);

		void eventFields(const EventFieldArray::SPtr eventFieldsSPtr);
		EventFieldArray::SPtr eventFields(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		EventFieldArray::SPtr eventFieldsSPtr_;
	};

	class HistoryEventFieldListArray
	: public OpcUaArray<HistoryEventFieldList::SPtr, SPtrTypeCoder<HistoryEventFieldList> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<HistoryEventFieldListArray> SPtr;
	};

}

#endif
