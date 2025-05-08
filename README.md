# ICPC 模板生成工具

## 依赖

- [TexLive](http://tug.org/texlive/)
- [Pandoc](https://www.pandoc.org/)
- [Pygments](http://pygments.org/)
- [pandoc-minted](https://pypi.org/project/pandoc-minted/)

```bash
sudo apt install pandoc texlive-latex-recommended \
         texlive-latex-extra texlive-fonts-recommended
sudo apt install texlive-xetex
pip install Pygments pandoc-minted
```

注: 最初版本在 Ubuntu 18.04 可以正常使用，但是在 Ubuntu 20.04 中会出现不兼容的问题，推荐使用 Ubuntu 22.04

## 使用方式

- 使用 markdown 编辑工具在 `src` 文件夹内编写模板、修改 `header.md` 中的作者信息。
- 运行 `generate.sh` 自动生成 `template.pdf`；各章节会按 `ls` 命令中所列的顺序排序。
- 相关细节需要定制请自行修改脚本和阅读相关文档。

运行脚本方式:

```bash
sh generate.sh
bash generate.sh 两种都可
```

注意：需要到达对应的目录底下

```cpp
sh支持\\\newpage
bash 支持\\newpage
```

打开 pdf 的命令：
```bash
evince template.pdf
```

## FAQ

- head.md 语法问题

head.md里的--- --- 是frontmetter，pandoc 读的元数据！！！

- Ubuntu 22.04.3 生成模板时出现的问题

问题描述
```
! LaTeX Error: File ctexhook.sty' not found.
```

解决方法
```bash
sudo apt install texlive-lang-chinese
```

- xelatex 的字体问题

```bash
sudo apt-get install latex-cjk-all
```
