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

#ifndef __OpcUaStackServer_AcknowledgementManager_h__
#define __OpcUaStackServer_AcknowledgementManager_h__

#include <boost/shared_ptr.hpp>
#include <list>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSet/DataChangeNotification.h"

using namespace OpcUaStackCore;

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
		void dataChangeNotification(DataChangeNotification::SPtr& dataChangeNotification);
		DataChangeNotification::SPtr dataChangeNotification(void);

	  private:
		uint32_t sequenceNumber_;
		DataChangeNotification::SPtr dataChangeNotification_;

	};

	class DLLEXPORT AcknowledgementManager
	{
	  public:
		typedef boost::shared_ptr<AcknowledgementManager> SPtr;
		typedef std::list<AcknowledgementElement::SPtr> AcknowledgementList;

		AcknowledgementManager(void);
		~AcknowledgementManager(void);

		uint32_t nextSequenceNumber(void);
		uint32_t actSequenceNumber(void);

		uint32_t size(void);
		void addDataChangeNotification(
			uint32_t sequenceNumber,
			DataChangeNotification::SPtr& dataChangeNotification
		);
		void deleteDataChangeNotification(
			uint32_t sequenceNumber
		);
		bool firstDataChangeNotification(
			uint32_t& sequenceNumber,
			DataChangeNotification::SPtr& dataChangeNotification
		);
		bool getDataChangeNotification(
			uint32_t sequenceNumber,
			DataChangeNotification::SPtr& dataChangeNotification
		);

	  private:
		uint32_t sequenceNumber_;
		AcknowledgementList acknowledgementList_;
	};

}

#endif
