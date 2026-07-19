#!/bin/bash
awk -F',' '{print $1 " gross pay: $" $3*$4}' employees.txt
