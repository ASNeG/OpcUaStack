Certificate Validate
===========================

Certificate Exchange
---------------------

When the OPC UA client opens a connection to the OPC UA server, the OPC UA
client sends its certificates to the OPC UA server and the OPC UA server 
sends its certificates to the OPC UA client. Depends on application, only
one certificate or an entire certificate chain is transferred to the
communication partner.

The following constellations are possible:

- A self signed certificate 
- A application certificate
- A application certificate and a CA certificate 
- A application certificate and one or more intermediate certificates
- A application certificate, one or more intermediate certificates and a 
  CA certificate

If the self signed certificate or the application certificate is unknown
on the receiver, this received self signed certificate or the applcation
certificate is saved in the Reject folder and marked as Untrusted. 

Validate Certificate Chain
---------------------------

The recipient of a certificate or certificate chain performs the 
following tests.

- If a received certificate chain is incomplete, the missing certificates 
  are searched for in the recipient's cert store.
- The signatures in the Cert chain are checked.
- At least one certificate in the certificate chain must be trusted.
- No certificate in the certificate chain can be untrusted.
- Check application certificate (Subject, Issuer, Time, ...)
