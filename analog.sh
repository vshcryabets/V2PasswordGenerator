#!/bin/bash

SITE=$1

echo Generating password for $SITE
echo $SITE | md5
