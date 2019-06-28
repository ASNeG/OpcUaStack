/*
    DataTypeClass: HistoryModifiedData

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_HistoryModifiedData_h__
#define __OpcUaStackCore_HistoryModifiedData_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryData.h"
#include "OpcUaStackCore/StandardDataTypes/ModificationInfo.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT HistoryModifiedData
    : public HistoryData
    {
      public:
        typedef boost::shared_ptr<HistoryModifiedData> SPtr;
        typedef std::vector<HistoryModifiedData::SPtr> Vec;
    
        HistoryModifiedData(void);
        HistoryModifiedData(const HistoryModifiedData& value);
        virtual ~HistoryModifiedData(void);
        
        ModificationInfoArray& modificationInfos(void);
        
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
        
        void copyTo(HistoryModifiedData& value);
        bool operator==(const HistoryModifiedData& value);
        bool operator!=(const HistoryModifiedData& value);
        HistoryModifiedData& operator=(const HistoryModifiedData& value);
    
      private:
        ModificationInfoArray modificationInfos_;
    
    };
    
    class DLLEXPORT HistoryModifiedDataArray
    : public OpcUaArray<HistoryModifiedData::SPtr, SPtrTypeCoder<HistoryModifiedData> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<HistoryModifiedDataArray> SPtr;
    };

}

#endif
