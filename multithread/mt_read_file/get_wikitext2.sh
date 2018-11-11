#!/bin/bash

echo "Fetch the wikitext-2 dataset, 4.3M zip file, 13M unzip file"

if [ ! -e wiki2.txt ]; then
  wget https://s3.amazonaws.com/research.metamind.io/wikitext/wikitext-2-v1.zip
  unzip wikitext-2-v1.zip
  cat wikitext-2/wiki.* > wiki2.txt
  rm -rf wikitext-2
fi
