# PHPExtension_EasyCache
�򵥵Ļ��棬����̽��PHP����չ������
Ŀǰֻ��һ����ϣ���Լ����ڴ����ͻ������
TODO:
����ҵ�� 
�ڴ������Ż�(malloc �Ż�/�������) 
��ϣ����Ż� 
�Ժ���˵...


# Compile
���뻷�� gcc-4.8 �� mingw-4.8

debug: gcc -DDEBUG -g x.c -o test

# Compile as php ext
ʹ�� phpsource/ext/ext_skel ������չ�Ǽ�

...with zend api...

�޸�config.m4

ʹ��phpize ����configure�ļ�

./configure &&��make 
