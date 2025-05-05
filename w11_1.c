#include <stdio.h>

int main() {
    int ch;
    int quote_open = 1;  // 狀態標記：1 表示下一個 " 是開引號，0 表示下一個 " 是關引號

    while ((ch = getchar()) != EOF) {
        if (ch == '"') {
            if (quote_open) {
                printf("``");
            } else {
                printf("''");
            }
            quote_open = !quote_open;  // 切換狀態
        } else {
            putchar(ch);  // 其他字元照常輸出
        }
    }

    return 0;
}
/*使用 getchar() 一次讀取一個字元，直到遇到 EOF。

每遇到一個 "，根據 quote_open 狀態決定是要輸出 ```` 還是 ''，並切換狀態。

其他字元不做變動，直接輸出。*/
