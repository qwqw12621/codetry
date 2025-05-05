#include <stdio.h>
#include <ctype.h>

int main() {
    char line[256];
    int firstMaze = 1;

    while (fgets(line, sizeof(line), stdin)) {
        // 檢查是否為空行（迷宮之間的分隔）
        int isEmpty = 1;
        int i;
		for (i = 0; line[i]; i++) {
            if (line[i] != '\n' && line[i] != '\r') {
                isEmpty = 0;
                break;
            }
        }

        if (isEmpty) {
            if (!firstMaze) {
                printf("\n"); // 輸出迷宮間空行
            }
            continue;
        }

        if (!firstMaze) {
            printf("\n"); // 迷宮之間要空行
        }
        firstMaze = 0;

        // 解析每一行直到 EOF
        do {
            int i = 0;
            int count = 0;
            while (line[i] != '\0') {
                if (isdigit(line[i])) {
                    count += line[i] - '0';
                } else if (line[i] == '!') {
                    printf("\n"); // 換行指令
                    count = 0;
                } else {
                    char ch = (line[i] == 'b') ? ' ' : line[i];
                    int j;
					for (j = 0; j < count; j++) {
                        putchar(ch);
                    }
                    count = 0;
                }
                i++;
            }
        } while (fgets(line, sizeof(line), stdin) && line[0] != '\n');
    }

    return 0;
}

