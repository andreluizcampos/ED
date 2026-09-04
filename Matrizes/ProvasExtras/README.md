# Provas de Treino — Matrizes

Cinco provas de treino elaboradas a partir das provas oficiais encontradas em
`Matrizes/lab04/` (Filtro de Suavização, Busca Palavras, Organiza Palavras) e
dos exercícios extras em `MatrizesExtras/`. O grau de dificuldade é
ligeiramente maior que o das provas originais: cada uma introduz uma etapa a
mais ou uma estrutura de controle mais elaborada (múltiplas gerações, matriz
derivada reaproveitada em consultas, busca de um bloco inteiro em vez de um
elemento, percurso com limites dinâmicos, etc.), mantendo o mesmo formato de
enunciado, entrada/saída em arquivo e as mesmas regras de TAD das provas
oficiais.

Cada pasta contém:

- `enunciado.txt` — o enunciado da prova, no formato das provas oficiais
  (contexto, formato de entrada, algoritmo quando necessário, saída esperada
  e regras);
- `entrada.txt` — um exemplo de arquivo de entrada;
- `saida.txt` — a saída esperada para aquele exemplo (conferida manualmente).

## Convenções (iguais às usadas nas provas oficiais)

- Implementar um TAD Matriz (ao menos 2 arquivos para o TAD + 1 para o
  cliente/main);
- Usar somente alocação dinâmica para vetores e matrizes;
- Usar tipo opaco estruturado (estilo `typedef struct x Tx`);
- Manipulação de arquivo de entrada somente na `main`;
- Liberar toda a memória alocada (testar com Valgrind).

## Lista de provas

1. **Achar Submatriz** — buscar a(s) posição(ões) onde uma submatriz P x Q
   ocorre, como bloco contíguo, dentro de uma matriz maior N x M.
2. **Jogo da Vida (simplificado)** — simular G gerações de um autômato
   celular sobre uma matriz 0/1, com regras de nascimento/sobrevivência
   baseadas na contagem de vizinhos vivos.
3. **Soma de Regiões (Matriz de Somas Acumuladas)** — construir uma matriz de
   somas acumuladas e usá-la para responder K consultas de soma de regiões
   retangulares.
4. **Maior Bloco Retangular Homogêneo** — encontrar o maior retângulo
   contíguo cujos elementos são todos iguais.
5. **Espiral da Matriz** — percorrer a matriz em espiral (de fora para
   dentro), produzindo a sequência de valores visitados e uma matriz com a
   ordem de visita de cada posição.
