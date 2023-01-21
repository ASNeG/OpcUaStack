/*
   Copyright 2015-2023 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaStackServer_ReferenceItemMap_h__
#define __OpcUaStackServer_ReferenceItemMap_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackServer/AddressSpaceModel/ReferenceType.h"
#include "OpcUaStackServer/AddressSpaceModel/ReferenceItem.h"

namespace OpcUaStackServer
{

	typedef std::map<OpcUaStackCore::OpcUaNodeId, ReferenceItem::SPtr> ReferenceItemTable;
	typedef std::map<OpcUaStackCore::OpcUaNodeId, ReferenceItemTable> ReferenceItemMultiMap;

	class DLLEXPORT ReferenceItemMap
	: public OpcUaStackCore::Object
	{
	  public:
		typedef boost::shared_ptr<ReferenceItemMap> SPtr;

		class DLLEXPORT const_iterator {
		    friend class ReferenceItemMap;
		  public:
			const_iterator();
			const_iterator(const const_iterator&);
		    ~const_iterator();
		    const_iterator& operator=(const const_iterator&);
		    bool operator==(const const_iterator&);
		    bool operator!=(const const_iterator&);
		    const_iterator& operator++(); //prefix increment
		    const ReferenceItem::SPtr operator*() const;

		  private:
		    ReferenceItemTable::const_iterator refItemIt_;
		    ReferenceItemTable::const_iterator refItemEnd_;
		    ReferenceItemMultiMap::const_iterator refTypeIt_;
		    ReferenceItemMultiMap::const_iterator refTypeEnd_;
		};

		ReferenceItemMap(void);
		~ReferenceItemMap(void);

		void clear(void);
		bool add(ReferenceType referenceType, ReferenceItem::SPtr& referenceItem);
		bool add(ReferenceType referenceType, bool isForward, const OpcUaStackCore::OpcUaNodeId& nodeId);
		bool add(ReferenceType referenceType, bool isForward, std::vector<OpcUaStackCore::OpcUaNodeId>& nodes);
		bool add(const OpcUaStackCore::OpcUaNodeId& referenceTypeNodeId, ReferenceItem::SPtr& referenceItem);
		bool add(const OpcUaStackCore::OpcUaNodeId& referenceTypeNodeId, bool isForward, const OpcUaStackCore::OpcUaNodeId& nodeId);
		bool add(const OpcUaStackCore::OpcUaNodeId& referenceTypeNodeId, bool isForward, std::vector<OpcUaStackCore::OpcUaNodeId>& nodes);

		bool exist(OpcUaStackCore::OpcUaNodeId& referenceTypeNodeId, bool isForward, OpcUaStackCore::OpcUaNodeId& nodeId);

		void get(ReferenceType referenceType, std::vector<bool>& isForwards, std::vector<OpcUaStackCore::OpcUaNodeId>& nodes);
		bool getHasTypeDefinition(OpcUaStackCore::OpcUaNodeId& node);
		bool getHasModellingRule(OpcUaStackCore::OpcUaNodeId& node);

		bool remove(const OpcUaStackCore::OpcUaNodeId& referenceTypeNodeId, ReferenceItem::SPtr& referenceItem);
		bool remove(const OpcUaStackCore::OpcUaNodeId& referenceTypeNodeId, const OpcUaStackCore::OpcUaNodeId& nodeId);
		bool remove(const OpcUaStackCore::OpcUaNodeId& referenceTypeNodeId, bool isForward, const OpcUaStackCore::OpcUaNodeId& nodeId);

		void copyTo(ReferenceItemMap::SPtr& referenceItemMap) const;
		void copyTo(ReferenceItemMap& referenceItemMap) const;

		const_iterator begin() const;
		const_iterator end() const;
		bool erase(const_iterator& it);
		std::pair<ReferenceItemTable::const_iterator, ReferenceItemTable::const_iterator> equal_range(const OpcUaStackCore::OpcUaNodeId& referenceTypeNodeId) const;
		size_t size() const;

	  private:
		ReferenceItemMultiMap referenceItemMultiMap_;
	};

}

#endif
