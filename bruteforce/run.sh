#!/bin/bash

#TODO Testcase have to be loaded from file
declare TESTCASE="2
12 6 6 6 6 6 12 12 12 12 12 12 12 12 12 12
12 9 3 12 6 6 9 3 12 9 12 9 12 12 6 6
"

usage() {
echo "  -c file : compile
  -r file : run file with TESTCASE
  -a file : compile and run
  ex)$0 -a boardcover.cpp : compile boardcover.cpp and excute with TESTCASE" 1>&2;
  exit 0;
}

while getopts ":c:r:a:" opt; do
  case $opt in
    c)
      echo "Compile $OPTARG"
      g++ -g -o a.out $OPTARG
      ;;
    r)
      echo "Run $OPTARG with $TESTCASE"
      echo "---------------------------------------"
      echo $TESTCASE | ./$OPTARG
      ;;
    a)
      echo "Compile $OPTARG"
      g++ -o $OPTARG.tmp $OPTARG
      echo "Run $OPTARG with $TESTCASE"
      echo "---------------------------------------"
      echo $TESTCASE | ./$OPTARG.tmp
      echo
      rm $OPTARG.tmp
      ;;
    :)
      echo "Option -$OPTARG requires an argument."
      ;;
    *)
      usage
  esac
done
