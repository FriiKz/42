#!/bin/bash
git status --ignored --porcelain=v1 | grep ! | cut -f 2 -d ' '
