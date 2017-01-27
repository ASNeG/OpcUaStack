#!/bin/bash
#
# list of possible environment variables
#   - OPENSSL_VERSION_MAJOR
#   - OPENSSL_VERSION_MINOR
#   - OPENSSL_VERSION_PATCH
#   - BOOST_VERSION_MAJOR
#   - BOOST_VERSION_MINOR
#

OPENSSL_VERSION_MAJOR_=${OPENSSL_VERSION_MAJOR:-1}
OPENSSL_VERSION_MINOR_=${OPENSSL_VERSION_MINOR:-0}
OPENSSL_VERSION_PATCH_=${OPENSSL_VERSION_PATCH:-0}

BOOST_VERSION_MAJOR_=${BOOST_VERSION_MAJOR:-1}
BOOST_VERSION_MINOR_=${BOOST_VERSION_MINOR:-54}

VERSION_OPENSSL=${OPENSSL_VERSION_MAJOR}.${OPENSSL_VERSION_MINOR_}.${OPENSSL_VERSION_PATCH_}
VERSION_BOOST=${BOOST_VERSION_MAJOR_}.${BOOST_VERSION_MINOR_}.0

apt-get install libboost-test
apt-get install libboost-system${VERSION_BOOST}-dev
apt-get install libboost-filesystem${VERSION_BOOST}-dev
apt-get install libboost-thread${VERSION_BOOST}-dev
apt-get install libboost-date-time${VERSION_BOOST}-dev
apt-get install libboost-chrono${VERSION_BOOST}-dev
apt-get install libboost-regex${VERSION_BOOST}-dev
apt-get install libssl-dev
