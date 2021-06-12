#include "curl/curl.h"
#include <iostream>

using namespace std;

/**
* һ��curl���յ����ݣ��ͻ���ô˻ص�����
* buffer:���ݻ�����ָ��
* size:���Խ׶����Ƿ���Ϊ1
* nmemb:(memory block)����˴ν��ܵ��ڴ��ĳ���
* userp:�û��Զ����һ������
*/
size_t write_data(void* buffer, size_t size, size_t nmemb, void* userp)
{
	static int current_index = 0;

	cout << "current:" << current_index++;
	cout << (char*)buffer;
	cout << "---------------" << endl;

	int temp = *(int*)userp;    // �����ȡ�û��Զ������
	return nmemb;
}

int curl_test(void)
{
	curl_global_init(CURL_GLOBAL_ALL); // ����ȫ�ֳ�ʼ��CURL
	CURL* curl = curl_easy_init(); // ��ʼ��CURL���

	if (NULL == curl)
	{
		printf("(curl is NULL!\r\n");
		return 0;
	}

	int my_param = 1;    // �Զ���һ���û�����

	// ����Ŀ��URL
	curl_easy_setopt(curl, CURLOPT_URL, "http://www.baidu.com");
	// ���ý��յ�HTTP������������ʱ���õĻص�����
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
	// �����Զ������(�ص������ĵ��ĸ�����)
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &my_param);
	// ִ��һ��URL����
	CURLcode res = curl_easy_perform(curl);
	// ����ɾ�
	curl_easy_cleanup(curl);

	return 0;
}

int main()
{
	curl_test();

	getchar();
	return 0;
}