# Log de dicas — MergeOcorrencias

## 2026-10-18 — lista.c / RetiraRepetidos
- **Sintoma:** o programa trava em `RetiraRepetidos(mix)` (loop infinito; no valgrind não termina, só é morto pelo timeout).
- **Dica nível 1:** Quando você chama `InsereAluno(lista, B)`, *onde* na lista esse aluno vai parar? E o ponteiro `I`, que está andando pela lista, vai chegar lá também?
- **Ferramenta sugerida:** `gdb ./a.out` → `break RetiraRepetidos`, `display I->aluno->mat` e `next` várias vezes; ou um `printf` da matrícula a cada volta do `while (I != NULL)`.
- **Status:** resolvido
- **Lição:** se você reinsere elementos numa lista enquanto a percorre, eles precisam ir para uma parte que o iterador já passou (o início). Se forem para a frente dele (o fim), ele os encontra de novo e o loop nunca acaba.

## 2026-10-18 — lista.c / LiberaLista (e quem é dono de cada TAluno)
- **Sintoma:** valgrind: 96 bytes "definitely lost" em 6 blocos (16 bytes cada + o nome), alocados em `InicializaAluno`.
- **Dica nível 1:** 16 bytes é o `sizeof(TAluno)`. Quem tem a responsabilidade de liberar cada aluno no fim do programa? Pense também nas cópias repetidas que `RetiraRepetidos` tira da lista: o que acontece com elas?
- **Ferramenta sugerida:** `valgrind --leak-check=full ./a.out` e leia o stack de cada "definitely lost".
- **Status:** aberto
