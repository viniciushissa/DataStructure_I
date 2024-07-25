struct no {
    int coeficiente;
    int expoente;
    struct no* proximo;
};

struct no* novoNo(int coeficiente, int expoente);
void inserirNo(struct no** cabeca, int coeficiente, int expoente);
struct no* somarPolinomios(struct no* poli1, struct no* poli2);
void imprimirPolinomio(struct no* poli);
