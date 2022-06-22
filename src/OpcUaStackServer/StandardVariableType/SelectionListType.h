/*
    VariableTypeClass: SelectionListType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SelectionListType_h__
#define __OpcUaStackServer_SelectionListType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT SelectionListType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<SelectionListType> SPtr;
       typedef std::vector<SelectionListType::SPtr> Vec;
   
       SelectionListType(void);
       SelectionListType(const SelectionListType& value);
       virtual ~SelectionListType(void);

        //
        // Boolean
        //
        void restrictToList_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& restrictToList_Variable(void);
        bool get_RestrictToList_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_RestrictToList_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText (Array)
        //
        void selectionDescriptions_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& selectionDescriptions_Variable(void);
        bool get_SelectionDescriptions_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SelectionDescriptions_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Variant (Array)
        //
        void selections_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& selections_Variable(void);
        bool get_Selections_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Selections_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Variant
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr restrictToList_Variable_;
        ServerVariable::SPtr selectionDescriptions_Variable_;
        ServerVariable::SPtr selections_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
