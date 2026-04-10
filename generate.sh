#/bin/bash
FILENAME=template
SRCDIR=src
OUTPUTDIR=output
USE_IMAGE=0

# parse --image flag
for arg in "$@"; do
    [ "$arg" = "--image" ] && USE_IMAGE=1
done

MARKDOWN=$FILENAME.md
TEX=$FILENAME.tex
PDF=$FILENAME.pdf

rm -rf $OUTPUTDIR
mkdir -p $OUTPUTDIR

cat icpcfoundation.jpg > $OUTPUTDIR/icpcfoundation.jpg
cat header.md > $OUTPUTDIR/$MARKDOWN
printf "\\\pagestyle{fancy}\n \\\fancyhead[RO,LE]{\\\textbf{ACM 模板  by Lese}}\n\n" >> $OUTPUTDIR/$MARKDOWN
for file in `ls $SRCDIR`
do
    if [ -f $SRCDIR/$file ]; then
        printf "\\\newpage\n \\\pagestyle{fancy}\n" >> $OUTPUTDIR/$MARKDOWN
        printf "\\\fancyhead[RO,LE]{\\\textbf{ACM 模板  by Lese}}\n\n" >> $OUTPUTDIR/$MARKDOWN
        echo >> $OUTPUTDIR/$MARKDOWN
        cat $SRCDIR/$file >> $OUTPUTDIR/$MARKDOWN
    else
        cp -r $SRCDIR/$file $OUTPUTDIR/$file
    fi
done

cd $OUTPUTDIR

pandoc -F pandoc-minted -s $MARKDOWN -o $TEX --toc-depth=2

sed -i '/^\\maketitle$/i \\\begin{titlepage}' $TEX

if [ $USE_IMAGE -eq 1 ]; then
    # Extract title/author/date values from preamble for manual placement
    TITLE=$(grep '^\\title{' $TEX | sed 's/^\\title{\(.*\)}/\1/')
    AUTHOR=$(grep '^\\author{' $TEX | sed 's/^\\author{\(.*\)}/\1/')
    DATE=$(grep '^\\date{' $TEX | sed 's/^\\date{\(.*\)}/\1/')
    # Suppress all three so \maketitle produces only empty spacing (not visible content)
    sed -i 's/^\\title{.*}/\\title{}/' $TEX
    sed -i 's/^\\author{.*}/\\author{}/' $TEX
    sed -i 's/^\\date{.*}/\\date{}/' $TEX
    # Escape backslashes for awk -v (awk interprets \X as escape sequences)
    TITLE_AWK="${TITLE//\\/\\\\}"
    AUTHOR_AWK="${AUTHOR//\\/\\\\}"
    DATE_AWK="${DATE//\\/\\\\}"
    # Keep \maketitle for its empty spacing, then manually place title/image/author/date
    awk -v title="$TITLE_AWK" -v author="$AUTHOR_AWK" -v date="$DATE_AWK" '
        /^\\maketitle$/{
            print;
            print "\\vspace{2cm}";
            print "\\centerline{" title "}";
            print "\\vspace{5cm}";
            print "\\centerline{\\includegraphics[width=12cm]{icpcfoundation.jpg}}";
            print "\\vspace{1.6cm}";
            print "\\centerline{" author "}";
            print "\\vspace{0.5cm}";
            print "\\centerline{" date "}";
            print "\\thispagestyle{empty}";
            print "\\end{titlepage}";
            next
        }1' $TEX > ${TEX}.tmp && mv ${TEX}.tmp $TEX
else
    sed -i '/^\\maketitle$/a \\\thispagestyle{empty}\n\\\end{titlepage}' $TEX
fi

xelatex -synctex=1 -interaction=nonstopmode --shell-escape $TEX
xelatex -synctex=1 -interaction=nonstopmode --shell-escape $TEX
xelatex -synctex=1 -interaction=nonstopmode --shell-escape $TEX

if [ $? -ne 0 ]; then
    echo "error"
    exit
fi

cd -

mv $OUTPUTDIR/$PDF $PDF >/dev/null 2>&1
rm -r $OUTPUTDIR >/dev/null 2>&1

echo "done"
