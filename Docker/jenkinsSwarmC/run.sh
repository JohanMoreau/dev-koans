#!/bin/sh
docker run -v "$PWD"/jenkins/.ssh:/home/jenkins-slave/.ssh:ro --name slaveC --rm --network ci_default -d heliostech/jenkins-slave-gcc:centos-7 -master http://jenkins:8080/ -username root -password "Azerty123" -executors 2 -labels "linux centos-7-gcc"

