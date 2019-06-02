/*
    DataTypeClass: SamplingIntervalDiagnosticsDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_SamplingIntervalDiagnosticsDataType_h__
#define __OpcUaStackCore_SamplingIntervalDiagnosticsDataType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT SamplingIntervalDiagnosticsDataType
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<SamplingIntervalDiagnosticsDataType> SPtr;
        typedef std::vector<SamplingIntervalDiagnosticsDataType::SPtr> Vec;
    
        SamplingIntervalDiagnosticsDataType(void);
        SamplingIntervalDiagnosticsDataType(const SamplingIntervalDiagnosticsDataType& value);
        virtual ~SamplingIntervalDiagnosticsDataType(void);
        
        OpcUaDuration& samplingInterval(void);
        OpcUaUInt32& monitoredItemCount(void);
        OpcUaUInt32& maxMonitoredItemCount(void);
        OpcUaUInt32& disabledMonitoredItemCount(void);
        
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
        virtual bool jsonEncode(boost::property_tree::ptree& pt, const std::string& element);
        virtual bool jsonEncode(boost::property_tree::ptree& pt);
        virtual bool jsonDecode(boost::property_tree::ptree& pt, const std::string& element);
        virtual bool jsonDecode(boost::property_tree::ptree& pt);
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
        void copyTo(SamplingIntervalDiagnosticsDataType& value);
        bool operator==(const SamplingIntervalDiagnosticsDataType& value);
        bool operator!=(const SamplingIntervalDiagnosticsDataType& value);
        SamplingIntervalDiagnosticsDataType& operator=(const SamplingIntervalDiagnosticsDataType& value);
    
      private:
        OpcUaDuration samplingInterval_;
        OpcUaUInt32 monitoredItemCount_;
        OpcUaUInt32 maxMonitoredItemCount_;
        OpcUaUInt32 disabledMonitoredItemCount_;
    
    };
    
    class DLLEXPORT SamplingIntervalDiagnosticsDataTypeArray
    : public OpcUaArray<SamplingIntervalDiagnosticsDataType::SPtr, SPtrTypeCoder<SamplingIntervalDiagnosticsDataType> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<SamplingIntervalDiagnosticsDataTypeArray> SPtr;
    };

}

#endif
