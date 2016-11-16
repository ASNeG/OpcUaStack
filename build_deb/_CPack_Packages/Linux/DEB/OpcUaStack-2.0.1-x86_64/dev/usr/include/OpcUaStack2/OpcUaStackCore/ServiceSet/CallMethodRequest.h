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

#ifndef __OpcUaStackCore_CallMethodRequest_h__
#define __OpcUaStackCore_CallMethodRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CallMethodRequest
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<CallMethodRequest> SPtr;

		CallMethodRequest(void);
		virtual ~CallMethodRequest(void);

		void objectId(const OpcUaNodeId::SPtr objectId);
		OpcUaNodeId::SPtr objectId(void) const;
		void methodId(const OpcUaNodeId::SPtr methodId);
		OpcUaNodeId::SPtr methodId(void) const;
		void inputArguments(const OpcUaVariantArray::SPtr inputArguments);
		OpcUaVariantArray::SPtr inputArguments(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		  OpcUaNodeId::SPtr objectIdSPtr_;
		  OpcUaNodeId::SPtr methodIdSPtr_;
		  OpcUaVariantArray::SPtr inputArgumentArraySPtr_;
	};

	class CallMethodRequestArray
	: public OpcUaArray<CallMethodRequest::SPtr, SPtrTypeCoder<CallMethodRequest> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<CallMethodRequestArray> SPtr;
	};

}

#endif
