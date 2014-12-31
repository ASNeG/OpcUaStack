#ifndef __OpcUaStackCore_HistoryEventFieldList_h__
#define __OpcUaStackCore_HistoryEventFieldList_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT HistoryEventFieldList : public  ObjectPool<HistoryEventFieldList>
	{
	  public:
		typedef boost::shared_ptr<HistoryEventFieldList> SPtr;

		HistoryEventFieldList(void);
		virtual ~HistoryEventFieldList(void);

		void eventFields(const OpcUaVariantArray::SPtr eventFields);
		OpcUaVariantArray::SPtr eventFields(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaVariantArray::SPtr eventFieldArraySPtr_;
	};

	class HistoryEventFieldListArray : public OpcUaArray<HistoryEventFieldList::SPtr, SPtrTypeCoder<HistoryEventFieldList> >, public ObjectPool<HistoryEventFieldListArray> 
	{
	  public:
		typedef boost::shared_ptr<HistoryEventFieldListArray> SPtr;
	};

}

#endif