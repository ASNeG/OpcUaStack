/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_RelativePathElement_h__
#define __OpcUaStackCore_RelativePathElement_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT RelativePathElement
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<RelativePathElement> SPtr;

		RelativePathElement(void);
		virtual ~RelativePathElement(void);

		void referenceTypeId(const OpcUaNodeId::SPtr referenceTypeId);
		OpcUaNodeId::SPtr referenceTypeId(void) const;
		void isInverse(const OpcUaBoolean& isInverse);
		OpcUaBoolean isInverse(void) const;
		void includeSubtypes(const OpcUaBoolean& includeSubtypes);
		OpcUaBoolean includeSubtypes(void) const;
		void targetName(const OpcUaQualifiedName& tragetName);
		OpcUaQualifiedName& targetName(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaNodeId::SPtr referenceTypeIdSPtr_;
		OpcUaBoolean isInverse_;
		OpcUaBoolean includeSubtypes_;
		OpcUaQualifiedName targetName_;
	};

	class RelativePathElementArray
	: public OpcUaArray<RelativePathElement::SPtr, SPtrTypeCoder<RelativePathElement> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<RelativePathElementArray> SPtr;
	};

}

#endif
