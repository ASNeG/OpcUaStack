/*
   Copyright 2015-2016 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_OpcUaNodeId_h__
#define __OpcUaStackCore_OpcUaNodeId_h__

#include <boost/shared_ptr.hpp>
#include <boost/optional/optional.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeIdBase.h"
#include "OpcUaStackCore/Base/os.h"
#include <list>
#include <vector>

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaNodeId
	: public OpcUaNodeIdBase
	{
	  public:
		typedef boost::optional<OpcUaNodeId&> Opt;
		typedef boost::shared_ptr<OpcUaNodeId> SPtr;
		typedef std::vector<OpcUaNodeId::SPtr> Vec;

	    OpcUaNodeId(void);
	    OpcUaNodeId(OpcUaUInt32 nodeId, OpcUaUInt16 namespaceIndex = 0);
	    OpcUaNodeId(const std::string& nodeId, OpcUaUInt16 namespaceIndex = 0);
		virtual ~OpcUaNodeId(void);
	};

	class OpcUaNodeSPtrLess
	{
	  public:
		bool operator()(const OpcUaNodeId::SPtr a, const OpcUaNodeId::SPtr b) const {
			if (a.get() == nullptr && b.get() != nullptr) return true;
			if (a.get() != nullptr && b.get() == nullptr) return false;
			if (a.get() == nullptr && b.get() == nullptr) return false;
			return *a < *b;
		}
	};

	class OpcUaNodeIdArray
	: public OpcUaArray<OpcUaNodeId::SPtr, SPtrTypeCoder<OpcUaNodeId> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<OpcUaNodeIdArray> SPtr;
	};

	typedef std::list<OpcUaNodeId> OpcUaNodeIdList;

}

#endif
