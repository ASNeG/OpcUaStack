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

#ifndef __OpcUaStackCore_OpcUaOpterator_h__
#define __OpcUaStackCore_OpcUaOpterator_h__

#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	typedef enum {
		Equals,				// Number of Operands: 2
		// TRUE if operand[0] is equal to operand[1].
		// If the operands are of different types, the system shall perform any implicit
		// conversion to a common type. This operator resolves to FALSE if no implicit
		// conversion is available and the operands are of different types. This operator returns
		// FALSE if the implicit conversion fails. See the discussion on data type precedence in
		// Table 119 for more information how to convert operands of different types.

		// FIXME: todo

	} OpcUaOpterator;

}

#endif
