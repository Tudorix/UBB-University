#!/bin/bash
content=""
for P in `cat $1`; do
	content="$content,$P.@scs.ubbcluj.ro"
done

echo $content
