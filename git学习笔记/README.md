
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

## git rm

当我们需要删除暂存区或分支上的文件, 同时工作区也不需要这个文件了, 可以使用

git rm file_path
git commit -m 'delete somefile'
git push origin main:main

## git rm --cached

当我们需要删除暂存区或分支上的文件, 但本地又需要使用, 只是不希望这个文件被版本控制, 可以使用

git rm --cached file_path
git commit -m 'delete remote somefile'
git push origin main:main

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

git push [-f] [--set-upstream] [远端名称] [本地分支名][:远端分支名]

将仓库里的更新都抓取到本地，不会进行合并
git fetch [remote name] [branch name]

拉取远端仓库的修改拉到本地自动进行合并，等同于fetch+merge
git pull [remote name] [branch name]

查看本地分支与远程分支的绑定关系
git branch -vv

如果没有绑定关系，就将本地分支main和远程分支main绑定关系
git push --set-upstream origin main:main

# 修改分支名
git branch -m [原名称] [新名称]

# 删除分支名
git branch -d [分支名称]

# 删除远程分支
git push origin :[远程分支名]

更新远程分支列表
git remote update origin --prune

查看所有分支
git branch -a

删除远程分支Chapater6
git push origin --delete Chapater6

删除本地分支 Chapater6
git branch -d  Chapater6

# 合并本地分支并提交到远程分支

假设我们在本地dev分支上进行了修改，现在需要和远程的main分支合并。
我们可以先切换到本地的main分支上，之后拉取远程main分支，
使用git merge dev将本地main分支和本地dev分支合并
之后使用git push origin main提交合并后的代码

# Git常见警告和错误

## Git:warning: ignoring broken ref refs/remotes/origin/HEAD

这个问题最初是我在git remote add添加了一个新的远端仓库引用时遇到的，当时起的名字时mytest，之后我在使用git branch -a时遇到了这个警告，这里可以通过删除./.git/refs/remotes/mytest来解决

- 找到.git目录下refs/remotes/origin目录（子模块的这个目录是在主模块的.git目录下，因为子模块没有.git目录）
- 删除里面的HEAD文件或者所有文件
- 然后运行git fetch –all

# 更新git版本

## 更新windows下的git版本

查看git版本

```bash
git --version / git version
```

更新

git版本是2.17.1之前的话使用 git update
git版本是2.17.1之后的话使用 git update-git-for-windows

## 更新ubuntu下的git版本

查看git版本

```bash

git --version

```

升级

sudo apt update  # 更新源
sudo apt install software-properties-common # 安装 PPA 需要的依赖
sudo add-apt-repository ppa:git-core/ppa    # 向 PPA 中添加 git 的软件源
sudo apt-get update
sudo apt-get install git


