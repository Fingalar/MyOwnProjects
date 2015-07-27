#!/bin/sh
make -C ..
gcc -o test0 test0.c -g
echo "TEST 0 sans lib"
/usr/bin/time -l ./test0
gcc -o test1 test1.c -g
echo "TEST 1 sans lib"
/usr/bin/time -l ./test1
gcc -o test2 test2.c -g
gcc -o test3 test3.c -g
gcc -o test3++ test3++.c -g
gcc -o test_error test_error.c -g
gcc -o test_show_alloc test_show_alloc.c -L.. -lft_malloc -g
export DYLD_LIBRARY_PATH='..'
export DYLD_INSERT_LIBRARIES='../libft_malloc.so'
export DYLD_FORCE_FLAT_NAMESPACE='1'
echo "TEST 0 avec lib"
/usr/bin/time -l ./test0
echo "TEST 1 avec lib"
/usr/bin/time -l ./test1
echo "TEST 2 avec lib"
/usr/bin/time -l ./test2
echo "TEST 3 avec lib"
./test3
echo "TEST 3++ avec lib"
./test3++
echo "TEST 4 avec lib"
./test_error
echo "TEST 5 avec lib"
./test_show_alloc
./delete.sh
