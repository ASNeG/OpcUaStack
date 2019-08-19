/*
    DataTypeClass: ReadProcessedDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ReadProcessedDetails_h__
#define __OpcUaStackCore_ReadProcessedDetails_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryReadDetails.h"
#include "OpcUaStackCore/StandardDataTypes/AggregateConfiguration.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ReadProcessedDetails
    : public HistoryReadDetails
    {
      public:
        typedef boost::shared_ptr<ReadProcessedDetails> SPtr;
        typedef std::vector<ReadProcessedDetails::SPtr> Vec;
    
        ReadProcessedDetails(void);
        ReadProcessedDetails(const ReadProcessedDetails& value);
        virtual ~ReadProcessedDetails(void);
        
        OpcUaUtcTime& startTime(void);
        OpcUaUtcTime& endTime(void);
        OpcUaDuration& processingInterval(void);
        OpcUaNodeIdArray& aggregateType(void);
        AggregateConfiguration& aggregateConfiguration(void);
        
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
        
        void copyTo(ReadProcessedDetails& value);
        bool operator==(const ReadProcessedDetails& value);
        bool operator!=(const ReadProcessedDetails& value);
        ReadProcessedDetails& operator=(const ReadProcessedDetails& value);
    
      private:
        OpcUaUtcTime startTime_;
        OpcUaUtcTime endTime_;
        OpcUaDuration processingInterval_;
        OpcUaNodeIdArray aggregateType_;
        AggregateConfiguration aggregateConfiguration_;
    
    };
    
    class DLLEXPORT ReadProcessedDetailsArray
    : public OpcUaArray<ReadProcessedDetails::SPtr, SPtrTypeCoder<ReadProcessedDetails> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ReadProcessedDetailsArray> SPtr;
    };

}

#endif
