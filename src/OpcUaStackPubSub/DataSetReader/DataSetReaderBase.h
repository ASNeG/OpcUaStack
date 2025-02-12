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

#ifndef __OpcUaStackPubSub_DataSetReaderBase_h__
#define __OpcUaStackPubSub_DataSetReaderBase_h__

#include <boost/asio.hpp>

#include <map>

#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackPubSub
{

	class DLLEXPORT DataSetReaderBase
	{
	  public:
		typedef boost::shared_ptr<DataSetReaderBase> SPtr;
		typedef std::map<uint16_t, SPtr> Map;

		DataSetReaderBase(void);
		virtual ~DataSetReaderBase(void);

		void dataSetReaderId(uint32_t dataSetReaderId);
		uint32_t dataSetReaderId(void);

		bool encodeDataSet(boost::asio::streambuf& dataSet, uint16_t& size);

	  public:
		uint32_t dataSetReaderId_ = 0;			// unique data set writer id
	};

}

#endif
