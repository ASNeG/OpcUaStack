/*
    DataTypeClass: StructureDescription

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_StructureDescription_h__
#define __OpcUaStackCore_StructureDescription_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/DataTypeDescription.h"
#include "OpcUaStackCore/StandardDataTypes/StructureDefinition.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT StructureDescription
    : public DataTypeDescription
    {
      public:
        typedef boost::shared_ptr<StructureDescription> SPtr;
        typedef std::vector<StructureDescription::SPtr> Vec;
    
        StructureDescription(void);
        StructureDescription(const StructureDescription& value);
        virtual ~StructureDescription(void);
        
        StructureDefinition& structureDefinition(void);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void) override;
        virtual std::string namespaceName(void) override;
        virtual std::string typeName(void) override;
        virtual OpcUaNodeId typeId(void) override;
        virtual OpcUaNodeId binaryTypeId(void) override;
        virtual OpcUaNodeId xmlTypeId(void) override;
        virtual OpcUaNodeId jsonTypeId(void) override;
        virtual bool opcUaBinaryEncode(std::ostream& os) const override;
        virtual bool opcUaBinaryDecode(std::istream& is) override;
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
        
        void copyTo(StructureDescription& value);
        bool operator==(const StructureDescription& value);
        bool operator!=(const StructureDescription& value);
        StructureDescription& operator=(const StructureDescription& value);
    
      private:
        StructureDefinition structureDefinition_;
    
    };
    
    class DLLEXPORT StructureDescriptionArray
    : public OpcUaArray<StructureDescription::SPtr, SPtrTypeCoder<StructureDescription> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<StructureDescriptionArray> SPtr;
    };

}

#endif
