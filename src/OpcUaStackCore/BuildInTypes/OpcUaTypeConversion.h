/*
   Copyright 2017-2021 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"


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
			OpcUaVariant& sourceVariant,		// source variant data
			OpcUaBuildInType targetType,		// target type
			OpcUaVariant& targetVariant 		// target variant data
		);

		uint8_t precedenceRank(OpcUaBuildInType type);
	  private:
		int8_t indexForConversationTable(OpcUaBuildInType type);

		static char conversationTypeTable[TYPE_CONVERSATION_TABLE_SIZE][TYPE_CONVERSATION_TABLE_SIZE];

		bool cast(OpcUaVariant& sourceVariant, OpcUaBuildInType targetType, OpcUaVariant& targetVariant);

		template <typename T1, typename T2>
		bool cast(OpcUaVariant& source, OpcUaVariant& target)
		{
			T2 val = source.get<T1>();
			target.set<T2>(val);

			return true;
		}

		template <typename T1, typename T2>
		bool castRealToInteger(OpcUaVariant& source, OpcUaVariant& target)
		{
			T1 val = source.get<T1>();
			if ((val <= std::numeric_limits<T2>::max())
					&& (val >= std::numeric_limits<T2>::min())) {

				T2 val = source.get<T1>() + 0.5;
				target.set<T2>(val);
				return true;
			}

			return false;
		}

		template <typename T1, typename T2>
		bool castIntegerToInteger(OpcUaVariant& source, OpcUaVariant& target)
		{
			try {

				T2 val = boost::numeric_cast<T2>(source.get<T1>());
				target.set<T2>(val);

				return true;
			} catch (boost::bad_numeric_cast &e) {
				return false;
			}
		}

		template <typename T>
		bool castToString(OpcUaVariant& source, OpcUaVariant& target)
		{
			OpcUaString value(
					boost::lexical_cast<std::string>(source.get<T>()));
			target.setValue(value);

			return true;
		}

		template <typename T>
		bool castStatusCode(OpcUaVariant& source, OpcUaVariant& target)
		{
			OpcUaStatusCode status = (OpcUaStatusCode) source.get<T>();
			if (OpcUaStatusCodeMap::exist(status) == true) {
				target.set<OpcUaStatusCode>(status);
				return true;
			}

			return false;
		}

		template <typename T>
		bool castStringToReal(OpcUaVariant& source, OpcUaVariant& target)
		{
			try {
				T value = boost::lexical_cast<T>(source.getSPtr<OpcUaString>()->toStdString());
				target.variant(value);
				return true;
			} catch (boost::bad_lexical_cast &e) {
				return false;
			}
		}

		template <typename T>
		bool castStringToInteger(OpcUaVariant& source, OpcUaVariant& target)
		{
			try {
				OpcUaVariant tmp;
				if (std::numeric_limits<T>::min() == 0) {
					uint64_t value = boost::lexical_cast<uint64_t>(source.getSPtr<OpcUaString>()->toStdString());
					tmp.variant(value);
					return castIntegerToInteger<uint64_t, T>(tmp, target);
				} else {
					int64_t value = boost::lexical_cast<int64_t>(source.getSPtr<OpcUaString>()->toStdString());
					tmp.variant(value);
					return castIntegerToInteger<int64_t, T>(tmp, target);
				}

			} catch (boost::bad_lexical_cast &e) {
				return false;
			}
		}
	};

}

#endif
