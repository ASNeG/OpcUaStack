/*
    ObjectTypeClass: AddressSpaceFileType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_AddressSpaceFileType_h__
#define __OpcUaStackServer_AddressSpaceFileType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT AddressSpaceFileType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<AddressSpaceFileType> SPtr;
       typedef std::vector<AddressSpaceFileType::SPtr> Vec;
   
       AddressSpaceFileType(void);
       AddressSpaceFileType(const AddressSpaceFileType& value);
       virtual ~AddressSpaceFileType(void);

        //
        // String
        //
        void mimeType_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& mimeType_Variable(void);
        bool get_MimeType_Variable(OpcUaDataValue& dataValue);
        bool set_MimeType_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void openCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& openCount_Variable(void);
        bool get_OpenCount_Variable(OpcUaDataValue& dataValue);
        bool set_OpenCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt64
        //
        void size_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& size_Variable(void);
        bool get_Size_Variable(OpcUaDataValue& dataValue);
        bool set_Size_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void userWritable_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& userWritable_Variable(void);
        bool get_UserWritable_Variable(OpcUaDataValue& dataValue);
        bool set_UserWritable_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void writable_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& writable_Variable(void);
        bool get_Writable_Variable(OpcUaDataValue& dataValue);
        bool set_Writable_Variable(const OpcUaDataValue& dataValue);

        virtual void call_Close_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_ExportNamespace_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_GetPosition_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_Open_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_Read_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_SetPosition_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_Write_Method(ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr mimeType_Variable_;
        ServerVariable::SPtr openCount_Variable_;
        ServerVariable::SPtr size_Variable_;
        ServerVariable::SPtr userWritable_Variable_;
        ServerVariable::SPtr writable_Variable_;
        ServerMethod::SPtr close_Method_;
        ServerMethod::SPtr exportNamespace_Method_;
        ServerMethod::SPtr getPosition_Method_;
        ServerMethod::SPtr open_Method_;
        ServerMethod::SPtr read_Method_;
        ServerMethod::SPtr setPosition_Method_;
        ServerMethod::SPtr write_Method_;
   
   };

}

#endif
