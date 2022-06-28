# OI-TRAINING
从零开始进行OI康复训练，已经是个读不懂题的废物了。

## 使用指南
配套vscode使用：

1. 配置.vscode下的各种json文件，Mac OS和Windows的配置见附录。
2. 解题前，只需要在仓库根目录执行`python run.py [leetcode|luogu|openjudge] ${problem}`即可在相应目录下生成板子。
3. `cd`到`${problem}`目录下，有4个文件，in.txt用于填写输入，out.txt填写输出，${problem}.cpp用于写题，${problem}.md用来记录题、写writeup或者思路。
4. shift+command+b(Mac OS)或者ctrl+shift+b(Windows)编译，F5可单步调试。


## 附录
### Mac OS配置

c_cpp_properties.json

```json
{
    "configurations": [
        {
            "name": "Mac",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": ["LOCAL"],
            "macFrameworkPath": [
                "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks"
            ],
            "compilerPath": "/usr/bin/clang++",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "macos-clang-x64"
        }
    ],
    "version": 4
}
```

launch.json

```json
{
    // 使用 IntelliSense 了解相关属性。 
    // 悬停以查看现有属性的描述。
    // 欲了解更多信息，请访问: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "lldb",
        },
    ]
}
```

settings.json

```json
{
    "files.associations": {
        "chrono": "cpp",
        "ostream": "cpp",
        "vector": "cpp",
        "iosfwd": "cpp",
        "string": "cpp",
        "__bit_reference": "cpp",
        "__hash_table": "cpp",
        "__split_buffer": "cpp",
        "__tree": "cpp",
        "array": "cpp",
        "deque": "cpp",
        "initializer_list": "cpp",
        "ios": "cpp",
        "map": "cpp",
        "set": "cpp",
        "string_view": "cpp",
        "unordered_map": "cpp",
        "iterator": "cpp",
        "iostream": "cpp",
        "algorithm": "cpp"
    }
}
```

tasks.json

```json
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: g++ 生成活动文件",
            "command": "/usr/bin/g++",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}",
                "-DLOCAL",
                "-std=c++17"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "调试器生成的任务。"
        }
    ],
    "version": "2.0.0"
}
```

### Windows配置
TODO