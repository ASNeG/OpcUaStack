/*
    ObjectTypeClass: TransparentRedundancyType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_TransparentRedundancyType_h__
#define __OpcUaStackServer_TransparentRedundancyType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT TransparentRedundancyType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<TransparentRedundancyType> SPtr;
       typedef std::vector<TransparentRedundancyType::SPtr> Vec;
   
       TransparentRedundancyType(void);
       TransparentRedundancyType(const TransparentRedundancyType& value);
       virtual ~TransparentRedundancyType(void);

        //
        // String
        //
        void currentServerId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& currentServerId_Variable(void);
        bool get_CurrentServerId_Variable(OpcUaDataValue& dataValue);
        bool set_CurrentServerId_Variable(const OpcUaDataValue& dataValue);

        //
        // RedundancySupport
        //
        void redundancySupport_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& redundancySupport_Variable(void);
        bool get_RedundancySupport_Variable(OpcUaDataValue& dataValue);
        bool set_RedundancySupport_Variable(const OpcUaDataValue& dataValue);

        //
        // RedundantServerDataType (Array)
        //
        void redundantServerArray_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& redundantServerArray_Variable(void);
        bool get_RedundantServerArray_Variable(OpcUaDataValue& dataValue);
        bool set_RedundantServerArray_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr currentServerId_Variable_;
        ServerVariable::SPtr redundancySupport_Variable_;
        ServerVariable::SPtr redundantServerArray_Variable_;
   
   };

}

#endif
