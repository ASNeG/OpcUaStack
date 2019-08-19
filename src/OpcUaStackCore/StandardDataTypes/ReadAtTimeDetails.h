/*
    DataTypeClass: ReadAtTimeDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ReadAtTimeDetails_h__
#define __OpcUaStackCore_ReadAtTimeDetails_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryReadDetails.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ReadAtTimeDetails
    : public HistoryReadDetails
    {
      public:
        typedef boost::shared_ptr<ReadAtTimeDetails> SPtr;
        typedef std::vector<ReadAtTimeDetails::SPtr> Vec;
    
        ReadAtTimeDetails(void);
        ReadAtTimeDetails(const ReadAtTimeDetails& value);
        virtual ~ReadAtTimeDetails(void);
        
        OpcUaUtcTimeArray& reqTimes(void);
        OpcUaBoolean& useSimpleBounds(void);
        
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
        
        void copyTo(ReadAtTimeDetails& value);
        bool operator==(const ReadAtTimeDetails& value);
        bool operator!=(const ReadAtTimeDetails& value);
        ReadAtTimeDetails& operator=(const ReadAtTimeDetails& value);
    
      private:
        OpcUaUtcTimeArray reqTimes_;
        OpcUaBoolean useSimpleBounds_;
    
    };
    
    class DLLEXPORT ReadAtTimeDetailsArray
    : public OpcUaArray<ReadAtTimeDetails::SPtr, SPtrTypeCoder<ReadAtTimeDetails> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ReadAtTimeDetailsArray> SPtr;
    };

}

#endif
