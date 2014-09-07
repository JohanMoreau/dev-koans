apache2: # Id, using like main parameter for this state
  pkg:
    - installed # state to call : this pack must be installed
  service:
    - running # check if running
    - watch: # reload if change
      - file: /etc/apache2/httpd.conf
/etc/apache2/httpd.conf:
  file.managed:
    - source: salt://apache/httpd.conf # find the file on salt master
    - user: root
    - group: root
    - mode: 644
    - require:
      - pkg: apache2 # update this file only if apach2 is installed
