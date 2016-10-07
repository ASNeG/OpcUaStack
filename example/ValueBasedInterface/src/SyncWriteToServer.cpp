/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#define REAL_SERVER_URI "opc.tcp://127.0.0.1:8889"
#define REAL_SESSION_NAME "urn:127.0.0.1:ASNeG.de:ASNeG-Client"

#include "OpcUaStackClient/ValueBasedInterface/VBIClient.h"

using namespace OpcUaStackClient;

class ExampleClient
{
  public:
	VBIClient client;

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// open a secure channel to the opc ua server
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool connectToServer(void)
	{
		OpcUaStatusCode statusCode;
		ConnectContext connectContext;

		//
		// connect to the opc ua server
		//
		connectContext.endpointUrl_ = REAL_SERVER_URI;
		connectContext.sessionName_ = REAL_SESSION_NAME;
		statusCode = client.syncConnect(connectContext);
		if (statusCode != Success) {
			std::cout << std::endl << "**** connect to opc ua server error ****" << std::endl;
			return false;
		}

		std::cout << std::endl << "**** connect to opc ua server success ****" << std::endl;
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// close the secure channel to the opc ua server
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool disconnectFromServer(void)
	{
		OpcUaStatusCode statusCode;

		//
		// diconnect from the opc ua server
		//
		statusCode = client.syncDisconnect();
		if (statusCode != Success) {
			std::cout << std::endl << "**** disconnect from opc ua server error ****" << std::endl;
			return false;
		}

		std::cout << std::endl << "**** disconnect from opc ua server success ****" << std::endl;
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// write some data values to the opc ua server
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool writeToServer(void)
	{
		OpcUaDataValue dataValue;
		OpcUaStatusCode statusCode;
		OpcUaNodeId nodeId;

		boost::posix_time::ptime ptime1 = boost::posix_time::from_iso_string("20140506T102013.123456789");
		boost::posix_time::ptime ptime2 = boost::posix_time::from_iso_string("20140506T102014.123456789");
		OpcUaDateTime sourceTimestamp, serverTimestamp;

		//
		// write node 218 to namespace 1 (type Double)
		//
		nodeId.set((OpcUaInt32)218, 1);
		dataValue.variant()->set((OpcUaDouble)3.14);
		dataValue.statusCode((OpcUaStatusCode)Success);
		dataValue.sourceTimestamp(sourceTimestamp);
		dataValue.serverTimestamp(serverTimestamp);

		statusCode = client.syncWrite(nodeId, dataValue);
		if (statusCode != Success) {
			std::cout << std::endl << "**** write to opc ua server error (Double) ****" << std::endl;
			return false;
		}
		out(dataValue);

		//
		// write node 204 to namespace 1 (type Int16)
		//
		nodeId.set((OpcUaInt32)204, 1);
		dataValue.variant()->set((OpcUaInt16)66);
		dataValue.statusCode((OpcUaStatusCode)Success);
		dataValue.sourceTimestamp(sourceTimestamp);
		dataValue.serverTimestamp(serverTimestamp);

		statusCode = client.syncWrite(nodeId, dataValue);
		if (statusCode != Success) {
			std::cout << std::endl << "**** write to opc ua server error (Int16) ****" << std::endl;
			return false;
		}
		out(dataValue);


		//
		// write node 222 to namespace 1 (type String)
		//
		nodeId.set((OpcUaInt32)222, 1);
		OpcUaString::SPtr strValue = constructSPtr<OpcUaString>();
		strValue->value("Text1");
		dataValue.variant()->variant(strValue);
		dataValue.statusCode((OpcUaStatusCode)Success);
		dataValue.sourceTimestamp(sourceTimestamp);
		dataValue.serverTimestamp(serverTimestamp);

		statusCode = client.syncWrite(nodeId, dataValue);
		if (statusCode != Success) {
			std::cout << std::endl << "**** write to opc ua server error (String) ****" << std::endl;
			return false;
		}
		out(dataValue);

		std::cout << std::endl << "**** write to opc ua server success ****" << std::endl;
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// print data value to screen
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void out(OpcUaDataValue& dataValue)
	{
		std::cout << "**** ";
		dataValue.out(std::cout);
		std::cout << " ****" << std::endl;
	}
};


int main(int argc, char**argv)
{
	ExampleClient client;

	// connect to the opc ua server
	if (!client.connectToServer()) return 0;

	// write data to opc ua server
	if (!client.writeToServer()) return 0;

	// disconnect from the opc ua server
	if (!client.disconnectFromServer()) return 0;

	return 1;
}

