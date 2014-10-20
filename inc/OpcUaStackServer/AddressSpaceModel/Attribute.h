#ifndef __OpcUaStackServer_Attribute_h__
#define __OpcUaStackServer_Attribute_h__

#include <boost/optional.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/NodeClass.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	typedef enum
	{
		AttributeId_NodeId = 1,
		AttributeId_NodeClass = 2,
		AttributeId_BrowseName = 3,
		AttributeId_DisplayName = 4, 
		AttributeId_Description = 5,
		AttributeId_WriteMask = 6,
		AttributeId_UserWriteMask = 7,
		AttributeId_IsAbstract = 8,
		AttributeId_Symmetric = 9, 
		AttributeId_InverseName = 10,
		AttributeId_ContainsNoLoops = 11,
		AttributeId_EventNotifier = 12,
		AttributeId_Value = 13,
		AttributeId_DataType = 14,
		AttributeId_ValueRank = 15,
		AttributeId_ArrayDimensions = 16,
		AttributeId_AccessLevel = 17,
		AttributeId_UserAccessLevel = 18,
		AttributeId_MinimumSamplingInterval = 19,
		AttributeId_Historizing = 20,
		AttributeId_Executable = 21,
		AttributeId_UserExecutable = 22,
	} AttributeId;


	typedef enum
	{
		AttributeModel_Mandatory,
		AttributeModel_Optional
	} AttributeModel;


	class DLLEXPORT Attribute
	{
	  public:
		Attribute(void);
		virtual ~Attribute(void);

		virtual OpcUaUInt32 id(void) = 0;
		virtual std::string name(void) = 0;
		virtual std::string description(void);
		virtual OpcUaBuildInType type(void) = 0;
		virtual bool exist(void) = 0;
		virtual void exist(bool exist) = 0;

		virtual void out(std::ostream& os) const = 0;
		friend std::ostream& operator<<(std::ostream& os, const Attribute& value) {
			value.out(os);
			return os;
		}

	  private:
	};

	
	template<typename DATATYPE>
	  class DLLEXPORT AttributeData : public Attribute
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
			 
		  virtual ~AttributeData(void)
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

		  bool exist(void) {
			  return exist_;
		  }

		  void exist(bool exist) {
			  exist_ = exist;
		  }

		  virtual void out(std::ostream& os) const {
			  os << data_;
		  }
		  friend std::ostream& operator<<(std::ostream& os, const AttributeData& attributeData) {
			os << attributeData.data_;
			return os;
		  }

	    private:
		  bool exist_;
		  DATATYPE data_;
	  };


    template<typename DATATYPE, OpcUaUInt32 id_, OpcUaBuildInType type_>
	  class DLLEXPORT AttributeMeta : public AttributeData<DATATYPE>
	  {
	    public:
			AttributeMeta(void) 
			: AttributeData<DATATYPE>()
			{}

			AttributeMeta(const DATATYPE& data)
			: AttributeData<DATATYPE>(data)
			{}

			virtual ~AttributeMeta(void) 
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
					case AttributeId_ValueRank: return "ValueRank";
					case AttributeId_WriteMask: return "WriteMask";
					default: return "Unknown";
				}
			}

			OpcUaBuildInType type(void) {
				return type_;
			}
	  };

	  typedef AttributeMeta<OpcUaByte, AttributeId_AccessLevel, OpcUaBuildInType_OpcUaUInt32> AccessLevelAttribute;
	  typedef AttributeMeta<OpcUaNodeId, AttributeId_NodeId, OpcUaBuildInType_OpcUaNodeId> NodeIdAttribute;
	  typedef AttributeMeta<NodeClassType, AttributeId_NodeClass, OpcUaBuildInType_OpcUaUInt32> NodeClassAttribute;
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
	  typedef AttributeMeta<OpcUaUInt32, AttributeId_ValueRank, OpcUaBuildInType_OpcUaUInt32> ValueRankAttribute;
	  typedef AttributeMeta<OpcUaUInt32Array, AttributeId_ArrayDimensions, OpcUaBuildInType_OpcUaUInt32> ArrayDimensionsAttribute;
	  typedef AttributeMeta<OpcUaDouble, AttributeId_MinimumSamplingInterval, OpcUaBuildInType_OpcUaDouble> MinimumSamplingIntervalAttribute;
	  typedef AttributeMeta<OpcUaBoolean, AttributeId_Historizing, OpcUaBuildInType_OpcUaBoolean> HistorizingAttribute;
	  typedef AttributeMeta<OpcUaNodeId, AttributeId_DataType, OpcUaBuildInType_OpcUaNodeId> DataTypeAttribute;
	  typedef AttributeMeta<OpcUaBoolean, AttributeId_Executable, OpcUaBuildInType_OpcUaBoolean> ExecutableAttribute;
	  typedef AttributeMeta<OpcUaBoolean, AttributeId_UserExecutable, OpcUaBuildInType_OpcUaBoolean> UserExecutableAttribute;
	  typedef AttributeMeta<OpcUaByte, AttributeId_UserAccessLevel, OpcUaBuildInType_OpcUaByte> UserAccessLevelAttribute;

}

#endif
