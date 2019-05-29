#!/bin/bash
#Script

echo "Data de hoje"
date
echo ""

echo "Frase"
shuf -n 1 arq.txt
echo ""


echo "Memoria RAM"
free -h --giga
echo ""


echo "Memoria disponivel HD Ubuntu"
df -h -l /
echo ""

echo "Arquivos da pasta Downloads"
cd
cd Downloads
ls
echo ""

echo "Quantidade de musicas do usuário"
cd
cd Música
ls -la|grep -e "^-"|wc -l
echo ""

echo "Quantidade de vídeos do usuário"
cd
cd Vídeos
ls -la|grep -e "^-"|wc -l
echo ""

echo "Quantidade de imagens do usuário"
cd
cd Imagens
ls -la|grep -e "^-"|wc -l
