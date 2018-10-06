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

#ifndef __OpcUaStackPubSub_DataSetFieldContentMask_h__
#define __OpcUaStackPubSub_DataSetFieldContentMask_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	class DLLEXPORT DataSetFieldContentMask
	{
	  public:

		typedef enum
		{
			StatusCode,			//!< The DataValue structure field StatusCode is included in the DataSetMessages.
			SourceTimestamp,	//!< The DataValue structure field SourceTimestamp is included in the DataSetMessages.
			ServerTimestamp,	//!< The DataValue structure field ServerTimestamp is included in the DataSetMessages
			SourcePicoSeconds,	//!< The DataValue structure field SourcePicoSeconds is included in the DataSetMessages
			ServerPicoSeconds,	//!< The DataValue structure field ServerPicoSeconds is included in the DataSetMessages
			RawData				//!< The DataValue structure field RawData is included in the DataSetMessages
		} Flag;

		/**
		 * constructor
		 */
		DataSetFieldContentMask(void);

		/**
		 * destructor
		 */
		~DataSetFieldContentMask(void);

		/**
		 * setter method for value encoding mask
		 *
		 * @param[in] value 	encoding mask
		 */
		void encodingMask(OpcUaByte encodingMask);

		/**
		 * getter method for value encoding mask
		 *
		 * @return value encoding masj
		 */
		OpcUaByte encodingMask(void);

		/**
		 * set a flag in the encoding mask
		 *
		 * @param[in] flag		flag to set in the encoding mask
		 */
		void set(Flag flag);

		/**
		 * unset a flag in the encoding mask
		 *
		 * @param[in] flag		flag to unset in the encoding mask
		 */
		void unset(Flag flag);

		/**
		 * check if lag exist in the encoding mask
		 *
		 * @param[in] flag		flag to check in the encoding maask
		 * @return true, if flag exist
		 */
		bool exist(Flag flag);

	  private:
		OpcUaByte encodingMask_;		//!< encoding mask

	};
}

#endif
