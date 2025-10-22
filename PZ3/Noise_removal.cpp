#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class PGMReader{
    private:
        string format, str;
        string storage_address, address_filtered_image;
        int width, height, max_znach;
        int **arr;
//      height -> ROWS;   width -> COLS

        int insertion_sort(int *A,int size){
            int min, t;
            for (int i = 0; i < size-1; i++){
                min = i;
                for (int j = i+1; j < size; j++){
                    if (A[j] < A[min]){
                        min = j;
                    }
                }
                t = A[i];
                A[i] = A[min];
                A[min] = t;
            }
            return A[size/2];
        }


    public:
        PGMReader(string storage_address_, string address_filtered_image_){
            storage_address = storage_address_;
            address_filtered_image = address_filtered_image_;

            ifstream file(storage_address);

            // Получение из файла данных о изображение (первые 4 строки файла)
            if (file.is_open()){
                getline(file, format);
                getline(file, str);
                file >> width >> height >> max_znach;
            }

            // Создание двумерного массива с данными о каждом пикселе
            arr = new int* [height];
            for (int i = 0; i < height; i++){
                arr[i] = new int [width];
            }

            // Заполнение массива данными о пикселях
            for (int row = 0; row < height; row++){
                for (int cols = 0; cols < width; cols++){
                    file >> arr[row][cols];
                }
            }

            // for (int row = 0; row < height; row++){
            //     for (int cols = 0; cols < width; cols++){
            //         cout << arr[row][cols] << " ";
            //     }
            //     cout << endl;
            // }
        }

        ~PGMReader(){
            // Запись в PGM файл
            ofstream filtered_image;
            filtered_image.open(address_filtered_image);
            if (!filtered_image.is_open()){
                cout << "file opening error" << endl;
            }
            else{
                cout << "file is open!" << endl;

                // Добавление информации о PGM картинки в файл
                filtered_image << format << endl << str << endl << width << " " << height << endl << max_znach << endl;

                // Добавление пикселей в файл
                for (int row = 0; row < height; row++){
                    for (int cols = 0; cols < width; cols++){
                        filtered_image << arr[row][cols] << endl;
                    }
                }
            }


            // Удаление двумерного денамического массива
            for (int i = 0; i < height; i++){
                delete []arr[i];
            }
            delete []arr;
        }


        // Медианный фильтр
        void median_processing(int filter_size){
            if (filter_size % 2 == 0 or filter_size >= width){
                cout << "The filter size must be an odd number (3, 5, 7.....) and less than the width" << endl;
            }
            else{
                int *filter_arr = new int[filter_size];
                for (int row = 0; row < height; row++){
                    for (int cols = filter_size / 2; cols < height - (filter_size / 2); cols++){
                        for (int i = 0; i < filter_size; i++){
                            filter_arr[i] = arr[row][(cols - filter_size / 2) + i];
                        }
                        arr[row][cols] = insertion_sort(filter_arr, filter_size);
                    }
                    if (row % 10 == 0){
                        cout << ((row*100)/height) << " complit" << endl;
                    }
                }
            }
        }
        
};


int main(){
    PGMReader A("C://VSCod//PZ3//orig_shum_P2.pgm","filtered_image.pgm");
    A.median_processing(3);
}