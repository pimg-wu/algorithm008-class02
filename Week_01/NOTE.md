学习笔记

名：pimg

git和GitHub的使用：
git init //初始化
git config --global user.name "pimg"
git config --global user.email ""
git config --global --list
git status	//查看状态
工作区到暂存区： git add
暂存区到git仓库： git commit -m "注释"
git log
添加到仓库： git remote add origin "git@github.com:pimg-wu/learn_git.git
git push -u origin master
复制仓库： git clone git@github.com:pimg-wu/alo...

视频 + 题目
1、数组、链表、跳表的实现和特性
2、栈和队列的实现和特性
	双端队列Deque
	优先队列Priority Queue
	底层具体实现的数据结构较为多样和复杂  //？
	
题解优化思路：
1、空间换时间
2、升维

解题常见思路：
1、左右夹逼 （双指针法）
2、锁定数组下标
3、找最近重复子问题