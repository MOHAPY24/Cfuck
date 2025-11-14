#include "core.c"


int main() {
    while(1){
        char command[255] = "";
        printf(">> ");
        scanf("%255s", command);
        if (strcmp(command, " ") == 0){
            break;
        }
        run(command);
    }
    return 0;
}