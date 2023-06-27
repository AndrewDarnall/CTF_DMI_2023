#!/bin/bash

gcc -Wall -fno-stack-protector -o /home/Login /home/auth.c 2> /dev/null
chmod u=+s /home/Login