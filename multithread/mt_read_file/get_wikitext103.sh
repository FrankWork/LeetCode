#!/bin/bash

echo "Fetch the wikitext-103 dataset, 182M zip file, 517M unzip file"

if [ ! -e wiki103.txt ]; then
  wget https://s3.amazonaws.com/research.metamind.io/wikitext/wikitext-103-v1.zip
  unzip wikitext-103-v1.zip
  cat wikitext-103/wiki.* > wiki103.txt
  rm -rf wikitext-103
fi
