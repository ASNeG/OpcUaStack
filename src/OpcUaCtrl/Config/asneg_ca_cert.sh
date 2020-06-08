
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# create ca certificate 
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------

# cleanup 
rm -rf asneg_ca_key.pem
rm -rf asneg_ca_req.pem
rm -rf asneg_ca_cert.pem
rm -rf index.txt

touch index.txt
export OPENSSL_CONF=${HOME}/.ASNeG/etc/OpcUaStack4/ssl/openssl.cnf

# create a csr
echo "create csr request"
openssl req -new \
        -nodes \
        -subj '/DC=127.0.0.1/CN=ASNeG CA/O=ASNeG/C=DE/ST=Neukirchen/L=Hessen/OU=ASNeG CA' \
        -keyout asneg_ca_key.pem \
        -out asneg_ca_req.pem

# create ca certificate
echo "create ca certificate"
openssl ca -create_serial \
        -out ./asneg_ca_cert.pem -days 3650 -batch \
        -keyfile asneg_ca_key.pem -selfsign \
        -extensions v3_ca \
        -infiles asneg_ca_req.pem

# show ca
echo "show ca certificate"
openssl x509 -in ./asneg_ca_cert.pem -text
