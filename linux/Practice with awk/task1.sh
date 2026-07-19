#!/bin/bash
awk -F',' '{print $1, $2}' employees.txt
