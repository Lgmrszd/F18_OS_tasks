touch ../week01/file.txt
link ../week01/file.txt _ex2.txt > ex2.txt
inode=`ls -i _ex2.txt | cut -f1 -d" "`
find ../ -inum $inode >> ex2.txt
find ../ -inum $inode -exec rm {} \; >> ex2.txt
