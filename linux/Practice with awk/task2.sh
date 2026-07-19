#!/bin/bash
awk -F',' '$2 == "Engineering" {print $0}' employees.txt
