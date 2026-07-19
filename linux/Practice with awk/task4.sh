#!/bin/bash
awk -F',' '{print NR " (" NF " fields): " $0}' employees.txt
