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

#ifndef __OpcUaStackPubSub_DataKeyFrameDataSetMessage_h__
#define __OpcUaStackPubSub_DataKeyFrameDataSetMessage_h__

#include <boost/shared_ptr.hpp>
#include <iostream>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackPubSub/DataSetMessage/DataSetMessage.h"
#include "OpcUaStackPubSub/DataSetMessage/DataSetField.h"
#include "OpcUaStackPubSub/DataSetMessage/FieldEncoding.h"

namespace OpcUaStackPubSub
{

	class DLLEXPORT DataKeyFrameDataSetMessage
	: public DataSetMessage
	{
	  public:
		typedef boost::shared_ptr<DataKeyFrameDataSetMessage> SPtr;

		DataKeyFrameDataSetMessage(void);
		~DataKeyFrameDataSetMessage(void);

		DataSetFieldArray::SPtr& dataSetFields(void);
		void fieldEncoding(FieldEncoding fieldEncoding);

		virtual void setFieldEncoding(void);
		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		DataSetFieldArray::SPtr dataSetFields_;
	};

}

#endif
