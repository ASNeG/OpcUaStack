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

#ifndef __OpcUaStackPubSub_ReaderGroupMessageModel_h__
#define __OpcUaStackPubSub_ReaderGroupMessageModel_h__

#include <boost/shared_ptr.hpp>

#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackPubSub
{

	/**
	 * This class is an abstract base class for message specific reader group parameters
	 */
	class DLLEXPORT ReaderGroupMessageModel
	{
	  public:
		typedef boost::shared_ptr<ReaderGroupMessageModel> SPtr;

		/**
		 * constructor
		 */
		ReaderGroupMessageModel(void);

		/**
		 * destructor
		 */
		virtual ~ReaderGroupMessageModel(void);
	};

}

#endif
