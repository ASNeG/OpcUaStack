/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaStatusCodeMap
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool OpcUaStatusCodeMap::mapExist_ = false;
	OpcUaStatusCodeMap::StatusCodeMap OpcUaStatusCodeMap::shortStatusCodeMap_;
	OpcUaStatusCodeMap::StatusCodeMap OpcUaStatusCodeMap::longStatusCodeMap_;
	OpcUaStatusCodeMap::StatusCodeReverseMap OpcUaStatusCodeMap::reverseStatusCodeMap_;

	std::string 
	OpcUaStatusCodeMap::shortString(OpcUaStatusCode statusCode)
	{
		initial();
		StatusCodeMap::iterator it = shortStatusCodeMap_.find(statusCode);
		if (it == shortStatusCodeMap_.end()) {
			std::stringstream ss;
			ss << statusCode;
			return ss.str();
		}
		return it->second;
	}

	std::string 
	OpcUaStatusCodeMap::longString(OpcUaStatusCode statusCode)
	{
		initial();
		StatusCodeMap::iterator it = longStatusCodeMap_.find(statusCode);
		if (it == longStatusCodeMap_.end()) {
			std::stringstream ss;
			ss << statusCode;
			return ss.str();
		}
		return it->second;
	}

	OpcUaStatusCode
	OpcUaStatusCodeMap::statusCode(const std::string& statusCodeString)
	{
		initial();
		auto it = reverseStatusCodeMap_.find(statusCodeString);
		if (it == reverseStatusCodeMap_.end()) {
			return BadStatusCodeUnknown;
		}
		return it->second;
	}

	bool
	OpcUaStatusCodeMap::exist(OpcUaStatusCode statusCode)
	{
		initial();
		auto it = longStatusCodeMap_.find(statusCode);
		if (it == longStatusCodeMap_.end()) return false;
		return true;
	}

	bool
	OpcUaStatusCodeMap::exist(const std::string& statusCodeString)
	{
		initial();
		StatusCodeReverseMap::iterator it = reverseStatusCodeMap_.find(statusCodeString);
		if (it == reverseStatusCodeMap_.end()) return false;
		return true;
	}

	void
	OpcUaStatusCodeMap::getStatusCodeVec(std::vector<std::string>& statusCodeVec)
	{
		initial();
		StatusCodeMap::iterator it;
		for (it = shortStatusCodeMap_.begin(); it !=  shortStatusCodeMap_.end(); it++) {
			statusCodeVec.push_back(it->second);
		}
	}

	void 
	OpcUaStatusCodeMap::insert(OpcUaStatusCode statusCode, const std::string& shortStatusCodeString, const std::string& longStatusCodeString)
	{
		shortStatusCodeMap_.insert(std::make_pair(statusCode, shortStatusCodeString));
		longStatusCodeMap_.insert(std::make_pair(statusCode, longStatusCodeString));

		reverseStatusCodeMap_.insert(std::make_pair(shortStatusCodeString, statusCode));
	}

	void
	OpcUaStatusCodeMap::initial(void)
	{
		if (mapExist_) return;
		mapExist_ = true;

		insert(Success,											"Success",										"Success");
		insert(BadUnexpectedError,								"BadUnexpectedError",							"An unexpected error occurred");
		insert(BadInternalError,								"BadInternalError",								"An internal error occurred as a result of a programming or configuration error");
		insert(BadOutOfMemory,									"BadOutOfMemory",								"Not enough memory to complete the operation");
		insert(BadResourceUnavailable,							"BadResourceUnavailable",						"An operating system resource is not available");
		insert(BadCommunicationError,							"BadCommunicationError",						"A low level communication error occurred");
		insert(BadEncodingError,								"BadEncodingError",								"Encoding halted because of invalid data in the objects being serialized");
		insert(BadDecodingError,								"BadDecodingError",								"Decoding halted because of invalid data in the stream");
		insert(BadEncodingLimitsExceeded,						"BadEncodingLimitsExceeded",					"The message encoding/decoding limits imposed by the stack have been exceeded");
		insert(BadRequestTooLarge,								"BadRequestTooLarge",							"The request message size exceeds limits set by the server");
		insert(BadResponseTooLarge,								"BadResponseTooLarge",							"The response message size exceeds limits set by the client");
		insert(BadUnknownResponse,								"BadUnknownResponse",							"An unrecognized response was received from the server");
		insert(BadTimeout,										"BadTimeout",									"The operation timed out");
		insert(BadServiceUnsupported,							"BadServiceUnsupported",						"The server does not support the requested service");
		insert(BadShutdown,										"BadShutdown",									"The operation was cancelled because the application is shutting down");
		insert(BadServerNotConnected,							"BadServerNotConnected",						"The operation could not complete because the client is not connected to the server");
		insert(BadServerHalted,									"BadServerHalted",								"The server has stopped and cannot process any requests");
		insert(BadNothingToDo,									"BadNothingToDo",								"There was nothing to do because the client passed a list of operations with no elements");
		insert(BadTooManyOperations,							"BadTooManyOperations",							"The request could not be processed because it specified too many operations");
		insert(BadTooManyMonitoredItems,						"BadTooManyMonitoredItems",						"The request could not be processed because there are too many monitored items in the subscription");
		insert(BadDataTypeIdUnknown,							"BadDataTypeIdUnknown",							"The extension object cannot be (de)serialized because the data type id is not recognized");
		insert(BadCertificateInvalid,							"BadCertificateInvalid",						"The certificate provided as a parameter is not valid");
		insert(BadCertificateChainIncomplete,					"BadCertificateChainIncomplete",				"The certificate chain is invalid");
		insert(BadSecurityChecksFailed,							"BadSecurityChecksFailed",						"An error occurred verifying security");
		insert(BadCertificateTimeInvalid,						"BadCertificateTimeInvalid",					"The Certificate has expired or is not yet valid");
		insert(BadCertificateIssuerTimeInvalid,					"BadCertificateIssuerTimeInvalid",				"An Issuer Certificate has expired or is not yet valid");
		insert(BadCertificateHostNameInvalid,					"BadCertificateHostNameInvalid",				"The HostName used to connect to a Server does not match a HostName in the Certificate");
		insert(BadCertificateUriInvalid,						"BadCertificateUriInvalid",						"The URI specified in the ApplicationDescription does not match the URI in the Certificate");
		insert(BadCertificateUseNotAllowed,						"BadCertificateUseNotAllowed",					"The Certificate may not be used for the requested operation");
		insert(BadCertificateIssuerUseNotAllowed,				"BadCertificateIssuerUseNotAllowed",			"The Issuer Certificate may not be used for the requested operation");
		insert(BadCertificateUntrusted,							"BadCertificateUntrusted",						"The Certificate is not trusted");
		insert(BadCertificateRevocationUnknown,					"BadCertificateRevocationUnknown",				"It was not possible to determine if the Certificate has been revoked");
		insert(BadCertificateIssuerRevocationUnknown,			"BadCertificateIssuerRevocationUnknown",		"It was not possible to determine if the Issuer Certificate has been revoked");
		insert(BadCertificateRevoked,							"BadCertificateRevoked",						"The Certificate has been revoked");
		insert(BadCertificateIssuerRevoked,						"BadCertificateIssuerRevoked",					"The Issuer Certificate has been revoked");
		insert(BadUserAccessDenied,								"BadUserAccessDenied",							"User does not have permission to perform the requested operation");
		insert(BadIdentityTokenInvalid,							"BadIdentityTokenInvalid",						"The user identity token is not valid");
		insert(BadIdentityTokenRejected,						"BadIdentityTokenRejected",						"The user identity token is valid but the server has rejected it");
		insert(BadSecureChannelIdInvalid,						"BadSecureChannelIdInvalid",					"The specified secure channel is no longer valid");
		insert(BadInvalidTimestamp,								"BadInvalidTimestamp",							"The timestamp is outside the range allowed by the server");
		insert(BadNonceInvalid,									"BadNonceInvalid",								"The nonce does appear to be not a random value or it is not the correct length");
		insert(BadSessionIdInvalid,								"BadSessionIdInvalid",							"The session id is not valid");
		insert(BadSessionClosed,								"BadSessionClosed",								"The session was closed by the client");
		insert(BadSessionNotActivated,							"BadSessionNotActivated",						"The session cannot be used because ActivateSession has not been called");
		insert(BadSubscriptionIdInvalid,						"BadSubscriptionIdInvalid",						"The subscription id is not valid");
		insert(BadRequestHeaderInvalid,							"BadRequestHeaderInvalid",						"The header for the request is missing or invalid");
		insert(BadTimestampsToReturnInvalid,					"BadTimestampsToReturnInvalid",					"The timestamps to return parameter is invalid");
		insert(BadRequestCancelledByClient,						"BadRequestCancelledByClient",					"The request was cancelled by the client");
		insert(GoodSubscriptionTransferred,						"GoodSubscriptionTransferred",					"The subscription was transferred to another session");
		insert(GoodCompletesAsynchronously,						"GoodCompletesAsynchronously",					"The processing will complete asynchronously");
		insert(GoodOverload,									"GoodOverload",									"Sampling has slowed down due to resource limitations");
		insert(GoodClamped,										"GoodClamped",									"The value written was accepted but was clamped");
		insert(BadNoCommunication,								"BadNoCommunication",							"Communication with the data source is defined, but not established, and there is no last known value available");
		insert(BadWaitingForInitialData,						"BadWaitingForInitialData",						"Waiting for the server to obtain values from the underlying data source");
		insert(BadNodeIdInvalid,								"BadNodeIdInvalid",								"The syntax of the node id is not valid");
		insert(BadNodeIdUnknown,								"BadNodeIdUnknown",								"The node id refers to a node that does not exist in the server address space");
		insert(BadAttributeIdInvalid,							"BadAttributeIdInvalid",						"The attribute is not supported for the specified Node");
		insert(BadIndexRangeInvalid,							"BadIndexRangeInvalid",							"The syntax of the index range parameter is invalid");
		insert(BadIndexRangeNoData,								"BadIndexRangeNoData",							"No data exists within the range of indexes specified");
		insert(BadDataEncodingInvalid,							"BadDataEncodingInvalid",						"The data encoding is invalid");
		insert(BadDataEncodingUnsupported,						"BadDataEncodingUnsupported",					"The server does not support the requested data encoding for the node");
		insert(BadNotReadable,									"BadNotReadable",								"The access level does not allow reading or subscribing to the Node");
		insert(BadNotWritable,									"BadNotWritable",								"The access level does not allow writing to the Node");
		insert(BadOutOfRange,									"BadOutOfRange",								"The value was out of range");
		insert(BadNotSupported,									"BadNotSupported",								"The requested operation is not supported");
		insert(BadNotFound,										"BadNotFound",									"A requested item was not found or a search operation ended without success");
		insert(BadObjectDeleted,								"BadObjectDeleted",								"The object cannot be used because it has been deleted");
		insert(BadNotImplemented,								"BadNotImplemented",							"Requested operation is not implemented");
		insert(BadMonitoringModeInvalid,						"BadMonitoringModeInvalid",						"The monitoring mode is invalid");
		insert(BadMonitoredItemIdInvalid,						"BadMonitoredItemIdInvalid",					"The monitoring item id does not refer to a valid monitored item");
		insert(BadMonitoredItemFilterInvalid,					"BadMonitoredItemFilterInvalid",				"The monitored item filter parameter is not valid");
		insert(BadMonitoredItemFilterUnsupported,				"BadMonitoredItemFilterUnsupported",			"The server does not support the requested monitored item filter");
		insert(BadFilterNotAllowed,								"BadFilterNotAllowed",							"A monitoring filter cannot be used in combination with the attribute specified");
		insert(BadStructureMissing,								"BadStructureMissing",							"A mandatory structured parameter was missing or null");
		insert(BadEventFilterInvalid,							"BadEventFilterInvalid",						"The event filter is not valid");
		insert(BadContentFilterInvalid,							"BadContentFilterInvalid",						"The content filter is not valid");
		insert(BadFilterOperatorInvalid,						"BadFilterOperatorInvalid",						"An unregognized operator was provided in a filter");
		insert(BadFilterOperatorUnsupported,					"BadFilterOperatorUnsupported",					"A valid operator was provided, but the server does not provide support for this filter operator");
		insert(BadFilterOperandCountMismatch,					"BadFilterOperandCountMismatch",				"The number of operands provided for the filter operator was less then expected for the operand provided");
		insert(BadFilterOperandInvalid,							"BadFilterOperandInvalid",						"The operand used in a content filter is not valid");
		insert(BadFilterElementInvalid,							"BadFilterElementInvalid",						"The referenced element is not a valid element in the content filter");
		insert(BadFilterLiteralInvalid,							"BadFilterLiteralInvalid",						"The referenced literal is not a valid value");
		insert(BadContinuationPointInvalid,						"BadContinuationPointInvalid",					"The continuation point provide is longer valid");
		insert(BadNoContinuationPoints,							"BadNoContinuationPoints",						"The operation could not be processed because all continuation points have been allocated");
		insert(BadReferenceTypeIdInvalid,						"BadReferenceTypeIdInvalid",					"The reference type is not valid");
		insert(BadBrowseDirectionInvalid,						"BadBrowseDirectionInvalid",					"The browse direction is not valid");
		insert(BadNodeNotInView,								"BadNodeNotInView",								"The node is not part of the view");
		insert(BadServerUriInvalid,								"BadServerUriInvalid",							"The ServerUri is not a valid URI");
		insert(BadServerNameMissing,							"BadServerNameMissing",							"No ServerName was specified");
		insert(BadDiscoveryUrlMissing,							"BadDiscoveryUrlMissing",						"No DiscoveryUrl was specified");
		insert(BadSempahoreFileMissing,							"BadSempahoreFileMissing",						"The semaphore file specified by the client is not valid");
		insert(BadRequestTypeInvalid,							"BadRequestTypeInvalid",						"The security token request type is not valid");
		insert(BadSecurityModeRejected,							"BadSecurityModeRejected",						"The security mode does not meet the requirements set by the Server");
		insert(BadSecurityPolicyRejected,						"BadSecurityPolicyRejected",					"The security policy does not meet the requirements set by the Server");
		insert(BadTooManySessions,								"BadTooManySessions",							"The server has reached its maximum number of sessions");
		insert(BadUserSignatureInvalid,							"BadUserSignatureInvalid",						"The user token signature is missing or invalid");
		insert(BadApplicationSignatureInvalid,					"BadApplicationSignatureInvalid",				"The signature generated with the client certificate is missing or invalid");
		insert(BadNoValidCertificates,							"BadNoValidCertificates",						"The client did not provide at least one software certificate that is valid and meets the profile requirements for the server");
		insert(BadIdentityChangeNotSupported,					"BadIdentityChangeNotSupported",				"The Server does not support changing the user identity assigned to the session");
		insert(BadRequestCancelledByRequest,					"BadRequestCancelledByRequest",					"The request was cancelled by the client with the Cancel service");
		insert(BadParentNodeIdInvalid,							"BadParentNodeIdInvalid",						"The parent node id does not to refer to a valid node");
		insert(BadReferenceNotAllowed,							"BadReferenceNotAllowed",						"The reference could not be created because it violates constraints imposed by the data model");
		insert(BadNodeIdRejected,								"BadNodeIdRejected",							"The requested node id was reject because it was either invalid or server does not allow node ids to be specified by the client");
		insert(BadNodeIdExists,									"BadNodeIdExists",								"The requested node id is already used by another node");
		insert(BadNodeClassInvalid,								"BadNodeClassInvalid",							"The node class is not valid");
		insert(BadBrowseNameInvalid,							"BadBrowseNameInvalid",							"The browse name is invalid");
		insert(BadBrowseNameDuplicated,							"BadBrowseNameDuplicated",						"The browse name is not unique among nodes that share the same relationship with the parent");
		insert(BadNodeAttributesInvalid,						"BadNodeAttributesInvalid",						"The node attributes are not valid for the node class");
		insert(BadTypeDefinitionInvalid,						"BadTypeDefinitionInvalid",						"The type definition node id does not reference an appropriate type node");
		insert(BadSourceNodeIdInvalid,							"BadSourceNodeIdInvalid",						"The source node id does not reference a valid node");
		insert(BadTargetNodeIdInvalid,							"BadTargetNodeIdInvalid",						"The target node id does not reference a valid node");
		insert(BadDuplicateReferenceNotAllowed,					"BadDuplicateReferenceNotAllowed",				"The reference type between the nodes is already defined");
		insert(BadInvalidSelfReference,							"BadInvalidSelfReference",						"The server does not allow this type of self reference on this node");
		insert(BadReferenceLocalOnly,							"BadReferenceLocalOnly",						"The reference type is not valid for a reference to a remote server");
		insert(BadNoDeleteRights,								"BadNoDeleteRights",							"The server will not allow the node to be deleted");
		insert(UncertainReferenceNotDeleted,					"UncertainReferenceNotDeleted",					"The server was not able to delete all target references");
		insert(BadServerIndexInvalid,							"BadServerIndexInvalid",						"The server index is not valid");
		insert(BadViewIdUnknown,								"BadViewIdUnknown",								"The view id does not refer to a valid view node");
		insert(BadViewTimestampInvalid,							"BadViewTimestampInvalid",						"The view timestamp is not available or not supported");
		insert(BadViewParameterMismatch,						"BadViewParameterMismatch",						"The view parameters are not consistent with each other");
		insert(BadViewVersionInvalid,							"BadViewVersionInvalid",						"The view version is not available or not supported");
		insert(UncertainNotAllNodesAvailable,					"UncertainNotAllNodesAvailable",				"The list of references may not be complete because the underlying system is not available");
		insert(GoodResultsMayBeIncomplete,						"GoodResultsMayBeIncomplete",					"The server should have followed a reference to a node in a remote server but did not. The result set may be incomplete");
		insert(BadNotTypeDefinition,							"BadNotTypeDefinition",							"The provided Nodeid was not a type definition nodeid");
		insert(UncertainReferenceOutOfServer,					"UncertainReferenceOutOfServer",				"One of the references to follow in the relative path references to a node in the address space in another server");
		insert(BadTooManyMatches,								"BadTooManyMatches",							"The requested operation has too many matches to return");
		insert(BadQueryTooComplex,								"BadQueryTooComplex",							"The requested operation requires too many resources in the server");
		insert(BadNoMatch,										"BadNoMatch",									"The requested operation has no match to return");
		insert(BadMaxAgeInvalid,								"BadMaxAgeInvalid",								"The max age parameter is invalid");
		insert(BadHistoryOperationInvalid,						"BadHistoryOperationInvalid",					"The history details parameter is not valid");
		insert(BadHistoryOperationUnsupported,					"BadHistoryOperationUnsupported",				"The server does not support the requested operation");
		insert(BadInvalidTimestampArgument,						"BadInvalidTimestampArgument",					"The defined timestamp to return was invalid");
		insert(BadWriteNotSupported,							"BadWriteNotSupported",							"The server not does support writing the combination of value, status and timestamps provided");
		insert(BadTypeMismatch,									"BadTypeMismatch",								"The value supplied for the attribute is not of the same type as the attribute's value");
		insert(BadMethodInvalid,								"BadMethodInvalid",								"The method id does not refer to a method for the specified object");
		insert(BadArgumentsMissing,								"BadArgumentsMissing",							"The client did not specify all of the input arguments for the method");
		insert(BadTooManySubscriptions,							"BadTooManySubscriptions",						"The server has reached its  maximum number of subscriptions");
		insert(BadTooManyPublishRequests,						"BadTooManyPublishRequests",					"The server has reached the maximum number of queued publish requests");
		insert(BadNoSubscription,								"BadNoSubscription",							"There is no subscription available for this session");
		insert(BadSequenceNumberUnknown,						"BadSequenceNumberUnknown",						"The sequence number is unknown to the server");
		insert(BadMessageNotAvailable,							"BadMessageNotAvailable",						"The requested notification message is no longer available");
		insert(BadInsufficientClientProfile,					"BadInsufficientClientProfile",					"The Client of the current Session does not support one or more Profiles that are necessary for the Subscription");
		insert(BadStateNotActive,								"BadStateNotActive",							"The sub-state machine is not currently active");
		insert(BadTcpServerTooBusy,								"BadTcpServerTooBusy",							"The server cannot process the request because it is too busy");
		insert(BadTcpMessageTypeInvalid,						"BadTcpMessageTypeInvalid",						"The type of the message specified in the header invalid");
		insert(BadTcpSecureChannelUnknown,						"BadTcpSecureChannelUnknown",					"The SecureChannelId and/or TokenId are not currently in use");
		insert(BadTcpMessageTooLarge,							"BadTcpMessageTooLarge",						"The size of the message specified in the header is too large");
		insert(BadTcpNotEnoughResources,						"BadTcpNotEnoughResources",						"There are not enough resources to process the request");
		insert(BadTcpInternalError,								"BadTcpInternalError",							"An internal error occurred");
		insert(BadTcpEndpointUrlInvalid,						"BadTcpEndpointUrlInvalid",						"The Server does not recognize the QueryString specified");
		insert(BadRequestInterrupted,							"BadRequestInterrupted",						"The request could not be sent because of a network interruption");
		insert(BadRequestTimeout,								"BadRequestTimeout",							"Timeout occurred while processing the request");
		insert(BadSecureChannelClosed,							"BadSecureChannelClosed",						"The secure channel has been closed");
		insert(BadSecureChannelTokenUnknown,					"BadSecureChannelTokenUnknown",					"The token has expired or is not recognized");
		insert(BadSequenceNumberInvalid,						"BadSequenceNumberInvalid",						"The sequence number is not valid");
		insert(BadProtocolVersionUnsupported,					"BadProtocolVersionUnsupported",				"The applications do not have compatible protocol versions");
		insert(BadConfigurationError,							"BadConfigurationError",						"There is a problem with the configuration that affects the usefulness of the value");
		insert(BadNotConnected,									"BadNotConnected",								"The variable should receive its value from another variable, but has never been configured to do so");
		insert(BadDeviceFailure,								"BadDeviceFailure",								"There has been a failure in the device/data source that generates the value that has affected the value");
		insert(BadSensorFailure,								"BadSensorFailure",								"There has been a failure in the sensor from which the value is derived by the device/data source");
		insert(BadOutOfService,									"BadOutOfService",								"The source of the data is not operational");
		insert(BadDeadbandFilterInvalid,						"BadDeadbandFilterInvalid",						"The deadband filter is not valid");
		insert(UncertainNoCommunicationLastUsableValue,			"UncertainNoCommunicationLastUsableValue",		"Communication to the data source has failed. The variable value is the last value that had a good quality");
		insert(UncertainLastUsableValue,						"UncertainLastUsableValue",						"Whatever was updating this value has stopped doing so");
		insert(UncertainSubstituteValue,						"UncertainSubstituteValue",						"The value is an operational value that was manually overwritten");
		insert(UncertainInitialValue,							"UncertainInitialValue",						"The value is an initial value for a variable that normally receives its value from another variable");
		insert(UncertainSensorNotAccurate,						"UncertainSensorNotAccurate",					"The value is at one of the sensor limits");
		insert(UncertainEngineeringUnitsExceeded,				"UncertainEngineeringUnitsExceeded",			"The value is outside of the range of values defined for this parameter");
		insert(UncertainSubNormal,								"UncertainSubNormal",							"The value is derived from multiple sources and has less than the required number of Good sources");
		insert(GoodLocalOverride,								"GoodLocalOverride",							"The value has been overridden");
		insert(BadRefreshInProgress,							"BadRefreshInProgress",							"This Condition refresh failed, a Condition refresh operation is already in progress");
		insert(BadConditionAlreadyDisabled,						"BadConditionAlreadyDisabled",					"This condition has already been disabled");
		insert(BadConditionAlreadyEnabled,						"BadConditionAlreadyEnabled",					"This condition has already been enabled");
		insert(BadConditionDisabled,							"BadConditionDisabled",							"Property not available, this condition is disabled");
		insert(BadEventIdUnknown,								"BadEventIdUnknown",							"The specified event id is not recognized");
		insert(BadEventNotAcknowledgeable,						"BadEventNotAcknowledgeable",					"The event cannot be acknowledged");
		insert(BadDialogNotActive,								"BadDialogNotActive",							"The dialog condition is not active");
		insert(BadDialogResponseInvalid,						"BadDialogResponseInvalid",						"The response is not valid for the dialog");
		insert(BadConditionBranchAlreadyAcked,					"BadConditionBranchAlreadyAcked",				"The condition branch has already been acknowledged");
		insert(BadConditionBranchAlreadyConfirmed,				"BadConditionBranchAlreadyConfirmed",			"The condition branch has already been confirmed");
		insert(BadConditionAlreadyShelved,						"BadConditionAlreadyShelved",					"The condition has already been shelved");
		insert(BadConditionNotShelved,							"BadConditionNotShelved",						"The condition is not currently shelved");
		insert(BadShelvingTimeOutOfRange,						"BadShelvingTimeOutOfRange",					"The shelving time not within an acceptable range");
		insert(BadNoData,										"BadNoData",									"No data exists for the requested time range or event filter");
		insert(BadBoundNotFound,								"BadBoundNotFound",								"No data found to provide upper or lower bound value");
		insert(BadBoundNotSupported,							"BadBoundNotSupported",							"The server cannot retrieve a bound for the variable");
		insert(BadDataLost,										"BadDataLost",									"Data is missing due to collection started/stopped/lost");
		insert(BadDataUnavailable,								"BadDataUnavailable",							"Expected data is unavailable for the requested time range due to an un-mounted volume, an off-line archive or tape, or similar reason for temporary unavailability");
		insert(BadEntryExists,									"BadEntryExists",								"The data or event was not successfully inserted because a matching entry exists");
		insert(BadNoEntryExists,								"BadNoEntryExists",								"The data or event was not successfully updated because no matching entry exists");
		insert(BadTimestampNotSupported,						"BadTimestampNotSupported",						"The client requested history using a timestamp format the server does not support (i.e requested ServerTimestamp when server only supports SourceTimestamp)");
		insert(GoodEntryInserted,								"GoodEntryInserted",							"The data or event was successfully inserted into the historical database");
		insert(GoodEntryReplaced,								"GoodEntryReplaced",							"The data or event field was successfully replaced in the historical database");
		insert(UncertainDataSubNormal,							"UncertainDataSubNormal",						"The value is derived from multiple values and has less than the required number of Good values");
		insert(GoodNoData,										"GoodNoData",									"No data exists for the requested time range or event filter");
		insert(GoodMoreData,									"GoodMoreData",									"The data or event field was successfully replaced in the historical database");
		insert(BadAggregateListMismatch,						"BadAggregateListMismatch",						"The requested number of Aggregates does not match the requested number of NodeIds");
		insert(BadAggregateNotSupported,						"BadAggregateNotSupported",						"The requested Aggregate is not support by the server");
		insert(BadAggregateInvalidInputs,						"BadAggregateInvalidInputs",					"The aggregate value could not be derived due to invalid data inputs");
		insert(BadAggregateConfigurationRejected,				"BadAggregateConfigurationRejected",			"The aggregate configuration is not valid for specified node");
		insert(GoodDataIgnored,									"GoodDataIgnored",								"The request pecifies fields which are not valid for the EventType or cannot be saved by the historian");
		insert(GoodCommunicationEvent,							"GoodCommunicationEvent",						"The communication layer has raised an event");
		insert(GoodShutdownEvent,								"GoodShutdownEvent",							"The system is shutting down");
		insert(GoodCallAgain,									"GoodCallAgain",								"The operation is not finished and needs to be called again");
		insert(GoodNonCriticalTimeout,							"GoodNonCriticalTimeout",						"A non-critical timeout occurred");
		insert(BadInvalidArgument,								"BadInvalidArgument",							"One or more arguments are invalid");
		insert(BadConnectionRejected,							"BadConnectionRejected",						"Could not establish a network connection to remote server");
		insert(BadDisconnect,									"BadDisconnect",								"The server has disconnected from the client");
		insert(BadConnectionClosed,								"BadConnectionClosed",							"The network connection has been closed");
		insert(BadInvalidState,									"BadInvalidState",								"The operation cannot be completed because the object is closed, uninitialized or in some other invalid state");
		insert(BadEndOfStream,									"BadEndOfStream",								"Cannot move beyond end of the stream");
		insert(BadNoDataAvailable,								"BadNoDataAvailable",							"No data is currently available for reading from a non-blocking stream");
		insert(BadWaitingForResponse,							"BadWaitingForResponse",						"The asynchronous operation is waiting for a response");
		insert(BadOperationAbandoned,							"BadOperationAbandoned",						"The asynchronous operation was abandoned by the caller");
		insert(BadExpectedStreamToBlock,						"BadExpectedStreamToBlock",						"The stream did not return all data requested (possibly because it is a non-blocking stream)");
		insert(BadWouldBlock,									"BadWouldBlock",								"Non blocking behaviour is required and the operation would block");
		insert(BadSyntaxError,									"BadSyntaxError",								"A value had an invalid syntax");
		insert(BadMaxConnectionsReached,						"BadMaxConnectionsReached",						"The operation could not be finished because all available connections are in use");

		insert(BadSignatureInvalid,								"BadSignatureInvalid",							"signature is missing or invalid");
	}
};
