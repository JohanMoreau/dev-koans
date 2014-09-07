docker_repo:
    pkgrepo.managed:
      - repo: 'deb http://get.docker.io/ubuntu docker main'
      - file: /etc/apt/sources.list.d/docker.list
      - keyid: 36A1D7869245C8950F966E92D8576A8BA88D21E9
      - keyserver: keyserver.ubuntu.com
      - require_in:
          - pkg: mydocker
mydocker:
    pkg:
        - installed
        - name: lxc-docker
    service:
        - running
        - name: docker
        - require:
           - pkg : mydocker
           - pip : docker-python-dockerpy
