#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int POP_SIZE=20;
int CHROM_LEN=10;
double MUT_RATE=0.1;
int MAX_GEN=100;
string TARGET="1111111111";

struct Individual {
    string chrom;
    int fitness;
};

int getFitness(string chrom){
    int f=0;
    for(int i=0;i<CHROM_LEN;i++){
        if(chrom[i]==TARGET[i]) f++;
    }
    return f;
}

string createChrom(){
    string s="";
    for(int i=0;i<CHROM_LEN;i++){
        s += (rand()%2 == 0) ? '0' : '1';
    }
    return s;
}

Individual selection(vector<Individual>& pop){
    int idx1=rand()%POP_SIZE;
    int idx2=rand()%POP_SIZE;
    if(pop[idx1].fitness > pop[idx2].fitness) return pop[idx1];
    return pop[idx2];
}

pair<string, string> crossover(string p1, string p2){
    int pt=rand()%CHROM_LEN;
    string c1=p1.substr(0,pt)+p2.substr(pt);
    string c2=p2.substr(0,pt)+p1.substr(pt);
    return {c1,c2};
}

void mutate(string& chrom){
    for(int i=0;i<CHROM_LEN;i++){
        double r=(double)rand()/RAND_MAX;
        if(r<MUT_RATE){
            chrom[i]=(chrom[i]=='0') ? '1' : '0';
        }
    }
}

int main() {
    srand(time(0));
    vector<Individual> pop(POP_SIZE);

    for(int i=0;i<POP_SIZE;i++){
        pop[i].chrom=createChrom();
        pop[i].fitness=getFitness(pop[i].chrom);
    }

    for(int gen=1;gen<=MAX_GEN;gen++){
        vector<Individual> nextPop;
        while(nextPop.size()<POP_SIZE){
            Individual p1=selection(pop);
            Individual p2=selection(pop);
            auto children=crossover(p1.chrom,p2.chrom);
            mutate(children.first);
            mutate(children.second);
            nextPop.push_back({children.first,getFitness(children.first)});
            if(nextPop.size()<POP_SIZE){
                nextPop.push_back({children.second,getFitness(children.second)});
            }
        }
        pop=nextPop;

        Individual best=pop[0];
        for(int i=1;i<POP_SIZE;i++){
            if(pop[i].fitness>best.fitness) best=pop[i];
        }

        cout<<"Gen "<<gen<<" | Best: "<<best.chrom<<" | Fitness: "<<best.fitness<<endl;

        if(best.fitness==CHROM_LEN){
            cout<<"\nTarget reached in generation "<<gen<<"!"<<endl;
            break;
        }
    }
    return 0;
}