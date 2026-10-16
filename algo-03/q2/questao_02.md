Poles está desenvolvendo uma árvore de habilidades para o seu jogo de RPG. Ele quer que os personagens possam escolher, partindo de uma habilidade principal, algumas ramificações possíveis. Cada habilidade pode ser desbloqueada por diferentes caminhos de upgrades, porém todos os upgrades são direcionados.

Para cada upgrade de habilidade, o personagem deve gastar alguns pontos de experiência e pode adquirir alguma pontuação de poder.

Ele quer saber, dada um determinada árvore de habilidades, qual é o custo mínimo de experiência para desbloquear todas as habilidades.

Entrada
A entrada começa com um número inteiro indicando a quantidade H de habilidades. As H linhas seguintes contêm o nome (palavra) e o poder (número real) de cada habilidade (cada habilidade tem um código automático de 0 a H de acordo com a entrada de dados).

Em seguida é informado um valor inteiro indicando a quantidade U de upgrades possíveis. As U linhas seguintes contêm três inteiros indicando o código da habilidade origem, o código da habilidade destino e o custo de cada upgrade.

Saída
A saída é um número inteiro indicando o custo mínimo para desbloquear todas as habilidades.

Exemplo de entrada     	Exemplo de saída     
10
Base 0
Dash 1
Thief 3
Hunter 3
Assassin 4
BeastMaster 5
Berserker 7
WildMagic 2
Vengeance 4
Life 5                         23
12
0 1 1
1 2 2
1 3 2
3 4 3
3 5 3
3 6 4
0 7 2
7 8 3
7 9 3
1 7 3
8 6 5
2 4 5