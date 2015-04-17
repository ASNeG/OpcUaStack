#ifndef __OpcUaStackServer_AttributeBase_h__
#define __OpcUaStackServer_AttributeBase_h__

#include <boost/thread/mutex.hpp>
#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/AddressSpaceModel/Attribute.h"

namespace OpcUaStackServer
{

	class DLLEXPORT AttributeBase
	{
	  public:
		typedef boost::shared_ptr<AttributeBase> SPtr;
		typedef boost::weak_ptr<AttributeBase> WPtr;

		AttributeBase(void);
		virtual ~AttributeBase(void);

		void lock(void);
		void unlock(void);
		boost::mutex& mutex(void);

		Attribute* attribute(AttributeId attributeId);

		//
		// attribute node id
		//
		virtual Attribute* nodeIdAttribute(void);
		bool unsetNodeId(void);
		bool setNodeId(OpcUaNodeId& nodeId);
		bool getNodeId(OpcUaNodeId& nodeId);
		bool isPartNodeId(void);
		bool isNullNodeId(void);
		boost::optional<OpcUaNodeId&> getNodeId(void);

		//
		// attribute node class
		//
		virtual Attribute* nodeClassAttribute(void);
		bool unsetNodeClass(void);
		bool setNodeClass(NodeClassType& nodeClass);
		bool getNodeClass(NodeClassType& nodeClass);
		bool isPartNodeClass(void);
		bool isNullNodeClass(void);
		boost::optional<NodeClassType&> getNodeClass(void);

		//
		// attribute browse name
		//
		virtual Attribute* browseNameAttribute(void);
		bool unsetBrowseName(void);
		bool setBrowseName(OpcUaQualifiedName& browseName);
		bool getBrowseName(OpcUaQualifiedName& browseName);
		bool isPartBrowseName(void);
		bool isNullBrowseName(void);
		boost::optional<OpcUaQualifiedName&> getBrowseName(void);

		virtual Attribute* displayNameAttribute(void);
		virtual Attribute* descriptionAttribute(void);
		virtual Attribute* writeMaskAttribute(void);
		virtual Attribute* userWriteMaskAttribute(void);
		virtual Attribute* isAbstractAttribute(void);
		virtual Attribute* symmetricAttribute(void);
		virtual Attribute* inverseNameAttribute(void);
		virtual Attribute* containsNoLoopsAttribute(void);
		virtual Attribute* eventNotifierAttribute(void);
		virtual Attribute* valueAttribute(void);
		virtual Attribute* dataTypeAttribute(void);
		virtual Attribute* valueRankAttribute(void);
		virtual Attribute* arrayDimensionsAttribute(void);
		virtual Attribute* accessLevelAttribute(void);
		virtual Attribute* userAccessLevelAttribute(void);
		virtual Attribute* historizingAttribute(void);
		virtual Attribute* executableAttribute(void);
		virtual Attribute* userExecutableAttribute(void);
		virtual Attribute* minimumSamplingIntervalAttribute(void);

	  private:
		boost::mutex mutex_;
	};

}

#endif
