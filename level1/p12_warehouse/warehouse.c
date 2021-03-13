#include <stdio.h>
#include <string.h>
#include <conio.h>
#define MAX_SIZE 100
char filename[] = "data.txt",tempfile_name[] = "temp.txt";
char put[MAX_SIZE],get[MAX_SIZE];
int i;
void CheckIn();
FILE * OpenData(char * filename);
void Log(FILE * data_file);
char * ReadLine(FILE * data_file);
void ListWare();
void CheckOut();

int main(int argc, char const *argv[])
{
    
    printf("Please hit\n\t1 to list wares\n\t2 to check in\n\t3 to check out\n\t4 to quit.\n");
    int ch;
    while (1) {
        if (_kbhit()) {
            ch = _getch();
            if (ch == 49) {
                ListWare();
            }
            else if (ch == 50) {
                CheckIn();
            }
            else if (ch == 51) {
                CheckOut();
            }
            else if (ch == 52) {
                break;
            }
        }
    }
    printf("Thanks for using");
    return 0;
}
void CheckOut() {
    FILE * data_file = OpenData(filename);
    FILE * temp_file = OpenData(tempfile_name);
    char model_number[MAX_SIZE];
    printf("Please enter the model number you want to check out:\n");
    fgets(model_number,MAX_SIZE,stdin);
    printf("Having successfully checked out %s",model_number);
    while (ReadLine(data_file)) {
        fseek(temp_file,0L,SEEK_END);
        if (strcmp(model_number,get)) {
            fputs(get,temp_file);
        }
        else {
            ReadLine(data_file);ReadLine(data_file);
        }
    }
    fclose(temp_file);
    fclose(data_file);
    remove(filename);
    rename(tempfile_name,filename);
}
FILE * OpenData(char * filename) {
    FILE * data_file = fopen(filename,"r+");
    if (NULL == data_file) {
        data_file = fopen(filename,"w+");
    }
    return data_file;
}
void ListWare() {
    FILE * data_file = OpenData(filename);
    printf("We already have following wares:\n");
    fseek(data_file,0L,SEEK_SET);
    for (i = 0;; ++ i) {
        if (!ReadLine(data_file))break;
        if (!(i % 3))
            printf("\t%s",get);
    }
    fclose(data_file);
}
void Log(FILE * data_file) {
    fgets(put,MAX_SIZE,stdin);
    fseek(data_file,0L,SEEK_END);
    fputs(put,data_file);
}
char * ReadLine(FILE * data_file) {
    return fgets(get,MAX_SIZE,data_file);
}
void CheckIn() {
    FILE * data_file = OpenData(filename);
    printf("Please enter the model number:\n");
    Log(data_file);
    printf("Please enter the quantity:\n");
    Log(data_file);
    printf("Please enter the weight(XXkg):\n");
    Log(data_file);
    printf("OK, the ware is successfully checked in!\n");
    fclose(data_file);
}