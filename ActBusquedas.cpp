#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include "t2.cpp"


using namespace std;

class Busqueda{
public:

    

    template <typename T> int secuencial(vector <T> elementos, int num){
        int x = elementos.size();
        for (int i = 0; i < x ; i++)
        {
            if (elementos[i]==num){
                return i;
            }
        }
        return -1;
    }
    template <typename T> int MovFrente(vector <T> elementos, int num){
        int x = elementos.size();
        for(int i = 0; i < x; i++){
            if (elementos[i] == num){
                elementos.erase(elementos.begin()+i);
                elementos.insert(elementos.begin(),num);
                return i;
            }
        }
        return -1;
        }
    
    template <typename T> int transposicion(vector <T> elementos, int num){
        int x = elementos.size();

		for (int i = 0; i < x; i++){

			if (elementos[i] == num){
				int x = elementos[0];

				elementos.erase(elementos.begin());
				elementos.insert(elementos.begin(), num);
				

				elementos.insert(elementos.begin()+i, x);
				elementos.erase(elementos.begin()+i+1);
				return i;
			}
		}
        return -1;
		
	}
    template <typename T> int ordenamiento(vector <T> elementos, int num){
        sort(elementos.begin(), elementos.end());
        int pos = 0;
        int tam = elementos.size();

        while(true){
            if (elementos[pos] == num){
                return pos;
            }
            else if ((elementos[pos] > num) || (elementos[pos] >= tam)){
                return -1;
            }
            pos++;
        }

    }
template <typename T> int binario(vector<T> elementos, int num){
		sort(elementos.begin(), elementos.end()); 
		bool val = false;

		int final = elementos.size()-1;
		int inicio = 0;
		int medio = final/2;

		while (true){
			if (elementos[medio] == num){
				return medio;
			}
			else if(medio == inicio || medio == final){
				return -1;
			}
			else if (elementos[medio] < num){
				inicio = medio;
				if (final - inicio == 1){
					medio += 1;
				}
				else{
					medio = (final + inicio) / 2;
				}
			}

			else if (elementos[medio] > num){
				final = medio;
				if (final - inicio == 1){
					medio -= 1;
				}
				else{
					medio = (final + inicio) / 2;
				}
			}
		}

	}
    template <typename T> vector<T> miVector(T val, int num){
		vector<T> vec;

		srand(time(0));
		for (int i = 0; i < num; ++i){
			vec.push_back(rand() % (100000) + 1);
		}
		return vec;
	}

};

int main(){

    int num = 729;

    Busqueda busqueda;
    vector <int> vec;
    vec = busqueda.miVector(1,100000);

    //cout << busqueda.secuencial(vec,num) << endl;
    //cout << busqueda.MovFrente(vec,num) << endl;
    //cout << busqueda.transposicion(vec,num) << endl;
    //cout << busqueda.ordenamiento(vec,num) << endl;
    cout << busqueda.binario(vec,num) << endl;

tiempo();
    
}

 
