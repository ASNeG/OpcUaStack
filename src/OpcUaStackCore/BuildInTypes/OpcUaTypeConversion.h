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

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (timin-ayu@nefteavtomatika.ru)
 */

/*
  OPC UA Specification Part 4:
  Chapter 7.4.3 Filter Operator
  Table 118 Conversion Rules
 */

#ifndef __OpcUaStackCore_OpcUaTypeConversion_h__
#define __OpcUaStackCore_OpcUaTypeConversion_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaVariant.h"


namespace OpcUaStackCore
{

	const int TYPE_CONVERSATION_TABLE_SIZE = 21;
	class DLLEXPORT OpcUaTypeConversion
	{
	  public:
		OpcUaTypeConversion(void);
		~OpcUaTypeConversion(void);

		char conversionType(OpcUaBuildInType sourceType, OpcUaBuildInType targetType);
		bool conversion(
			OpcUaVariant::SPtr& sourceVariant,		// source variant data
			OpcUaBuildInType targetType,			// target type
			OpcUaVariant::SPtr& targetVariant 		// target variant data
		);

		uint8_t precedenceRank(OpcUaBuildInType type);
	  private:
		int8_t indexForConversationTable(OpcUaBuildInType type);

		static char conversationTypeTable[TYPE_CONVERSATION_TABLE_SIZE][TYPE_CONVERSATION_TABLE_SIZE];

		bool cast(OpcUaVariant::SPtr& sourceVariant, OpcUaBuildInType targetType, OpcUaVariant::SPtr& targetVariant);

		template <typename T1, typename T2>
		bool cast(OpcUaVariant::SPtr& source, OpcUaVariant::SPtr& target)
		{
			if (source->isArray()) {
				target->clear();
				for (int i = 0; i < source->arrayLength(); ++i) {
					T2 val = source->get<T1>(i);

					target->pushBack(val);
				}
			} else {
				T2 val = source->get<T1>();
				target->set<T2>(val);
			}

			return true;
		}

		template <typename T1, typename T2>
		bool castRealToInteger(OpcUaVariant::SPtr& source, OpcUaVariant::SPtr& target)
		{
			T1 val = source->get<T1>();

			if ((val <= std::numeric_limits<T2>::max())
					&& (val >= std::numeric_limits<T2>::min())) {

				OpcUaVariant::SPtr tmpVariant = constructSPtr<OpcUaVariant>();
				tmpVariant->set<T1>(val + 0.5);

				return cast<T1, T2>(tmpVariant, target);
			}

			return false;
		}

		template <typename T>
		bool castToString(OpcUaVariant::SPtr& source, OpcUaVariant::SPtr& target)
		{
			OpcUaString::SPtr value = constructSPtr<OpcUaString>(
					boost::lexical_cast<std::string>(source->get<T>()));
			target->variant(value);

			return true;
		}
	};

}

#endif
