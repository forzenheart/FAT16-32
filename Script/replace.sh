#!/bin/bash -
#iterate through all the files in a directory

#替换该文件下面的所有文件
sedfile=fix.sed
for file in *.cpp *.h
do
	if [ -f "$file" ]
	then
		echo "replace data in $file"
		sed -f $sedfile $file > "$file.bk"
		#移除已经被替换的源文件
		rm -v $file
	fi
done

#将已经替换好的文件重命名为原来的名字
for replacefile in *.bk
do
	cp -nv $replacefile ${replacefile%.bk} 
	rm -v $replacefile
done
