#ifndef __OpcUaStackCore_BrowseDescritpion_h__
#define __OpcUaStackCore_BrowseDescritpion_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{
	
	typedef enum {
		BrowseDirection_Forward = 0,
		BrowseDirection_Inverse = 1,
		BrowseDirection_Both = 2
	} BrowseDirectionEnum;
	                
	class DLLEXPORT BrowseDescription : public  ObjectPool<BrowseDescription>
	{
	  public:
		typedef boost::shared_ptr<BrowseDescription> SPtr;

		BrowseDescription(void);
		virtual ~BrowseDescription(void);

		void nodeId(const OpcUaNodeId::SPtr nodeId);
		OpcUaNodeId::SPtr nodeId(void) const;
		void browseDirection(const BrowseDirectionEnum browseDirection);
		BrowseDirectionEnum browseDirection(void);
		void referenceTypeId(const OpcUaNodeId::SPtr referenceTypeId);
		OpcUaNodeId::SPtr referenceTypeId(void) const;
		void includeSubtypes(const OpcUaBoolean includeSubtypes);
		OpcUaBoolean includeSubtypes(void);
		void nodeClassMask(const OpcUaUInt32 nodeClassMask);
		OpcUaUInt32 nodeClassMask(void);
		void resultMask(const OpcUaUInt32 resultMask);
		OpcUaUInt32 resultMask(void);
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaNodeId::SPtr nodeIdSPtr_;
		BrowseDirectionEnum browseDirection_;
		OpcUaNodeId::SPtr referenceTypeIdSPtr_;
		OpcUaBoolean includeSubtypes_;
		OpcUaUInt32 nodeClassMask_;
		OpcUaUInt32 resultMask_;
	};

	class BrowseDescriptionArray : public OpcUaArray<BrowseDescription::SPtr, SPtrTypeCoder<BrowseDescription> >, public ObjectPool<BrowseDescriptionArray> 
	{
	  public:
		typedef boost::shared_ptr<BrowseDescriptionArray> SPtr;
	};

}

#endif