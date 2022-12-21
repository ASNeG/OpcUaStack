/*
    ObjectTypeClass: FileType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_FileType_h__
#define __OpcUaStackServer_FileType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT FileType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<FileType> SPtr;
       typedef std::vector<FileType::SPtr> Vec;
   
       FileType(void);
       FileType(const FileType& value);
       virtual ~FileType(void);

        //
        // String
        //
        void mimeType_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& mimeType_Variable(void);
        bool get_MimeType_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MimeType_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void openCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& openCount_Variable(void);
        bool get_OpenCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_OpenCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt64
        //
        void size_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& size_Variable(void);
        bool get_Size_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Size_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void userWritable_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& userWritable_Variable(void);
        bool get_UserWritable_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_UserWritable_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void writable_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& writable_Variable(void);
        bool get_Writable_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Writable_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        virtual void call_Close_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_GetPosition_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_Open_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_Read_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_SetPosition_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_Write_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr mimeType_Variable_;
        ServerVariable::SPtr openCount_Variable_;
        ServerVariable::SPtr size_Variable_;
        ServerVariable::SPtr userWritable_Variable_;
        ServerVariable::SPtr writable_Variable_;
        ServerMethod::SPtr close_Method_;
        ServerMethod::SPtr getPosition_Method_;
        ServerMethod::SPtr open_Method_;
        ServerMethod::SPtr read_Method_;
        ServerMethod::SPtr setPosition_Method_;
        ServerMethod::SPtr write_Method_;
   
   };

}

#endif
