#ifndef __OpcUaStackCore_HistoryData_h__
#define __OpcUaStackCore_HistoryData_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT HistoryData : public  ObjectPool<HistoryData>, public ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<HistoryData> SPtr;

		HistoryData(void);
		virtual ~HistoryData(void);

		void dataValues(const OpcUaDataValueArray::SPtr dataValues);
		OpcUaDataValueArray::SPtr dataValues(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::BSPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		OpcUaDataValueArray::SPtr dataValueArraySPtr_;
	};

}

#endif