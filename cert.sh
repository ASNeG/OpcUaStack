#!/bin/bash

#
# init 
#
rm -rf demoCA 
mkdir -p ./demoCA
mkdir -p ./demoCA/newcerts
mkdir -p ./demoCA/certs
mkdir -p ./demoCA/crl
touch ./demoCA/index.txt
echo "1000" >> ./demoCA/serial



echo "================================================================"
echo "================================================================"
echo "==="
echo "=== create ca certificate"
echo "==="
echo "================================================================"
echo "================================================================"
rm -rf ca_key.pem
rm -rf ca_req.pem
rm -rf ca_cert.pem
rm -rf ca_cert.der

# create a csr
openssl req -new \
	-nodes \
	-subj '/DC=127.0.0.1/CN=ASNeG CA/O=ASNeG/C=DE/ST=Neukirchen/L=Hessen/OU=ASNeG CA' \
	-keyout ca_key.pem \
	-out ca_req.pem

# create ca
openssl ca -create_serial \
        -out ./ca_cert.pem -days 3650 -batch \
        -keyfile ca_key.pem -selfsign \
        -extensions v3_ca \
        -infiles ca_req.pem 

# change format
openssl x509 -inform pem -in ./ca_cert.pem -outform der -out ./ca_cert.der

# show ca
openssl x509 -in ./ca_cert.pem -text



echo "================================================================"
echo "================================================================"
echo "==="
echo "=== create client certificate"
echo "==="
echo "================================================================"
echo "================================================================"
rm -rf client_key.pem
rm -rf client_req.pem
rm -rf client_cert.pem
rm -rf client_cert.der
rm -rf client.cfg

ext=subjectAltName="URI:urn:127.0.0.1:ASNeG:ASNeG Client, IP:127.0.0.1, DNS:devel, email:kai@huebl-sgh.de\n"
ext=${ext}"keyUsage = digitalSignature, nonRepudiation, keyEncipherment, dataEncipherment, keyCertSign\n"
ext=${ext}"extendedKeyUsage = serverAuth, clientAuth"
cat /etc/ssl/openssl.cnf > client.cfg
sed -i 's/\[ usr_cert \]/\[ usr_cert \]\n'"$ext"'\n/' client.cfg

#
# create a csr
export OPENSSL_CONF=client.cfg
openssl req -new \
        -nodes \
        -days 3650 \
	-subj '/DC=127.0.0.1/CN=ASNeG Client/O=ASNeG/C=DE/ST=Neukirchen/L=Hessen/OU=ASNeG Software' \
	-keyout client_key.pem \
	-out client_req.pem

# sign csr
openssl ca \
	-policy policy_anything \
        -days 3650 \
 	-keyfile ca_key.pem \
        -cert ca_cert.pem \
        -out client_cert.pem \
	-infiles client_req.pem 

# change format
openssl x509 -inform pem -in ./client_cert.pem -outform der -out ./client_cert.der
	
# show certificate
openssl x509 -in ./client_cert.pem -text



echo "================================================================"
echo "================================================================"
echo "==="
echo "=== create server certificate"
echo "==="
echo "================================================================"
echo "================================================================"
rm -rf server_key.pem
rm -rf server_req.pem
rm -rf server_cert.pem
rm -rf server_cert.der
rm -rf server.cfg

ext=subjectAltName="URI:urn:127.0.0.1:ASNeG:ASNeG Server, IP:127.0.0.1, DNS:devel, email:kai@huebl-sgh.de\n"
ext=${ext}"keyUsage = digitalSignature, nonRepudiation, keyEncipherment, dataEncipherment, keyCertSign\n"
ext=${ext}"extendedKeyUsage = serverAuth, clientAuth"
cat /etc/ssl/openssl.cnf > server.cfg
sed -i 's/\[ usr_cert \]/\[ usr_cert \]\n'"$ext"'\n/' server.cfg


#
# create a csr
export OPENSSL_CONF=server.cfg
openssl req -new \
	-nodes \
        -days 3650 \
	-subj '/DC=127.0.0.1/CN=ASNeG Server/O=ASNeG/C=DE/ST=Neukirchen/L=Hessen/OU=ASNeG Software' \
	-keyout  server_key.pem \
	-out server_req.pem

# sign csr
openssl ca \
	-policy policy_anything \
        -days 3650 \
 	-keyfile ca_key.pem \
        -cert ca_cert.pem \
        -out server_cert.pem \
	-infiles server_req.pem 

# change format
openssl x509 -inform pem -in ./server_cert.pem -outform der -out ./server_cert.der
	
# show certificate
openssl x509 -in ./server_cert.pem -text



echo "================================================================"
echo "================================================================"
echo "==="
echo "=== install client certificate"
echo "==="
echo "================================================================"
echo "================================================================"
cp ./client_cert.der /home/huebl/.config/unifiedautomation/uaexpert/PKI/own/certs//uaexpert.der
cp ./client_key.pem /home/huebl/.config/unifiedautomation/uaexpert/PKI/own/private/uaexpert_key.pem
cp ./ca_cert.der /home/huebl/.config/unifiedautomation/uaexpert/PKI/issuers/certs
cp ./ca_req.pem ~/.config/unifiedautomation/uaexpert/PKI/issuers/crl/


echo "================================================================"
echo "================================================================"
echo "==="
echo "=== install server certificate"
echo "==="
echo "================================================================"
echo "================================================================"
cp ./server_cert.der /home/huebl/.ASNeG/etc/OpcUaStack/ASNeG-Demo/pki/own/certs/ASNeG-Demo.der
cp ./server_key.pem  /home/huebl/.ASNeG/etc/OpcUaStack/ASNeG-Demo/pki/own/private/ASNeG-Demo.pem
cp ./ca_cert.der /home/huebl/.ASNeG/etc/OpcUaStack/ASNeG-Demo/pki/issuers/cert
