#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    getchar(); // 吃掉換行字元

    while (T--) {
        char line[300];
        fgets(line, sizeof(line), stdin);

        int m_count = 0, f_count = 0;
        int pieces = 0;

        char *token = strtok(line, " \n");
        while (token != NULL) {
            if (strlen(token) == 2) {
                if (token[0] == 'M') m_count++;
                if (token[0] == 'F') f_count++;
                if (token[1] == 'M') m_count++;
                if (token[1] == 'F') f_count++;
                pieces++;
            }
            token = strtok(NULL, " \n");
        }

        if (pieces >= 2 && m_count == f_count) {
            printf("LOOP\n");
        } else {
            printf("NO LOOP\n");
        }
    }

    return 0;
}
/*使用 strtok() 切割輸入的每一段軌道。

每段長度必為 2，例如 "MF"。

分別計算 M 和 F 的出現次數。

最後根據條件輸出結果*/
