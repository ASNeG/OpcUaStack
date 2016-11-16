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

#ifndef __OpcUaStackCore_BrowsePath_h__
#define __OpcUaStackCore_BrowsePath_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/RelativePath.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT BrowsePath
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<BrowsePath> SPtr;

		BrowsePath(void);
		virtual ~BrowsePath(void);

		void startingNode(const OpcUaNodeId::SPtr startingNode);
		OpcUaNodeId::SPtr startingNode(void) const;
		void relativePath(const RelativePath& relativePath);
		RelativePath& relativePath(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaNodeId::SPtr startingNodeSPtr_;
		RelativePath relativePath_;
	};

	class BrowsePathArray
	: public OpcUaArray<BrowsePath::SPtr, SPtrTypeCoder<BrowsePath> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<BrowsePathArray> SPtr;
	};
	
}

#endif
