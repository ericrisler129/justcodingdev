#!/bin/bash
mkdir /mnt/files || true
# TODO: Use EB Environmental variables to handle multiple environments
mountpoint -q /mnt/files || mount nfs.blrdata.com:/mnt/var/production/justcoding.com /mnt/files
test -L /var/www/html/sites/justcoding.com/files || (rm -rf /var/www/html/sites/justcoding.com/files && ln -s -T /mnt/files/public /var/www/html/sites/justcoding.com/files)
test -L /var/www/html/sites/justcoding.com/private || (rm -rf /var/www/html/sites/justcoding.com/private && ln -s -T /mnt/files/private /var/www/html/sites/justcoding.com/private)
