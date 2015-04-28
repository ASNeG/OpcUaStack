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

		//
		// display name
		//
		virtual Attribute* displayNameAttribute(void);
		bool unsetDisplayName(void);
		bool setDisplayName(OpcUaLocalizedText& displayName);
		bool getDisplayName(OpcUaLocalizedText& displayName);
		bool isPartDisplayName(void);
		bool isNullDisplayName(void);
		boost::optional<OpcUaLocalizedText&> getDisplayName(void);

		//
		// description
		//
		virtual Attribute* descriptionAttribute(void);
		bool unsetDescription(void);
		bool setDescription(OpcUaLocalizedText& displayName);
		bool getDescription(OpcUaLocalizedText& displayName);
		bool isPartDescription(void);
		bool isNullDescription(void);
		boost::optional<OpcUaLocalizedText&> getDescription(void);

		//
		// write mask
		//
		virtual Attribute* writeMaskAttribute(void);
		bool unsetWriteMask(void);
		bool setWriteMask(OpcUaUInt32& writeMask);
		bool getWriteMask(OpcUaUInt32& writeMask);
		bool isPartWriteMask(void);
		bool isNullWriteMask(void);
		boost::optional<OpcUaUInt32&> getWriteMask(void);

		//
		// user write mask
		//
		virtual Attribute* userWriteMaskAttribute(void);
		bool unsetUserWriteMask(void);
		bool setUserWriteMask(OpcUaUInt32& writeMask);
		bool getUserWriteMask(OpcUaUInt32& writeMask);
		bool isPartUserWriteMask(void);
		bool isNullUserWriteMask(void);
		boost::optional<OpcUaUInt32&> getUserWriteMask(void);

		//
		// is abstract
		//
		virtual Attribute* isAbstractAttribute(void);
		bool unsetIsAbstract(void);
		bool setIsAbstract(OpcUaBoolean& isAbstract);
		bool getIsAbstract(OpcUaBoolean& isAbstract);
		bool isPartIsAbstract(void);
		bool isNullIsAbstract(void);
		boost::optional<OpcUaBoolean&> getIsAbstract(void);

		//
		// symmetric
		//
		virtual Attribute* symmetricAttribute(void);
		bool unsetSymmetric(void);
		bool setSymmetric(OpcUaBoolean& isAbstract);
		bool getSymmetric(OpcUaBoolean& isAbstract);
		bool isPartSymmetric(void);
		bool isNullSymmetric(void);
		boost::optional<OpcUaBoolean&> getSymmetric(void);

		//
		// inverse name
		//
		virtual Attribute* inverseNameAttribute(void);
		bool unsetInverseName(void);
		bool setInverseName(OpcUaLocalizedText& inverseName);
		bool getInverseName(OpcUaLocalizedText& inverseName);
		bool isPartInverseName(void);
		bool isNullInverseName(void);
		boost::optional<OpcUaLocalizedText&> getInverseName(void);

		//
		// contains no loops
		//
		virtual Attribute* containsNoLoopsAttribute(void);
		bool unsetContainsNoLoops(void);
		bool setContainsNoLoops(OpcUaBoolean& containsNoLoops);
		bool getContainsNoLoops(OpcUaBoolean& containsNoLoops);
		bool isPartContainsNoLoops(void);
		bool isNullContainsNoLoops(void);
		boost::optional<OpcUaBoolean&> getContainsNoLoops(void);

		//
		// event notifier
		//
		virtual Attribute* eventNotifierAttribute(void);
		bool unsetEventNotifier(void);
		bool setEventNotifier(OpcUaByte& eventNotifierLoops);
		bool getEventNotifier(OpcUaByte& eventNotifierLoops);
		bool isPartEventNotifier(void);
		bool isNullEventNotifier(void);
		boost::optional<OpcUaByte&> getEventNotifier(void);

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
