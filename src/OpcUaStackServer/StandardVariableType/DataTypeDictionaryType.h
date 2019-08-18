/*
    VariableTypeClass: DataTypeDictionaryType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_DataTypeDictionaryType_h__
#define __OpcUaStackServer_DataTypeDictionaryType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
   
   class DLLEXPORT DataTypeDictionaryType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<DataTypeDictionaryType> SPtr;
       typedef std::vector<DataTypeDictionaryType::SPtr> Vec;
   
       DataTypeDictionaryType(void);
       DataTypeDictionaryType(const DataTypeDictionaryType& value);
       virtual ~DataTypeDictionaryType(void);

        //
        // String
        //
        void dataTypeVersion_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& dataTypeVersion_Variable(void);
        bool get_DataTypeVersion_Variable(OpcUaDataValue& dataValue);
        bool set_DataTypeVersion_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void deprecated_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& deprecated_Variable(void);
        bool get_Deprecated_Variable(OpcUaDataValue& dataValue);
        bool set_Deprecated_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void namespaceUri_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& namespaceUri_Variable(void);
        bool get_NamespaceUri_Variable(OpcUaDataValue& dataValue);
        bool set_NamespaceUri_Variable(const OpcUaDataValue& dataValue);

        //
        // ByteString (Array)
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr dataTypeVersion_Variable_;
        ServerVariable::SPtr deprecated_Variable_;
        ServerVariable::SPtr namespaceUri_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
