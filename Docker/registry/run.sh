#!/bin/sh
echo 'DOCKER\_OPTS="--insecure-registry 127.0.0.1:5000"' >> /etc/docker/docker
docker run -d -p 5000:5000 --name registry v $(pwd)/registry-data:/var/lib/registry registry:2
docker tag hello-world 127.0.0.1:5000/hello-world
docker push 127.0.0.1:5000/hello-world
