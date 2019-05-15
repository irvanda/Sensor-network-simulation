#!/bin/bash

cp $1 process/tmp1
cp $2 process/tmp2

clear
for i in {0..9}
do
awk -F";" -v iter="$i" '$1 == iter {print $6}' process/tmp1 > process/tmp3
uniq process/tmp3 > process/tmp3_uniq
r=`cat process/tmp3_uniq |wc -l`
echo $i ";" $r >>process/tmp4
done

for i in {0..9}
do
r=`awk -F";" -v iter="$i" '$1 == iter {print $2}' process/tmp4`
g=`awk -F";" -v iter="$i" '$1 == iter {print $2}' process/tmp2`
h=`awk -F";" -v iter="$i" '$1 == iter {print $3}' process/tmp2`
echo $i";"$g";"$r";"$h >> process/tmp5
done

mv process/tmp5 result
rm process/tmp*
