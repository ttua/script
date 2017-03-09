#!/bin/bash

 lastb | tac | sed '1,2d' | awk '{a[$3]+=1;}END{for(i in a){print "sshd: ",i;}}' >>  /etc/hosts.deny
 echo " " > /var/log/btmp
