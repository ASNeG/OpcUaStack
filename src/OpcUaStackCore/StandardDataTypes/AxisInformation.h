/*
    DataTypeClass: AxisInformation

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_AxisInformation_h__
#define __OpcUaStackCore_AxisInformation_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/EUInformation.h"
#include "OpcUaStackCore/StandardDataTypes/Range.h"
#include "OpcUaStackCore/StandardDataTypes/AxisScaleEnumeration.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT AxisInformation
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<AxisInformation> SPtr;
        typedef std::vector<AxisInformation::SPtr> Vec;
    
        AxisInformation(void);
        AxisInformation(const AxisInformation& value);
        virtual ~AxisInformation(void);
        
        EUInformation& engineeringUnits(void);
        Range& eURange(void);
        OpcUaLocalizedText& title(void);
        AxisScaleEnumeration& axisScaleType(void);
        OpcUaDoubleArray& axisSteps(void);
        
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
        
        void copyTo(AxisInformation& value);
        bool operator==(const AxisInformation& value);
        bool operator!=(const AxisInformation& value);
        AxisInformation& operator=(const AxisInformation& value);
    
      private:
        EUInformation engineeringUnits_;
        Range eURange_;
        OpcUaLocalizedText title_;
        AxisScaleEnumeration axisScaleType_;
        OpcUaDoubleArray axisSteps_;
    
    };
    
    class DLLEXPORT AxisInformationArray
    : public OpcUaArray<AxisInformation::SPtr, SPtrTypeCoder<AxisInformation> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<AxisInformationArray> SPtr;
    };

}

#endif
