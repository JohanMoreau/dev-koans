snmpd.conf:
  file:
    - name: /etc/snmp/snmpd.conf
    - source: salt://nux/snmp/files/snmpd.conf
    - template: jinja
    - context: snmpcom: {{ pillar.get('snmpcom', 'public') }}
