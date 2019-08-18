/*
    VariableTypeClass: DataTypeDescriptionType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_DataTypeDescriptionType_h__
#define __OpcUaStackServer_DataTypeDescriptionType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
   
   class DLLEXPORT DataTypeDescriptionType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<DataTypeDescriptionType> SPtr;
       typedef std::vector<DataTypeDescriptionType::SPtr> Vec;
   
       DataTypeDescriptionType(void);
       DataTypeDescriptionType(const DataTypeDescriptionType& value);
       virtual ~DataTypeDescriptionType(void);

        //
        // String
        //
        void dataTypeVersion_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& dataTypeVersion_Variable(void);
        bool get_DataTypeVersion_Variable(OpcUaDataValue& dataValue);
        bool set_DataTypeVersion_Variable(const OpcUaDataValue& dataValue);

        //
        // ByteString
        //
        void dictionaryFragment_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& dictionaryFragment_Variable(void);
        bool get_DictionaryFragment_Variable(OpcUaDataValue& dataValue);
        bool set_DictionaryFragment_Variable(const OpcUaDataValue& dataValue);

        //
        // String (Array)
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr dataTypeVersion_Variable_;
        ServerVariable::SPtr dictionaryFragment_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
