/*
    DataTypeClass: ReadEventDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ReadEventDetails_h__
#define __OpcUaStackCore_ReadEventDetails_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryReadDetails.h"
#include "OpcUaStackCore/StandardDataTypes/EventFilter.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ReadEventDetails
    : public HistoryReadDetails
    {
      public:
        typedef boost::shared_ptr<ReadEventDetails> SPtr;
        typedef std::vector<ReadEventDetails::SPtr> Vec;
    
        ReadEventDetails(void);
        ReadEventDetails(const ReadEventDetails& value);
        virtual ~ReadEventDetails(void);
        
        OpcUaCounter& numValuesPerNode(void);
        OpcUaUtcTime& startTime(void);
        OpcUaUtcTime& endTime(void);
        EventFilter& filter(void);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void);
        virtual std::string namespaceName(void);
        virtual std::string typeName(void);
        virtual OpcUaNodeId typeId(void);
        virtual OpcUaNodeId binaryTypeId(void);
        virtual OpcUaNodeId xmlTypeId(void);
        virtual OpcUaNodeId jsonTypeId(void);
        virtual void opcUaBinaryEncode(std::ostream& os) const;
        virtual void opcUaBinaryDecode(std::istream& is);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
        virtual bool jsonEncodeImpl(boost::property_tree::ptree& pt) const;
        virtual bool jsonDecodeImpl(const boost::property_tree::ptree& pt);
        
        void copyTo(ReadEventDetails& value);
        bool operator==(const ReadEventDetails& value);
        bool operator!=(const ReadEventDetails& value);
        ReadEventDetails& operator=(const ReadEventDetails& value);
    
      private:
        OpcUaCounter numValuesPerNode_;
        OpcUaUtcTime startTime_;
        OpcUaUtcTime endTime_;
        EventFilter filter_;
    
    };
    
    class DLLEXPORT ReadEventDetailsArray
    : public OpcUaArray<ReadEventDetails::SPtr, SPtrTypeCoder<ReadEventDetails> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ReadEventDetailsArray> SPtr;
    };

}

#endif
