#!/bin/bash

x=$(nmap -sP $*/24 | grep --color=auto -E -o '([0-9]{1,3}[\.]){3}[0-9]{1,3}' )

echo start:
echo $x
echo ..............................................................................

for i in $x; do
	nmap -A $i > $i.txt
	echo $i--It\'s OK!
	echo ..............................................................................
done
echo Over!

