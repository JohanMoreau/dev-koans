#!/bin/bash
docker run -d -P --name my-apache-php-app \
	   -v "$PWD":/var/www/html php:7.0-apache
