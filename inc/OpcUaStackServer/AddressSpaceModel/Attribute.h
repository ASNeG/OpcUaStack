#ifndef __OpcUaStackServer_Attribute_h__
#define __OpcUaStackServer_Attribute_h__

#include <boost/optional.hpp>
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
		  , exist_(false)
		  {}

		  AttributeData(const DATATYPE& data)
		  : Attribute()
		  , exist_(true)
		  {
			  data_ = data;
		  }
			 
		  ~AttributeData(void)
		  {}

		  void reset(void)
		  {
			  exist_ = false;
		  }

		  void data(const DATATYPE& data) {
			  exist_ = true;
			  data_ = data;
		  }

		  DATATYPE& data(void) {
			  return data_;
		  }

		  boost::optional<DATATYPE&> data_optional(void) {
			  if (!exist_) return nullptr;
			  return data_;
		  }

	    private:
		  bool exist_;
		  DATATYPE data_;
	  };


    template<typename DATATYPE, OpcUaUInt32 id_, OpcUaBuildInType type_>
	  class AttributeMeta : public AttributeData<DATATYPE>
	  {
	    public:
			AttributeMeta(void) 
			: AttributeData<DATATYPE>()
			{}

			AttributeMeta(const DATATYPE& data)
			: AttributeData<DATATYPE>(data)
			{}

			~AttributeMeta(void) 
			{}

			OpcUaUInt32 id(void) {
				return id_;
			}

			std::string name(void) {
				switch (id_)
				{
					case AttributeId_AccessLevel: return "AccessLevel";
					case AttributeId_ArrayDimensions: return "ArrayDimensions";
					case AttributeId_BrowseName: return "BrowseName";
					case AttributeId_ContainsNoLoops: return "ContainsNoLoops";
					case AttributeId_DataType: return "DataType";
					case AttributeId_Description: return "Description";
					case AttributeId_DisplayName: return "DisplayName";
					case AttributeId_EventNotifier: return "EventNotifier";
					case AttributeId_Executable: return "Executable";
					case AttributeId_Historizing: return "Historizing";
					case AttributeId_InverseName: return "InverseName";
					case AttributeId_IsAbstract: return "IsAbstrace";
					case AttributeId_MinimumSamplingInterval: return "MinimumSamplingInterval";
					case AttributeId_NodeClass: return "NodeClass";
					case AttributeId_NodeId: return "NodeId";
					case AttributeId_Symmetric: return "Symmetric";
					case AttributeId_UserAccessLevel: return "UserAccessLevel";
					case AttributeId_UserExecutable: return "UserExecutable";
					case AttributeId_UserWriteMask: return "UserWriteMask";
					case AttributeId_Value: return "Value";
					case AttributeId_ValueRank: return "ValueRanl";
					case AttributeId_WriteMask: return "WriteMask";
					default: return "Unknown";
				}
			}

			OpcUaBuildInType type(void) {
				return type_;
			}
	  };

	  typedef AttributeMeta<OpcUaUInt32, AttributeId_AccessLevel, OpcUaBuildInType_OpcUaUInt32> AccessLevelAttribute;
	  typedef AttributeMeta<OpcUaNodeId, AttributeId_NodeId, OpcUaBuildInType_OpcUaNodeId> NodeIdAttribute;
	  typedef AttributeMeta<NodeClass, AttributeId_NodeClass, OpcUaBuildInType_OpcUaUInt32> NodeClassAttribute;
	  typedef AttributeMeta<OpcUaQualifiedName, AttributeId_BrowseName, OpcUaBuildInType_OpcUaQualifiedName> BrowseNameAttribute;
	  typedef AttributeMeta<OpcUaLocalizedText, AttributeId_DisplayName, OpcUaBuildInType_OpcUaLocalizedText> DisplayNameAttribute;
	  typedef AttributeMeta<OpcUaLocalizedText, AttributeId_Description, OpcUaBuildInType_OpcUaLocalizedText> DescriptionAttribute;
	  typedef AttributeMeta<OpcUaUInt32, AttributeId_WriteMask, OpcUaBuildInType_OpcUaUInt32> WriteMaskAttribute;
	  typedef AttributeMeta<OpcUaUInt32, AttributeId_UserWriteMask, OpcUaBuildInType_OpcUaUInt32> UserWriteMaskAttribute;
	  typedef AttributeMeta<OpcUaBoolean, AttributeId_IsAbstract, OpcUaBuildInType_OpcUaBoolean> IsAbstractAttribute;
	  typedef AttributeMeta<OpcUaBoolean, AttributeId_Symmetric, OpcUaBuildInType_OpcUaBoolean> SymmetricAttribute;
	  typedef AttributeMeta<OpcUaLocalizedText, AttributeId_InverseName, OpcUaBuildInType_OpcUaLocalizedText> InverseNameAttribute;
	  typedef AttributeMeta<OpcUaBoolean, AttributeId_ContainsNoLoops, OpcUaBuildInType_OpcUaBoolean> ContainsNoLoopsAttribute;
	  typedef AttributeMeta<OpcUaByte, AttributeId_EventNotifier, OpcUaBuildInType_OpcUaByte> EventNotifierAttribute;
	  typedef AttributeMeta<OpcUaDataValue, AttributeId_Value, OpcUaBuildInType_OpcUaDataValue> ValueAttribute;
	  typedef AttributeMeta<OpcUaUInt32, AttributeId_ValueRank, OpcUaBuildInType_OpcUaUInt32> ValueRanklAttribute;
	  typedef AttributeMeta<OpcUaUInt32Array, AttributeId_ArrayDimensions, OpcUaBuildInType_OpcUaUInt32> ArrayDimensionsAttribute;
	  typedef AttributeMeta<OpcUaDouble, AttributeId_MinimumSamplingInterval, OpcUaBuildInType_OpcUaDouble> MinimumSamplingIntervalAttribute;
	  typedef AttributeMeta<OpcUaBoolean, AttributeId_Historizing, OpcUaBuildInType_OpcUaBoolean> HistorizingAttribute;
	  typedef AttributeMeta<OpcUaNodeId, AttributeId_DataType, OpcUaBuildInType_OpcUaNodeId> DataTypeAttribute;
	  typedef AttributeMeta<OpcUaBoolean, AttributeId_Executable, OpcUaBuildInType_OpcUaBoolean> ExecutableAttribute;
	  typedef AttributeMeta<OpcUaBoolean, AttributeId_UserExecutable, OpcUaBuildInType_OpcUaBoolean> UserExecutableAttribute;
	  typedef AttributeMeta<OpcUaByte, AttributeId_UserAccessLevel, OpcUaBuildInType_OpcUaByte> UserAccessLevelAttribute;

}

#endif