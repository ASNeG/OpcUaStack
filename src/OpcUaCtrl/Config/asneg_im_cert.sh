
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
#
# create intermediate certificate 
#
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------

# cleanup
rm -rf asneg_im_key.pem
rm -rf asneg_im_req.pem
rm -rf asneg_im_cert.pem
rm -rf index.txt

touch index.txt
export OPENSSL_CONF=${HOME}/.ASNeG/etc/OpcUaStack4/ssl/openssl.cnf

# create csr
echo "create csr request"
openssl req -new \
        -nodes \
        -days 3650 \
        -subj '/DC=127.0.0.1/CN=ASNeG IM/O=ASNeG/C=DE/ST=Neukirchen/L=Hessen/OU=ASNeG IM' \
        -keyout asneg_im_key.pem \
        -out asneg_im_req.pem

# create intermediate certificate
echo "create intermediate certificate"
openssl ca \
        -policy policy_anything \
        -days 3650 \
        -keyfile asneg_ca_key.pem \
        -extensions v3_ca \
        -cert asneg_ca_cert.pem \
        -out asneg_im_cert.pem \
        -infiles asneg_im_req.pem

# show intermediate certificate
echo "show intermediate certificate"
openssl x509 -in ./asneg_im_cert.pem -text
