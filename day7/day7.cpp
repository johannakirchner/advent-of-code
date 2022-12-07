#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Nodo
{
private:
    string dir;
    int tamanho = 0;
    vector<Nodo *> prox;
    Nodo *anterior;

public:
    Nodo(string d, Nodo *ant)
    {
        this->dir = d;
        this->tamanho = 0;
        this->anterior = ant;
    }
    int getTam()
    {
        return this->tamanho;
    }
    void setTam(int x)
    {
        this->tamanho = this->tamanho + x;
    }
    void addProx(string dir)
    {
        Nodo *n = new Nodo(dir, this);

        this->prox.push_back(n);
    }
    string getDir()
    {
        return this->dir;
    }
    vector<Nodo *> getProxs()
    {
        return this->prox;
    }
    Nodo *getAnt()
    {
        return this->anterior;
    }
};

int indexSpace(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            return i;
        }
    }
}

int findNode(string name, vector<Nodo *> r)
{
    for (int i = 0; i < r.size(); i++)
    {
        if (r[i]->getDir() == name)
            return i;
    }
}

void montaArvore(Nodo *raiz, vector<string> line, int index)
{
    for (int i = index; i < line.size(); i++)
    {
        if (index == 3)
        {
            return;
        }
        if (line[i][0] == '$')
        {
            if (line[i][5] == '.')
            {
                montaArvore(raiz->getAnt(), line, i + 1);
                return;
            }
            else if (line[i][2] == 'c')
            {
                int k = findNode(line[i].substr(5, line[i].length() - 1), raiz->getProxs());

                montaArvore(raiz->getProxs()[k], line, i + 1);
                return;
            }
        }
        else
        {
            if (line[i][0] == 'd')
            {
                raiz->addProx(line[i].substr(4, line[i].length() - 1));
            }
            else
            {
                raiz->setTam(stoi(line[i].substr(0, indexSpace(line[i]))));

                Nodo *aux = raiz;
                while (aux->getAnt() != nullptr)
                {
                    aux->getAnt()->setTam(stoi(line[i].substr(0, indexSpace(line[i]))));
                    aux = aux->getAnt();
                }
            }
        }
    }
}

int tamanhozao = 0;
vector<int> tamanhos;

void somaMaiores(Nodo *raiz)
{
    if (raiz->getTam() <= 100000)
    {
        tamanhozao += raiz->getTam();
    }
    tamanhos.push_back(raiz->getTam());
    

    for (int i = 0; i < raiz->getProxs().size(); i++)
    {
        somaMaiores(raiz->getProxs()[i]);
    }
}

int encontraTamanho(int falta)
{
    sort(tamanhos.begin(), tamanhos.end());

    for (int i = 0; i < tamanhos.size(); i++)
    {
        if (tamanhos[i] >= falta)
        {
            return tamanhos[i];
        }
    }
}

int main()
{
    Nodo *root = new Nodo("/", nullptr);

    ifstream infile("input.txt");
    vector<string> line;
    string l;
    int i = 0;
    while (getline(infile, l))
    {
        line.push_back(l);
        i++;
    }

    montaArvore(root, line, 1);

    somaMaiores(root);

    cout << tamanhozao << endl;

    int livre = 70000000 - root->getTam();
    int falta = 30000000 - livre;


    cout << encontraTamanho(falta) << endl;

    return 0;
}