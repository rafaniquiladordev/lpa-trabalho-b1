# lpa-trabalho-b1
trabalhodelogica
# Trabalho B1 - Lógica de Programação e Algoritmos

## Descrição

Simulador de entregas desenvolvido em linguagem C e executado em terminal. O programa permite processar uma ou várias solicitações de entrega durante uma sessão, realizando a validação dos dados informados e calculando o valor final de cada entrega de acordo com as regras definidas.

São considerados dados como distância, peso, modalidade de entrega, contratação de proteção e quantidade de tentativas adicionais. Ao final da sessão, o programa apresenta um resumo estatístico das entregas processadas.

## Funcionalidades

- Cálculo do valor-base da entrega de acordo com a faixa de distância.
- Cálculo do subtotal inicial, considerando o valor-base e a tarifa de R$ 1,20 por quilômetro.
- Cálculo do adicional de peso de acordo com a faixa de peso da encomenda.
- Cálculo do adicional de modalidade:
  - Econômica;
  - Expressa;
  - Prioritária.
- Acréscimo de R$ 7,50 quando a proteção da entrega é contratada.
- Acréscimo de R$ 4,00 para cada tentativa adicional de entrega.
- Validação das entradas informadas pelo usuário.
- Repetição da solicitação até que sejam fornecidos valores válidos.
- Processamento de múltiplas entregas na mesma execução.
- Contagem da quantidade de entregas por modalidade.
- Cálculo do valor total das entregas.
- Cálculo do valor médio das entregas.
- Identificação do maior valor de entrega.
- Identificação do menor valor de entrega.
- Exibição dos dados e dos cálculos de cada entrega.
- Exibição de um resumo estatístico ao final da sessão.

## Regras de cálculo

### Valor-base

O valor-base é definido conforme a distância:

| Distância | Valor-base |
|---|---:|
| Até 5 km | R$ 8,00 |
| Até 15 km | R$ 12,00 |
| Até 30 km | R$ 18,00 |
| Acima de 30 km | R$ 25,00 |

Além do valor-base, é acrescentado R$ 1,20 por quilômetro:

```text
Subtotal = Valor-base + (Distância × 1,20)

## Compilação
```
gcc -Wall -o main src/main.c
```

## Execução
```
./main
```
No Windows, compile com o mesmo comando (usando MinGW, por exemplo) e
execute com `main.exe`.

## Uso de Inteligência Artificial
Utilizei da ferramenta do Chatgpt para me ajudar a construir o código, tendo correção de linhas do código, como parâmetros, sintaxe e organização geral baseado na linguagem C.



