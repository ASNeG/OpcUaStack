/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackClient_EndpointDescriptionCache_h__
#define __OpcUaStackClient_EndpointDescriptionCache_h__

#include <boost/thread/mutex.hpp>
#include "OpcUaStackCore/StandardDataTypes/EndpointDescription.h"

namespace OpcUaStackClient 
{

	class DLLEXPORT EndpointDescriptionCache
	{
	  public:
		typedef boost::shared_ptr<EndpointDescriptionCache> SPtr;
		typedef std::map<std::string, OpcUaStackCore::EndpointDescriptionArray::SPtr> EndpointDescriptionMap;

		EndpointDescriptionCache(void);
		~EndpointDescriptionCache(void);

		static EndpointDescriptionCache& instance(void)
		{
			static EndpointDescriptionCache instance_;
			return instance_;
		}

		uint32_t size(void);
		void clear(void);
		void insertEndpointDescription(
			const std::string& endpointUrl,
			OpcUaStackCore::EndpointDescriptionArray::SPtr& endpointDescriptionArray
		);
		void deleteEndpointDescription(
			const std::string& endpointUrl
		);
		OpcUaStackCore::EndpointDescriptionArray::SPtr getEndpointDescription(
			const std::string& endpointUrl
		);
		void getEndpointUrls(std::vector<std::string>& endpointUrls);

	  private:
		boost::mutex mutex_;
		EndpointDescriptionMap endpointDescriptionMap_;
	};

}

#endif
