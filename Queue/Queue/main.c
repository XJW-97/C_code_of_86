#include "Queue.h"

//��ѭ�����Ա�ʵ�ֶ���
int main()
{
	//�ɻ�֮ǰ����Ҫ���Լ��Ķ���
	SeqQueue myqueue;
	//�����Լ��Ķ�����Ҫ���г�ʼ��
	SeqQueueInit(&myqueue);
	//��ʼ�����֮����Ҫ���и�ֵ
	SeqQueueEn(&myqueue, 1);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 2);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 3);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 4);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 5);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 6);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 7);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 8);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 9);
	SeqQueueEn(&myqueue, 10);
	printf("����ͷ������Ϊ%d \n", SeqQueueFront(&myqueue));
	printf("����β������Ϊ%d \n", SeqQueueBack(&myqueue));
	printf("==========================================\n");
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 9);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 10);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueDestroy(&myqueue);
	return 0;
}




/*
//�����Ա�ʵ�ֶ���
int main()
{
	//�ɻ�֮ǰ����Ҫ���Լ��Ķ���
	SeqQueue myqueue;
	//�����Լ��Ķ�����Ҫ���г�ʼ��
	SeqQueueInit(&myqueue);
	//��ʼ�����֮����Ҫ���и�ֵ
	SeqQueueEn(&myqueue, 1);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 2);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 3);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 4);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 5);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 6);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 7);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 8);
	SeqQueueShow(&myqueue);
	printf("����ͷ������Ϊ%d \n", SeqQueueFront(&myqueue));
	printf("����β������Ϊ%d \n", SeqQueueBack(&myqueue));
	printf("==========================================\n");
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueDestroy(&myqueue);
	return 0;
}

*/

/*
//������ʵ��
int main()
{
	//����Ҫ���Լ��Ķ���
	LinkQueue myqueue;
	//�����Լ��Ķ��к���г�ʼ��
	LinkQueueInit(&myqueue);
	//�������
	LinkQueueEn(&myqueue, 1);
	LinkQueueShow(&myqueue);
	LinkQueueEn(&myqueue, 2);
	LinkQueueShow(&myqueue);
	LinkQueueEn(&myqueue, 3);
	LinkQueueShow(&myqueue);
	LinkQueueEn(&myqueue, 4);
	LinkQueueShow(&myqueue);
	LinkQueueEn(&myqueue, 5);
	LinkQueueShow(&myqueue);
	printf("====================================================\n");
	LinkQueueShow(&myqueue);
	LinkQueueDe(&myqueue);//����(�൱��ɾ��һ������)
	LinkQueueShow(&myqueue);
	LinkQueueDe(&myqueue);
	LinkQueueShow(&myqueue);
	LinkQueueDe(&myqueue);
	LinkQueueShow(&myqueue);
	LinkQueueDe(&myqueue);
	LinkQueueShow(&myqueue);
	LinkQueueDe(&myqueue);
	LinkQueueShow(&myqueue);

	return 0;
}*/