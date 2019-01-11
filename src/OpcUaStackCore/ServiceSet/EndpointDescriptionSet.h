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

#ifndef __OpcUaStackCore_EndpointDescriptionSet_h__
#define __OpcUaStackCore_EndpointDescriptionSet_h__

#include "OpcUaStackCore/StandardDataTypes/EndpointDescription.h"
#include "OpcUaStackCore/ServiceSet/EndpointDescriptionSet.h"

namespace OpcUaStackCore
{

	typedef std::multimap<std::string, EndpointDescription::SPtr> EndpointDescriptionMultimap;

	class DLLEXPORT EndpointDescriptionSet
	{
	  public:
		typedef boost::shared_ptr<EndpointDescriptionSet> SPtr;

		EndpointDescriptionSet(void);
		~EndpointDescriptionSet(void);

		void addEndpoint(const std::string& endpointUrl, EndpointDescription::SPtr& endpointDescription);
		void getEndpoints(const std::string& endpointUrl, EndpointDescriptionArray::SPtr& endpointDescriptionArray);
		void getEndpoints(EndpointDescriptionArray::SPtr& endpointDescriptionArray);
		void getEndpointUrls(std::vector<std::string>& endpointUrls);

	  private:
		EndpointDescriptionMultimap endpointDescriptionMap_;
	};

}

#endif
