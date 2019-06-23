/*
    DataTypeClass: UpdateStructureDataDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_UpdateStructureDataDetails_h__
#define __OpcUaStackCore_UpdateStructureDataDetails_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryUpdateDetails.h"
#include "OpcUaStackCore/StandardDataTypes/PerformUpdateType.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT UpdateStructureDataDetails
    : public HistoryUpdateDetails
    {
      public:
        typedef boost::shared_ptr<UpdateStructureDataDetails> SPtr;
        typedef std::vector<UpdateStructureDataDetails::SPtr> Vec;
    
        UpdateStructureDataDetails(void);
        UpdateStructureDataDetails(const UpdateStructureDataDetails& value);
        virtual ~UpdateStructureDataDetails(void);
        
        PerformUpdateType& performInsertReplace(void);
        OpcUaDataValueArray& updateValues(void);
        
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
        
        void copyTo(UpdateStructureDataDetails& value);
        bool operator==(const UpdateStructureDataDetails& value);
        bool operator!=(const UpdateStructureDataDetails& value);
        UpdateStructureDataDetails& operator=(const UpdateStructureDataDetails& value);
    
      private:
        PerformUpdateType performInsertReplace_;
        OpcUaDataValueArray updateValues_;
    
    };
    
    class DLLEXPORT UpdateStructureDataDetailsArray
    : public OpcUaArray<UpdateStructureDataDetails::SPtr, SPtrTypeCoder<UpdateStructureDataDetails> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<UpdateStructureDataDetailsArray> SPtr;
    };

}

#endif
