这个代码是从distrilua的代码里提取出来的。

主要包括：

| 名字        | 说明                                                         |
| ----------- | ------------------------------------------------------------ |
| linkque.lua | 这个是lua实现一个双向队列。可以跟C语言版本印证。看看lua的特点是什么。 |
| minheap相关 | 对应的几个文件，一起实现了C调用lua文件，lua文件里再使用C语言实现的模块的过程。使用方式是：make test-luaminheap 会得到一个test-luaminheap的可执行文件。执行这个文件，就可以看到效果。 |
|             |                                                              |

