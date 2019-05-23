/*
    DataTypeClass: AxisInformation

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_AxisInformation_h__
#define __OpcUaStackCore_AxisInformation_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/JsonFormatter.h"
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
