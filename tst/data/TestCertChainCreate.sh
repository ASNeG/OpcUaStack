#!/usr/bin/bash

###############################################################################
###############################################################################
#
# This script generates the following test certificates
#
# 1. TestCa Certificate
# 2. TestApp1 Certificate
# 3. TestIm Certificate
# 4. TestApp2 Certificate
#
# Certificate Chain
# -----------------
# TestCa <- TestApp1
# TestCa <- TestIm <- TestApp2
# 
#
###############################################################################
###############################################################################

###############################################################################
#
# init 
#
###############################################################################
export OPENSSL_CONF=${HOME}/.ASNeG/etc/OpcUaStack/ssl/openssl.cnf
touch index.txt


###############################################################################
#
# Create TestCa Certificate
#
###############################################################################
# create a csr
echo "create csr request"
openssl req -new \
        -nodes \
        -subj '/DC=127.0.0.1/CN=Test CA/O=ASNeG/C=DE/ST=Neukirchen/L=Hessen/OU=ASNeG CA' \
        -keyout test_ca_key.pem \
        -out test_ca_req.pem

# create ca certificate
echo "create test ca certificate"
openssl ca -create_serial \
	-out ./test_ca_cert.pem \
	-days 3650 -batch \
        -keyfile test_ca_key.pem -selfsign \
        -extensions v3_ca \
        -infiles test_ca_req.pem
openssl x509 -outform der -in ./test_ca_cert.pem -out ./test_ca_cert.der

# show ca
echo "show test ca certificate"
openssl x509 -inform der -inform der  -in ./test_ca_cert.der -text


###############################################################################
#
# Create TestApp1 Certificate 
#
###############################################################################
# create csr
echo "create csr request"
openssl req -new \
        -nodes \
        -days 3650 \
        -subj "/DC=127.0.0.1/CN=Test App1/O=ASNeG/C=DE/ST=Neukirchen/L=Hessen/OU=ASNeG Product" \
        -keyout test_app1_key.pem \
        -out test_app1_req.pem

# create product certificate
echo "create product certificate"
openssl ca \
        -policy policy_anything \
        -days 3650 \
	-extensions demo-extension \
        -keyfile test_ca_key.pem \
        -cert test_ca_cert.pem \
        -out test_app1_cert.pem \
        -infiles test_app1_req.pem
openssl x509 -outform der -in ./test_app1_cert.pem -out ./test_app1_cert.der

# show product certificate
echo "show product certificate"
openssl x509 -inform der -inform der -in ./test_app1_cert.der -text


###############################################################################
#
# Create Intermdiate Certificate 
#
###############################################################################
# create csr
echo "create csr request"
openssl req -new \
        -nodes \
        -days 3650 \
        -subj '/DC=127.0.0.1/CN=Test IM/O=ASNeG/C=DE/ST=Neukirchen/L=Hessen/OU=ASNeG IM' \
        -keyout test_im_key.pem \
        -out test_im_req.pem

# create intermediate certificate
echo "create intermediate certificate"
openssl ca \
        -policy policy_anything \
        -days 3650 \
        -keyfile test_ca_key.pem \
        -extensions v3_ca \
        -cert test_ca_cert.pem \
        -out test_im_cert.pem \
        -infiles test_im_req.pem
openssl x509 -outform der -in ./test_im_cert.pem -out ./test_im_cert.der

# show intermediate certificate
echo "show intermediate certificate"
openssl x509 -inform der -in ./test_im_cert.der -text


###############################################################################
#
# Create TestApp2 Certificate 
#
###############################################################################
# create csr
echo "create csr request"
openssl req -new \
        -nodes \
        -days 3650 \
        -subj "/DC=127.0.0.1/CN=Test App2/O=ASNeG/C=DE/ST=Neukirchen/L=Hessen/OU=ASNeG Product" \
        -keyout test_app2_key.pem \
        -out test_app2_req.pem

# create product certificate
echo "create product certificate"
openssl ca \
        -policy policy_anything \
        -days 3650 \
	-extensions demo-extension \
        -keyfile test_im_key.pem \
        -cert test_im_cert.pem \
        -out test_app2_cert.pem \
        -infiles test_app2_req.pem
openssl x509 -outform der -in ./test_app2_cert.pem -out ./test_app2_cert.der

# show product certificate
echo "show product certificate"
openssl x509 -inform der -inform der -in ./test_app2_cert.der -text


###############################################################################
#
# cleanup
#
###############################################################################
rm `ls -1 | grep ^[a-fA-F0-9]*.pem$`
rm index.*
rm serial
rm serial.old
rm -rf test_ca_cert.pem
rm -rf test_ca_req.pem
rm -rf test_app1_cert.pem
rm -rf test_app1_req.pem
rm -rf test_im_cert.pem
rm -rf test_im_req.pem
rm -rf test_app2_cert.pem
rm -rf test_app2_req.pem


