#ifndef __OpcUaStackCore_ViewDescription_h__
#define __OpcUaStackCore_ViewDescription_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ViewDescription : public  ObjectPool<ViewDescription>
	{
	  public:
		typedef boost::shared_ptr<ViewDescription> SPtr;

		ViewDescription(void);
		virtual ~ViewDescription(void);

		void viewId(const OpcUaNodeId::SPtr viewId);
		OpcUaNodeId::SPtr viewId(void);
		void timestamp(const UtcTime& timestamp);
		void timestamp(const boost::posix_time::ptime& timestamp);
		UtcTime& timestamp(void);
		void viewVersion(const OpcUaUInt32& viewVersion);
		OpcUaUInt32 viewVersion(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaNodeId::SPtr viewIdSPtr_;
		UtcTime timestamp_;
		OpcUaUInt32 viewVersion_;
	};

	class ViewDescriptionArray : public OpcUaArray<ViewDescription::SPtr, SPtrTypeCoder<ViewDescription> >, public ObjectPool<ViewDescriptionArray> 
	{
	  public:
		typedef boost::shared_ptr<ViewDescriptionArray> SPtr;
	};

}

#endif