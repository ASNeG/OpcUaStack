/*
   Copyright 2017-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_EventBase_h__
#define __OpcUaStackCore_EventBase_h__

#include <boost/shared_ptr.hpp>
#include <OpcUaStackCore/EventType/EventResult.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaVariant.h"
#include "OpcUaStackCore/Filter/SimpleAttributeIf.h"

namespace OpcUaStackCore
{

	class DLLEXPORT EventBase
	: public SimpleAttributeIf
	{
	  public:
		typedef boost::shared_ptr<EventBase> SPtr;

		EventBase(void);
		virtual ~EventBase(void);

		void namespaceArray(std::vector<std::string>* namespaceArray);
		bool setNamespaceIndex(
			const std::string& namespaceUri_,
			uint32_t& namespaceIndex,
			OpcUaQualifiedName& browseName_,
			OpcUaVariant::SPtr& eventType_
		);

		EventResult::Code get(
			OpcUaNodeId& eventType,
			std::list<OpcUaQualifiedName::SPtr>& browseNameList,
			OpcUaVariant::SPtr& variant
		);

		virtual void mapNamespaceUri(void);

		virtual OpcUaVariant::SPtr get(
			OpcUaNodeId& eventType,
			std::list<OpcUaQualifiedName::SPtr>& browseNameList,
			EventResult::Code& resultCode
		);

		//- SimpleAttributeIf -------------------------------------------------
	    virtual bool getAttribute(
	        OpcUaNodeId& typeId,
			std::list<OpcUaQualifiedName::SPtr>& browsePath,
			OpcUaUInt32 attributeId,
			OpcUaString& numericRange,
			OpcUaVariant& value
		);
		//- SimpleAttributeIf -------------------------------------------------

	  private:
	    int32_t findNamespaceIndex(const std::string& namespaceUri);

		std::vector<std::string>* namespaceArray_;
	};


}

#endif
