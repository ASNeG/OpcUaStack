/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_NodeClassOld_h__
#define __OpcUaStackCore_NodeClassOld_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/NodeClass.h"

namespace OpcUaStackCore
{

	class DLLEXPORT NodeClassOld
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<NodeClassOld> SPtr;

		NodeClassOld(void);
		virtual ~NodeClassOld(void);

		static std::string toString(NodeClass::Enum nodeClassType);
		static NodeClass::Enum toNodeClassType(const std::string& nodeClassTypeString);

		void nodeClassType(const NodeClass::Enum nodeClassType);
		NodeClass::Enum nodeClassType(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		
	  private:
		NodeClass::Enum nodeClassType_;
	};

}

#endif
