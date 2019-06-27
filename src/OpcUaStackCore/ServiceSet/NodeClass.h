/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_NodeClass_h__
#define __OpcUaStackCore_NodeClass_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
	typedef enum {
		NodeClassType_Unspecified = 0,
		NodeClassType_Object = 1,
		NodeClassType_Variable = 2,
		NodeClassType_Method = 4,
		NodeClassType_ObjectType = 8,
		NodeClassType_VariableType = 16,
		NodeClassType_ReferenceType = 32,
		NodeClassType_DataType = 64,
		NodeClassType_View = 128,
		NodeClassType_Dummy = 256,
	} NodeClassType;


	class DLLEXPORT NodeClass
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<NodeClass> SPtr;

		NodeClass(void);
		virtual ~NodeClass(void);

		static std::string toString(NodeClassType nodeClassType);
		static NodeClassType toNodeClassType(const std::string& nodeClassTypeString);

		void nodeClassType(const NodeClassType nodeClassType);
		NodeClassType nodeClassType(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		
	  private:
		NodeClassType nodeClassType_;
	};

}

#endif
