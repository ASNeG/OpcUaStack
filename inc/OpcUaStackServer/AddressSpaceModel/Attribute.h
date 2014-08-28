#ifndef __OpcUaStackServer_Attribute_h__
#define __OpcUaStackServer_Attribute_h__

#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackServer/AddressSpaceModel/NodeClass.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	typedef enum
	{
		AttributeId_AccessLevel,
		AttributeId_ArrayDimensions,
		AttributeId_BrowseName,
		AttributeId_ContainsNoLoops,
		AttributeId_DataType,
		AttributeId_Description,
		AttributeId_DisplayName,
		AttributeId_EventNotifier,
		AttributeId_Executable,
		AttributeId_Historizing,
		AttributeId_InverseName,
		AttributeId_IsAbstract,
		AttributeId_MinimumSamplingInterval,
		AttributeId_NodeClass,
		AttributeId_NodeId,
		AttributeId_Symmetric,
		AttributeId_UserAccessLevel,
		AttributeId_UserExecutable,
		AttributeId_UserWriteMask,
		AttributeId_Value,
		AttributeId_ValueRank,
		AttributeId_WriteMask
	} AttributeId;


	typedef enum
	{
		AttributeModel_Mandatory,
		AttributeModel_Optional
	} AttributeModel;


	class Attribute
	{
	  public:
		Attribute(void);
		~Attribute(void);

		virtual OpcUaUInt32 id(void) = 0;
		virtual std::string name(void) = 0;
		virtual std::string description(void);
		virtual OpcUaBuildInType type(void) = 0;

	  private:
	};

	
	template<typename DATATYPE>
	  class AttributeData : public Attribute
	  {
	    public:
		  AttributeData(void) 
		  : Attribute()
		  , data_()
		  {}

		  ~AttributeData(void)
		  {}

		  void data(const DATATYPE& data) {
			  data_ = data;
		  }

		  DATATYPE& data(void) const {
			  return data_;
		  }

	    private:
		  DATATYPE data_;
	  };


    template<typename DATATYPE, OpcUaUInt32 id_, char const * name_, OpcUaBuildInType type_>
	  class AttributeMeta
	  {
	    public:
			AttributeMeta(void) 
			: AttributeData<DATATYPE>()
			{}

			~AttributeMeta(void) 
			{}

			OpcUaUInt32 id(void) {
				return id_;
			}

			std::string name(void) {
				return name_;
			}

			OpcUaBuildInType type(void) {
				return type_;
			}
	  };

	  typedef AttributeMeta<OpcUaUInt32, AttributeId_AccessLevel, nullptr, OpcUaBuildInType_OpcUaUInt32> AccessLevelAttribute;
	  typedef AttributeMeta<OpcUaNodeId, AttributeId_NodeId, nullptr, OpcUaBuildInType_OpcUaNodeId> NodeIdAttribute;
	  typedef AttributeMeta<NodeClass, AttributeId_NodeClass, nullptr, OpcUaBuildInType_OpcUaUInt32> NodeClassAttribute;
	  typedef AttributeMeta<OpcUaQualifiedName, AttributeId_BrowseName, nullptr, OpcUaBuildInType_OpcUaQualifiedName> BrowseNameAttribute;
	  typedef AttributeMeta<OpcUaLocalizedText, AttributeId_DisplayName, nullptr, OpcUaBuildInType_OpcUaLocalizedText> DisplayNameAttribute;
	  typedef AttributeMeta<OpcUaLocalizedText, AttributeId_Description, nullptr, OpcUaBuildInType_OpcUaLocalizedText> DescriptionAttribute;
	  typedef AttributeMeta<OpcUaUInt32, AttributeId_WriteMask, nullptr, OpcUaBuildInType_OpcUaUInt32> WriteMaskAttribute;
	  typedef AttributeMeta<OpcUaUInt32, AttributeId_UserWriteMask, nullptr, OpcUaBuildInType_OpcUaUInt32> UserWriteMaskAttribute;
	  typedef AttributeMeta<OpcUaBoolean, AttributeId_IsAbstract, nullptr, OpcUaBuildInType_OpcUaBoolean> IsAbstractAttribute;
	  typedef AttributeMeta<OpcUaBoolean, AttributeId_Symmetric, nullptr, OpcUaBuildInType_OpcUaBoolean> SymmetricAttribute;
	  typedef AttributeMeta<OpcUaLocalizedText, AttributeId_InverseName, nullptr, OpcUaBuildInType_OpcUaLocalizedText> InverseNameAttribute;
	  typedef AttributeMeta<OpcUaBoolean, AttributeId_ContainsNoLoops, nullptr, OpcUaBuildInType_OpcUaBoolean> ContainsNoLoopsAttribute;
	  typedef AttributeMeta<OpcUaByte, AttributeId_EventNotifier, nullptr, OpcUaBuildInType_OpcUaByte> EventNotifierAttribute;
	  typedef AttributeMeta<OpcUaDataValue, AttributeId_Value, nullptr, OpcUaBuildInType_OpcUaDataValue> ValueAttribute;
	  typedef AttributeMeta<OpcUaUInt32, AttributeId_ValueRank, nullptr, OpcUaBuildInType_OpcUaUInt32> ValueRanklAttribute;
	  typedef AttributeMeta<OpcUaUInt32Array, AttributeId_ArrayDimensions, nullptr, OpcUaBuildInType_OpcUaUInt32> ArrayDimensionsAttribute;
	  typedef AttributeMeta<OpcUaDouble, AttributeId_MinimumSamplingInterval, nullptr, OpcUaBuildInType_OpcUaDouble> MinimumSamplingIntervalAttribute;
	  typedef AttributeMeta<OpcUaBoolean, AttributeId_Historizing, nullptr, OpcUaBuildInType_OpcUaBoolean> HistorizingAttribute;
	  typedef AttributeMeta<OpcUaNodeId, AttributeId_DataType, nullptr, OpcUaBuildInType_OpcUaNodeId> DataTypeAttribute;
	  typedef AttributeMeta<OpcUaBoolean, AttributeId_Executable, nullptr, OpcUaBuildInType_OpcUaBoolean> ExecutableAttribute;
	  typedef AttributeMeta<OpcUaBoolean, AttributeId_UserExecutable, nullptr, OpcUaBuildInType_OpcUaBoolean> UserExecutableAttribute;
	  typedef AttributeMeta<OpcUaByte, AttributeId_UserAccessLevel, nullptr, OpcUaBuildInType_OpcUaByte> UserAccessLevelAttribute;

}

#endif