#include <stdio.h>

int main() {
    int ch;
    int quote_open = 1;  // ���A�аO�G1 ��ܤU�@�� " �O�}�޸��A0 ��ܤU�@�� " �O���޸�

    while ((ch = getchar()) != EOF) {
        if (ch == '"') {
            if (quote_open) {
                printf("``");
            } else {
                printf("''");
            }
            quote_open = !quote_open;  // �������A
        } else {
            putchar(ch);  // ��L�r���ӱ`��X
        }
    }

    return 0;
}
/*�ϥ� getchar() �@��Ū���@�Ӧr���A����J�� EOF�C

�C�J��@�� "�A�ھ� quote_open ���A�M�w�O�n��X ```` �٬O ''�A�ä������A�C

��L�r�������ܰʡA������X�C*/
