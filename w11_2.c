#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    getchar(); // �Y������r��

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
/*�ϥ� strtok() ���ο�J���C�@�q�y�D�C

�C�q���ץ��� 2�A�Ҧp "MF"�C

���O�p�� M �M F ���X�{���ơC

�̫�ھڱ����X���G*/
