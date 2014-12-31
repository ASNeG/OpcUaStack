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

	class DLLEXPORT BrowsePath : public  ObjectPool<BrowsePath>
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

	class BrowsePathArray : public OpcUaArray<BrowsePath::SPtr, SPtrTypeCoder<BrowsePath> >, public ObjectPool<BrowsePathArray> 
	{
	  public:
		typedef boost::shared_ptr<BrowsePathArray> SPtr;
	};
	
}

#endif