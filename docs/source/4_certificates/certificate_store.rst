Certificate Store
===========================

The OPC UA endpoint saves its own certificate and the certificates of its
communication partners in a certificate store. The following table provides
an overview of the directories in the filesystem that are used for the 
certificate store.

+-----------------------------+---------------------------------------+----------------------------------------+
|                             | Trusted                               | Untrusted                              |
+=============================+=======================================+========================================+
| **Certificate**             | CertificateTrustListLocation          | CertificateRevocationListLocation      |
|                             |                                       | CertificateRejectListLocation          |
+-----------------------------+---------------------------------------+----------------------------------------+
| **Issuer Certificate**      | IssuerCertificatesLocation            | IssuerRevocationListLocation           |
+-----------------------------+---------------------------------------+----------------------------------------+
| **CA Root Certificates**    | CertificateTrustListLocation          | CertificateRevocationListLocation      |
+-----------------------------+---------------------------------------+----------------------------------------+

The directories specified in the table are defined in the OPC UA servers's
configuration file. 

- **CertificateTrustListLocation:** This directory contains the trusted CA root certificates and the trusted 
  application certificates of the communication partners.
- **CertificateRevocationListLocation:** This directory contains the untrusted CA root certificates and the
  untrusted application certificates of the communication partners.
- **CertificateRejectListLocation:**
  This directory contains the rejected application certificates of the communication partners. 
- **IssuerCertificatesLocation:**
  This directory contains the trusted intermediate certificates.
- **IssuerRevocationListLocation:**
  This directory contains the untrusted intermediate certificates.
