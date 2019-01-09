/*
    ObjectTypeClass: FileType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

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
        void userWriteable_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& userWriteable_Variable(void);
        bool get_UserWriteable_Variable(OpcUaDataValue& dataValue);
        bool set_UserWriteable_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void writeable_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& writeable_Variable(void);
        bool get_Writeable_Variable(OpcUaDataValue& dataValue);
        bool set_Writeable_Variable(const OpcUaDataValue& dataValue);

        virtual void call_Close_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_GetPosition_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_Open_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_Read_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_SetPosition_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_Write_Method(ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr openCount_Variable_;
        ServerVariable::SPtr size_Variable_;
        ServerVariable::SPtr userWriteable_Variable_;
        ServerVariable::SPtr writeable_Variable_;
        ServerMethod::SPtr close_Method_;
        ServerMethod::SPtr getPosition_Method_;
        ServerMethod::SPtr open_Method_;
        ServerMethod::SPtr read_Method_;
        ServerMethod::SPtr setPosition_Method_;
        ServerMethod::SPtr write_Method_;
   
   };

}

#endif
