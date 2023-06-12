// -*- coding: gb2312 -*-
#include <stdio.h>
unsigned __int32 ci, m_shift, m_musk = 0;
int len_ci;
__int32 scan_b()
{
    char ch[36];
    int i, num = 0;
    scanf("%s", ch);
    for (i = 0; ch[i]; i++)
        num = num << 1 | (ch[i] ^ '0');
    return num;
}
void print_b(unsigned __int32 num, int len)
{
    int i;
    for (i = len - 1; i >= 0; i--)
        putchar((num >> i & 1) ^ '0');
    putchar('\n');
}
int main()
{
    printf("\n");
    printf("----------------------------------------\n");
    printf("* M ����ģ���� | M-sequence simulator  *\n");
    printf("* author: Vincent SHI                  *\n");
    printf("* blog: https://blog.vincent1230.top/  *\n");
    printf("* version: 1.0                         *\n");
    printf("----------------------------------------\n");
    int i;
    printf("\n��ʹ�� 8 ������������ M ���еķ���ϵ��, \n");
    printf("����, M(23)_8 �����з�����, ���� 23. \n");
    printf("Use 8 decimal number to input the feedback coefficient of M sequence, \n");
    printf("For example, M(23)_8, input 23. \n");
    printf("������ | Please input: ");
    scanf("%o", &ci);
    while (ci & ~m_musk)
        m_musk = m_musk << 1 | 1;
    m_musk = m_musk >> 1;
    len_ci = __builtin_popcount(m_musk);
    printf("    ����> %d bits: (1)", len_ci + 1);
    print_b(ci, len_ci);
    printf("\n��ʹ�� 2 �������������ʼ״̬, \n");
    printf("����, \"-> 0 0 0 1 ->\" �ĳ�ʼ״̬Ϊ 0001. \n");
    printf("Use 2 decimal number to input the initial state, \n");
    printf("For example, \"-> 0 0 0 1 ->\" , input 0001. \n");
    printf("������ | Please input: ");
    m_shift = scan_b();
    printf("    ����> %d regs: ", len_ci);
    print_b(m_shift, len_ci);
    m_shift &= m_musk;
    printf("\n");
    printf("----------------------------------------\n");
    printf("     M ������� | M-sequence output     \n");
    printf("----------------------------------------\n\n");
    printf("���س����������, ���������˳�. \n");
    printf("Press Enter to continue and any other key to exit. \n");
    while (getchar() == '\n')
    {
        printf("\n");
        for (i = 0; i < 32; i++)
        {
            putchar((m_shift & 1) ^ '0');
            m_shift |= __builtin_parity(m_shift & ci) << len_ci;
            m_shift >>= 1;
            putchar(' ');
        }
        printf("\n... ");
    }
    return 0;
}
