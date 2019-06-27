/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_UpdateEventDetails_h__
#define __OpcUaStackCore_UpdateEventDetails_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"
#include "OpcUaStackCore/ServiceSet/EventFilter.h"
#include "OpcUaStackCore/ServiceSet/EventFieldList.h"
#include "OpcUaStackCore/ServiceSet/PerformUpdateEnumeration.h"

namespace OpcUaStackCore
{

	class DLLEXPORT UpdateEventDetails
	: public  Object
	, public ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<UpdateEventDetails> SPtr;

		UpdateEventDetails(void);
		virtual ~UpdateEventDetails(void);

		void nodeId(const OpcUaNodeId& nodeId);
		OpcUaNodeId& nodeId(void);
		void performInsertReplace(const PerformUpdateEnumeration performInsertReplace);
		PerformUpdateEnumeration performInsertReplace(void);
		void filter(const EventFilter& filter);
		EventFilter& filter(void);
		void eventData(const EventFieldListArray::SPtr eventData);
		EventFieldListArray::SPtr eventData(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::SPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		OpcUaNodeId nodeId_;
		PerformUpdateEnumeration performInsertReplace_;
		EventFilter filter_;
		EventFieldListArray::SPtr eventDataArraySPtr_; // TODO Check Type.
	};

}

#endif
