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

#ifndef __OpcUaStackPubSub_DataSetWriter_h__
#define __OpcUaStackPubSub_DataSetWriter_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackPubSub/DataSet/DataSetWriterIf.h"

namespace OpcUaStackPubSub
{

	class DLLEXPORT DataSetWriter
	: public DataSetWriterIf
	{
	  public:
		DataSetWriter(void);
		~DataSetWriter(void);

		virtual bool publishTimeout(DataSetMessage::SPtr& dataSetMessage, uint32_t publishInterval);
	};

}

#endif
