# Conway's Life Game Simulator

Desenvolvedores:
- Henrique David de Medeiros
- Pablo Emanuell L. Targino

Instruções de Compilação:
	
- Na pasta src, da pasta life_game, execute o seguinte código:
"g++ -Wall -std=c++11 Life.cpp main.cpp -o exec"

Instruções de Execução:

- Na pasta src:
"./exec <arqEntrada> [<arqSaida>]"

O trabalho está dividindo em dois tipo:
- execução no terminal, pasta life_game; e
- execução visual, pasta life_game_sfml.

Acesso pelo GitHub:
- Organização dos dados em branches diferentes.
- Branch master -> Jogo completo e funcional, sem erros.
- Branch sfml_version -> Versão visual, pode conter alguns erros.

Os arquivos na visualização gráfica (sfml) são uma cópia dos arquivos do life_game/master(branch), porém com a adição da biblioteca SFML.
