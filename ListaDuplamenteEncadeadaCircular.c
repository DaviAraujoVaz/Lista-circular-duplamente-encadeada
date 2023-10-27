#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
struct node
{
    int data;
    struct node *prox;
    struct node *ant;
};

// Definição do tipo Node
typedef struct node Node;

// Função para criar um novo nó
Node *criarNo(int data)
{
    // Aloca memória para o novo nó
    Node *novoNo = (Node *)malloc(sizeof(Node));
    // Verifica se a alocação de memória foi bem sucedida
    if (novoNo == NULL)
    {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    // Inicializa os campos do novo nó
    novoNo->data = data;
    novoNo->prox = NULL;
    novoNo->ant = NULL;
    // Retorna o novo nó
    return novoNo;
}

// Função para inserir um novo nó no início da lista
void inserirInicio(Node **cabeca, int data)
{
    // Cria um novo nó
    Node *novoNo = criarNo(data);

    // Verifica se a lista está vazia
    if (*cabeca == NULL)
    {
        // Se estiver vazia, o novo nó é o primeiro e o último da lista
        *cabeca = novoNo;
        (*cabeca)->prox = *cabeca;
        (*cabeca)->ant = *cabeca;
    }
    else
    {
        // Se a lista não estiver vazia, o novo nó é inserido no início da lista
        novoNo->prox = *cabeca;
        novoNo->ant = (*cabeca)->ant;
        (*cabeca)->ant->prox = novoNo;
        (*cabeca)->ant = novoNo;
        *cabeca = novoNo;
    }
    // Imprime uma mensagem informando que o nó foi inserido no início da lista
    printf("Nó com valor %d inserido no início da lista.\n\n", data);
    getchar();
}

// Função para inserir um novo nó no final da lista
void inserirFinal(Node **cabeca, int data)
{
    // Cria um novo nó
    Node *novoNo = criarNo(data);

    // Verifica se a lista está vazia
    if (*cabeca == NULL)
    {
        // Se estiver vazia, o novo nó é o primeiro e o último da lista
        *cabeca = novoNo;
        (*cabeca)->prox = *cabeca;
        (*cabeca)->ant = *cabeca;
    }
    else
    {
        // Se a lista não estiver vazia, o novo nó é inserido no final da lista
        novoNo->prox = *cabeca;
        novoNo->ant = (*cabeca)->ant;
        (*cabeca)->ant->prox = novoNo;
        (*cabeca)->ant = novoNo;
    }
    // Imprime uma mensagem informando que o nó foi inserido no final da lista
    printf("Nó com valor %d inserido no final da lista.\n\n", data);
    getchar();
}

// Função para remover um nó da lista
void removerNo(Node **cabeca, int data)
{
    // Verifica se a lista está vazia
    if (*cabeca == NULL)
    {
        printf("A lista está vazia.\n\n");
        getchar();
        return;
    }

    // Procura o nó com o valor especificado
    Node *temp = *cabeca;
    while (temp->data != data && temp->prox != *cabeca)
    {
        temp = temp->prox;
    }

    // Verifica se o nó foi encontrado
    if (temp->data != data)
    {
        printf("Nó com valor %d não encontrado na lista.\n\n", data);
        getchar();
        return;
    }

    // Remove o nó da lista
    if (temp == *cabeca && temp->prox == *cabeca)
    {
        // Se o nó a ser removido for o único nó da lista
        *cabeca = NULL;
    }
    else if (temp == *cabeca)
    {
        // Se o nó a ser removido for o primeiro nó da lista
        *cabeca = (*cabeca)->prox;
        (*cabeca)->ant = temp->ant;
        temp->ant->prox = *cabeca;
    }
    else if (temp->prox == *cabeca)
    {
        // Se o nó a ser removido for o último nó da lista
        temp->ant->prox = *cabeca;
        (*cabeca)->ant = temp->ant;
    }
    else
    {
        // Se o nó a ser removido estiver no meio da lista
        temp->ant->prox = temp->prox;
        temp->prox->ant = temp->ant;
    }
    // Libera a memória alocada para o nó removido
    free(temp);
    // Imprime uma mensagem informando que o nó foi removido da lista
    printf("Nó com valor %d removido da lista.\n\n", data);
    getchar();
}

// Função para procurar um nó na lista
void procurarNo(Node *cabeca, int data)
{
    // Verifica se a lista está vazia
    if (cabeca == NULL)
    {
        printf("A lista está vazia.\n\n");
        getchar();
        return;
    }

    // Procura o nó com o valor especificado
    Node *temp = cabeca;
    int pos = 1;
    while (temp->data != data && temp->prox != cabeca)
    {
        temp = temp->prox;
        pos++;
    }

    // Verifica se o nó foi encontrado
    if (temp->data != data)
    {
        printf("Nó com valor %d não encontrado na lista.\n\n", data);
        getchar();
        return;
    }
    // Imprime uma mensagem informando que o nó foi encontrado e em qual posição da lista ele está
    printf("Nó com valor %d encontrado na posição %d da lista.\n\n", data, pos);
    getchar();
}

// Função para imprimir a lista
void imprimeLista(Node *cabeca)
{
    // Verifica se a lista está vazia
    if (cabeca == NULL)
    {
        printf("A lista está vazia.\n");
        getchar();
        return;
    }

    // Percorre a lista e imprime os valores dos nós
    Node *temp = cabeca;
    printf("Nós na lista: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->prox;
    } while (temp != cabeca);
    printf("\n\n");
    getchar();
}

// Função para liberar a memória alocada para a lista
void liberaLista(Node **cabeca)
{
    // Verifica se a lista está vazia
    if (*cabeca == NULL)
    {
        return;
    }

    // Percorre a lista e libera a memória alocada para cada nó
    Node *temp = *cabeca;
    while (temp->prox != *cabeca)
    {
        temp = temp->prox;
    }
    while (temp != *cabeca)
    {
        temp = temp->ant;
        free(temp->prox);
    }
    // Libera a memória alocada para o primeiro nó da lista
    free(*cabeca);
    // Define o ponteiro para a cabeça da lista como NULL
    *cabeca = NULL;
    // Imprime uma mensagem informando que a memória foi liberada
    printf("\nMemória liberada.");
}

// Função principal
int main()
{
    // Cria a cabeça da lista
    Node *cabeca = NULL;
    // Declara as variáveis de escolha e valor
    int escolha, valor;

    // Loop principal do programa
    do
    {
        // Imprime o menu de opções
        printf("\nOperações da Lista Circular Duplamente Encadeada\n");
        printf("1. Inserir no início\n");
        printf("2. Inserir no final\n");
        printf("3. Remover nó\n");
        printf("4. Procurar nó\n");
        printf("5. Exibir lista\n");
        printf("6. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);
        getchar();

        // Executa a opção escolhida pelo usuário
        switch (escolha)
        {
        case 1:
            printf("\nDigite o valor a ser inserido: ");
            scanf("%d", &valor);
            getchar();
            inserirInicio(&cabeca, valor);
            break;

        case 2:
            printf("\nDigite o valor a ser inserido: ");
            scanf("%d", &valor);
            getchar();
            inserirFinal(&cabeca, valor);
            break;

        case 3:
            printf("\nDigite o valor do nó a ser removido: ");
            scanf("%d", &valor);
            getchar();
            removerNo(&cabeca, valor);
            break;

        case 4:
            printf("\nDigite o valor do nó a ser procurado: ");
            scanf("%d", &valor);
            getchar();
            procurarNo(cabeca, valor);
            break;

        case 5:
            imprimeLista(cabeca);
            break;

        case 6:
            liberaLista(&cabeca);
            printf("\nEncerrando o programa.\n");
            break;

        default:
            printf("Escolha inválida.\n");
        }
    } while (escolha != 6);

    // Retorna 0 para indicar que o programa foi executado com sucesso
    return 0;
}
