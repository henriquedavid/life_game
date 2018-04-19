# Conway's Life Game Simulator - Visual Edition
### DESCONSIDERAR ESTE BRANCH (sfml_version) PARA CASOS DE AVALIAÇÃO.
### A versão desse código pode conter erros, para uma melhor análise consultar o branch [master](https://github.com/henriquedavidufrn/life_game/tree/master)!


Desenvolvedores:
- Henrique David de Medeiros (henriquemed101@gmail.com)
- Pablo Emanuell L. Targino (pabloemanuell@academico.ufrn.br)

Instruções de Compilação:
	
- Na pasta src, da pasta life_game, pelo terminal execute o seguinte código:
*g++ -Wall -std=c++11 life.cpp main.cpp button.cpp quadboard.cpp -o exec*
ou
- No terminal execute: <br>*make*.

Instruções de Execução:

- Na pasta src:
*./exec arqEntrada arqSaida*

ou

- Na pasta raiz execute:<br>*./bin/release/exec data/arqEntrada arqSaida*
Exemplo:
*./bin/release/exec data/cfg1.dat out_cfg1.dat*

**Modelos de arquivos de entradas estão na pasta *data/*.**

O trabalho está dividindo em dois tipo:
- execução no terminal, pasta life_game; e
- execução visual, pasta life_game_sfml.


Acesso pelo GitHub:
- Organização dos dados em branches diferentes.
- Branch master -> Jogo completo e funcional, sem erros.
- Branch sfml_version -> Versão visual, pode conter alguns erros.

Os arquivos na visualização gráfica (sfml) são uma cópia dos arquivos do life_game/master(branch), porém com a adição da biblioteca SFML. **Para avaliação considerar apenas a versão life_game/master(branch).**
