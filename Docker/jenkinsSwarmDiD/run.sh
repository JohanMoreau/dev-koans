#!/bin/sh
docker run -v /tmp:/var/lib/docker -v /tmp:/workspace -v /var/run/docker.sock:/var/run/docker.sock -v "$PWD"/jenkins/.ssh:/home/jenkins-slave/.ssh:ro --name slaveDocker --rm --network ci_default -d -e "COMMAND_OPTIONS=-master http://jenkins:8080/ -username root -password Azerty123 -executors 2 -labels docker" vfarcic/jenkins-swarm-agent
