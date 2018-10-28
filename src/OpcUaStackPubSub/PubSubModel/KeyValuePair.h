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

#ifndef __OpcUaStackPubSub_KeyValuePair_h__
#define __OpcUaStackPubSub_KeyValuePair_h__

#include <boost/shared_ptr.hpp>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	/**
	 * This class is used to provide a key value pair.
	 */
	class DLLEXPORT KeyValuePair
	{
	  public:
		typedef boost::shared_ptr<KeyValuePair> SPtr;
		typedef std::vector<KeyValuePair> Vec;

		/**
		 * constructor
		 */
		KeyValuePair(void);

		/**
		 * destructor
		 */
		virtual ~KeyValuePair(void);

		/**
		 * setter method for the key value
		 *
		 * @param[in] key					key of the value
		 */
		void key(const OpcUaQualifiedName& key);

		/**
		 * getter method of the key value
		 *
		 * @return key value
		 */
		const OpcUaQualifiedName& key(void);

		/**
		 * setter method for the value value
		 *
		 * @param[in] value					value
		 */
		void value(const OpcUaVariant& value);

		/**
		 * getter method of the value
		 *
		 * @return value
		 */
		const OpcUaVariant& value(void);

		/**
		 * operator
		 *
		 * @param[in] value					value
		 *
		 * @return value
		 */
		KeyValuePair& operator=(const KeyValuePair& value);

	  private:
		OpcUaQualifiedName key_;			//!< The key of the value
		OpcUaVariant value_;				//!< The value associated with the key
	};

}

#endif
