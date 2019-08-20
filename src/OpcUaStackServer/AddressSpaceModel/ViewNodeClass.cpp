/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/AddressSpaceModel/ViewNodeClass.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	ViewNodeClass::ViewNodeClass(void)
	: BaseNodeClass(NodeClass::EnumView)
	, containsNoLoops_()
	, eventNotifier_()
	{
	}

	ViewNodeClass::~ViewNodeClass(void)
	{
	}

	ContainsNoLoopsAttribute& 
	ViewNodeClass::containsNoLoops(void)
	{
		return containsNoLoops_;
	}
		
	EventNotifierAttribute& 
	ViewNodeClass::eventNotifier(void)
	{
		return eventNotifier_;
	}

	Attribute* 
	ViewNodeClass::containsNoLoopsAttribute(void)
	{
		return &containsNoLoops_;
	}
		
	Attribute* 
	ViewNodeClass::eventNotifierAttribute(void)
	{
		return &eventNotifier_;
	}

	void
	ViewNodeClass::copyTo(ViewNodeClass::SPtr viewNodeClass)
	{
		copyTo(*viewNodeClass);
	}

	void
	ViewNodeClass::copyTo(ViewNodeClass& viewNodeClass)
	{
		BaseNodeClass::copyTo(viewNodeClass);
		containsNoLoopsAttribute()->copyTo(viewNodeClass.containsNoLoopsAttribute());
		eventNotifierAttribute()->copyTo(viewNodeClass.eventNotifierAttribute());
	}

	BaseNodeClass::SPtr
	ViewNodeClass::clone(void)
	{
		ViewNodeClass::SPtr viewNodeClass = boost::make_shared<ViewNodeClass>();
		copyTo(viewNodeClass);
		return viewNodeClass;
	}

}
