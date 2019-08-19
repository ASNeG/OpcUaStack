/*
    DataTypeClass: UpdateDataDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_UpdateDataDetails_h__
#define __OpcUaStackCore_UpdateDataDetails_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryUpdateDetails.h"
#include "OpcUaStackCore/StandardDataTypes/PerformUpdateType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT UpdateDataDetails
    : public HistoryUpdateDetails
    {
      public:
        typedef boost::shared_ptr<UpdateDataDetails> SPtr;
        typedef std::vector<UpdateDataDetails::SPtr> Vec;
    
        UpdateDataDetails(void);
        UpdateDataDetails(const UpdateDataDetails& value);
        virtual ~UpdateDataDetails(void);
        
        PerformUpdateType& performInsertReplace(void);
        OpcUaDataValueArray& updateValues(void);
        
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
        
        void copyTo(UpdateDataDetails& value);
        bool operator==(const UpdateDataDetails& value);
        bool operator!=(const UpdateDataDetails& value);
        UpdateDataDetails& operator=(const UpdateDataDetails& value);
    
      private:
        PerformUpdateType performInsertReplace_;
        OpcUaDataValueArray updateValues_;
    
    };
    
    class DLLEXPORT UpdateDataDetailsArray
    : public OpcUaArray<UpdateDataDetails::SPtr, SPtrTypeCoder<UpdateDataDetails> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<UpdateDataDetailsArray> SPtr;
    };

}

#endif
