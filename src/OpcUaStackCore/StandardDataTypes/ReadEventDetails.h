/*
    DataTypeClass: ReadEventDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ReadEventDetails_h__
#define __OpcUaStackCore_ReadEventDetails_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
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
        virtual ExtensionObjectBase::SPtr factory(void) override;
        virtual std::string namespaceName(void) override;
        virtual std::string typeName(void) override;
        virtual OpcUaNodeId typeId(void) override;
        virtual OpcUaNodeId binaryTypeId(void) override;
        virtual OpcUaNodeId xmlTypeId(void) override;
        virtual OpcUaNodeId jsonTypeId(void) override;
        virtual void opcUaBinaryEncode(std::ostream& os) const override;
        virtual void opcUaBinaryDecode(std::istream& is) override;
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) override;
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns) override;
        virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) override;
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns) override;
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase) override;
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const override;
        virtual void out(std::ostream& os) override;
        //- ExtensionObjectBase -----------------------------------------------
        
        virtual bool jsonEncodeImpl(boost::property_tree::ptree& pt) const override;
        virtual bool jsonDecodeImpl(const boost::property_tree::ptree& pt) override;
        
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
