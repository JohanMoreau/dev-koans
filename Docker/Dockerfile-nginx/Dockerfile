FROM ubuntu:quantal
MAINTAINER johan moreau johan.moreau+docker@gmail.com
RUN echo "deb http://fr.archive.ubuntu.com/ubuntu quantal main " \
          > /etc/apt/sources.list
RUN apt-get update
RUN apt-get install -y nginx
ENTRYPOINT ["nginx"]
EXPOSE 80
