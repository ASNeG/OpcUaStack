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

#ifndef __OpcUaStackCore_NamespaceInfoResponse_h__
#define __OpcUaStackCore_NamespaceInfoResponse_h__

#include <map>
#include <string>
#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"


namespace OpcUaStackCore
{

	class DLLEXPORT NamespaceInfoResponse
	: public Object
	{
	  public:
		typedef boost::shared_ptr<NamespaceInfoResponse> SPtr;
		typedef std::map<uint32_t,std::string> Index2NamespaceMap;
		typedef std::map<std::string,uint32_t> Namespace2IndexMap;

	    NamespaceInfoResponse(void);
		virtual ~NamespaceInfoResponse(void);

		Index2NamespaceMap& index2NamespaceMap(void);
		Namespace2IndexMap& namespace2IndexMap(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		Index2NamespaceMap index2NamespaceMap_;
		Namespace2IndexMap namespace2IndexMap_;
	};
}

#endif
