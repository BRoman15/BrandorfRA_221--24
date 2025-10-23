#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
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
        }

        ~PGMReader(){
            // Запись в PGM файл
            ofstream filtered_image;
            filtered_image.open(address_filtered_image);
            if (!filtered_image.is_open()){
                cout << "file opening error" << endl;
            }
            else{
                // Добавление информации о PGM картинки в файл
                filtered_image << format << endl << str << endl << width << " " << height << endl << max_znach << endl;

                // Добавление пикселей в файл
                for (int row = 0; row < height; row++){
                    for (int cols = 0; cols < width; cols++){
                        filtered_image << arr[row][cols] << endl;
                    }
                }
            }
            filtered_image.close();


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
                        cout << ((row*100)/height) << "% complit" << endl;
                    }
                }
                cout << "100% complit" << endl << endl;
            }
            cout << "The filtered image is ready" << endl;
        }
};





// Алгоритм сравнение отфильтрованного изображения с исходным
void image_comparison(string shum_image, string filtered_image){
        int width_1, height_1, max_znach_1, width_2, height_2, max_znach_2;
        int **arr_shum_image, **arr_filtered_image;
        string format_1, str_1, format_2, str_2;
        float matching_pixels = 0, size_pixel = 1, result = 0;

// Изображение с шумом
        ifstream file_1(shum_image);

        // Получение из файла данных о изображение (первые 4 строки файла) 1
        if (file_1.is_open()){
            getline(file_1, format_1);
            getline(file_1, str_1);
            file_1 >> width_1 >> height_1 >> max_znach_1;
        }


        // Создание двумерного массива с данными о каждом пикселе 1
        arr_shum_image = new int* [height_1];
        for (int i = 0; i < height_1; i++){
            arr_shum_image[i] = new int [width_1];
        }

        // Заполнение массива данными о пикселях 1
        for (int row = 0; row < height_1; row++){
            for (int cols = 0; cols < width_1; cols++){
                file_1 >> arr_shum_image[row][cols];
            }
        }
        file_1.close();

// Изображение без шума
        ifstream file_2(filtered_image);
        // Получение из файла данных о изображение (первые 4 строки файла) 1
        if (file_2.is_open()){
            getline(file_2, format_2);
            getline(file_2, str_2);
            file_2 >> width_2 >> height_2 >> max_znach_2;
        }

        // Создание двумерного массива с данными о каждом пикселе 1
        arr_filtered_image = new int* [height_2];
        for (int i = 0; i < height_2; i++){
            arr_filtered_image[i] = new int [width_2];
        }

        // Заполнение массива данными о пикселях 1
        for (int row = 0; row < height_2; row++){
            for (int cols = 0; cols < width_2; cols++){
                file_2 >> arr_filtered_image[row][cols];
            }
        }
        file_2.close();

        // Сравниваем
        size_pixel = width_1*height_1;
        if (height_1 != height_2 or width_1 != width_2){
            cout << "Error: different pictures" << endl;
        }
        else{
            for (int row = 0; row < height_1; row++){
                for (int cols = 0; cols < width_1; cols++){
                    if (abs(arr_shum_image[row][cols] - arr_filtered_image[row][cols]) <= 11){
                        matching_pixels = matching_pixels + 1;
                    }
                }

            }
        }
        result = matching_pixels / size_pixel *100;
        cout << endl << "The original and filtered images are "<< round(result) << "% similar";

        // Освобождаем память
        for (int i = 0; i < height_1; i++){
            delete []arr_filtered_image[i];
        }
        delete []arr_filtered_image;

        for (int i = 0; i < height_1; i++){
            delete []arr_shum_image[i];
        }
        delete []arr_shum_image;
}




int main(){
    string shum_image = "shum_image//6_level_shum.pgm";
    string filtered_image = "image//filtered_image5_level6.pgm";

    {
    PGMReader A(shum_image,filtered_image);
    A.median_processing(3);
    }

    image_comparison(shum_image,filtered_image);
}