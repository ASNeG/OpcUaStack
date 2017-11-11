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

#ifndef __OpcUaStackPubSub_DataSetMessage_h__
#define __OpcUaStackPubSub_DataSetMessage_h__

#include <boost/shared_ptr.hpp>
#include <iostream>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	class DLLEXPORT DataSetMessage
	{
	  public:
		typedef boost::shared_ptr<DataSetMessage> SPtr;

		typedef enum
		{
			DataKeyFrame,
			DataDeltaFrame,
			EventData,
			KeepAlive
		} MessageType;

		DataSetMessage(void);
		virtual ~DataSetMessage(void);

		void messageType(MessageType messageType);
		MessageType messageType(void);

		virtual void opcUaBinaryEncode(std::ostream& os) const = 0;
		virtual void opcUaBinaryDecode(std::istream& is) = 0;

	  private:
		MessageType messageType_;
	};

	class DataSetMessageArray
	: public OpcUaArray<DataSetMessage::SPtr, SPtrTypeCoder<DataSetMessage> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<DataSetMessageArray> SPtr;
	};

}

#endif
