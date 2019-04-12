/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include <OpcUaStackCore/ServiceSet/EndpointDescriptionSet.h>

namespace OpcUaStackCore
{

	EndpointDescriptionSet::EndpointDescriptionSet(void)
	: endpointDescriptionMap_()
	{
	}

	EndpointDescriptionSet::~EndpointDescriptionSet(void)
	{
	}

	void
	EndpointDescriptionSet::addEndpoint(const std::string& endpointUrl, EndpointDescription::SPtr& endpointDescription)
	{
		endpointDescriptionMap_.insert(std::make_pair(endpointUrl, endpointDescription));
	}

	void
	EndpointDescriptionSet::getEndpoints(const std::string& endpointUrl, EndpointDescriptionArray::SPtr& endpointDescriptionArray)
	{
		auto ret = endpointDescriptionMap_.equal_range(endpointUrl);

		uint32_t count = endpointDescriptionMap_.count(endpointUrl);
		if (count == 0) return;

		endpointDescriptionArray->resize(count);
		for (auto it = ret.first; it != ret.second; it++) {
			EndpointDescription::SPtr endpointDescription = it->second;
			endpointDescriptionArray->push_back(endpointDescription);
		}
	}

	void
	EndpointDescriptionSet::getEndpoints(EndpointDescriptionArray::SPtr& endpointDescriptionArray)
	{
		endpointDescriptionArray->resize(endpointDescriptionMap_.size());

		for (auto it = endpointDescriptionMap_.begin(); it != endpointDescriptionMap_.end(); it++) {
			endpointDescriptionArray->push_back(it->second);
		}
	}

	void
	EndpointDescriptionSet::getEndpointUrls(std::vector<std::string>& endpointUrls)
	{
		std::set<std::string> endpointSet;

		for (auto it = endpointDescriptionMap_.begin(); it != endpointDescriptionMap_.end(); it++) {
			if (endpointSet.insert(it->first).second) {
				endpointUrls.push_back(it->first);
			}
		}
	}

}
