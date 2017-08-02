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

/*

 	 SimpleAttributeOperand:
 	 	 IN: TypeNodeId, BrowseNames
 	 	 OUT: Variant

 */

#ifndef __OpcUaStackCore_EventBase_h__
#define __OpcUaStackCore_EventBase_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{

	class DLLEXPORT EventBase
	{
	  public:
		typedef boost::shared_ptr<EventBase> SPtr;

		EventBase(void);
		virtual ~EventBase(void);

		uint32_t findNamespaceIndex(const std::string& namespaceUri);

		virtual void mapNamespaceUri(void);
		virtual OpcUaVariant::SPtr get(
			OpcUaNodeId& eventType,
			bool eventTypeFound,
			std::list<OpcUaQualifiedName::SPtr>& browseNameList,
			bool& error
		);

	  private:
	};


}

#endif
