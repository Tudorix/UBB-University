```
1. Given a separator character (by default it is space), treats the input text as a table, with each line being a row, and the
fields of each row the tokens of the line, as determined by the separator.
2. Processes the input based on a program written in a simple C-like language
3. A program is a sequence of instruction blocks, prefixed by an optional selector
4. Each block in the program is applied to every line of input matching its selector. If the block does not have a selector, it
is applied to every line of input
5. A selector is any valid conditional expression, or one of the following two special selectors
a. BEGIN - the block associated with this selector is executed before any input has been processed
b. END - the block associated with this selector is executed after all input has been processed
6. Special variables
a. NR - number of the current line of input
b. NF - the number of fields on the current line
c. $0 - the entire input line
d. $1, $2, ... - the fields of the current line
7. The AWK program can be written in a file, or provided directly on the command line between apostrophes
   
awk -F: '{print $5}' /etc/passwd

awk -F: '{print $5; print $1}' /etc/passwd

awk -F: -f prog.awk /etc/passwd

awk -F: 'NR%2==1 {print $5} NR%2==0 {print $1}' /etc/passwd

awk -F: '/regex^Cprint $6}' /etc/passwd - da match la regex

$NF - ultimul field

awk -F: '$NF ~ /nologin$/  {print $1}' /etc/passwd

awk -F: 'length($1)>10 {print $5}' /etc/passwd

	NR - indexare de la 1
```