/*
    ObjectTypeClass: HistoryServerCapabilitiesType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_HistoryServerCapabilitiesType_h__
#define __OpcUaStackServer_HistoryServerCapabilitiesType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT HistoryServerCapabilitiesType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<HistoryServerCapabilitiesType> SPtr;
       typedef std::vector<HistoryServerCapabilitiesType::SPtr> Vec;
   
       HistoryServerCapabilitiesType(void);
       HistoryServerCapabilitiesType(const HistoryServerCapabilitiesType& value);
       virtual ~HistoryServerCapabilitiesType(void);

        //
        // Boolean
        //
        void accessHistoryDataCapability_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& accessHistoryDataCapability_Variable(void);
        bool get_AccessHistoryDataCapability_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_AccessHistoryDataCapability_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void accessHistoryEventsCapability_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& accessHistoryEventsCapability_Variable(void);
        bool get_AccessHistoryEventsCapability_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_AccessHistoryEventsCapability_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void deleteAtTimeCapability_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& deleteAtTimeCapability_Variable(void);
        bool get_DeleteAtTimeCapability_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DeleteAtTimeCapability_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void deleteEventCapability_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& deleteEventCapability_Variable(void);
        bool get_DeleteEventCapability_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DeleteEventCapability_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void deleteRawCapability_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& deleteRawCapability_Variable(void);
        bool get_DeleteRawCapability_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DeleteRawCapability_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void insertAnnotationCapability_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& insertAnnotationCapability_Variable(void);
        bool get_InsertAnnotationCapability_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_InsertAnnotationCapability_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void insertDataCapability_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& insertDataCapability_Variable(void);
        bool get_InsertDataCapability_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_InsertDataCapability_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void insertEventCapability_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& insertEventCapability_Variable(void);
        bool get_InsertEventCapability_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_InsertEventCapability_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxReturnDataValues_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxReturnDataValues_Variable(void);
        bool get_MaxReturnDataValues_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MaxReturnDataValues_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxReturnEventValues_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxReturnEventValues_Variable(void);
        bool get_MaxReturnEventValues_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MaxReturnEventValues_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void replaceDataCapability_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& replaceDataCapability_Variable(void);
        bool get_ReplaceDataCapability_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ReplaceDataCapability_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void replaceEventCapability_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& replaceEventCapability_Variable(void);
        bool get_ReplaceEventCapability_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ReplaceEventCapability_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void updateDataCapability_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& updateDataCapability_Variable(void);
        bool get_UpdateDataCapability_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_UpdateDataCapability_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void updateEventCapability_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& updateEventCapability_Variable(void);
        bool get_UpdateEventCapability_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_UpdateEventCapability_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr accessHistoryDataCapability_Variable_;
        ServerVariable::SPtr accessHistoryEventsCapability_Variable_;
        ServerVariable::SPtr deleteAtTimeCapability_Variable_;
        ServerVariable::SPtr deleteEventCapability_Variable_;
        ServerVariable::SPtr deleteRawCapability_Variable_;
        ServerVariable::SPtr insertAnnotationCapability_Variable_;
        ServerVariable::SPtr insertDataCapability_Variable_;
        ServerVariable::SPtr insertEventCapability_Variable_;
        ServerVariable::SPtr maxReturnDataValues_Variable_;
        ServerVariable::SPtr maxReturnEventValues_Variable_;
        ServerVariable::SPtr replaceDataCapability_Variable_;
        ServerVariable::SPtr replaceEventCapability_Variable_;
        ServerVariable::SPtr updateDataCapability_Variable_;
        ServerVariable::SPtr updateEventCapability_Variable_;
   
   };

}

#endif
