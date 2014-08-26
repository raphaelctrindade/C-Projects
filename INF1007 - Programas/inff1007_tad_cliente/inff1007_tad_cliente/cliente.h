/* "arquivo de interface do TAD Cliente" */

typedef struct cliente Cliente;

Cliente*cliCria(char*n,int cpf, float ultValor);
int cliObtemCPF(Cliente*pcli);
float cliObtemUltValor(Cliente*pcli);
void cliExibe(Cliente*pcli);
void cliLibera(Cliente*pcli);