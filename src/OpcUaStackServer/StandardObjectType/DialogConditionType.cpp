/*
    VariableTypeClass: DialogConditionType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/DialogConditionType.h"

namespace OpcUaStackServer
{
    
    DialogConditionType::DialogConditionType(void)
    : ObjectBase()
    , branchId_Variable_(boost::make_shared<ServerVariable>("BranchId_Variable"))
    , cancelResponse_Variable_(boost::make_shared<ServerVariable>("CancelResponse_Variable"))
    , clientUserId_Variable_(boost::make_shared<ServerVariable>("ClientUserId_Variable"))
    , comment_SourceTimestamp_Variable_(boost::make_shared<ServerVariable>("Comment_SourceTimestamp_Variable"))
    , comment_Variable_(boost::make_shared<ServerVariable>("Comment_Variable"))
    , conditionClassId_Variable_(boost::make_shared<ServerVariable>("ConditionClassId_Variable"))
    , conditionClassName_Variable_(boost::make_shared<ServerVariable>("ConditionClassName_Variable"))
    , conditionName_Variable_(boost::make_shared<ServerVariable>("ConditionName_Variable"))
    , conditionSubClassId_Variable_(boost::make_shared<ServerVariable>("ConditionSubClassId_Variable"))
    , conditionSubClassName_Variable_(boost::make_shared<ServerVariable>("ConditionSubClassName_Variable"))
    , defaultResponse_Variable_(boost::make_shared<ServerVariable>("DefaultResponse_Variable"))
    , dialogState_FalseState_Variable_(boost::make_shared<ServerVariable>("DialogState_FalseState_Variable"))
    , dialogState_Id_Variable_(boost::make_shared<ServerVariable>("DialogState_Id_Variable"))
    , dialogState_TransitionTime_Variable_(boost::make_shared<ServerVariable>("DialogState_TransitionTime_Variable"))
    , dialogState_TrueState_Variable_(boost::make_shared<ServerVariable>("DialogState_TrueState_Variable"))
    , dialogState_Variable_(boost::make_shared<ServerVariable>("DialogState_Variable"))
    , enabledState_EffectiveDisplayName_Variable_(boost::make_shared<ServerVariable>("EnabledState_EffectiveDisplayName_Variable"))
    , enabledState_EffectiveTransitionTime_Variable_(boost::make_shared<ServerVariable>("EnabledState_EffectiveTransitionTime_Variable"))
    , enabledState_FalseState_Variable_(boost::make_shared<ServerVariable>("EnabledState_FalseState_Variable"))
    , enabledState_Id_Variable_(boost::make_shared<ServerVariable>("EnabledState_Id_Variable"))
    , enabledState_TransitionTime_Variable_(boost::make_shared<ServerVariable>("EnabledState_TransitionTime_Variable"))
    , enabledState_TrueState_Variable_(boost::make_shared<ServerVariable>("EnabledState_TrueState_Variable"))
    , enabledState_Variable_(boost::make_shared<ServerVariable>("EnabledState_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , lastResponse_Variable_(boost::make_shared<ServerVariable>("LastResponse_Variable"))
    , lastSeverity_SourceTimestamp_Variable_(boost::make_shared<ServerVariable>("LastSeverity_SourceTimestamp_Variable"))
    , lastSeverity_Variable_(boost::make_shared<ServerVariable>("LastSeverity_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , okResponse_Variable_(boost::make_shared<ServerVariable>("OkResponse_Variable"))
    , prompt_Variable_(boost::make_shared<ServerVariable>("Prompt_Variable"))
    , quality_SourceTimestamp_Variable_(boost::make_shared<ServerVariable>("Quality_SourceTimestamp_Variable"))
    , quality_Variable_(boost::make_shared<ServerVariable>("Quality_Variable"))
    , receiveTime_Variable_(boost::make_shared<ServerVariable>("ReceiveTime_Variable"))
    , responseOptionSet_Variable_(boost::make_shared<ServerVariable>("ResponseOptionSet_Variable"))
    , retain_Variable_(boost::make_shared<ServerVariable>("Retain_Variable"))
    , severity_Variable_(boost::make_shared<ServerVariable>("Severity_Variable"))
    , sourceName_Variable_(boost::make_shared<ServerVariable>("SourceName_Variable"))
    , sourceNode_Variable_(boost::make_shared<ServerVariable>("SourceNode_Variable"))
    , time_Variable_(boost::make_shared<ServerVariable>("Time_Variable"))
    , addComment_Method_(boost::make_shared<ServerMethod>("AddComment_Method"))
    , disable_Method_(boost::make_shared<ServerMethod>("Disable_Method"))
    , enable_Method_(boost::make_shared<ServerMethod>("Enable_Method"))
    , respond_Method_(boost::make_shared<ServerMethod>("Respond_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2830);
        setServerVariable(branchId_Variable_);
        setServerVariable(cancelResponse_Variable_);
        setServerVariable(clientUserId_Variable_);
        setServerVariable(comment_SourceTimestamp_Variable_);
        setServerVariable(comment_Variable_);
        setServerVariable(conditionClassId_Variable_);
        setServerVariable(conditionClassName_Variable_);
        setServerVariable(conditionName_Variable_);
        setServerVariable(conditionSubClassId_Variable_);
        setServerVariable(conditionSubClassName_Variable_);
        setServerVariable(defaultResponse_Variable_);
        setServerVariable(dialogState_FalseState_Variable_);
        setServerVariable(dialogState_Id_Variable_);
        setServerVariable(dialogState_TransitionTime_Variable_);
        setServerVariable(dialogState_TrueState_Variable_);
        setServerVariable(dialogState_Variable_);
        setServerVariable(enabledState_EffectiveDisplayName_Variable_);
        setServerVariable(enabledState_EffectiveTransitionTime_Variable_);
        setServerVariable(enabledState_FalseState_Variable_);
        setServerVariable(enabledState_Id_Variable_);
        setServerVariable(enabledState_TransitionTime_Variable_);
        setServerVariable(enabledState_TrueState_Variable_);
        setServerVariable(enabledState_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(lastResponse_Variable_);
        setServerVariable(lastSeverity_SourceTimestamp_Variable_);
        setServerVariable(lastSeverity_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(okResponse_Variable_);
        setServerVariable(prompt_Variable_);
        setServerVariable(quality_SourceTimestamp_Variable_);
        setServerVariable(quality_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(responseOptionSet_Variable_);
        setServerVariable(retain_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(time_Variable_);
        setServerMethod(addComment_Method_);
        setServerMethod(disable_Method_);
        setServerMethod(enable_Method_);
        setServerMethod(respond_Method_);
        addComment_Method_->registerMethod(boost::bind(&DialogConditionType::call_AddComment_Method, this, _1));
        disable_Method_->registerMethod(boost::bind(&DialogConditionType::call_Disable_Method, this, _1));
        enable_Method_->registerMethod(boost::bind(&DialogConditionType::call_Enable_Method, this, _1));
        respond_Method_->registerMethod(boost::bind(&DialogConditionType::call_Respond_Method, this, _1));
    }
    
    DialogConditionType::DialogConditionType(const DialogConditionType& value)
    : ObjectBase()
    , branchId_Variable_(boost::make_shared<ServerVariable>("BranchId_Variable"))
    , cancelResponse_Variable_(boost::make_shared<ServerVariable>("CancelResponse_Variable"))
    , clientUserId_Variable_(boost::make_shared<ServerVariable>("ClientUserId_Variable"))
    , comment_SourceTimestamp_Variable_(boost::make_shared<ServerVariable>("Comment_SourceTimestamp_Variable"))
    , comment_Variable_(boost::make_shared<ServerVariable>("Comment_Variable"))
    , conditionClassId_Variable_(boost::make_shared<ServerVariable>("ConditionClassId_Variable"))
    , conditionClassName_Variable_(boost::make_shared<ServerVariable>("ConditionClassName_Variable"))
    , conditionName_Variable_(boost::make_shared<ServerVariable>("ConditionName_Variable"))
    , conditionSubClassId_Variable_(boost::make_shared<ServerVariable>("ConditionSubClassId_Variable"))
    , conditionSubClassName_Variable_(boost::make_shared<ServerVariable>("ConditionSubClassName_Variable"))
    , defaultResponse_Variable_(boost::make_shared<ServerVariable>("DefaultResponse_Variable"))
    , dialogState_FalseState_Variable_(boost::make_shared<ServerVariable>("DialogState_FalseState_Variable"))
    , dialogState_Id_Variable_(boost::make_shared<ServerVariable>("DialogState_Id_Variable"))
    , dialogState_TransitionTime_Variable_(boost::make_shared<ServerVariable>("DialogState_TransitionTime_Variable"))
    , dialogState_TrueState_Variable_(boost::make_shared<ServerVariable>("DialogState_TrueState_Variable"))
    , dialogState_Variable_(boost::make_shared<ServerVariable>("DialogState_Variable"))
    , enabledState_EffectiveDisplayName_Variable_(boost::make_shared<ServerVariable>("EnabledState_EffectiveDisplayName_Variable"))
    , enabledState_EffectiveTransitionTime_Variable_(boost::make_shared<ServerVariable>("EnabledState_EffectiveTransitionTime_Variable"))
    , enabledState_FalseState_Variable_(boost::make_shared<ServerVariable>("EnabledState_FalseState_Variable"))
    , enabledState_Id_Variable_(boost::make_shared<ServerVariable>("EnabledState_Id_Variable"))
    , enabledState_TransitionTime_Variable_(boost::make_shared<ServerVariable>("EnabledState_TransitionTime_Variable"))
    , enabledState_TrueState_Variable_(boost::make_shared<ServerVariable>("EnabledState_TrueState_Variable"))
    , enabledState_Variable_(boost::make_shared<ServerVariable>("EnabledState_Variable"))
    , eventId_Variable_(boost::make_shared<ServerVariable>("EventId_Variable"))
    , eventType_Variable_(boost::make_shared<ServerVariable>("EventType_Variable"))
    , lastResponse_Variable_(boost::make_shared<ServerVariable>("LastResponse_Variable"))
    , lastSeverity_SourceTimestamp_Variable_(boost::make_shared<ServerVariable>("LastSeverity_SourceTimestamp_Variable"))
    , lastSeverity_Variable_(boost::make_shared<ServerVariable>("LastSeverity_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , message_Variable_(boost::make_shared<ServerVariable>("Message_Variable"))
    , okResponse_Variable_(boost::make_shared<ServerVariable>("OkResponse_Variable"))
    , prompt_Variable_(boost::make_shared<ServerVariable>("Prompt_Variable"))
    , quality_SourceTimestamp_Variable_(boost::make_shared<ServerVariable>("Quality_SourceTimestamp_Variable"))
    , quality_Variable_(boost::make_shared<ServerVariable>("Quality_Variable"))
    , receiveTime_Variable_(boost::make_shared<ServerVariable>("ReceiveTime_Variable"))
    , responseOptionSet_Variable_(boost::make_shared<ServerVariable>("ResponseOptionSet_Variable"))
    , retain_Variable_(boost::make_shared<ServerVariable>("Retain_Variable"))
    , severity_Variable_(boost::make_shared<ServerVariable>("Severity_Variable"))
    , sourceName_Variable_(boost::make_shared<ServerVariable>("SourceName_Variable"))
    , sourceNode_Variable_(boost::make_shared<ServerVariable>("SourceNode_Variable"))
    , time_Variable_(boost::make_shared<ServerVariable>("Time_Variable"))
    , addComment_Method_(boost::make_shared<ServerMethod>("AddComment_Method"))
    , disable_Method_(boost::make_shared<ServerMethod>("Disable_Method"))
    , enable_Method_(boost::make_shared<ServerMethod>("Enable_Method"))
    , respond_Method_(boost::make_shared<ServerMethod>("Respond_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2830);
        setServerVariable(branchId_Variable_);
        setServerVariable(cancelResponse_Variable_);
        setServerVariable(clientUserId_Variable_);
        setServerVariable(comment_SourceTimestamp_Variable_);
        setServerVariable(comment_Variable_);
        setServerVariable(conditionClassId_Variable_);
        setServerVariable(conditionClassName_Variable_);
        setServerVariable(conditionName_Variable_);
        setServerVariable(conditionSubClassId_Variable_);
        setServerVariable(conditionSubClassName_Variable_);
        setServerVariable(defaultResponse_Variable_);
        setServerVariable(dialogState_FalseState_Variable_);
        setServerVariable(dialogState_Id_Variable_);
        setServerVariable(dialogState_TransitionTime_Variable_);
        setServerVariable(dialogState_TrueState_Variable_);
        setServerVariable(dialogState_Variable_);
        setServerVariable(enabledState_EffectiveDisplayName_Variable_);
        setServerVariable(enabledState_EffectiveTransitionTime_Variable_);
        setServerVariable(enabledState_FalseState_Variable_);
        setServerVariable(enabledState_Id_Variable_);
        setServerVariable(enabledState_TransitionTime_Variable_);
        setServerVariable(enabledState_TrueState_Variable_);
        setServerVariable(enabledState_Variable_);
        setServerVariable(eventId_Variable_);
        setServerVariable(eventType_Variable_);
        setServerVariable(lastResponse_Variable_);
        setServerVariable(lastSeverity_SourceTimestamp_Variable_);
        setServerVariable(lastSeverity_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(message_Variable_);
        setServerVariable(okResponse_Variable_);
        setServerVariable(prompt_Variable_);
        setServerVariable(quality_SourceTimestamp_Variable_);
        setServerVariable(quality_Variable_);
        setServerVariable(receiveTime_Variable_);
        setServerVariable(responseOptionSet_Variable_);
        setServerVariable(retain_Variable_);
        setServerVariable(severity_Variable_);
        setServerVariable(sourceName_Variable_);
        setServerVariable(sourceNode_Variable_);
        setServerVariable(time_Variable_);
        setServerMethod(addComment_Method_);
        setServerMethod(disable_Method_);
        setServerMethod(enable_Method_);
        setServerMethod(respond_Method_);
        addComment_Method_->registerMethod(boost::bind(&DialogConditionType::call_AddComment_Method, this, _1));
        disable_Method_->registerMethod(boost::bind(&DialogConditionType::call_Disable_Method, this, _1));
        enable_Method_->registerMethod(boost::bind(&DialogConditionType::call_Enable_Method, this, _1));
        respond_Method_->registerMethod(boost::bind(&DialogConditionType::call_Respond_Method, this, _1));
    }
    
    DialogConditionType::~DialogConditionType(void)
    {
    }

    ServerVariable::SPtr&
    DialogConditionType::branchId_Variable(void)
    {
        return branchId_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::cancelResponse_Variable(void)
    {
        return cancelResponse_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::clientUserId_Variable(void)
    {
        return clientUserId_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::comment_SourceTimestamp_Variable(void)
    {
        return comment_SourceTimestamp_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::comment_Variable(void)
    {
        return comment_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::conditionClassId_Variable(void)
    {
        return conditionClassId_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::conditionClassName_Variable(void)
    {
        return conditionClassName_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::conditionName_Variable(void)
    {
        return conditionName_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::conditionSubClassId_Variable(void)
    {
        return conditionSubClassId_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::conditionSubClassName_Variable(void)
    {
        return conditionSubClassName_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::defaultResponse_Variable(void)
    {
        return defaultResponse_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::dialogState_FalseState_Variable(void)
    {
        return dialogState_FalseState_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::dialogState_Id_Variable(void)
    {
        return dialogState_Id_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::dialogState_TransitionTime_Variable(void)
    {
        return dialogState_TransitionTime_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::dialogState_TrueState_Variable(void)
    {
        return dialogState_TrueState_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::dialogState_Variable(void)
    {
        return dialogState_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::enabledState_EffectiveDisplayName_Variable(void)
    {
        return enabledState_EffectiveDisplayName_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::enabledState_EffectiveTransitionTime_Variable(void)
    {
        return enabledState_EffectiveTransitionTime_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::enabledState_FalseState_Variable(void)
    {
        return enabledState_FalseState_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::enabledState_Id_Variable(void)
    {
        return enabledState_Id_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::enabledState_TransitionTime_Variable(void)
    {
        return enabledState_TransitionTime_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::enabledState_TrueState_Variable(void)
    {
        return enabledState_TrueState_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::enabledState_Variable(void)
    {
        return enabledState_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::eventId_Variable(void)
    {
        return eventId_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::eventType_Variable(void)
    {
        return eventType_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::lastResponse_Variable(void)
    {
        return lastResponse_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::lastSeverity_SourceTimestamp_Variable(void)
    {
        return lastSeverity_SourceTimestamp_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::lastSeverity_Variable(void)
    {
        return lastSeverity_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::localTime_Variable(void)
    {
        return localTime_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::message_Variable(void)
    {
        return message_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::okResponse_Variable(void)
    {
        return okResponse_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::prompt_Variable(void)
    {
        return prompt_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::quality_SourceTimestamp_Variable(void)
    {
        return quality_SourceTimestamp_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::quality_Variable(void)
    {
        return quality_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::receiveTime_Variable(void)
    {
        return receiveTime_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::responseOptionSet_Variable(void)
    {
        return responseOptionSet_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::retain_Variable(void)
    {
        return retain_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::severity_Variable(void)
    {
        return severity_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::sourceName_Variable(void)
    {
        return sourceName_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::sourceNode_Variable(void)
    {
        return sourceNode_Variable_;
    }

    ServerVariable::SPtr&
    DialogConditionType::time_Variable(void)
    {
        return time_Variable_;
    }

    void
    DialogConditionType::branchId_Variable(ServerVariable::SPtr& serverVariable)
    {
        branchId_Variable_ = serverVariable;
    }

    void
    DialogConditionType::cancelResponse_Variable(ServerVariable::SPtr& serverVariable)
    {
        cancelResponse_Variable_ = serverVariable;
    }

    void
    DialogConditionType::clientUserId_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientUserId_Variable_ = serverVariable;
    }

    void
    DialogConditionType::comment_SourceTimestamp_Variable(ServerVariable::SPtr& serverVariable)
    {
        comment_SourceTimestamp_Variable_ = serverVariable;
    }

    void
    DialogConditionType::comment_Variable(ServerVariable::SPtr& serverVariable)
    {
        comment_Variable_ = serverVariable;
    }

    void
    DialogConditionType::conditionClassId_Variable(ServerVariable::SPtr& serverVariable)
    {
        conditionClassId_Variable_ = serverVariable;
    }

    void
    DialogConditionType::conditionClassName_Variable(ServerVariable::SPtr& serverVariable)
    {
        conditionClassName_Variable_ = serverVariable;
    }

    void
    DialogConditionType::conditionName_Variable(ServerVariable::SPtr& serverVariable)
    {
        conditionName_Variable_ = serverVariable;
    }

    void
    DialogConditionType::conditionSubClassId_Variable(ServerVariable::SPtr& serverVariable)
    {
        conditionSubClassId_Variable_ = serverVariable;
    }

    void
    DialogConditionType::conditionSubClassName_Variable(ServerVariable::SPtr& serverVariable)
    {
        conditionSubClassName_Variable_ = serverVariable;
    }

    void
    DialogConditionType::defaultResponse_Variable(ServerVariable::SPtr& serverVariable)
    {
        defaultResponse_Variable_ = serverVariable;
    }

    void
    DialogConditionType::dialogState_FalseState_Variable(ServerVariable::SPtr& serverVariable)
    {
        dialogState_FalseState_Variable_ = serverVariable;
    }

    void
    DialogConditionType::dialogState_Id_Variable(ServerVariable::SPtr& serverVariable)
    {
        dialogState_Id_Variable_ = serverVariable;
    }

    void
    DialogConditionType::dialogState_TransitionTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        dialogState_TransitionTime_Variable_ = serverVariable;
    }

    void
    DialogConditionType::dialogState_TrueState_Variable(ServerVariable::SPtr& serverVariable)
    {
        dialogState_TrueState_Variable_ = serverVariable;
    }

    void
    DialogConditionType::dialogState_Variable(ServerVariable::SPtr& serverVariable)
    {
        dialogState_Variable_ = serverVariable;
    }

    void
    DialogConditionType::enabledState_EffectiveDisplayName_Variable(ServerVariable::SPtr& serverVariable)
    {
        enabledState_EffectiveDisplayName_Variable_ = serverVariable;
    }

    void
    DialogConditionType::enabledState_EffectiveTransitionTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        enabledState_EffectiveTransitionTime_Variable_ = serverVariable;
    }

    void
    DialogConditionType::enabledState_FalseState_Variable(ServerVariable::SPtr& serverVariable)
    {
        enabledState_FalseState_Variable_ = serverVariable;
    }

    void
    DialogConditionType::enabledState_Id_Variable(ServerVariable::SPtr& serverVariable)
    {
        enabledState_Id_Variable_ = serverVariable;
    }

    void
    DialogConditionType::enabledState_TransitionTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        enabledState_TransitionTime_Variable_ = serverVariable;
    }

    void
    DialogConditionType::enabledState_TrueState_Variable(ServerVariable::SPtr& serverVariable)
    {
        enabledState_TrueState_Variable_ = serverVariable;
    }

    void
    DialogConditionType::enabledState_Variable(ServerVariable::SPtr& serverVariable)
    {
        enabledState_Variable_ = serverVariable;
    }

    void
    DialogConditionType::eventId_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventId_Variable_ = serverVariable;
    }

    void
    DialogConditionType::eventType_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventType_Variable_ = serverVariable;
    }

    void
    DialogConditionType::lastResponse_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastResponse_Variable_ = serverVariable;
    }

    void
    DialogConditionType::lastSeverity_SourceTimestamp_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastSeverity_SourceTimestamp_Variable_ = serverVariable;
    }

    void
    DialogConditionType::lastSeverity_Variable(ServerVariable::SPtr& serverVariable)
    {
        lastSeverity_Variable_ = serverVariable;
    }

    void
    DialogConditionType::localTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        localTime_Variable_ = serverVariable;
    }

    void
    DialogConditionType::message_Variable(ServerVariable::SPtr& serverVariable)
    {
        message_Variable_ = serverVariable;
    }

    void
    DialogConditionType::okResponse_Variable(ServerVariable::SPtr& serverVariable)
    {
        okResponse_Variable_ = serverVariable;
    }

    void
    DialogConditionType::prompt_Variable(ServerVariable::SPtr& serverVariable)
    {
        prompt_Variable_ = serverVariable;
    }

    void
    DialogConditionType::quality_SourceTimestamp_Variable(ServerVariable::SPtr& serverVariable)
    {
        quality_SourceTimestamp_Variable_ = serverVariable;
    }

    void
    DialogConditionType::quality_Variable(ServerVariable::SPtr& serverVariable)
    {
        quality_Variable_ = serverVariable;
    }

    void
    DialogConditionType::receiveTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        receiveTime_Variable_ = serverVariable;
    }

    void
    DialogConditionType::responseOptionSet_Variable(ServerVariable::SPtr& serverVariable)
    {
        responseOptionSet_Variable_ = serverVariable;
    }

    void
    DialogConditionType::retain_Variable(ServerVariable::SPtr& serverVariable)
    {
        retain_Variable_ = serverVariable;
    }

    void
    DialogConditionType::severity_Variable(ServerVariable::SPtr& serverVariable)
    {
        severity_Variable_ = serverVariable;
    }

    void
    DialogConditionType::sourceName_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceName_Variable_ = serverVariable;
    }

    void
    DialogConditionType::sourceNode_Variable(ServerVariable::SPtr& serverVariable)
    {
        sourceNode_Variable_ = serverVariable;
    }

    void
    DialogConditionType::time_Variable(ServerVariable::SPtr& serverVariable)
    {
        time_Variable_ = serverVariable;
    }

    bool
    DialogConditionType::get_BranchId_Variable(OpcUaDataValue& dataValue)
    {
        return branchId_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_CancelResponse_Variable(OpcUaDataValue& dataValue)
    {
        return cancelResponse_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_ClientUserId_Variable(OpcUaDataValue& dataValue)
    {
        return clientUserId_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_Comment_SourceTimestamp_Variable(OpcUaDataValue& dataValue)
    {
        return comment_SourceTimestamp_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_Comment_Variable(OpcUaDataValue& dataValue)
    {
        return comment_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_ConditionClassId_Variable(OpcUaDataValue& dataValue)
    {
        return conditionClassId_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_ConditionClassName_Variable(OpcUaDataValue& dataValue)
    {
        return conditionClassName_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_ConditionName_Variable(OpcUaDataValue& dataValue)
    {
        return conditionName_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_ConditionSubClassId_Variable(OpcUaDataValue& dataValue)
    {
        return conditionSubClassId_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_ConditionSubClassName_Variable(OpcUaDataValue& dataValue)
    {
        return conditionSubClassName_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_DefaultResponse_Variable(OpcUaDataValue& dataValue)
    {
        return defaultResponse_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_DialogState_FalseState_Variable(OpcUaDataValue& dataValue)
    {
        return dialogState_FalseState_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_DialogState_Id_Variable(OpcUaDataValue& dataValue)
    {
        return dialogState_Id_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_DialogState_TransitionTime_Variable(OpcUaDataValue& dataValue)
    {
        return dialogState_TransitionTime_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_DialogState_TrueState_Variable(OpcUaDataValue& dataValue)
    {
        return dialogState_TrueState_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_DialogState_Variable(OpcUaDataValue& dataValue)
    {
        return dialogState_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_EnabledState_EffectiveDisplayName_Variable(OpcUaDataValue& dataValue)
    {
        return enabledState_EffectiveDisplayName_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_EnabledState_EffectiveTransitionTime_Variable(OpcUaDataValue& dataValue)
    {
        return enabledState_EffectiveTransitionTime_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_EnabledState_FalseState_Variable(OpcUaDataValue& dataValue)
    {
        return enabledState_FalseState_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_EnabledState_Id_Variable(OpcUaDataValue& dataValue)
    {
        return enabledState_Id_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_EnabledState_TransitionTime_Variable(OpcUaDataValue& dataValue)
    {
        return enabledState_TransitionTime_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_EnabledState_TrueState_Variable(OpcUaDataValue& dataValue)
    {
        return enabledState_TrueState_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_EnabledState_Variable(OpcUaDataValue& dataValue)
    {
        return enabledState_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_EventId_Variable(OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_EventType_Variable(OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_LastResponse_Variable(OpcUaDataValue& dataValue)
    {
        return lastResponse_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_LastSeverity_SourceTimestamp_Variable(OpcUaDataValue& dataValue)
    {
        return lastSeverity_SourceTimestamp_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_LastSeverity_Variable(OpcUaDataValue& dataValue)
    {
        return lastSeverity_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_LocalTime_Variable(OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_Message_Variable(OpcUaDataValue& dataValue)
    {
        return message_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_OkResponse_Variable(OpcUaDataValue& dataValue)
    {
        return okResponse_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_Prompt_Variable(OpcUaDataValue& dataValue)
    {
        return prompt_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_Quality_SourceTimestamp_Variable(OpcUaDataValue& dataValue)
    {
        return quality_SourceTimestamp_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_Quality_Variable(OpcUaDataValue& dataValue)
    {
        return quality_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_ReceiveTime_Variable(OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_ResponseOptionSet_Variable(OpcUaDataValue& dataValue)
    {
        return responseOptionSet_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_Retain_Variable(OpcUaDataValue& dataValue)
    {
        return retain_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_Severity_Variable(OpcUaDataValue& dataValue)
    {
        return severity_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_SourceName_Variable(OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_SourceNode_Variable(OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::get_Time_Variable(OpcUaDataValue& dataValue)
    {
        return time_Variable_->getDataValue(dataValue);
    }

    bool
    DialogConditionType::set_BranchId_Variable(const OpcUaDataValue& dataValue)
    {
        return branchId_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_CancelResponse_Variable(const OpcUaDataValue& dataValue)
    {
        return cancelResponse_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_ClientUserId_Variable(const OpcUaDataValue& dataValue)
    {
        return clientUserId_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_Comment_SourceTimestamp_Variable(const OpcUaDataValue& dataValue)
    {
        return comment_SourceTimestamp_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_Comment_Variable(const OpcUaDataValue& dataValue)
    {
        return comment_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_ConditionClassId_Variable(const OpcUaDataValue& dataValue)
    {
        return conditionClassId_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_ConditionClassName_Variable(const OpcUaDataValue& dataValue)
    {
        return conditionClassName_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_ConditionName_Variable(const OpcUaDataValue& dataValue)
    {
        return conditionName_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_ConditionSubClassId_Variable(const OpcUaDataValue& dataValue)
    {
        return conditionSubClassId_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_ConditionSubClassName_Variable(const OpcUaDataValue& dataValue)
    {
        return conditionSubClassName_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_DefaultResponse_Variable(const OpcUaDataValue& dataValue)
    {
        return defaultResponse_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_DialogState_FalseState_Variable(const OpcUaDataValue& dataValue)
    {
        return dialogState_FalseState_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_DialogState_Id_Variable(const OpcUaDataValue& dataValue)
    {
        return dialogState_Id_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_DialogState_TransitionTime_Variable(const OpcUaDataValue& dataValue)
    {
        return dialogState_TransitionTime_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_DialogState_TrueState_Variable(const OpcUaDataValue& dataValue)
    {
        return dialogState_TrueState_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_DialogState_Variable(const OpcUaDataValue& dataValue)
    {
        return dialogState_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_EnabledState_EffectiveDisplayName_Variable(const OpcUaDataValue& dataValue)
    {
        return enabledState_EffectiveDisplayName_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_EnabledState_EffectiveTransitionTime_Variable(const OpcUaDataValue& dataValue)
    {
        return enabledState_EffectiveTransitionTime_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_EnabledState_FalseState_Variable(const OpcUaDataValue& dataValue)
    {
        return enabledState_FalseState_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_EnabledState_Id_Variable(const OpcUaDataValue& dataValue)
    {
        return enabledState_Id_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_EnabledState_TransitionTime_Variable(const OpcUaDataValue& dataValue)
    {
        return enabledState_TransitionTime_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_EnabledState_TrueState_Variable(const OpcUaDataValue& dataValue)
    {
        return enabledState_TrueState_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_EnabledState_Variable(const OpcUaDataValue& dataValue)
    {
        return enabledState_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_EventId_Variable(const OpcUaDataValue& dataValue)
    {
        return eventId_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_EventType_Variable(const OpcUaDataValue& dataValue)
    {
        return eventType_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_LastResponse_Variable(const OpcUaDataValue& dataValue)
    {
        return lastResponse_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_LastSeverity_SourceTimestamp_Variable(const OpcUaDataValue& dataValue)
    {
        return lastSeverity_SourceTimestamp_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_LastSeverity_Variable(const OpcUaDataValue& dataValue)
    {
        return lastSeverity_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_LocalTime_Variable(const OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_Message_Variable(const OpcUaDataValue& dataValue)
    {
        return message_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_OkResponse_Variable(const OpcUaDataValue& dataValue)
    {
        return okResponse_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_Prompt_Variable(const OpcUaDataValue& dataValue)
    {
        return prompt_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_Quality_SourceTimestamp_Variable(const OpcUaDataValue& dataValue)
    {
        return quality_SourceTimestamp_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_Quality_Variable(const OpcUaDataValue& dataValue)
    {
        return quality_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_ReceiveTime_Variable(const OpcUaDataValue& dataValue)
    {
        return receiveTime_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_ResponseOptionSet_Variable(const OpcUaDataValue& dataValue)
    {
        return responseOptionSet_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_Retain_Variable(const OpcUaDataValue& dataValue)
    {
        return retain_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_Severity_Variable(const OpcUaDataValue& dataValue)
    {
        return severity_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_SourceName_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceName_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_SourceNode_Variable(const OpcUaDataValue& dataValue)
    {
        return sourceNode_Variable_->setDataValue(dataValue);
    }

    bool
    DialogConditionType::set_Time_Variable(const OpcUaDataValue& dataValue)
    {
        return time_Variable_->setDataValue(dataValue);
    }

    void
    DialogConditionType::call_AddComment_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    DialogConditionType::call_Disable_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    DialogConditionType::call_Enable_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    DialogConditionType::call_Respond_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
