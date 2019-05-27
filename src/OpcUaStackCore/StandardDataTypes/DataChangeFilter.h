/*
    DataTypeClass: DataChangeFilter

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

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
