#!/bin/bash

ls -l | cut -c38-42 > /tmp/filesize.txt
ls -l | cut -c57- > /tmp/filename.txt
paste /tmp/filename.txt /tmp/filesize.txt
