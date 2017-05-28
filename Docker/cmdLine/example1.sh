sudo /usr/bin/docker -d & # run the daemon
sudo docker search ubuntu # give ubuntu images from public index (official/trusted)
sudo docker pull stackbrew/ubuntu # pull latest stackbrew/ubuntu images
sudo docker history stackbrew/ubuntu # view history for this images
sudo docker images # show local images
sudo docker run -i -t stackbrew/ubuntu /bin/bash # run this images / create container
sudo docker run -t -i -link redis:db -name webapp ubuntu bash # link 2 containers
sudo docker ps # show active containers (-a to show all containers)
sudo docker logs myUbuntu
sudo docker attach myUbuntu # retake the hand on the container
sudo docker run -d -p 8888:80 ubuntu # export 8888 on master
sudo docker stop # SIGTERM suivi d'un SIGKILL
sudo docker kill # SIGKILL directement

