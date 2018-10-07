/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Aleksey Timin (atimin@gmail.com)
 */

#include <OpcUaStackPubSub/PubSubModel/PublishedDataSetModel.h>

namespace OpcUaStackPubSub
{

	PublishedDataSetModel::PublishedDataSetModel(void)
	: name_("")
	, dataSetFolder_()
	, dataSetMetaData_()
	, extensionFields_()
	, dataSetSource_()
	{
	}

	PublishedDataSetModel::~PublishedDataSetModel(void)
	{
	}

	void
	PublishedDataSetModel::name(const OpcUaString& name)
	{
		name_ = name;
	}

	OpcUaString&
	PublishedDataSetModel::name(void)
	{
		return name_;
	}

	void
	PublishedDataSetModel::dataSetFolder(OpcUaStringArray::SPtr& dataSetFolder)
	{
		dataSetFolder_ = dataSetFolder;
	}

	OpcUaStringArray::SPtr&
	PublishedDataSetModel::dataSetFolder(void)
	{
		return dataSetFolder_;
	}

	void
	PublishedDataSetModel::dataSetMetaData(DataSetMetaDataModel::SPtr& dataSetMetaData)
	{
		dataSetMetaData_ = dataSetMetaData;
	}

	DataSetMetaDataModel::SPtr&
	PublishedDataSetModel::dataSetMetaData(void)
	{
		return dataSetMetaData_;
	}

	void
	PublishedDataSetModel::extensionFields(const KeyValuePair::Vec& extensionFields)
	{
		extensionFields_ = extensionFields;
	}

	KeyValuePair::Vec&
	PublishedDataSetModel::extensionFields(void)
	{
		return extensionFields_;
	}

	void
	PublishedDataSetModel::dataSetSource(PublishedDataSetSourceModel::SPtr& dataSetSource)
	{
		dataSetSource_ = dataSetSource;
	}

	PublishedDataSetSourceModel::SPtr&
	PublishedDataSetModel::dataSetSource(void)
	{
		return dataSetSource_;
	}

}
