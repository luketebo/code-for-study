#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char passageA[20];
    char passageB[20];
    printf("�������һƪ���µ��ļ�����");
    scanf("%s", passageA);
    printf("������ڶ�ƪ���µ��ļ�����");
    scanf("%s", passageB);
    char* nameA = (char*)malloc(strlen(passageA) + 7);
    char* nameB = (char*)malloc(strlen(passageB) + 7);
    sprintf(nameA, "./%s.txt", passageA);
    sprintf(nameB, "./%s.txt", passageB);
    //    printf("%s\n",nameA);
    //    printf("%s\n",nameB);
    printf("���������Ե�...\n");
    FILE* fpA, * fpB;
    fpA = fopen(nameA, "r");
    fpB = fopen(nameB, "r");
    if (fpA == NULL || fpB == NULL) {
        if (fpA == NULL)
            printf("��һƪ���²����ڣ�\n");
        if (fpB == NULL)
            printf("�ڶ�ƪ���²����ڣ�\n");
    }
    char words_A[3000][20];
    int words_A_length = 0;
    char words_B[3000][20];
    int words_B_length = 0;
    fscanf(fpA, "%s", words_A[0]);
    words_A_length++;
    if (feof(fpA)) {
        printf("��һƪ����Ϊ�գ�");
    }
    for (int i = 1; !feof(fpA); i++) {
        fscanf(fpA, "%s", words_A[i]);
        words_A_length++;
    }
    fscanf(fpB, "%s", words_B[0]);
    words_B_length++;
    if (feof(fpB)) {
        printf("�ڶ�ƪ����Ϊ�գ�");
    }
    for (int i = 1; !feof(fpB); i++) {
        fscanf(fpB, "%s", words_B[i]);
        words_B_length++;
    }
    printf("%d", words_B_length);
    //����
//    for(int i=0;words_A[i][0]!='\0';i++){
//        printf("%s\n",words_A[i]);
//    }
//    printf("=======================================================\n");
//    for(int i=0;words_B[i][0]!='\0';i++){
//        printf("%s\n",words_B[i]);
//    }
    char sameWord[3000][20];//��ͬ�ĵ�������
    int sameWord_length = 0;//��ͬ�ĵ�������ĳ���
    for (int i = 0; words_A[i][0] != '\0'; i++) {
        //�жϵ����Ƿ��Ѵ���sameWord��
        int flag_already = 0;
        for (int m = 0; sameWord[m][0] != '\0'; m++) {
            if (strcmp(words_A[i], sameWord[m]) == 0) {
                flag_already = 1;
                break;
            }
        }
        if (flag_already == 1)
            continue;
        for (int j = 0; words_A[j][0] != '\0'; j++) {
            int flag = sameWord_length;
            if (strlen(words_A[i]) != strlen(words_B[j]))  // ���ʳ��Ȳ�ͬ
                continue;
            for (int k = 0; k < 20; k++) {
                if (words_A[i][k] != words_B[j][k])
                    break;
                if (words_A[i][k] == '\0' && words_B[j][k] == '\0') {
                    strcpy(sameWord[sameWord_length], words_A[i]);
                    sameWord_length++;
                    break;
                }
            }
            if (flag != sameWord_length)
                break;
        }
    }
    printf("��ͬ�ĵ����У�\n");
    for (int i = 0; sameWord[i][0] != '\0'; i++) {
        printf("%s\n", sameWord[i]);
        int occurrences = 0;
        for (int j = 0; words_A[j][0] != '\0'; j++) {
            if (strcmp(sameWord[i], words_A[j]) == 0) {
                occurrences++;
            }

        }
        printf("��һƪ���³��ִ�����%d\t", occurrences);
        printf("ռ��һƪ���µ��������İٷֱȣ�%f%%\n", (float)occurrences / (float)words_A_length * 100);
        occurrences = 0;
        for (int j = 0; words_B[j][0] != '\0'; j++) {
            if (strcmp(sameWord[i], words_B[j]) == 0) {
                occurrences++;
            }
        }
        printf("�ڶ�ƪ���³��ִ�����%d\t", occurrences);
        printf("ռ�ڶ�ƪ���µ��������İٷֱȣ�%f%%\n", (float)occurrences / (float)words_B_length * 100);
    }
    printf("��ͬ����������%d", sameWord_length);
    fclose(fpA);
    fclose(fpB);
    return 0;
}