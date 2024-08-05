#!/bin/bash

read -p "Enter a string: " str

if [ "$(echo $str | rev)" == "$str" ]; then
    echo "The string '$str' is a palindrome."
else
    echo "The string '$str' is not a palindrome."
fi
