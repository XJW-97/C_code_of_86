#include"Stack.h"
//������ʵ��ջ
int main()
{
	//�ɻ�֮ǰҪ���Լ���ջ
	LinkStack mystack;
	//�����Լ���ջ֮����Ҫ���г�ʼ��
	LinkStackInt(&mystack);
	//�������ݵĲ���
	LinkStackEn(&mystack, 1);
	LinkStackShow(&mystack);
	LinkStackEn(&mystack, 2);
	LinkStackShow(&mystack);
	LinkStackEn(&mystack, 3);
	LinkStackShow(&mystack);
	LinkStackEn(&mystack, 4);
	LinkStackShow(&mystack);
	printf("��ǰ��ջ��Ϊ %d \n", LinkStackTop(&mystack));
	printf("================================\n");
	LinkStackDe(&mystack);
	LinkStackShow(&mystack);
	LinkStackDe(&mystack);
	LinkStackShow(&mystack);
	LinkStackDe(&mystack);
	LinkStackShow(&mystack);
	LinkStackDe(&mystack);
	LinkStackShow(&mystack);
	LinkStackDe(&mystack);
	LinkStackDestroy(&mystack);

	return 0;
}






/*
//�����Ա������ʵ��ջ
//�Ƚ����  ����  ����ȳ�
int main()
{
	//�ɻ�֮ǰ��Ҫ���Լ���ջ
	SeqStack mystack;
	//�����Լ���ջ����Ҫ���г�ʼ��
	SeqStackInit(&mystack,0);
	//ʵ�����ݴ洢�����Ƚ����
	SeqStackEn(&mystack, 1);
	SeqStackShow(&mystack);
	SeqStackEn(&mystack, 2);
	SeqStackShow(&mystack);
	SeqStackEn(&mystack, 3);
	SeqStackShow(&mystack);
	SeqStackEn(&mystack, 4);
	SeqStackShow(&mystack);
	SeqStackEn(&mystack, 5);
	SeqStackShow(&mystack);
	SeqStackEn(&mystack, 6);
	SeqStackShow(&mystack);
	printf("��ǰ��ջ��Ԫ��Ϊ%d \n", SeqStackTop(&mystack));
	printf("================================\n");
	SeqStackDe(&mystack);
	SeqStackShow(&mystack);
	SeqStackDe(&mystack);
	SeqStackShow(&mystack);
	SeqStackDe(&mystack);
	SeqStackShow(&mystack);
	SeqStackDe(&mystack);
	SeqStackShow(&mystack);
}
*/