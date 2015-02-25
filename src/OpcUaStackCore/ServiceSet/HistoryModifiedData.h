#ifndef __OpcUaStackCore_HistoryModifiedData_h__
#define __OpcUaStackCore_HistoryModifiedData_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ModificationInfo.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT HistoryModifiedData : public  ObjectPool<HistoryModifiedData>, public ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<HistoryModifiedData> SPtr;

		HistoryModifiedData(void);
		virtual ~HistoryModifiedData(void);

		void dataValues(const OpcUaDataValueArray::SPtr dataValues);
		OpcUaDataValueArray::SPtr dataValues(void) const;
		void modificationInfos(const ModificationInfoArray::SPtr modificationInfos);
		ModificationInfoArray::SPtr modificationInfos(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::BSPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		OpcUaDataValueArray::SPtr dataValueArraySPtr_;
		ModificationInfoArray::SPtr modificationInfoArraySPtr_;
	};

}

#endif