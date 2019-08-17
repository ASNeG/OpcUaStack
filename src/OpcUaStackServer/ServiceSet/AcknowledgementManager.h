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

#ifndef __OpcUaStackServer_AcknowledgementManager_h__
#define __OpcUaStackServer_AcknowledgementManager_h__

#include <list>
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensibleParameter.h"

namespace OpcUaStackServer
{

	class DLLEXPORT AcknowledgementElement
	{
	  public:
		typedef boost::shared_ptr<AcknowledgementElement> SPtr;

		AcknowledgementElement(void);
		~AcknowledgementElement(void);

		void sequenceNumber(uint32_t sequenceNumber);
		uint32_t sequenceNumber(void);
		void notification(OpcUaStackCore::OpcUaExtensibleParameter::SPtr& notification);
		OpcUaStackCore::OpcUaExtensibleParameter::SPtr notification(void);

	  private:
		uint32_t sequenceNumber_;
		OpcUaStackCore::OpcUaExtensibleParameter::SPtr notification_;

	};

	class DLLEXPORT AcknowledgementManager
	{
	  public:
		typedef boost::shared_ptr<AcknowledgementManager> SPtr;
		typedef std::list<AcknowledgementElement::SPtr> AcknowledgementList;

		AcknowledgementManager(void);
		~AcknowledgementManager(void);

		uint32_t nextSequenceNumber(bool keepalive = false);
		uint32_t actSequenceNumber(void);

		uint32_t size(void);
		void maxListSize(uint32_t maxListSize);
		uint32_t maxListSize(void);
		void addNotification(
			uint32_t sequenceNumber,
			OpcUaStackCore::OpcUaExtensibleParameter::SPtr& notification
		);
		void deleteNotification(
			uint32_t sequenceNumber
		);
		bool firstNotification(
			uint32_t& sequenceNumber,
			OpcUaStackCore::OpcUaExtensibleParameter::SPtr& notification
		);
		bool getNotification(
			uint32_t sequenceNumber,
			OpcUaStackCore::OpcUaExtensibleParameter::SPtr& notification
		);
		void availableSequenceNumbers(
			OpcUaStackCore::OpcUaUInt32Array::SPtr& availableSequenceNumbers
		);

	  private:
		bool keepalive_;
		uint32_t maxListSize_;
		uint32_t sequenceNumber_;
		AcknowledgementList acknowledgementList_;
	};

}

#endif
