FILENAME=template
OUTPUTDIR=output

TEX=$FILENAME.tex

cd $OUTPUTDIR

# sed -i '/^\\maketitle$/i \\\begin{titlepage}' $TEX
# sed -i '/^\\maketitle$/a \\\thispagestyle{empty}\n\\\end{titlepage}' $TEX

xelatex -synctex=1 -interaction=nonstopmode --shell-escape $TEX
xelatex -synctex=1 -interaction=nonstopmode --shell-escape $TEX
xelatex -synctex=1 -interaction=nonstopmode --shell-escape $TEX
