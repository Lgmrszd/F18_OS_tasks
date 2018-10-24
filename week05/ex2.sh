#!/bin/bash

# Executing just "./ex2.sh" gives "501" as last line
# Executing ./ex2.sh & ./ex2.sh gives "1001"

FILE="ex2.txt"
FILELOCK=$FILE.lock
# rm $FILE.lock

# echo '1' > $FILE

N=500
while [ $N -gt 0 ]
do
    if $(ln $FILE $FILELOCK 2> /dev/null); then
        echo $(($(tail -n 1 $FILE) + 1)) >> $FILE
        rm $FILELOCK
        N=$(($N-1))
    fi
done

