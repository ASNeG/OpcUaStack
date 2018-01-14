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

#ifndef __OpcUaStackPubSub_DeltaFrameField_h__
#define __OpcUaStackPubSub_DeltaFrameField_h__

#include <boost/shared_ptr.hpp>
#include <iostream>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackPubSub/DataSetMessage/DataSetField.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	class DLLEXPORT DeltaFrameField
	: public DataSetField
	{
	  public:
		typedef boost::shared_ptr<DeltaFrameField> SPtr;

		DeltaFrameField(void);
		DeltaFrameField(FieldEncoding dataType);
		virtual ~DeltaFrameField(void);

		void fieldIndex(uint16_t fieldIndex);
		uint32_t fieldIndex(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		uint32_t fieldIndex_;
	};

	class DeltaFrameFieldArray
	: public OpcUaArray<DeltaFrameField::SPtr, SPtrTypeCoder<DeltaFrameField> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<DeltaFrameFieldArray> SPtr;
	};

}

#endif
