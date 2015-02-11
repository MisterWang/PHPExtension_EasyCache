# PHPExtension_EasyCache
简单的缓存，用以探究PHP的拓展开发。

# Compile
编译环境 gcc-4.8 或 mingw-4.8

debug: gcc -DDEBUG -g x.c -o test

# Compile as php ext
使用 phpsource/ext/ext_skel 生成拓展骨架

...with zend api...

修改config.m4

使用phpize 生成configure文件

./configure &&　make 
