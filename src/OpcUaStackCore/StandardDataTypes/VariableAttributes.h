/*
    DataTypeClass: VariableAttributes

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_VariableAttributes_h__
#define __OpcUaStackCore_VariableAttributes_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/NodeAttributes.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT VariableAttributes
    : public NodeAttributes
    {
      public:
        typedef boost::shared_ptr<VariableAttributes> SPtr;
        typedef std::vector<VariableAttributes::SPtr> Vec;
    
        VariableAttributes(void);
        VariableAttributes(const VariableAttributes& value);
        virtual ~VariableAttributes(void);
        
        OpcUaVariant& value(void);
        OpcUaNodeId& dataType(void);
        OpcUaInt32& valueRank(void);
        OpcUaUInt32Array& arrayDimensions(void);
        OpcUaByte& accessLevel(void);
        OpcUaByte& userAccessLevel(void);
        OpcUaDuration& minimumSamplingInterval(void);
        OpcUaBoolean& historizing(void);
        
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
        
        void copyTo(VariableAttributes& value);
        bool operator==(const VariableAttributes& value);
        bool operator!=(const VariableAttributes& value);
        VariableAttributes& operator=(const VariableAttributes& value);
    
      private:
        OpcUaVariant value_; //!< The value of the variable.
        OpcUaNodeId dataType_; //!< The data type of the value.
        OpcUaInt32 valueRank_; //!< Whether the value is an array type and the rank of the array if it is.
        OpcUaUInt32Array arrayDimensions_; //!< The number of dimensions if the value is an array type and one or more dimensions have a fixed length.
        OpcUaByte accessLevel_; //!< A bit mask specifying how the value may be accessed.
        OpcUaByte userAccessLevel_; //!< A bit mask specifying how the value may be accessed by the current user.
        OpcUaDuration minimumSamplingInterval_; //!< The minimum possible sampling interval for the value.
        OpcUaBoolean historizing_; //!< TRUE if the server is current storing the history of the value.
    
    };
    
    class DLLEXPORT VariableAttributesArray
    : public OpcUaArray<VariableAttributes::SPtr, SPtrTypeCoder<VariableAttributes> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<VariableAttributesArray> SPtr;
    };

}

#endif
