#!/bin/sh
cat /etc/passwd | grep -v "#" | sed -n "n;p" | cut -d":" -f1 | rev | sort -r | awk "FNR>=$FT_LINE1 && FNR<=$FT_LINE2" | sed "s/$/, /g" | tr -d "\n" | sed "s/, $/./g" | tr -d "\n"
