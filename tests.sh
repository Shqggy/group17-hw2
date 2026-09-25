#!/usr/bin/env bash

# CALCULATION TESTS
echo -e "TEST 1 (loan=1000, rate=12, payment=50)\n"
./main 1000 18 50
echo "EXPECTED OUTPUT: 24 month(s) and \$197.83 paid in interest"
echo -e "\n=================================================================\n"

echo -e "TEST 2 (loan=2000, rate=18, payment=80)\n"
./main 2000 18 80
echo "EXPECTED OUTPUT: 29 month(s) and \$312.98 paid in interest"
echo -e "\n=================================================================\n"

echo -e "TEST 3 (loan=1000, rate=12, payment=11)\n"
./main 1000 12 11
echo "EXPECTED OUTPUT: 241 month(s) and \$1650.85 paid in interest"
echo -e "\n=================================================================\n"

echo -e "TEST 4 (loan=1000, rate=12, payment=1010)\n"
./main 1000 12 1010
echo "EXPECTED OUTPUT: 1 month(s) and \$10.00 paid in interest"
echo -e "\n=================================================================\n"

echo -e "TEST 5 (loan=1000, rate=50, payment=2000)\n"
./main 1000 50 2000
echo "EXPECTED OUTPUT: 1 month(s) and \$41.67 paid in interest"
echo -e "\n=================================================================\n"

echo -e "TEST 6 (loan=1000, rate=12, payment=50)\n"
./main 1000 0 10
echo "EXPECTED OUTPUT: 100 month(s) and \$0.00 paid in interest"
echo -e "\n=================================================================\n"

# ERROR TESTS:

echo -e "TEST 7 (loan=2000, rate=50, payment=50)\n"
./main 2000 50 80
echo "EXPECTED OUTPUT: error, insufficient payment"
echo -e "\n=================================================================\n"

echo -e "TEST 8 (loan=1000, rate=12, payment=10)\n"
./main 1000 12 10
echo "EXPECTED OUTPUT: error, insufficient payment"
echo -e "\n=================================================================\n"

echo -e "TEST 9 (loan=-1000)\n"
./main -1000 12 50
echo "EXPECTED OUTPUT: error, invalid loan"
echo -e "\n=================================================================\n"

echo -e "TEST 10 (loan=abc)\n"
./main abc 12 50
echo "EXPECTED OUTPUT: error, invalid loan"
echo -e "\n=================================================================\n"

echo -e "TEST 11 (rate=-18)\n"
./main 1000 -18 50
echo "EXPECTED OUTPUT: error, invalid interest rate"
echo -e "\n=================================================================\n"

echo -e "TEST 12 (rate=abc)\n"
./main 1000 abc 50
echo "EXPECTED OUTPUT: error, invalid interest rate"
echo -e "\n=================================================================\n"

echo -e "TEST 13 (payment=-50)\n"
./main 1000 12 -50
echo "EXPECTED OUTPUT: error, invalid payment"
echo -e "\n=================================================================\n"

echo -e "TEST 14 (payment=abc)\n"
./main 1000 12 abc
echo "EXPECTED OUTPUT: error, invalid payment"
echo -e "\n=================================================================\n"
