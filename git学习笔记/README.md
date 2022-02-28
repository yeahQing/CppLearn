
# git常用命令记录

[git命令整理](https://www.runoob.com/note/56524)

git config

git help

git init

git clone

git status

git add

git commit

git push

git diff

git reset

git rm

git mv

git branch

git checkout

git fetch

git pull

git merge

git mergetool

git remote

git log

git stash

git tag

git submodule

git show

git shortlog

git describe

git rebase


# .gitignore文件使用方法

常用.gitignore文件配置: https://github.com/github/gitignore
在目录下创建.gitignore文件，其中添加需要排除的文件目录或文件
也可以使用git add添加已经排除的文件进行测试是否有效。

移除已经添加到缓存中的文件:

git rm --cached .

# 使用github token提交
使用下面的命令:

git remote set-url origin https://<your_token>@github.com/<USERNAME>/<REPO>.git

# 和远程仓库进行链接

git remote add origin git@github.com:yeahQing/CppLearn.git

可以看到添加token就是在原有的https链接的github.com之前加上token和@符号
git remote add origin https://github.com/yeahQing/CppLearn.git

移除链接:
git remote rm origin

# 创建和删除远程分支

在本地创建一个新的分支，并checkout到该分支，push到远端仓库，即可创建一个新的同名分支

git checkout -b 等价于 git branch new_branch_name + git checkout new_branch_name
git checkout -b new_branch_name 创建并切换到新的本地分支

git push origin new_branch_name 这里如果名字不一样也可以




