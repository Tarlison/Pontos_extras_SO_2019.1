#!/bin/bash

# Meu comentário

echo "Data e hora do sistema:"
date

echo "" #Somente para pular a linha

echo "Frase aleátoria:"
shuf -n 1 arq.txt #escolhe uma quantidade n de linhas para serem lidas de um arquivo

echo "" #Somente para pular a linha

echo "Espaço disponível e usado no HD:"
df -h -l /

echo "" #Somente para pular a linha

echo "Memória RAM:"
free -h --giga

echo "" #Somente para pular a linha

echo "Arquivos no diretório Downloads"
cd Downloads/
ls





#QUANTIDADE DE MUSICAS OU ARQUIVOS??
#DE VIDEOS ?
#DE IMAGENS" ?


save_ls=`ls -alh`

