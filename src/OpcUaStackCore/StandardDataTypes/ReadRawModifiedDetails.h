/*
    DataTypeClass: ReadRawModifiedDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ReadRawModifiedDetails_h__
#define __OpcUaStackCore_ReadRawModifiedDetails_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryReadDetails.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ReadRawModifiedDetails
    : public HistoryReadDetails
    {
      public:
        typedef boost::shared_ptr<ReadRawModifiedDetails> SPtr;
        typedef std::vector<ReadRawModifiedDetails::SPtr> Vec;
    
        ReadRawModifiedDetails(void);
        ReadRawModifiedDetails(const ReadRawModifiedDetails& value);
        virtual ~ReadRawModifiedDetails(void);
        
        OpcUaBoolean& isReadModified(void);
        OpcUaUtcTime& startTime(void);
        OpcUaUtcTime& endTime(void);
        OpcUaCounter& numValuesPerNode(void);
        OpcUaBoolean& returnBounds(void);
        
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
        
        void copyTo(ReadRawModifiedDetails& value);
        bool operator==(const ReadRawModifiedDetails& value);
        bool operator!=(const ReadRawModifiedDetails& value);
        ReadRawModifiedDetails& operator=(const ReadRawModifiedDetails& value);
    
      private:
        OpcUaBoolean isReadModified_;
        OpcUaUtcTime startTime_;
        OpcUaUtcTime endTime_;
        OpcUaCounter numValuesPerNode_;
        OpcUaBoolean returnBounds_;
    
    };
    
    class DLLEXPORT ReadRawModifiedDetailsArray
    : public OpcUaArray<ReadRawModifiedDetails::SPtr, SPtrTypeCoder<ReadRawModifiedDetails> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ReadRawModifiedDetailsArray> SPtr;
    };

}

#endif
