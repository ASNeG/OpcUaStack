/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_Attribute_h__
#define __OpcUaStackServer_Attribute_h__

#include <boost/optional.hpp>
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaAttributeId.h"
#include "OpcUaStackCore/StandardDataTypes/NodeClass.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

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
		virtual Attribute* clone(void) = 0;
		virtual void copyTo(Attribute* attribute) = 0;
		virtual bool equal(void) = 0;

		virtual void out(std::ostream& os) const = 0;
		friend std::ostream& operator<<(std::ostream& os, const Attribute& value) {
			value.out(os);
			return os;
		}

	  private:
	};

	
	template<typename DATATYPE>
	  class DLLEXPORT AttributeData
	  : public Attribute
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
	  class DLLEXPORT AttributeMeta
	  : public AttributeData<DATATYPE>
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
					case AttributeId_DataTypeDefinition: return "DataTypeDefinition";
					case AttributeId_RolePermissions: return "RolePermissions";
					case AttributeId_UserRolePermissions: return "UserRolePermissions";
					case AttributeId_AccessRestrictions: return "AccessRestrictions";
					case AttributeId_AccessLevelEx: return "AccessLevelEx";
					default: return "Unknown";
				}
			}

			OpcUaBuildInType type(void) {
				return type_;
			}

			Attribute* clone(void) {
				Attribute* clone = new AttributeMeta<DATATYPE, id_, type_>();
				copyTo(clone);
				return clone;
			}

			void copyTo(Attribute* attribute) {
				AttributeMeta<DATATYPE, id_, type_>* attributeMeta;
				attributeMeta = reinterpret_cast<AttributeMeta<DATATYPE, id_, type_>*>(attribute);
				if (this->exist()) attributeMeta->data(this->data());
			}

			bool equal(void) {
				// FIXME:
				return true;
			}
	  };

	  typedef AttributeMeta<OpcUaByte, AttributeId_AccessLevel, OpcUaBuildInType_OpcUaUInt32> AccessLevelAttribute;
	  typedef AttributeMeta<OpcUaNodeId, AttributeId_NodeId, OpcUaBuildInType_OpcUaNodeId> NodeIdAttribute;
	  typedef AttributeMeta<NodeClass::Enum, AttributeId_NodeClass, OpcUaBuildInType_OpcUaUInt32> NodeClassAttribute;
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
	  typedef AttributeMeta<OpcUaInt32, AttributeId_ValueRank, OpcUaBuildInType_OpcUaInt32> ValueRankAttribute;
	  typedef AttributeMeta<OpcUaUInt32Array, AttributeId_ArrayDimensions, OpcUaBuildInType_OpcUaUInt32> ArrayDimensionsAttribute;
	  typedef AttributeMeta<OpcUaDouble, AttributeId_MinimumSamplingInterval, OpcUaBuildInType_OpcUaDouble> MinimumSamplingIntervalAttribute;
	  typedef AttributeMeta<OpcUaBoolean, AttributeId_Historizing, OpcUaBuildInType_OpcUaBoolean> HistorizingAttribute;
	  typedef AttributeMeta<OpcUaNodeId, AttributeId_DataType, OpcUaBuildInType_OpcUaNodeId> DataTypeAttribute;
	  typedef AttributeMeta<OpcUaBoolean, AttributeId_Executable, OpcUaBuildInType_OpcUaBoolean> ExecutableAttribute;
	  typedef AttributeMeta<OpcUaBoolean, AttributeId_UserExecutable, OpcUaBuildInType_OpcUaBoolean> UserExecutableAttribute;
	  typedef AttributeMeta<OpcUaByte, AttributeId_UserAccessLevel, OpcUaBuildInType_OpcUaByte> UserAccessLevelAttribute;

	  // FIXME: todo
	  typedef AttributeMeta<OpcUaByte, AttributeId_DataTypeDefinition, OpcUaBuildInType_OpcUaExtensionObject> DataTypeDefinitionAttribute;
	  typedef AttributeMeta<OpcUaByte, AttributeId_RolePermissions, OpcUaBuildInType_OpcUaExtensionObject> RolePermissionsAttribute;
	  typedef AttributeMeta<OpcUaByte, AttributeId_UserRolePermissions, OpcUaBuildInType_OpcUaExtensionObject> UserRolePermissionsAttribute;
	  typedef AttributeMeta<OpcUaByte, AttributeId_AccessRestrictions, OpcUaBuildInType_OpcUaExtensionObject> AccessRestrictionsAttribute;
	  typedef AttributeMeta<OpcUaByte, AttributeId_AccessLevelEx, OpcUaBuildInType_OpcUaExtensionObject> AccessLevelExAttribute;

}

#endif
