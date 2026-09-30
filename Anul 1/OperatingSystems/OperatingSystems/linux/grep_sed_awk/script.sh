#!/bin/bash

sed '1 i DATE DESPRE PERSONAL' angajati.txt | \
sed '/49$/d' | \
sed '$ i TERMINAT' | \
