#!/bin/bash
if ! command -v wkhtmltopdf &> /dev/null
then
  wget https://github.com/wkhtmltopdf/packaging/releases/download/0.12.6-1/wkhtmltox-0.12.6-1.amazonlinux2.x86_64.rpm
  yum install -y wkhtmltox-0.12.6-1.amazonlinux2.x86_64.rpm
fi
