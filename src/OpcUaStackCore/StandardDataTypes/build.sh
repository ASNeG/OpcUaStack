!/bin/bash

NODESETS="--nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --nodeset Opc.Ua.NodeSet2.Services.xml"

OpcUaEnumTypeGenerator4 ${NODESETS} --enumtype DataChangeTrigger

OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype ServerStatusDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype AddNodesItem --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype AddReferencesItem --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype AggregateConfiguration --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype Annotation --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype ApplicationDescription --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype Argument --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype AxisInformation --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype BuildInfo --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype ComplexNumberType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype ConfigurationVersionDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype ConnectionTransportDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype BrokerConnectionTransportDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype DatagramConnectionTransportDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype ContentFilter --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype ContentFilterElement --buildSubTypes 0

OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype SimpleTypeDescription --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype EnumDescription --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype DataTypeDescription --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype StructureDescription --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype DataSetReaderDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype UserTokenPolicy --buildSubTypes 0

OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype DataSetReaderMessageDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype JsonDataSetReaderMessageDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype UadpDataSetReaderMessageDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype DataSetReaderTransportDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype BrokerDataSetReaderTransportDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype DataSetWriterDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype DataSetWriterMessageDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype JsonDataSetWriterMessageDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype UadpDataSetWriterMessageDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype DataSetWriterTransportDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype BrokerDataSetWriterTransportDataType --buildSubTypes 0

OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype DataTypeDefinition --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype EnumDefinition --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype StructureDefinition --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype EnumDescription --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype SimpleTypeDescription --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype StructureDescription --buildSubTypes 0

OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype DataTypeSchemaHeader --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype DataSetMetaDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype UABinaryFileDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype DeleteNodesItem --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype DeleteReferencesItem --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype DiscoveryConfiguration --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype MdnsDiscoveryConfiguration --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype DoubleComplexNumberType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype EUInformation --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype EndpointConfiguration --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype EndpointDescription --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype EndpointType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype EndpointUrlListDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype EnumValueType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype EnumField --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype FieldMetaData --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype FieldTargetDataType --buildSubTypes 0

OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype FilterOperand --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype AttributeOperand --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype RelativePathElement --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype RelativePath --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype ElementOperand --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype LiteralOperand --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype SimpleAttributeOperand --buildSubTypes 0

OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype HistoryEventFieldList --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype IdentityMappingRuleType --buildSubTypes 0

OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype KeyValuePair --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype ModelChangeStructureDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype ModelConfigDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype MonitoringFilter --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype EventFilter --buildSubTypes 0

OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype NetworkAddressDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype NetworkAddressUrlDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype NetworkGroupDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype OptionSet --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype ProgramDiagnosticDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype ProgramDiagnostic2DataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype PubSubConfigurationDataType --buildSubTypes 0

OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype PublishedDataSetDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype PubSubConnectionDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype WriterGroupDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype ReaderGroupDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype PubSubGroupDataType --buildSubTypes 0

OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype PublishedDataSetSourceDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype PublishedDataItemsDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype PublishedVariableDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype PublishedEventsDataType --buildSubTypes 0

OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype ReaderGroupMessageDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype ReaderGroupTransportDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype RedundantServerDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype RegisteredServer --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype RolePermissionType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype SamplingIntervalDiagnosticsDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype SemanticChangeStructureDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype ServerDiagnosticsSummaryDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype ServerOnNetwork --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype ServiceCounterDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype SessionDiagnosticsDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype SessionSecurityDiagnosticsDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype SignedSoftwareCertificate --buildSubTypes 0


OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype StatusResult --buildSubTypes 0



OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype StructureField --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype SubscribedDataSetDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype SubscribedDataSetMirrorDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype TargetVariablesDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype SubscriptionDiagnosticsDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype TimeZoneDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype TrustListDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype Union --buildSubTypes 0

OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype UserIdentityToken --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype AnonymousIdentityToken --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype IssuedIdentityToken --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype UserNameIdentityToken --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype X509IdentityToken --buildSubTypes 0

OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype WriterGroupMessageDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype JsonWriterGroupMessageDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype UadpWriterGroupMessageDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype WriterGroupTransportDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype BrokerWriterGroupTransportDataType --buildSubTypes 0
OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype DatagramWriterGroupTransportDataType --buildSubTypes 0

OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --nodeset Opc.Ua.NodeSet2.Part14.xml --datatype XVType --buildSubTypes 0


OpcUaDataTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --datatype Range --buildSubTypes 0


OpcUaDataTypeGenerator4 ${NODESETS} --datatype EventFilterResult --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype MonitoringFilterResult --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype ContentFilterResult --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype ContentFilterElementResult --buildSubTypes 0

OpcUaDataTypeGenerator4 ${NODESETS} --datatype NotificationMessage --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype DataChangeNotification --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype StatusChangeNotification --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype NotificationData --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype MonitoredItemNotification --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype EventNotificationList --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype EventFieldList --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype EventField --buildSubTypes 0

OpcUaDataTypeGenerator4 ${NODESETS} --datatype ReadEventDetails --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype HistoryReadDetails --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype ReadRawModifiedDetails --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype ReadProcessedDetails --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype ReadAtTimeDetails --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype HistoryData --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype HistoryModifiedData --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype ModificationInfo --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype HistoryEvent --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype UpdateDataDetails --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype HistoryUpdateDetails --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype UpdateStructureDataDetails --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype UpdateEventDetails --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype DeleteRawModifiedDetails --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype DeleteAtTimeDetails --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype DeleteEventDetails --buildSubTypes 0

OpcUaDataTypeGenerator4 ${NODESETS} --datatype ObjectAttributes --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype NodeAttributes --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype VariableAttributes --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype VariableTypeAttributes --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype MethodAttributes --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype ObjectTypeAttributes --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype DataTypeAttributes --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype ReferenceTypeAttributes --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype ViewAttributes --buildSubTypes 0

OpcUaDataTypeGenerator4 ${NODESETS} --datatype AggregateFilter --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype DataChangeFilter --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype AggregateFilterResult --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype MonitoredItemModifyResult --buildSubTypes 0
OpcUaDataTypeGenerator4 ${NODESETS} --datatype MonitoredItemCreateResult --buildSubTypes 0


















OpcUaEnumTypeGenerator4 --nodeset Opc.Ua.NodeSet2.xml --enumtype Enumeration --buildSubTypes 1

