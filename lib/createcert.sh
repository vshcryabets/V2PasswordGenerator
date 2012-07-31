#!/bin/bash

openssl genrsa -des3 -out private.pem 2048
openssl rsa -in private.pem -out public.pem -outform PEM -pubout
