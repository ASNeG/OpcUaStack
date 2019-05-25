/*
    DataTypeClass: UpdateDataDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_UpdateDataDetails_h__
#define __OpcUaStackCore_UpdateDataDetails_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"
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
