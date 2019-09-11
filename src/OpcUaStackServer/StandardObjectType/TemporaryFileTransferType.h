/*
    ObjectTypeClass: TemporaryFileTransferType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_TemporaryFileTransferType_h__
#define __OpcUaStackServer_TemporaryFileTransferType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT TemporaryFileTransferType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<TemporaryFileTransferType> SPtr;
       typedef std::vector<TemporaryFileTransferType::SPtr> Vec;
   
       TemporaryFileTransferType(void);
       TemporaryFileTransferType(const TemporaryFileTransferType& value);
       virtual ~TemporaryFileTransferType(void);

        //
        // Duration
        //
        void clientProcessingTimeout_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& clientProcessingTimeout_Variable(void);
        bool get_ClientProcessingTimeout_Variable(OpcUaDataValue& dataValue);
        bool set_ClientProcessingTimeout_Variable(const OpcUaDataValue& dataValue);

        virtual void call_CloseAndCommit_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_GenerateFileForRead_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_GenerateFileForWrite_Method(ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr clientProcessingTimeout_Variable_;
        ServerMethod::SPtr closeAndCommit_Method_;
        ServerMethod::SPtr generateFileForRead_Method_;
        ServerMethod::SPtr generateFileForWrite_Method_;
   
   };

}

#endif
