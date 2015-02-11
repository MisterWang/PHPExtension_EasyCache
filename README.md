# PHPExtension_EasyCache
简单的缓存，用以探究PHP的拓展开发。
目前只有一个哈希表以及用于处理冲突的链表。
TODO:
缓存业务 
内存管理的优化(malloc 优化/替代方案) 
哈希表的优化 
以后再说...


# Compile
编译环境 gcc-4.8 或 mingw-4.8

debug: gcc -DDEBUG -g x.c -o test

# Compile as php ext
使用 phpsource/ext/ext_skel 生成拓展骨架

...with zend api...

修改config.m4

使用phpize 生成configure文件

./configure &&　make 
