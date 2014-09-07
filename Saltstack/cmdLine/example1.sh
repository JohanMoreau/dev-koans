# from master to specific minion
sudo salt serveur.example.com cmd.run reboot
sudo salt -G 'os:debian' cmd.run apt-get update
# from master to multiples minion
sudo salt 'serveur(01|02).example.com' state.sls apache
sudo salt --grain-pcre 'os:(debian|ubuntu)' state.highstate
# from minion
sudo salt-call -l debug state.highstate
