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

#ifndef __OpcUaStackCore_SimpleAttributeOperand_h__
#define __OpcUaStackCore_SimpleAttributeOperand_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObjectBase.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SimpleAttributeOperand
	: public Object
	, public ExtensionObjectBase
	{
	  public:
		typedef boost::shared_ptr<SimpleAttributeOperand> SPtr;

		SimpleAttributeOperand(void);
		virtual ~SimpleAttributeOperand(void);

		void typeIdx(const OpcUaNodeId& typeId);
		OpcUaNodeId& typeIdx(void);
		void browsePath(const OpcUaQualifiedNameArray::SPtr browsePath);
		OpcUaQualifiedNameArray::SPtr browsePath(void);
		void attributeId(const OpcUaUInt32& attributeId);
		OpcUaUInt32 attributeId(void) const;
		void indexRange(const std::string& indexRange);
		OpcUaString& indexRange(void);

		//- ExtensionObjectBase -------------------------------------------
		virtual ExtensionObjectBase::SPtr factory(void);
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		virtual void copyTo(ExtensionObjectBase& extensionObjectBase) {}						// FIXME: todo
		virtual bool equal(ExtensionObjectBase& extensionObjectBase) const { return false; }	// FIXME: todo
		virtual void out(std::ostream& os) {}													// FIXME: todo
		//- ExtensionObjectBase -------------------------------------------
		
	  private:
		OpcUaNodeId typeId_;
		OpcUaQualifiedNameArray::SPtr browsePathArraySPtr_;
		OpcUaUInt32 attributeId_;
		OpcUaString indexRange_;
	};

	class SimpleAttributeOperandArray
	: public OpcUaArray<SimpleAttributeOperand::SPtr, SPtrTypeCoder<SimpleAttributeOperand> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<SimpleAttributeOperandArray> SPtr;
	};

}

#endif
