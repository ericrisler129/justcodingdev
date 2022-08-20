#!/bin/bash
echo 'upload_max_filesize = 9M' > /etc/php.d/99uploadsize.ini
echo 'post_max_size = 9M' >> /etc/php.d/99uploadsize.ini
chmod 644 /etc/php.d/99uploadsize.ini
service php-fpm restart
