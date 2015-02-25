#ifndef __OpcUaStackCore_ModificationInfo_h__
#define __OpcUaStackCore_ModificationInfo_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	typedef enum
	{
		HistoryUpdateMode_Insert = 1,
		HistoryUpdateMode_Replace = 2,
		HistoryUpdateMode_Update = 3,
		HistoryUpdateMode_Delete = 4
	} HistoryUpdateMode;

	class DLLEXPORT ModificationInfo : public  ObjectPool<ModificationInfo>
	{
	  public:
		typedef boost::shared_ptr<ModificationInfo> SPtr;

		ModificationInfo(void);
		virtual ~ModificationInfo(void);

		void username(const OpcUaString& username);
		void username(const std::string& username);
		OpcUaString& username(void);
		void modificationTime(const UtcTime& modificationTime);
		void modificationTime(const boost::posix_time::ptime& modificationTime);
		UtcTime& modificationTime(void);
		void updateType(const HistoryUpdateMode updateType);
		HistoryUpdateMode updateType(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaString username_;
		UtcTime modificationTime_;
		HistoryUpdateMode updateType_;
	};

	class ModificationInfoArray : public OpcUaArray<ModificationInfo::SPtr, SPtrTypeCoder<ModificationInfo> >, public ObjectPool<ModificationInfoArray> 
	{
	  public:
		typedef boost::shared_ptr<ModificationInfoArray> SPtr;
	};

}

#endif