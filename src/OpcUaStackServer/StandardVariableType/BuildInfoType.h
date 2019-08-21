/*
    VariableTypeClass: BuildInfoType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_BuildInfoType_h__
#define __OpcUaStackServer_BuildInfoType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT BuildInfoType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<BuildInfoType> SPtr;
       typedef std::vector<BuildInfoType::SPtr> Vec;
   
       BuildInfoType(void);
       BuildInfoType(const BuildInfoType& value);
       virtual ~BuildInfoType(void);

        //
        // UtcTime
        //
        void buildDate_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& buildDate_Variable(void);
        bool get_BuildDate_Variable(OpcUaDataValue& dataValue);
        bool set_BuildDate_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void buildNumber_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& buildNumber_Variable(void);
        bool get_BuildNumber_Variable(OpcUaDataValue& dataValue);
        bool set_BuildNumber_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void manufacturerName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& manufacturerName_Variable(void);
        bool get_ManufacturerName_Variable(OpcUaDataValue& dataValue);
        bool set_ManufacturerName_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void productName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& productName_Variable(void);
        bool get_ProductName_Variable(OpcUaDataValue& dataValue);
        bool set_ProductName_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void productUri_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& productUri_Variable(void);
        bool get_ProductUri_Variable(OpcUaDataValue& dataValue);
        bool set_ProductUri_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void softwareVersion_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& softwareVersion_Variable(void);
        bool get_SoftwareVersion_Variable(OpcUaDataValue& dataValue);
        bool set_SoftwareVersion_Variable(const OpcUaDataValue& dataValue);

        //
        // BuildInfo (Array)
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr buildDate_Variable_;
        ServerVariable::SPtr buildNumber_Variable_;
        ServerVariable::SPtr manufacturerName_Variable_;
        ServerVariable::SPtr productName_Variable_;
        ServerVariable::SPtr productUri_Variable_;
        ServerVariable::SPtr softwareVersion_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
