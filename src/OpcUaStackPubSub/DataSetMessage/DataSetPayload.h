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

#ifndef __OpcUaStackPubSub_DataSetPayload_h__
#define __OpcUaStackPubSub_DataSetPayload_h__

#include <boost/shared_ptr.hpp>
#include <iostream>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackPubSub/DataSetMessage/DataSetMessage.h"
#include "OpcUaStackPubSub/DataSetMessage/DataSetMessageHeader.h"

namespace OpcUaStackPubSub
{

	class DLLEXPORT DataSetPayload
	{
	  public:
		typedef boost::shared_ptr<DataSetPayload> SPtr;

		DataSetPayload(void);
		~DataSetPayload(void);

		void count(uint32_t count);
		uint32_t count(void);
		void dataSetMessages(const DataSetMessageArray::SPtr& dataSetMessages);
		DataSetMessageArray::SPtr& dataSetMessages(void);

		void dataSetArrayEnabled(bool dataSetArrayEnabled);
		bool dataSetArrayEnabled() const;

		void opcUaBinaryEncode(std::ostream& os);
		void opcUaBinaryDecode(std::istream& is);

		bool operator==(const DataSetPayload& other) const;

	  private:
		uint32_t count_;
		DataSetMessageArray::SPtr dataSetMessages_;

		bool dataSetArrayEnabled_;

	};

}

#endif
