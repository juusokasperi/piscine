#! /bin/bash
cat /etc/passwd | sed '/^#/d' | sed -n '1d;p;n' | cut -d : -f 1 | rev | sort -r | sed -n "$FT_LINE1"','"$FT_LINE2"'p' | sed ':a;N;$!ba;s/\n/\, /g' | sed '$s/$/./'
