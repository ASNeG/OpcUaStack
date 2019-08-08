/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/BuildInTypes/XmlnsGuard.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	XmlnsGuard::XmlnsGuard(boost::property_tree::ptree& nodeSetElement, Xmlns& xmlns)
	: xmlnsCopy_()
	, xmlnsAct_(nullptr)
	{
		xmlnsCopy_ = xmlns;
		xmlnsAct_ = &xmlns;

		Xmlns xmlnsNew;
		xmlnsNew.addNamespaceFromNodeSetElement(nodeSetElement);
		//xmlnsNew.log("NEW");

		std::vector<std::string> uris;
		std::vector<std::string>::iterator it;
		xmlnsNew.getUris(uris);

		for (it = uris.begin(); it != uris.end(); it++) {
			std::string uri = *it;
			std::string prefix = xmlnsNew.getPrefix(uri);
			xmlnsAct_->addNamespace(prefix, uri);
		}
	}

	XmlnsGuard::~XmlnsGuard(void)
	{
		xmlnsAct_->clear();
		*xmlnsAct_ = xmlnsCopy_;
	}

}
