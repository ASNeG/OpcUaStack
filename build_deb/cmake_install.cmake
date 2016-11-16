# Install script for directory: /home/huebl/devel_/OpcUaStack/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libraries")
  foreach(file
      "$ENV{DESTDIR}/usr/local/lib/libOpcUaStackCore.so.2.0.1"
      "$ENV{DESTDIR}/usr/local/lib/libOpcUaStackCore.so.2"
      "$ENV{DESTDIR}/usr/local/lib/libOpcUaStackCore.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/libOpcUaStackCore.so.2.0.1;/usr/local/lib/libOpcUaStackCore.so.2;/usr/local/lib/libOpcUaStackCore.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/lib" TYPE SHARED_LIBRARY FILES
    "/home/huebl/devel_/OpcUaStack/build_deb/libOpcUaStackCore.so.2.0.1"
    "/home/huebl/devel_/OpcUaStack/build_deb/libOpcUaStackCore.so.2"
    "/home/huebl/devel_/OpcUaStack/build_deb/libOpcUaStackCore.so"
    )
  foreach(file
      "$ENV{DESTDIR}/usr/local/lib/libOpcUaStackCore.so.2.0.1"
      "$ENV{DESTDIR}/usr/local/lib/libOpcUaStackCore.so.2"
      "$ENV{DESTDIR}/usr/local/lib/libOpcUaStackCore.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/OpcUaStack2/OpcUaStackCore/Base/Log.h;/usr/include/OpcUaStack2/OpcUaStackCore/Base/Utility.h;/usr/include/OpcUaStack2/OpcUaStackCore/Base/ConfigXmlManager.h;/usr/include/OpcUaStack2/OpcUaStackCore/Base/Condition.h;/usr/include/OpcUaStack2/OpcUaStackCore/Base/os.h;/usr/include/OpcUaStack2/OpcUaStackCore/Base/Object.h;/usr/include/OpcUaStack2/OpcUaStackCore/Base/ConditionProcess.h;/usr/include/OpcUaStack2/OpcUaStackCore/Base/Pool.h;/usr/include/OpcUaStack2/OpcUaStackCore/Base/Url.h;/usr/include/OpcUaStack2/OpcUaStackCore/Base/IOService.h;/usr/include/OpcUaStack2/OpcUaStackCore/Base/Base64.h;/usr/include/OpcUaStack2/OpcUaStackCore/Base/Config.h;/usr/include/OpcUaStack2/OpcUaStackCore/Base/Bitmask.h;/usr/include/OpcUaStack2/OpcUaStackCore/Base/Callback.h;/usr/include/OpcUaStack2/OpcUaStackCore/Base/ConfigIf.h;/usr/include/OpcUaStack2/OpcUaStackCore/Base/PoolBase.h;/usr/include/OpcUaStack2/OpcUaStackCore/Base/ConditionBool.h;/usr/include/OpcUaStack2/OpcUaStackCore/Base/ConfigXml.h;/usr/include/OpcUaStack2/OpcUaStackCore/Base/ObjectPool.h;/usr/include/OpcUaStack2/OpcUaStackCore/Base/Xmlns.h;/usr/include/OpcUaStack2/OpcUaStackCore/Base/BaseClass.h;/usr/include/OpcUaStack2/OpcUaStackCore/Base/Callback.txx")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/OpcUaStack2/OpcUaStackCore/Base" TYPE FILE FILES
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Base/Log.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Base/Utility.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Base/ConfigXmlManager.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Base/Condition.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Base/os.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Base/Object.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Base/ConditionProcess.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Base/Pool.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Base/Url.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Base/IOService.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Base/Base64.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Base/Config.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Base/Bitmask.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Base/Callback.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Base/ConfigIf.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Base/PoolBase.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Base/ConditionBool.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Base/ConfigXml.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Base/ObjectPool.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Base/Xmlns.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Base/BaseClass.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Base/Callback.txx"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/OpcUaNumberTypes.h;/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/OpcUaNodeIdBase.h;/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/OpcUaDataValue.h;/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/OpcUaLocalizedText.h;/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/BuildInTypes.h;/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h;/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/OpcUaNodeId.h;/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/OpcUaDateTime.h;/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/OpcUaAttributeId.h;/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/Json.h;/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/OpcUaDiagnosticInfo.h;/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h;/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/OpcUaNumber.h;/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/OpcUaGuid.h;/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/OpcUaString.h;/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/OpcUaQualifiedName.h;/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/OpcUaType.h;/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/OpcUaVariant.h;/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/OpcUaByteString.h;/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/OpcUaArray.h;/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h;/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/OpcUaExtensionObjectBase.h;/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/ByteOrder.h;/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/OpcUaExpandedNodeId.h;/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes/OpcUaXmlElement.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/OpcUaStack2/OpcUaStackCore/BuildInTypes" TYPE FILE FILES
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/OpcUaNumberTypes.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/OpcUaNodeIdBase.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/OpcUaDataValue.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/OpcUaLocalizedText.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/BuildInTypes.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/OpcUaDateTime.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/OpcUaAttributeId.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/Json.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/OpcUaDiagnosticInfo.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/OpcUaGuid.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/OpcUaString.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/OpcUaQualifiedName.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/OpcUaType.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/OpcUaVariant.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/OpcUaByteString.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/OpcUaArray.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/OpcUaExtensionObjectBase.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/ByteOrder.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/OpcUaExpandedNodeId.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/BuildInTypes/OpcUaXmlElement.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/OpcUaStack2/OpcUaStackCore/Component/Message.h;/usr/include/OpcUaStack2/OpcUaStackCore/Component/Component.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/OpcUaStack2/OpcUaStackCore/Component" TYPE FILE FILES
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Component/Message.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Component/Component.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/OpcUaStack2/OpcUaStackCore/Core/Core.h;/usr/include/OpcUaStack2/OpcUaStackCore/Core/FileLogger.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/OpcUaStack2/OpcUaStackCore/Core" TYPE FILE FILES
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Core/Core.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Core/FileLogger.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/HelloMessage.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/SecureChannelOld.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/ResponseHeader.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/Header.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/AcknowledgeMessage.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/SecureChannelClient.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/SecureChannelConfig.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/RequestHeader.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/SecureChannelServerConfig.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/MessageHeader.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/OpenSecureChannelRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/SecureChannelTransaction.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/OpenSecureChannelResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/MessageDefaults.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/CloseSecureChannelResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/SecurityToken.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/SecureChannelClientIf.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/SecureChannelTypes.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/SecureChannel.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/SessionAuthenticationToken.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/SequenceHeader.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/SecureChannelServerIf.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/ErrorMessage.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/SecureChannelBase.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/CloseSecureChannelRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/SecurityHeader.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/ApplicationInstanceCertificate.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/SecureChannelClientConfig.h;/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel/SecureChannelServer.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/OpcUaStack2/OpcUaStackCore/SecureChannel" TYPE FILE FILES
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/HelloMessage.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/SecureChannelOld.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/ResponseHeader.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/Header.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/AcknowledgeMessage.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/SecureChannelClient.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/SecureChannelConfig.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/RequestHeader.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/SecureChannelServerConfig.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/MessageHeader.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/OpenSecureChannelRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/SecureChannelTransaction.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/OpenSecureChannelResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/MessageDefaults.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/CloseSecureChannelResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/SecurityToken.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/SecureChannelClientIf.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/SecureChannelTypes.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/SecureChannel.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/SessionAuthenticationToken.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/SequenceHeader.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/SecureChannelServerIf.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/ErrorMessage.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/SecureChannelBase.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/CloseSecureChannelRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/SecurityHeader.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/ApplicationInstanceCertificate.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/SecureChannelClientConfig.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/SecureChannel/SecureChannelServer.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/BrowseNextRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/UnregisterNodesResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/QueryDataSet.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/CreateSessionRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/SignatureData.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/BrowsePathTarget.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ReadRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/StatusChangeNotification.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/QueryServiceTransaction.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ObjectTypeAttributes.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/AnonymousIdentityToken.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ModificationInfo.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/SignedSoftwareCertificate.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/MethodAttributes.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/CallResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ReadRawModifiedDetails.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/EndpointDescription.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/RelativePath.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/RegisteredServer.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/HistoryReadRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/DeleteEventDetails.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/RegisterNodesResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ElementOperand.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ModifyMonitoredItemsResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/GetEndpointsRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/DataChangeNotification.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/QueryFirstResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ExtensibleParameter.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/HistoryReadResult.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/RegisterNodesRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/RepublishResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/AddReferencesRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/MonitoringParameters.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/WriteResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/TranslateBrowsePathsToNodeIdsRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/UserTokenPolicy.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/DeleteReferencesItem.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/DeleteReferencesResult.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/MonitoredItemModifyRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/CreateMonitoredItemsResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/VariableTypeAttributes.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ReferenceTypeAttributes.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ObjectAttributes.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/PublishRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ModifyMonitoredItemsRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/AddNodesResult.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/MethodServiceTransaction.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/SetMonitoringModeResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/MonitoredItemNotification.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/UpdateDataDetails.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/DeleteSubscriptionsRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/HistoryEvent.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/DeleteSubscriptionsResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/MonitoredItemCreateRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/DeleteRawModifiedDetails.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/HistoryUpdateResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/SetTriggeringResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ViewDescription.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/MonitoringMode.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ReadResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/MonitoredItemServiceTransaction.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/DataChangeFilter.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ReadProcessedDetails.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/RegisterServerResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ModifySubscriptionResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/EventNotificationList.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ActivateSessionResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/AggregateConfiguration.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/BrowsePathResult.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/DeleteNodesResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/QueryFirstRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/SessionServiceTransaction.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/QueryNextRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/DeleteNodesItem.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/AttributeOperand.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/DeleteReferencesResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ContentFilterElementResult.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/AddNodesRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ContentFilter.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/TranslateBrowsePathsToNodeIdsResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/FindServersResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/EventFieldList.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/BrowseResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/SimpleAttributeOperand.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ViewAttributes.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/DeleteMonitoredItemsRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ServiceTransaction.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/SetPublishingModeRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/AddReferencesResult.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/NotificationData.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ApplicationDescription.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/EventFilterResult.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/CreateMonitoredItemsRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ReadAtTimeDetails.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/AttributesDescription.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/AttributeServiceTransaction.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/SetMonitoringModeRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ContentFilterResult.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/VariableAttributes.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/AddReferencesItem.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ViewServiceTransaction.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/NodeManagementServiceTransaction.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/BrowsePath.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/HistoryReadDetails.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ReadValueId.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ContentFilterElement.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/EventFilter.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/UserIdentityToken.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/WriteValue.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/AddNodesItem.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/BrowseResult.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ServiceBase.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/DataTypeAttributes.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/DiscoveryServiceTransaction.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ParsingResult.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/AggregateFilterResult.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/UpdateEventDetails.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/DeleteMonitoredItemsResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/HistoryReadResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/CloseSessionResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/TransferResult.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/MonitoredItemCreateResult.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/BrowseDescription.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ModifySubscriptionRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/WriteRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/SubscriptionAcknowledgement.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/FindServersRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/DeleteReferencesRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/UnregisterNodesRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/PublishResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/RepublishRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ActivateSessionRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/LiteralOperand.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/HistoryModifiedData.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/DeleteAtTimeDetails.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/CallMethodResult.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/QueryNextResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/DeleteNodesRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/CreateSubscriptionRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/GetEndpointsResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/TransferSubscriptionsRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/RegisterServerRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ReferenceDescription.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/HistoryEventFieldList.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/AddNodesResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/QueryDataDescription.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/EventField.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/DeleteNodesResult.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/HistoryUpdateRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/NodeTypeDescription.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/SetPublishingModeResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/NotificationMessage.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/UpdateStructureDataDetails.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/MonitoredItemModifyResult.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/UserNameIdentityToken.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ReadEventDetails.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/CreateSubscriptionResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/HistoryUpdateResult.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/CallRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/PerformUpdateEnumeration.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/HistoryReadValueId.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/TransferSubscriptionsResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/BrowseNextResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/NodeClass.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/BrowseRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ServiceTransactionIf.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/RelativePathElement.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/CancelResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/AggregateFilter.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/TimestampsToReturn.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/SubscriptionServiceTransaction.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/CreateSessionResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/HistoryData.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/SetTriggeringRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/AddReferencesResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/CloseSessionRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/CallMethodRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/CancelRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.txx")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSet" TYPE FILE FILES
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/BrowseNextRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/UnregisterNodesResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/QueryDataSet.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/CreateSessionRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/SignatureData.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/BrowsePathTarget.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ReadRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/StatusChangeNotification.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/QueryServiceTransaction.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ObjectTypeAttributes.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/AnonymousIdentityToken.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ModificationInfo.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/SignedSoftwareCertificate.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/MethodAttributes.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/CallResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ReadRawModifiedDetails.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/EndpointDescription.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/RelativePath.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/RegisteredServer.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/HistoryReadRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/DeleteEventDetails.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/RegisterNodesResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ElementOperand.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ModifyMonitoredItemsResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/GetEndpointsRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/DataChangeNotification.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/QueryFirstResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ExtensibleParameter.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/HistoryReadResult.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/RegisterNodesRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/RepublishResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/AddReferencesRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/MonitoringParameters.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/WriteResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/TranslateBrowsePathsToNodeIdsRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/UserTokenPolicy.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/DeleteReferencesItem.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/DeleteReferencesResult.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/MonitoredItemModifyRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/CreateMonitoredItemsResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/VariableTypeAttributes.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ReferenceTypeAttributes.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ObjectAttributes.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/PublishRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ModifyMonitoredItemsRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/AddNodesResult.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/MethodServiceTransaction.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/SetMonitoringModeResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/MonitoredItemNotification.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/UpdateDataDetails.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/DeleteSubscriptionsRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/HistoryEvent.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/DeleteSubscriptionsResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/MonitoredItemCreateRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/DeleteRawModifiedDetails.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/HistoryUpdateResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/SetTriggeringResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ViewDescription.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/MonitoringMode.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ReadResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/MonitoredItemServiceTransaction.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/DataChangeFilter.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ReadProcessedDetails.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/RegisterServerResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ModifySubscriptionResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/EventNotificationList.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ActivateSessionResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/AggregateConfiguration.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/BrowsePathResult.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/DeleteNodesResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/QueryFirstRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/SessionServiceTransaction.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/QueryNextRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/DeleteNodesItem.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/AttributeOperand.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/DeleteReferencesResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ContentFilterElementResult.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/AddNodesRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ContentFilter.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/TranslateBrowsePathsToNodeIdsResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/FindServersResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/EventFieldList.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/BrowseResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/SimpleAttributeOperand.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ViewAttributes.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/DeleteMonitoredItemsRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ServiceTransaction.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/SetPublishingModeRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/AddReferencesResult.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/NotificationData.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ApplicationDescription.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/EventFilterResult.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/CreateMonitoredItemsRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ReadAtTimeDetails.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/AttributesDescription.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/AttributeServiceTransaction.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/SetMonitoringModeRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ContentFilterResult.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/VariableAttributes.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/AddReferencesItem.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ViewServiceTransaction.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/NodeManagementServiceTransaction.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/BrowsePath.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/HistoryReadDetails.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ReadValueId.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ContentFilterElement.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/EventFilter.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/UserIdentityToken.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/WriteValue.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/AddNodesItem.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/BrowseResult.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ServiceBase.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/DataTypeAttributes.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/DiscoveryServiceTransaction.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ParsingResult.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/AggregateFilterResult.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/UpdateEventDetails.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/DeleteMonitoredItemsResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/HistoryReadResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/CloseSessionResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/TransferResult.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/MonitoredItemCreateResult.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/BrowseDescription.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ModifySubscriptionRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/WriteRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/SubscriptionAcknowledgement.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/FindServersRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/DeleteReferencesRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/UnregisterNodesRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/PublishResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/RepublishRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ActivateSessionRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/LiteralOperand.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/HistoryModifiedData.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/DeleteAtTimeDetails.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/CallMethodResult.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/QueryNextResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/DeleteNodesRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/CreateSubscriptionRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/GetEndpointsResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/TransferSubscriptionsRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/RegisterServerRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ReferenceDescription.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/HistoryEventFieldList.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/AddNodesResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/QueryDataDescription.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/EventField.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/DeleteNodesResult.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/HistoryUpdateRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/NodeTypeDescription.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/SetPublishingModeResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/NotificationMessage.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/UpdateStructureDataDetails.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/MonitoredItemModifyResult.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/UserNameIdentityToken.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ReadEventDetails.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/CreateSubscriptionResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/HistoryUpdateResult.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/CallRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/PerformUpdateEnumeration.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/HistoryReadValueId.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/TransferSubscriptionsResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/BrowseNextResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/NodeClass.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/BrowseRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/RelativePathElement.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/CancelResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/AggregateFilter.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/TimestampsToReturn.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/SubscriptionServiceTransaction.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/CreateSessionResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/HistoryData.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/SetTriggeringRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/AddReferencesResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/CloseSessionRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/CallMethodRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/CancelRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.txx"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSetApplication/RegisterForwardRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSetApplication/NodeReference.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSetApplication/GetNodeReferenceRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSetApplication/NamespaceInfoRequest.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSetApplication/ApplicationServiceTransaction.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSetApplication/GetNodeReferenceResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSetApplication/NamespaceInfoResponse.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSetApplication/ForwardInfoSync.h;/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSetApplication/RegisterForwardResponse.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/OpcUaStack2/OpcUaStackCore/ServiceSetApplication" TYPE FILE FILES
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSetApplication/RegisterForwardRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSetApplication/NodeReference.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSetApplication/GetNodeReferenceRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSetApplication/NamespaceInfoRequest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSetApplication/ApplicationServiceTransaction.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSetApplication/GetNodeReferenceResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSetApplication/NamespaceInfoResponse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSetApplication/ForwardInfoSync.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/ServiceSetApplication/RegisterForwardResponse.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/OpcUaStack2/OpcUaStackCore/TCPChannel/TCPConnection.h;/usr/include/OpcUaStack2/OpcUaStackCore/TCPChannel/TCPAcceptor.h;/usr/include/OpcUaStack2/OpcUaStackCore/TCPChannel/Coder.h;/usr/include/OpcUaStack2/OpcUaStackCore/TCPChannel/TCPConnector.h;/usr/include/OpcUaStack2/OpcUaStackCore/TCPChannel/TCPTestHandler.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/OpcUaStack2/OpcUaStackCore/TCPChannel" TYPE FILE FILES
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/TCPChannel/TCPConnection.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/TCPChannel/TCPAcceptor.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/TCPChannel/Coder.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/TCPChannel/TCPConnector.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/TCPChannel/TCPTestHandler.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/OpcUaStack2/OpcUaStackCore/Utility/PendingQueue.h;/usr/include/OpcUaStack2/OpcUaStackCore/Utility/Timer.h;/usr/include/OpcUaStack2/OpcUaStackCore/Utility/Library.h;/usr/include/OpcUaStack2/OpcUaStackCore/Utility/CSV.h;/usr/include/OpcUaStack2/OpcUaStackCore/Utility/Environment.h;/usr/include/OpcUaStack2/OpcUaStackCore/Utility/SlotTimer.h;/usr/include/OpcUaStack2/OpcUaStackCore/Utility/IOThread.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/OpcUaStack2/OpcUaStackCore/Utility" TYPE FILE FILES
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Utility/PendingQueue.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Utility/Timer.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Utility/Library.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Utility/CSV.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Utility/Environment.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Utility/SlotTimer.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Utility/IOThread.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/OpcUaStack2/OpcUaStackCore/Application/ApplicationFindServerContext.h;/usr/include/OpcUaStack2/OpcUaStackCore/Application/ApplicationMethodContext.h;/usr/include/OpcUaStack2/OpcUaStackCore/Application/ApplicationRegisterServerContext.h;/usr/include/OpcUaStack2/OpcUaStackCore/Application/ApplicationWriteContext.h;/usr/include/OpcUaStack2/OpcUaStackCore/Application/ApplicationHReadContext.h;/usr/include/OpcUaStack2/OpcUaStackCore/Application/ApplicationReadContext.h;/usr/include/OpcUaStack2/OpcUaStackCore/Application/ApplicationHWriteContext.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/OpcUaStack2/OpcUaStackCore/Application" TYPE FILE FILES
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Application/ApplicationFindServerContext.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Application/ApplicationMethodContext.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Application/ApplicationRegisterServerContext.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Application/ApplicationWriteContext.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Application/ApplicationHReadContext.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Application/ApplicationReadContext.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Application/ApplicationHWriteContext.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/OpcUaStack2/OpcUaStackCore/Container/DoublyLinkedList.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/OpcUaStack2/OpcUaStackCore/Container" TYPE FILE FILES "/home/huebl/devel_/OpcUaStack/src/OpcUaStackCore/Container/DoublyLinkedList.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libraries")
  foreach(file
      "$ENV{DESTDIR}/usr/local/lib/OpcUaStack/libOpcUaStackClient.so.2.0.1"
      "$ENV{DESTDIR}/usr/local/lib/OpcUaStack/libOpcUaStackClient.so.2"
      "$ENV{DESTDIR}/usr/local/lib/OpcUaStack/libOpcUaStackClient.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/OpcUaStack/libOpcUaStackClient.so.2.0.1;/usr/local/lib/OpcUaStack/libOpcUaStackClient.so.2;/usr/local/lib/OpcUaStack/libOpcUaStackClient.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/lib/OpcUaStack" TYPE SHARED_LIBRARY FILES
    "/home/huebl/devel_/OpcUaStack/build_deb/libOpcUaStackClient.so.2.0.1"
    "/home/huebl/devel_/OpcUaStack/build_deb/libOpcUaStackClient.so.2"
    "/home/huebl/devel_/OpcUaStack/build_deb/libOpcUaStackClient.so"
    )
  foreach(file
      "$ENV{DESTDIR}/usr/local/lib/OpcUaStack/libOpcUaStackClient.so.2.0.1"
      "$ENV{DESTDIR}/usr/local/lib/OpcUaStack/libOpcUaStackClient.so.2"
      "$ENV{DESTDIR}/usr/local/lib/OpcUaStack/libOpcUaStackClient.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_REMOVE
           FILE "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/OpcUaStack2/OpcUaStackClient/Client/Client.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/OpcUaStack2/OpcUaStackClient/Client" TYPE FILE FILES "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/Client/Client.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/SessionConfig.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/AttributeServiceConfig.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/AttributeService.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/MethodServiceIf.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/SessionManagerIf.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/QueryService.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/ViewServiceBrowse.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/MonitoredItemService.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/MethodServiceConfig.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/SubscriptionServiceConfig.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/MethodService.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/ServiceConfigBase.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/DiscoveryServiceConfig.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/ViewService.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/SessionServiceIf.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/SessionTestHandler.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/MonitoredItemServiceIf.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/NodeManagementServiceConfig.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/SessionServiceConfig.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/ServiceSetManager.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/NodeManagementServiceIf.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/SessionBase.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/SubscriptionServiceBase.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/NodeManagementService.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/AttributeServiceIf.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/QueryServiceConfig.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/SubscriptionService.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/SubscriptionServiceIf.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/QueryServiceIf.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/MonitoredItemServiceConfig.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/DiscoveryServiceIf.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/AttributeServiceNode.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/ViewServiceConfig.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/SessionService.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/ViewServiceIf.h;/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet/DiscoveryService.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/OpcUaStack2/OpcUaStackClient/ServiceSet" TYPE FILE FILES
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/SessionConfig.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/AttributeServiceConfig.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/AttributeService.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/MethodServiceIf.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/SessionManagerIf.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/QueryService.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/ViewServiceBrowse.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/MonitoredItemService.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/MethodServiceConfig.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/SubscriptionServiceConfig.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/MethodService.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/ServiceConfigBase.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/DiscoveryServiceConfig.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/ViewService.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/SessionServiceIf.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/SessionTestHandler.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/MonitoredItemServiceIf.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/NodeManagementServiceConfig.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/SessionServiceConfig.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/ServiceSetManager.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/NodeManagementServiceIf.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/SessionBase.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/SubscriptionServiceBase.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/NodeManagementService.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/AttributeServiceIf.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/QueryServiceConfig.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/SubscriptionService.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/SubscriptionServiceIf.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/QueryServiceIf.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/MonitoredItemServiceConfig.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/DiscoveryServiceIf.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/AttributeServiceNode.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/ViewServiceConfig.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/SessionService.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/ViewServiceIf.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ServiceSet/DiscoveryService.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/OpcUaStack2/OpcUaStackClient/ValueBasedInterface/VBIClientHandlerTest.h;/usr/include/OpcUaStack2/OpcUaStackClient/ValueBasedInterface/VBIContext.h;/usr/include/OpcUaStack2/OpcUaStackClient/ValueBasedInterface/VBIClient.h;/usr/include/OpcUaStack2/OpcUaStackClient/ValueBasedInterface/VBITransaction.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/OpcUaStack2/OpcUaStackClient/ValueBasedInterface" TYPE FILE FILES
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ValueBasedInterface/VBIClientHandlerTest.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ValueBasedInterface/VBIContext.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ValueBasedInterface/VBIClient.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackClient/ValueBasedInterface/VBITransaction.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libraries")
  foreach(file
      "$ENV{DESTDIR}/usr/local/lib/libOpcUaStackServer.so.2.0.1"
      "$ENV{DESTDIR}/usr/local/lib/libOpcUaStackServer.so.2"
      "$ENV{DESTDIR}/usr/local/lib/libOpcUaStackServer.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/libOpcUaStackServer.so.2.0.1;/usr/local/lib/libOpcUaStackServer.so.2;/usr/local/lib/libOpcUaStackServer.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/lib" TYPE SHARED_LIBRARY FILES
    "/home/huebl/devel_/OpcUaStack/build_deb/libOpcUaStackServer.so.2.0.1"
    "/home/huebl/devel_/OpcUaStack/build_deb/libOpcUaStackServer.so.2"
    "/home/huebl/devel_/OpcUaStack/build_deb/libOpcUaStackServer.so"
    )
  foreach(file
      "$ENV{DESTDIR}/usr/local/lib/libOpcUaStackServer.so.2.0.1"
      "$ENV{DESTDIR}/usr/local/lib/libOpcUaStackServer.so.2"
      "$ENV{DESTDIR}/usr/local/lib/libOpcUaStackServer.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_REMOVE
           FILE "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/OpcUaStack2/OpcUaStackServer/Server/Server.h;/usr/include/OpcUaStack2/OpcUaStackServer/Server/ServerStatusDataType.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/OpcUaStack2/OpcUaStackServer/Server" TYPE FILE FILES
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/Server/Server.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/Server/ServerStatusDataType.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/OpcUaStack2/OpcUaStackServer/AddressSpaceModel/MethodNodeClass.h;/usr/include/OpcUaStack2/OpcUaStackServer/AddressSpaceModel/DataTypeNodeClass.h;/usr/include/OpcUaStack2/OpcUaStackServer/AddressSpaceModel/ObjectNodeClass.h;/usr/include/OpcUaStack2/OpcUaStackServer/AddressSpaceModel/VariableNodeClass.h;/usr/include/OpcUaStack2/OpcUaStackServer/AddressSpaceModel/ReferenceItem.h;/usr/include/OpcUaStack2/OpcUaStackServer/AddressSpaceModel/ReferenceType.h;/usr/include/OpcUaStack2/OpcUaStackServer/AddressSpaceModel/ViewNodeClass.h;/usr/include/OpcUaStack2/OpcUaStackServer/AddressSpaceModel/AttributeBase.h;/usr/include/OpcUaStack2/OpcUaStackServer/AddressSpaceModel/DummyNodeClass.h;/usr/include/OpcUaStack2/OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h;/usr/include/OpcUaStack2/OpcUaStackServer/AddressSpaceModel/ObjectTypeNodeClass.h;/usr/include/OpcUaStack2/OpcUaStackServer/AddressSpaceModel/VariableTypeNodeClass.h;/usr/include/OpcUaStack2/OpcUaStackServer/AddressSpaceModel/AttributeAccess.h;/usr/include/OpcUaStack2/OpcUaStackServer/AddressSpaceModel/ReferenceTypeNodeClass.h;/usr/include/OpcUaStack2/OpcUaStackServer/AddressSpaceModel/ReferenceItemMap.h;/usr/include/OpcUaStack2/OpcUaStackServer/AddressSpaceModel/Attribute.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/OpcUaStack2/OpcUaStackServer/AddressSpaceModel" TYPE FILE FILES
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/AddressSpaceModel/MethodNodeClass.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/AddressSpaceModel/DataTypeNodeClass.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/AddressSpaceModel/ObjectNodeClass.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/AddressSpaceModel/VariableNodeClass.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/AddressSpaceModel/ReferenceItem.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/AddressSpaceModel/ReferenceType.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/AddressSpaceModel/ViewNodeClass.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/AddressSpaceModel/AttributeBase.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/AddressSpaceModel/DummyNodeClass.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/AddressSpaceModel/ObjectTypeNodeClass.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/AddressSpaceModel/VariableTypeNodeClass.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/AddressSpaceModel/AttributeAccess.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/AddressSpaceModel/ReferenceTypeNodeClass.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/AddressSpaceModel/ReferenceItemMap.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/AddressSpaceModel/Attribute.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/OpcUaStack2/OpcUaStackServer/Application/ApplicationServiceIf.h;/usr/include/OpcUaStack2/OpcUaStackServer/Application/ApplicationManager.h;/usr/include/OpcUaStack2/OpcUaStackServer/Application/Application.h;/usr/include/OpcUaStack2/OpcUaStackServer/Application/ApplicationIf.h;/usr/include/OpcUaStack2/OpcUaStackServer/Application/ApplicationInfo.h;/usr/include/OpcUaStack2/OpcUaStackServer/Application/ApplicationBase.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/OpcUaStack2/OpcUaStackServer/Application" TYPE FILE FILES
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/Application/ApplicationServiceIf.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/Application/ApplicationManager.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/Application/Application.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/Application/ApplicationIf.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/Application/ApplicationInfo.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/Application/ApplicationBase.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/OpcUaStack2/OpcUaStackServer/InformationModel/InformationModelNodeSet.h;/usr/include/OpcUaStack2/OpcUaStackServer/InformationModel/InformationModelConfig.h;/usr/include/OpcUaStack2/OpcUaStackServer/InformationModel/Merge.h;/usr/include/OpcUaStack2/OpcUaStackServer/InformationModel/ServerArray.h;/usr/include/OpcUaStack2/OpcUaStackServer/InformationModel/InformationModelAccess.h;/usr/include/OpcUaStack2/OpcUaStackServer/InformationModel/InformationModel.h;/usr/include/OpcUaStack2/OpcUaStackServer/InformationModel/NamespaceArray.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/OpcUaStack2/OpcUaStackServer/InformationModel" TYPE FILE FILES
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/InformationModel/InformationModelNodeSet.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/InformationModel/InformationModelConfig.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/InformationModel/Merge.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/InformationModel/ServerArray.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/InformationModel/InformationModelAccess.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/InformationModel/InformationModel.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/InformationModel/NamespaceArray.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/OpcUaStack2/OpcUaStackServer/NodeSet/NodeSetNamespace.h;/usr/include/OpcUaStack2/OpcUaStackServer/NodeSet/NodeSetValueParser.h;/usr/include/OpcUaStack2/OpcUaStackServer/NodeSet/NodeSetValueParserIf.h;/usr/include/OpcUaStack2/OpcUaStackServer/NodeSet/NodeSetBaseParser.h;/usr/include/OpcUaStack2/OpcUaStackServer/NodeSet/NodeSetXmlParser.h;/usr/include/OpcUaStack2/OpcUaStackServer/NodeSet/NodeSetAlias.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/OpcUaStack2/OpcUaStackServer/NodeSet" TYPE FILE FILES
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/NodeSet/NodeSetNamespace.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/NodeSet/NodeSetValueParser.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/NodeSet/NodeSetValueParserIf.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/NodeSet/NodeSetBaseParser.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/NodeSet/NodeSetXmlParser.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/NodeSet/NodeSetAlias.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/OpcUaStack2/OpcUaStackServer/SecureChannel/SecureChannelMap.h;/usr/include/OpcUaStack2/OpcUaStackServer/SecureChannel/SecureChannelServerConfig.h;/usr/include/OpcUaStack2/OpcUaStackServer/SecureChannel/SecureChannelTransaction.h;/usr/include/OpcUaStack2/OpcUaStackServer/SecureChannel/SecureChannelManagerIf.h;/usr/include/OpcUaStack2/OpcUaStackServer/SecureChannel/SecureChannelServer.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/OpcUaStack2/OpcUaStackServer/SecureChannel" TYPE FILE FILES
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/SecureChannel/SecureChannelMap.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/SecureChannel/SecureChannelServerConfig.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/SecureChannel/SecureChannelTransaction.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/SecureChannel/SecureChannelManagerIf.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/SecureChannel/SecureChannelServer.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/OpcUaStack2/OpcUaStackServer/ServiceManager/ServiceManager.h;/usr/include/OpcUaStack2/OpcUaStackServer/ServiceManager/ServiceContext.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/OpcUaStack2/OpcUaStackServer/ServiceManager" TYPE FILE FILES
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceManager/ServiceManager.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceManager/ServiceContext.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSet/SessionConfig.h;/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSet/AttributeService.h;/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSet/SessionManagerIf.h;/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSet/QueryService.h;/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSet/MonitoredItemService.h;/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSet/SessionIf.h;/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSet/MethodService.h;/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSet/ViewService.h;/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSet/MonitorManager.h;/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSet/SessionOld.h;/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSet/MonitorItem.h;/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSet/EndpointDescriptionConfig.h;/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSet/SessionMap.h;/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSet/NodeManagementService.h;/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSet/Subscription.h;/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSet/SessionManagerOld.h;/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSet/SubscriptionService.h;/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSet/TransactionManager.h;/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSet/ServiceSetBase.h;/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSet/SubscriptionManager.h;/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSet/NodeClass.h;/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSet/DiscoveryService.h;/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSet/DiscoveryManagerIf.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSet" TYPE FILE FILES
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSet/SessionConfig.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSet/AttributeService.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSet/SessionManagerIf.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSet/QueryService.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSet/MonitoredItemService.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSet/SessionIf.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSet/MethodService.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSet/ViewService.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSet/MonitorManager.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSet/SessionOld.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSet/MonitorItem.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSet/EndpointDescriptionConfig.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSet/SessionMap.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSet/NodeManagementService.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSet/Subscription.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSet/SessionManagerOld.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSet/SubscriptionService.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSet/TransactionManager.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSet/ServiceSetBase.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSet/SubscriptionManager.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSet/NodeClass.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSet/DiscoveryService.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSet/DiscoveryManagerIf.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSetApplication/ApplicationService.h;/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/OpcUaStack2/OpcUaStackServer/ServiceSetApplication" TYPE FILE FILES
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSetApplication/ApplicationService.h"
    "/home/huebl/devel_/OpcUaStack/src/OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "applications")
  if(EXISTS "$ENV{DESTDIR}/usr/local/bin/OpcUaServer2" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/bin/OpcUaServer2")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/bin/OpcUaServer2"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/bin/OpcUaServer2")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/bin" TYPE EXECUTABLE FILES "/home/huebl/devel_/OpcUaStack/build_deb/OpcUaServer2")
  if(EXISTS "$ENV{DESTDIR}/usr/local/bin/OpcUaServer2" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/bin/OpcUaServer2")
    file(RPATH_REMOVE
         FILE "$ENV{DESTDIR}/usr/local/bin/OpcUaServer2")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/bin/OpcUaServer2")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libraries")
  if(EXISTS "$ENV{DESTDIR}/usr/local/bin/OpcUaClient2" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/bin/OpcUaClient2")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/bin/OpcUaClient2"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/bin/OpcUaClient2")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/bin" TYPE EXECUTABLE FILES "/home/huebl/devel_/OpcUaStack/build_deb/OpcUaClient2")
  if(EXISTS "$ENV{DESTDIR}/usr/local/bin/OpcUaClient2" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/bin/OpcUaClient2")
    file(RPATH_REMOVE
         FILE "$ENV{DESTDIR}/usr/local/bin/OpcUaClient2")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/bin/OpcUaClient2")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "tools")
  if(EXISTS "$ENV{DESTDIR}/usr/local/bin/OpcUaProjectBuilder2" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/bin/OpcUaProjectBuilder2")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/bin/OpcUaProjectBuilder2"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/bin/OpcUaProjectBuilder2")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/bin" TYPE EXECUTABLE FILES "/home/huebl/devel_/OpcUaStack/build_deb/OpcUaProjectBuilder2")
  if(EXISTS "$ENV{DESTDIR}/usr/local/bin/OpcUaProjectBuilder2" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/bin/OpcUaProjectBuilder2")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/bin/OpcUaProjectBuilder2")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "tools")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/share/OpcUaStack2" TYPE DIRECTORY FILES "/home/huebl/devel_/OpcUaStack/src/OpcUaProjectBuilder/ProjectTemplate")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib/libOpcUaServerApplicationDemo.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib/libOpcUaServerApplicationDemo.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/lib/libOpcUaServerApplicationDemo.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/libOpcUaServerApplicationDemo.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/lib" TYPE SHARED_LIBRARY FILES "/home/huebl/devel_/OpcUaStack/build_deb/libOpcUaServerApplicationDemo.so")
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib/libOpcUaServerApplicationDemo.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib/libOpcUaServerApplicationDemo.so")
    file(RPATH_REMOVE
         FILE "$ENV{DESTDIR}/usr/local/lib/libOpcUaServerApplicationDemo.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/lib/libOpcUaServerApplicationDemo.so")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/etc/OpcUaStack/ASNeG-Demo/OpcUaServer.xml")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/etc/OpcUaStack/ASNeG-Demo" TYPE FILE FILES "/home/huebl/devel_/OpcUaStack/src/OpcUaServerApplicationDemo/Config/OpcUaServer.xml")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/etc/OpcUaStack/ASNeG-Demo/Opc.Ua.NodeSet.xml")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/etc/OpcUaStack/ASNeG-Demo" TYPE FILE FILES "/home/huebl/devel_/OpcUaStack/src/OpcUaServerApplicationDemo/Config/Opc.Ua.NodeSet.xml")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/etc/OpcUaStack/ASNeG-Demo/Opc.Ua.NodeSetTest.xml")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/etc/OpcUaStack/ASNeG-Demo" TYPE FILE FILES "/home/huebl/devel_/OpcUaStack/src/OpcUaServerApplicationDemo/Config/Opc.Ua.NodeSetTest.xml")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/etc/OpcUaStack/ASNeG-Demo/Opc.Ua.NodeSetTestLib.xml")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/etc/OpcUaStack/ASNeG-Demo" TYPE FILE FILES "/home/huebl/devel_/OpcUaStack/src/OpcUaServerApplicationDemo/Config/Opc.Ua.NodeSetTestLib.xml")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/etc/OpcUaStack/ASNeG-Demo/Opc.Ua.NodeSetTestLibClientServer.xml")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/etc/OpcUaStack/ASNeG-Demo" TYPE FILE FILES "/home/huebl/devel_/OpcUaStack/src/OpcUaServerApplicationDemo/Config/Opc.Ua.NodeSetTestLibClientServer.xml")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/etc/OpcUaStack/ASNeG-Demo/Opc.Ua.NodeSet.Camera.xml")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/etc/OpcUaStack/ASNeG-Demo" TYPE FILE FILES "/home/huebl/devel_/OpcUaStack/src/OpcUaServerApplicationDemo/Config/Opc.Ua.NodeSet.Camera.xml")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/etc/OpcUaStack/ASNeG-Demo/Opc.Ua.NodeSet.Function.xml")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/etc/OpcUaStack/ASNeG-Demo" TYPE FILE FILES "/home/huebl/devel_/OpcUaStack/src/OpcUaServerApplicationDemo/Config/Opc.Ua.NodeSet.Function.xml")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/etc/OpcUaStack/ASNeG-Demo/ApplicationDemoModel.xml")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/etc/OpcUaStack/ASNeG-Demo" TYPE FILE FILES "/home/huebl/devel_/OpcUaStack/src/OpcUaServerApplicationDemo/Config/ApplicationDemoModel.xml")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/etc/OpcUaStack/ASNeG-Demo/animation00.gif")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/etc/OpcUaStack/ASNeG-Demo" TYPE FILE FILES "/home/huebl/devel_/OpcUaStack/src/OpcUaServerApplicationDemo/Config/animation00.gif")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/etc/OpcUaStack/ASNeG-Demo/animation01.gif")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/etc/OpcUaStack/ASNeG-Demo" TYPE FILE FILES "/home/huebl/devel_/OpcUaStack/src/OpcUaServerApplicationDemo/Config/animation01.gif")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/etc/OpcUaStack/ASNeG-Demo/animation02.gif")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/etc/OpcUaStack/ASNeG-Demo" TYPE FILE FILES "/home/huebl/devel_/OpcUaStack/src/OpcUaServerApplicationDemo/Config/animation02.gif")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/etc/OpcUaStack/ASNeG-Demo/animation03.gif")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/etc/OpcUaStack/ASNeG-Demo" TYPE FILE FILES "/home/huebl/devel_/OpcUaStack/src/OpcUaServerApplicationDemo/Config/animation03.gif")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/etc/OpcUaStack/ASNeG-Demo/animation04.gif")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/etc/OpcUaStack/ASNeG-Demo" TYPE FILE FILES "/home/huebl/devel_/OpcUaStack/src/OpcUaServerApplicationDemo/Config/animation04.gif")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/var/log/OpcUaStack/ASNeG-Demo/README")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/var/log/OpcUaStack/ASNeG-Demo" TYPE FILE FILES "/home/huebl/devel_/OpcUaStack/src/OpcUaServerApplicationDemo/linux/log/README")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/var/log/OpcUaStack/ASNeG-Demo/")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/var/log/OpcUaStack/ASNeG-Demo" TYPE DIRECTORY FILES "")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "applications")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/share/icons/OpcUaStack2" TYPE FILE FILES "/home/huebl/devel_/OpcUaStack/src/icon/asneg.ico")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "applications")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/share/icons/OpcUaStack2" TYPE FILE FILES "/home/huebl/devel_/OpcUaStack/src/icon/asneg_install.ico")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "applications")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/share/icons/OpcUaStack2" TYPE FILE FILES "/home/huebl/devel_/OpcUaStack/src/icon/asneg_uninstall.ico")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "applications")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/share/OpcUaStack2" TYPE FILE FILES "/home/huebl/devel_/OpcUaStack/src/Copyright.txt")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "applications")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/usr/share/OpcUaStack2" TYPE FILE FILES "/home/huebl/devel_/OpcUaStack/src/../NOTICE")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/huebl/devel_/OpcUaStack/build_deb/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
