# GS_01_ECCS
Repositório conténdo o código fonte e explicação do projeto feito para a matéria de Edge Computing And Computer Systems.

## Problema
As enchentes são um problema recorrente no Brasil, com mais de 21 mil casos só entre 1991 e 2022. Esse problema que se não levado a sério tira moradias e vidas de milhares de pessoas.

A falta de cuidado e aviso sobre esse desastre pode pegar muitas pessoas desprevinidas, como ocorreu na enchente dentro do metrô Jardim São Paulo, na linha 1-Azul, que foi tomada pela água graças as chuvas intensas.

Muitas pessoas são pegas desprevinidas pela falta de aviso ou até mesmo pela falta de preocupação com o problema, levando elas a serem pegas de surpresa pelas enchentes, e em casos graves perdem suas moradias, bens preciosos ou até mesmo pior.

## A Solução 
<p>Para solucionar isso, nós montamos um dispositivo com o Arduino, que pegaria informações como Temperatura, Humidade e nível de água de ruas e lugares com perigo de enchente.</p>
<img src = "Images/SistemaArduino.png" alt = "Imagem do sistema arduino no simulador" style ="width: 500px;"></img>
<p>Utilizando um sensor de temperatura e umidade para pegar informações de risco de chuvas fortes, um sensor de distância ou um sensor de níve de água para medir possíveis enchentes.</p>

<p>Nesse mesmo sistema ativaria um alarme de som para avisar níveis de enchetes perigosas e mandaria tais informações para um banco de dados que alimentaria um site que avisaria ruas com risco ou já sendo afetadas por enchentes além do alarme sonoro que avisaria pessoas próximas sobre o perigo.</p>

## Guia para simular o projeto no Wokwi
<img src = "Images/Distancia.gif" alt = "Gif demostração de manipulação de distância no Simulador" style ="width: 500px;"></img>
<p>Após iniciar o simulador é possível ao clicar no sensor de distância e alterar o valor que está sendo devolvido por ele para testar a detecção da profundidade dá água. O sensor de distância seria substituído por um sensor de nível de água no arduino físico.</p>

<img src = "Images/TemperaturaEUmidade.gif" alt = "Gif demostração de manipulação de temperatura e umidade no Simulador" style ="width: 500px;"></img>
<p>Clicando no sensor de Temperatura e Umidade é possível alterar os valores retornados que seriam mandados para o banco de dados.</p>

## <a href = "https://wokwi.com/projects/432412556734678017">Simulador</a>

## <a href = "https://www.youtube.com/watch?v=FG0d37alZdI&ab_channel=NTK">Vídeo demonstrativo</a>