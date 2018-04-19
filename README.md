# Conway's Life Game Simulator

Desenvolvedores:
- Henrique David de Medeiros
- Pablo Emanuell L. Targino

Instruções de Compilação:
	
- Na pasta src, da pasta life_game, execute o seguinte código:<br>
"g++ -Wall -std=c++11 Life.cpp main.cpp -o exec"

ou 

- Abra a pasta principal (life_game) no terminal e execute "make", o executável aparecerá em uma pasta bin.

Instruções de Execução:

- Na pasta do executável:<br>
"./exec arqEntrada arqSaida_opcional"

ou

- Caso o executável foi gerado pelo make, na pasta principal execute <br> "./bin/exec arqEntrada arqSaida_opcional"


O trabalho está dividindo em dois tipo:
- execução no terminal, pasta life_game; e
- execução visual, pasta life_game_sfml.


Acesso pelo GitHub:
1. Organização dos dados em branches diferentes.
- Branch master -> Jogo completo e funcional, sem erros.
- Branch sfml_version -> Versão visual, pode conter alguns erros.


Os arquivos na visualização gráfica (sfml) são uma cópia dos arquivos do life_game/master(branch), porém com a adição da biblioteca SFML. Para avaliação considerar apenas a versão life_game/master(branch).
