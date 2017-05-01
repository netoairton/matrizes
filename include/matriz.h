/**
* @file 	matriz.h
* @brief	Arquivo de cabeçalho com a definição das funções
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @author   Airton Neto (netoairton@yahoo.com.br)
* @since    28/04/2017
* @date     28/04/2017
*/

#ifndef MATRIZ_H
    #define MATRIZ_H

    #include <iostream>
    using std::cout;
    using std::cerr;
    using std::endl;
    using std::string;
    using std::stringstream;
    
    #include <sstream>
    
    #include <fstream>
    using std::ifstream;

    /**
    * @brief Funcao que multiplica duas matrizes quadradas de dimensao n x n de forma iterativa
    * @param A Matriz de entrada
    * @param B Matriz de entrada
    * @param n Dimensao das matrizes de entrada
    * @return Matriz produto resultante da multiplicacao
    */
    template <typename T>
    T **multiplicaI(T **A, T **B, int n) {
        T soma;
        T **ret = new T*[n];
        for(int i=0; i<n; i++){
            ret[i]= new T[n];
            for(int j=0; j<n; j++){
                soma=0;
                for(int k=0; k<n; k++){
                    soma= soma+ (A[i][k]) * (B[k][j]);
                }
            ret[i][j]=soma;
            }
        }
    return ret;
    }

    /**
    * @brief Funcao que multiplica duas matrizes quadradas de dimensao n x n de forma recursiva
    * @param A Matriz de entrada
    * @param B Matriz de entrada
    * @param n Dimensao das matrizes de entrada
    * @return Matriz produto resultante da multiplicacao
    */
    template <typename T>
    T **multiplicaR(T **A, T **B, int n) {
        T **ret11 = new T*[n/2];
        T **ret12 = new T*[n/2];
        T **ret21 = new T*[n/2];
        T **ret22 = new T*[n/2];
        T **ret = new T*[n];
        T **a11 = new T*[n/2];
        T **a12 = new T*[n/2];
        T **a21 = new T*[n/2];
        T **a22 = new T*[n/2];
        T **b11 = new T*[n/2];
        T **b12 = new T*[n/2];
        T **b21 = new T*[n/2];
        T **b22 = new T*[n/2];
        T **p1 = new T*[n/2];
        T **p2 = new T*[n/2];
        T **p3 = new T*[n/2];
        T **p4 = new T*[n/2];
        T **p5 = new T*[n/2];
        T **p6 = new T*[n/2];
        T **p7 = new T*[n/2];
        T **p8 = new T*[n/2];

        for(int i=0; i<n/2; i++){
            ret11[i]= new T[n/2];
            ret12[i]= new T[n/2];
            ret21[i]= new T[n/2];
            ret22[i]= new T[n/2];
            a11[i]= new T[n/2];
            a12[i]= new T[n/2];
            a21[i]= new T[n/2];
            a22[i]= new T[n/2];
            b11[i]= new T[n/2];
            b12[i]= new T[n/2];
            b21[i]= new T[n/2];
            b22[i]= new T[n/2];
            p1[i]= new T[n/2];
            p2[i]= new T[n/2];
            p3[i]= new T[n/2];
            p4[i]= new T[n/2];
            p5[i]= new T[n/2];
            p6[i]= new T[n/2];
            p7[i]= new T[n/2];
            p8[i]= new T[n/2];
        }
        for(int i=0; i<n; i++){
        ret[i]= new T[n];
        }
        if(n==1){
            ret[0][0]= (A[0][0]) * (B[0][0]);
            return ret;
        }
        else{
            int a=0, b=0;
            for(int i=0; i<n/2; i++){
                for(int j=0; j<n/2; j++){
                    a11[a][b]=A[i][j];
                    b11[a][b]=B[i][j];
                    if(b<=n/2){
                        b=b+1;
                    }
                }
                b=0;
                if(a<=n/2){
                    a=a+1;
                }
            }
            a=0;
            b=0;
            for(int i=0; i<n/2; i++){
                for(int j=n/2; j<n; j++){
                    a12[a][b]=A[i][j];
                    b12[a][b]=B[i][j];
                    if(b<=n/2){
                        b=b+1;
                    }
                }
                b=0;
                if(a<=n/2){
                    a=a+1;
                }
            }
            a=0;
            b=0;
            for(int i=n/2; i<n; i++){
                for(int j=0; j<n/2; j++){
                    a21[a][b]=A[i][j];
                    b21[a][b]=B[i][j];
                    if(b<=n/2){
                        b=b+1;
                    }
                }
                b=0;
                if(a<=n/2){
                    a=a+1;
                }
            }
            a=0;
            b=0;
            for(int i=n/2; i<n; i++){
                for(int j=n/2; j<n; j++){
                    a22[a][b]=A[i][j];
                    b22[a][b]=B[i][j];
                    if(b<=n/2){
                        b=b+1;
                    }
                }
                b=0;
                if(a<=n/2){
                    a=a+1;
                }
            }
            a=0;
            b=0;
            p1=multiplicaR(a11, b11, n/2);
            p2=multiplicaR(a12, b21, n/2);
            p3=multiplicaR(a11, b12, n/2);
            p4=multiplicaR(a12, b22, n/2);
            p5=multiplicaR(a21, b11, n/2);
            p6=multiplicaR(a22, b21, n/2);
            p7=multiplicaR(a21, b12, n/2);
            p8=multiplicaR(a22, b22, n/2);

            for(int i=0; i<n/2; i++){
                for(int j=0; j<n/2; j++){
                    ret11[i][j]= p1[i][j] + p2[i][j];
                }
            }
            for(int i=0; i<n/2; i++){
                for(int j=0; j<n/2; j++){
                    ret12[i][j]= p3[i][j] + p4[i][j];
                }
            }
            for(int i=0; i<n/2; i++){
                for(int j=0; j<n/2; j++){
                    ret21[i][j]= p5[i][j] + p6[i][j];
                }
            }
            for(int i=0; i<n/2; i++){
                for(int j=0; j<n/2; j++){
                    ret22[i][j]= p7[i][j] + p8[i][j];
                }
            }
            for(int i=0; i<n/2; i++){
                for(int j=0; j<n/2; j++){
                    ret[i][j]=ret11[a][b];
                    if(b<=n/2){
                        b=b+1;
                    }
                }
                b=0;
                if(a<=n/2){
                    a=a+1;
                }
            }
            a=0;
            b=0;
            for(int i=0; i<n/2; i++){
                for(int j=n/2; j<n; j++){
                    ret[i][j]=ret12[a][b];
                    if(b<=n/2){
                        b=b+1;
                    }
                }
                b=0;
                if(a<=n/2){
                    a=a+1;
                }
            }
            a=0;
            b=0;
            for(int i=n/2; i<n; i++){
                for(int j=0; j<n/2; j++){
                    ret[i][j]=ret21[a][b];
                    if(b<=n/2){
                        b=b+1;
                    }
                }
                b=0;
                if(a<=n/2){
                    a=a+1;
                }
            }
            a=0;
            b=0;
            for(int i=n/2; i<n; i++){
                for(int j=n/2; j<n; j++){
                    ret[i][j]=ret22[a][b];
                    if(b<=n/2){
                        b=b+1;
                    }
                }
                b=0;
                if(a<=n/2){
                    a=a+1;
                }
            }
            a=0;
            b=0;
            return ret;
        }
    }

    /**
    * @brief     	Função que carrega um arquivo de dados contendo uma matriz quadrada
    * @param[in] 	nome String com o caminho/nome do arquivo à ler
    * @param[out]   dim Dimensão da matriz
    * @return    	Retorna a matriz lida
    */
    template <typename T>
    T **loadMatriz(string nome, int &dim = 0) {
        //Abrir o arquivo
        ifstream entrada(nome);
        if(!entrada) {
            cout << "Falha de arquivo" << endl;
            return NULL;
        }

        int colunas;
        string lido = "";
        stringstream sa;
        
        //Lê a primeira linha
        entrada.clear();
        entrada.seekg(0);
        getline(entrada, lido, ' '); //Primeira parte

        sa.clear();
        sa << lido;
        sa >> dim;
        getline(entrada, lido);//Parte final da linha
        sa.clear();
        sa << lido;
        sa >> colunas;
        if(dim != colunas) {        //Se valores são diferentes não aceita
            cout << "Só aceita matrizes quadradas" << endl;
            return NULL;
        }

        int **M = new int*[dim];
        
        for(int i = 0; i < dim; i++) {              //Lê o arquivo até o final
            M[i] = new int[dim];                    //Cria as colunas da linha atual
            for(int j = 0; j < dim; j++) {          //Lê todas as colunas da linha atual
                if(j == (dim - 1))                  
                    getline(entrada, lido);         //Se última coluna, a leitura é diferente
                else
                    getline(entrada, lido, ' ');

                //Converte string para o tipo T
                sa.clear();
                sa << lido;
                sa >> M[i][j];
            }
        }

        //Encerra a função devolvendo as informações
        entrada.close();
        return M;
    }

#endif