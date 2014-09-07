docker_nodejs_image:
  docker.pulled:
    - name: dockerfile/nodejs
    - tag: latest
    - force: True
    - require:
      - service: mydocker
docker_nodejs_container:
  docker.installed:
    - name: mynodejs
    - hostname: mynodejs
    - image: dockerfile/nodejs
    - command: /data/test.sh
    - detach: False
    - require:
      - docker: docker_nodejs_image
docker_nodejs_running:
...
