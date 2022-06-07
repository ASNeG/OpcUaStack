/*
   Copyright 2022 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackPubSub_DataSetWriterBase_h__
#define __OpcUaStackPubSub_DataSetWriterBase_h__

#include <boost/asio.hpp>

#include <map>

#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackPubSub
{

	class DLLEXPORT DataSetWriterBase
	{
	  public:
		typedef boost::shared_ptr<DataSetWriterBase> SPtr;
		typedef std::map<uint16_t, SPtr> Map;

		DataSetWriterBase(void);
		virtual ~DataSetWriterBase(void);

		void dataSetWriterId(uint32_t dataSetWriterId);
		uint32_t dataSetWriterId(void);

		bool encodeDataSet(boost::asio::streambuf& dataSet, uint16_t& size);

	  public:
		uint32_t dataSetWriterId_ = 0;			// unique data set writer id
	};

}

#endif
