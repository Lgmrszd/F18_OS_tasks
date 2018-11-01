gcc ex1.c -o ex1
echo "Short file test"
echo "a" > ex1.txt
./ex1
cat ex1.txt
echo "Long file test"
echo "testtesttesttesttesttesttesttesttesttest\ntesttest" > ex1.txt
./ex1
cat ex1.txt
echo "File does not exist test"
rm ex1.txt
./ex1
cat ex1.txt
rm ex1
