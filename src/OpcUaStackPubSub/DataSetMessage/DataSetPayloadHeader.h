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

#ifndef __OpcUaStackPubSub_DataSetPayloadHeader_h__
#define __OpcUaStackPubSub_DataSetPayloadHeader_h__

#include <boost/shared_ptr.hpp>
#include <iostream>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	class DLLEXPORT DataSetPayloadHeader
	{
	  public:
		typedef boost::shared_ptr<DataSetPayloadHeader> SPtr;

		DataSetPayloadHeader(void);
		virtual ~DataSetPayloadHeader(void);

		void dataSetWriterIds(const OpcUaUInt16Array::SPtr& dataSetWriterIds);
		OpcUaUInt16Array::SPtr& dataSetWriterIds(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		bool operator==(const DataSetPayloadHeader& other) const;

		void dataSetArrayEnabled(bool dataSetArrayEnabled);
		bool dataSetArrayEnabled() const;

	  private:
		OpcUaUInt16Array::SPtr dataSetWriterIds_;
		bool dataSetArrayEnabled_;
	};

}

#endif
