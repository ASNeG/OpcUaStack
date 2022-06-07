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

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaStackPubSub_DataSetWriterIf_h__
#define __OpcUaStackPubSub_DataSetWriterIf_h__

#include <map>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackPubSub/DataSetMessage/DataSetMessage.h"

namespace OpcUaStackPubSub
{

	class DLLEXPORT DataSetWriterIf
	{
	  public:
		typedef boost::shared_ptr<DataSetWriterIf> SPtr;
		typedef std::map<uint32_t, DataSetWriterIf::SPtr> Map;

		DataSetWriterIf(void);
		virtual ~DataSetWriterIf(void);

		void writerId(uint32_t writerId);
		uint32_t writerId(void) const;

		void keyFrameCount(uint32_t keyFrameCount);
		uint32_t keyFrameCount(void) const;

		void keepAliveTime(uint32_t keepAliveTime);
		uint32_t keepAliveTime(void) const;

		virtual bool publishTimeout(DataSetMessage::SPtr& dataSetMessage, uint32_t publishInterval) = 0;

	  private:
		uint32_t writerId_;
		uint32_t keyFrameCount_;
		uint32_t keepAliveTime_;
	};

}

#endif
