#!/bin/sh
docker run -v "$PWD"/jenkins/.ssh:/home/jenkins-slave/.ssh:ro --name slaveJava --rm --network ci_default -d heliostech/jenkins-slave-java -master http://jenkins:8080/ -username root -password "Azerty123" -executors 2 -labels "linux java"

