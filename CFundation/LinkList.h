#pragma once
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
	//����ڵ���������
	struct LinkNode {
		int data;
		struct LinkNode* next;
	};

	//��ʼ������
	struct LinkNode* Init_LinkList();
	//��ֵΪoldval��λ�ò���һ���µ�����newval
	void InsertByValue_LinkList(struct LinkNode* header, int oldval, int newval);
	//ɾ��ֵΪval�Ľ��
	void RemoveByValue_LinkList(struct LinkNode* header, int delValue);
	//����
	void Foreach_LinkList(struct LinkNode* header);
	//����
	void Destroy_LinkList(struct LinkNode * header);
	//���
	void Clear_LinkList(struct LinkNode* header);
	//��������
	void Reverse_LinkList(struct LinkNode* header);
#ifdef __cplusplus
}
#endif // __cplusplus
