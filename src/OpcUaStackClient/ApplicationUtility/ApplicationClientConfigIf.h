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

#ifndef __OpcUaStackClient_ApplicationClientConfigIf_h__
#define __OpcUaStackClient_ApplicationClientConfigIf_h__

#include "OpcUaStackCore/ApplicationUtility/ApplicationConfigIf.h"

namespace OpcUaStackClient
{

	class DLLEXPORT ApplicationClientConfigIf
	{
	  public:
		ApplicationClientConfigIf(void) {}
		virtual ~ApplicationClientConfigIf(void) {}

		virtual void clientNamespaces(NamespaceElement::Vec& namespaceElementVec) = 0;
		virtual void clientVariables(VariableElement::Vec& variableElementVec) = 0;
	};

}

#endif
