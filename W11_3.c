#include <stdio.h>
#include <ctype.h>

int main() {
    char line[256];
    int firstMaze = 1;

    while (fgets(line, sizeof(line), stdin)) {
        // �ˬd�O�_���Ŧ�]�g�c���������j�^
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
                printf("\n"); // ��X�g�c���Ŧ�
            }
            continue;
        }

        if (!firstMaze) {
            printf("\n"); // �g�c�����n�Ŧ�
        }
        firstMaze = 0;

        // �ѪR�C�@�檽�� EOF
        do {
            int i = 0;
            int count = 0;
            while (line[i] != '\0') {
                if (isdigit(line[i])) {
                    count += line[i] - '0';
                } else if (line[i] == '!') {
                    printf("\n"); // ������O
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

