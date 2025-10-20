#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


class Array{
    private:
        int size;
        int *data;
    
    public:

        Array(int size_){
            size = size_;
            data = new int[size];
        }

        Array(const Array &other){
            size = other.size;
            data = new int[other.size];
            for (int i = 0; i < other.size; ++i){
                data[i] = other.data[i];
            }
        }

        ~Array(){
            delete []data;
        }

        void set_array(){
            int n;
            for (int i = 0; i < size; ++i){
                cin >> n;
                if (n <= 100 and n >= -100){
                    data[i] = n;
                }
                else{
                    cout << "The value is not included in [-100;100]" << endl;
                    i--;
                }
            }
            cout << endl;
        }

        int get_array(int index){
            if (index < size and index>=0){
                return data[index];
            }
            else{
                cout << "Array bounds exceeded, the last element was received" << endl;
                return data[size-1];
            }
        }


        void array_output(){
            for (int i = 0; i < size; ++i){
                cout << data[i] << " ";
            }
            cout << endl;
        }

        void add_to_end(int a){
            if (a >= -100 and a <= 100){
                int *copy = new int[size + 1];
                for (int i = 0; i < size; ++i){
                    copy[i] = data[i];
                }
                copy[size] = a;
                data = copy;
                size = size + 1;
            }
            else{
                cout << "The value is not included in [-100;100]" << endl;
            }
        }

        void add_array(Array b, string sign){
            if (sign != "+" and sign != "-"){
                cout << "unidentified sign";
            }
            else{
                if (sign == "+"){
                    if (b.size >= this -> size){
                        for (int i = 0; i < size; ++i){
                            data[i] = data[i] + b.get_array(i);
                        }
                    }
                    else{
                        for (int i = 0; i < b.size; ++i){
                            data[i] = data[i] + b.get_array(i);
                        }
                    }
                }
                else{
                    if (b.size >= this -> size){
                        for (int i = 0; i < size; ++i){
                            data[i] = data[i] - b.get_array(i);
                        }
                    }
                    else{
                        for (int i = 0; i < b.size; ++i){
                            data[i] = data[i] - b.get_array(i);
                        }
                    }
                }
            }
        }
};


int main(){

    Array a(2);
    a.set_array();
    Array b(5);
    b.set_array();
    b.array_output();
    a.add_to_end(7);
    a.add_array(b,"-");
    a.array_output();
    cout << a.get_array(2);
}