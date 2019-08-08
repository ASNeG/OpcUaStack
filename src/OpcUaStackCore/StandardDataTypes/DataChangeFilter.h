/*
    DataTypeClass: DataChangeFilter

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_DataChangeFilter_h__
#define __OpcUaStackCore_DataChangeFilter_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/MonitoringFilter.h"
#include "OpcUaStackCore/StandardDataTypes/DataChangeTrigger.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT DataChangeFilter
    : public MonitoringFilter
    {
      public:
        typedef boost::shared_ptr<DataChangeFilter> SPtr;
        typedef std::vector<DataChangeFilter::SPtr> Vec;
    
        DataChangeFilter(void);
        DataChangeFilter(const DataChangeFilter& value);
        virtual ~DataChangeFilter(void);
        
        DataChangeTrigger& trigger(void);
        OpcUaUInt32& deadbandType(void);
        OpcUaDouble& deadbandValue(void);
        
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
        
        void copyTo(DataChangeFilter& value);
        bool operator==(const DataChangeFilter& value);
        bool operator!=(const DataChangeFilter& value);
        DataChangeFilter& operator=(const DataChangeFilter& value);
    
      private:
        DataChangeTrigger trigger_;
        OpcUaUInt32 deadbandType_;
        OpcUaDouble deadbandValue_;
    
    };
    
    class DLLEXPORT DataChangeFilterArray
    : public OpcUaArray<DataChangeFilter::SPtr, SPtrTypeCoder<DataChangeFilter> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<DataChangeFilterArray> SPtr;
    };

}

#endif
