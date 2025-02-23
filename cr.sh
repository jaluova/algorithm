#!/bin/bash

logError() {
  echo -e "\033[31m====== $1 ======\033[0m"
}
logWarning() {
  echo -e "\033[33m====== $1 ======\033[0m"
}
logInfo() {
  echo -e "\033[32m====== $1 ======\033[0m"
}

# 检查 cr 指令后是否跟着文件名
if [ -z "$1" ]; then
  logError "请在 cr 指令后跟上文件名，如 test.cpp"
  exit 1
fi

# 处理.cpp后缀
if [[ "$1"==*.cpp ]]; then
  sourceName="${1%.cpp}"
else
  sourceName="$1"
fi

# 检查是否存在 cpp 文件
if [ ! -e "$sourceName.cpp" ]; then
  logError "该目录下没有 $sourceName.cpp，请输入 ls 检查文件是否存在，或使用 cd 跳转到 cpp 所在目录"
  exit 1
fi

# 编译语句
c++ "$sourceName.cpp" -o "$sourceName" -O2 --std=c++20 -Wall -fdiagnostics-color=always 2>&1 | tee _compile.log
gpp_exit_status=${PIPESTATUS[0]}
# 编译失败
if [ $gpp_exit_status -ne 0 ]; then
  logError "编译失败，请检查上述语法错误"
  logError "查看红色 error 的信息，按住 command 点击 error 前面的文件坐标可以快速定位错误代码"
  rm _compile.log
  exit 1
fi

if grep -q "warning" _compile.log; then
  logWarning "上述是告警信息，请检查（如在预期内则可忽略）"
fi
# 如果你不希望看到编译成功和执行结束的话，可以在 logInfo 前加上 #
logInfo "编译成功，开始执行"
rm _compile.log

if [ $# -ge 2 ]; then
  # 检查是否存在输入文件
  if [ ! -e "$2" ]; then
    logError "该目录下没有输入文件 $2，请输入 ls 检查文件是否存在"
    exit 1
  fi
  if [[ $sourceName == "/"* ]]; then
    cat "$2" | $sourceName
  else
    cat "$2" | ./$sourceName
  fi
else
  if [[ $sourceName == "/"* ]]; then
    $sourceName
  else
    ./$sourceName
  fi
fi

logInfo "执行结束，删除可执行程序"
# 如果你不希望删除，可以在下面 rm 前加上 #
rm $sourceName