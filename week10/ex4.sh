rm -rf tmp
mkdir tmp
touch tmp/file1
touch tmp/file2
ln tmp/file1 tmp/link1
gcc ex4.c -o ex4
./ex4 > ex4.txt
