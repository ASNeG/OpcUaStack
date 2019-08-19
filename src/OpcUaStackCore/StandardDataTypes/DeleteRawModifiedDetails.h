/*
    DataTypeClass: DeleteRawModifiedDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_DeleteRawModifiedDetails_h__
#define __OpcUaStackCore_DeleteRawModifiedDetails_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryUpdateDetails.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT DeleteRawModifiedDetails
    : public HistoryUpdateDetails
    {
      public:
        typedef boost::shared_ptr<DeleteRawModifiedDetails> SPtr;
        typedef std::vector<DeleteRawModifiedDetails::SPtr> Vec;
    
        DeleteRawModifiedDetails(void);
        DeleteRawModifiedDetails(const DeleteRawModifiedDetails& value);
        virtual ~DeleteRawModifiedDetails(void);
        
        OpcUaBoolean& isDeleteModified(void);
        OpcUaUtcTime& startTime(void);
        OpcUaUtcTime& endTime(void);
        
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
        
        void copyTo(DeleteRawModifiedDetails& value);
        bool operator==(const DeleteRawModifiedDetails& value);
        bool operator!=(const DeleteRawModifiedDetails& value);
        DeleteRawModifiedDetails& operator=(const DeleteRawModifiedDetails& value);
    
      private:
        OpcUaBoolean isDeleteModified_;
        OpcUaUtcTime startTime_;
        OpcUaUtcTime endTime_;
    
    };
    
    class DLLEXPORT DeleteRawModifiedDetailsArray
    : public OpcUaArray<DeleteRawModifiedDetails::SPtr, SPtrTypeCoder<DeleteRawModifiedDetails> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<DeleteRawModifiedDetailsArray> SPtr;
    };

}

#endif
