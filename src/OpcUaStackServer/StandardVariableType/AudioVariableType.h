/*
    VariableTypeClass: AudioVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_AudioVariableType_h__
#define __OpcUaStackServer_AudioVariableType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
   
   class DLLEXPORT AudioVariableType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<AudioVariableType> SPtr;
       typedef std::vector<AudioVariableType::SPtr> Vec;
   
       AudioVariableType(void);
       AudioVariableType(const AudioVariableType& value);
       virtual ~AudioVariableType(void);

        //
        // String
        //
        void agencyId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& agencyId_Variable(void);
        bool get_AgencyId_Variable(OpcUaDataValue& dataValue);
        bool set_AgencyId_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void listId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& listId_Variable(void);
        bool get_ListId_Variable(OpcUaDataValue& dataValue);
        bool set_ListId_Variable(const OpcUaDataValue& dataValue);

        //
        // AudioDataType (Array)
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void versionId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& versionId_Variable(void);
        bool get_VersionId_Variable(OpcUaDataValue& dataValue);
        bool set_VersionId_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr agencyId_Variable_;
        ServerVariable::SPtr listId_Variable_;
        ServerVariable::SPtr variable_;
        ServerVariable::SPtr versionId_Variable_;
   
   };

}

#endif
